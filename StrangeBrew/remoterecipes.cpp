#include "remoterecipes.h"
#include "ui_remoterecipes.h"



RemoteRecipes::RemoteRecipes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoteRecipes)
{
    ui->setupUi(this);
    networkManager = new QNetworkAccessManager(this);
    rModel = new RecipeModel(ui->recipeTable);
    ui->recipeTable->setModel(rModel);

    ui->errorLabel->setText("Downloading recipe lists...");
    getRecipeStyles();
    getRecipeBrewers();

}

RemoteRecipes::~RemoteRecipes()
{
    delete ui;
}

QString RemoteRecipes::getBaseURL() {
    QSettings opts("Doug Edey", "StrangeBrew");
    QString baseURL = opts.value("Cloud/URL").toString();
    if (baseURL.startsWith("strangebrew://")) {
        baseURL.replace("strangebrew://", "http://");
    }

    if (!baseURL.startsWith("http://")) {
        baseURL = "http://" + baseURL;
    }

    return baseURL;
}

void RemoteRecipes::getRecipeStyles() {
    QString baseURL = getBaseURL();
    QUrl url(baseURL+"/styles/");

    QNetworkRequest request;
    request.setUrl(url);
    request.setRawHeader("User-agent", "StrangewbrewQT");


    QNetworkReply *stylesReply = networkManager->get(request);

    connect(stylesReply, SIGNAL(finished()), this, SLOT(stylesDownloaded()));
}

void RemoteRecipes::getRecipeBrewers() {
    QString baseURL = getBaseURL();
    QUrl url(baseURL+"/brewer/");

    QNetworkRequest request;
    request.setUrl(url);
    request.setRawHeader("User-agent", "StrangewbrewQT");


    QNetworkReply *brewersReply = networkManager->get(request);

    connect(brewersReply, SIGNAL(finished()), this, SLOT(brewersDownloaded()));
}

void RemoteRecipes::stylesDownloaded() {
    QDomDocument inputSource;
    QNetworkReply *reply = qobject_cast<QNetworkReply *> (sender());
    inputSource.setContent(reply->readAll());

    ui->errorLabel->setText("Reading Style list...");

    QDomNodeList styleList = inputSource.elementsByTagName("style");
    qDebug() << "Styles Found " << styleList.count();

    // clear the existing list
    ui->styleCombo->clear();

    for (int i = 0; i < styleList.count(); i++) {
        QDomNode curStyle = styleList.at(i);
        if (curStyle.isElement()) {

            qDebug() << "Value " << curStyle.toElement().text();
            //qDebug() << "Text " << curStyle.nodeType().s
            ui->styleCombo->addItem(curStyle.toElement().text());
        }
    }
    ui->errorLabel->setText("Style List updated.");
}

void RemoteRecipes::brewersDownloaded() {
    QDomDocument inputSource;
    QNetworkReply *reply = qobject_cast<QNetworkReply *> (sender());
    inputSource.setContent(reply->readAll());

    QDomNodeList brewersList = inputSource.elementsByTagName("brewer");
    ui->errorLabel->setText("Downloading brewer list...");

    // clear the existing list
    brewerList.clear();
    for (int i = 0; i < brewersList.count(); i++) {
        QDomNode curBrewer = brewersList.at(i);
        if (curBrewer.isElement()) {

            qDebug() << "Value " << curBrewer.toElement().text();
            //qDebug() << "Text " << curStyle.nodeType().s
            brewerList << curBrewer.toElement().text();
        }
    }

    brewerCompleter = new QCompleter(brewerList, this);
    brewerCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    brewerCompleter->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->brewerCombo->setCompleter(brewerCompleter);
    qDebug() << "Post update: " << brewerList.size();
    ui->errorLabel->setText("Brewer List updated.");
}


void RemoteRecipes::listRecipesByStyle(QString style) {
    QString baseURL = getBaseURL();
    QUrl url(baseURL+"/styles/"+style);

    QNetworkRequest request;
    request.setUrl(url);
    request.setRawHeader("User-agent", "StrangewbrewQT");

    ui->errorLabel->setText("Requesting recipe list for style " + style + "...");
    QNetworkReply *reply = networkManager->get(request);
    connect(reply, SIGNAL(finished()), this, SLOT(listRecipesDownloaded()));
}

void RemoteRecipes::listRecipesByBrewer(QString brewer) {
    QString baseURL = getBaseURL();
    QUrl url(baseURL+"/brewer/"+brewer);

    ui->errorLabel->setText("Requesting recipe list for brewer " + brewer + "...");
    QNetworkRequest request;
    request.setUrl(url);
    request.setRawHeader("User-agent", "StrangewbrewQT");


    QNetworkReply *reply = networkManager->get(request);
    connect(reply, SIGNAL(finished()), this, SLOT(listRecipesDownloaded()));
}

void RemoteRecipes::listRecipesDownloaded() {
    QDomDocument inputSource;
    QNetworkReply *reply = qobject_cast<QNetworkReply *> (sender());
    inputSource.setContent(reply->readAll());

    ui->errorLabel->setText("Displaying recipe list ...");
    //qDebug() << inputSource.toString();

    QDomNodeList recipeList = inputSource.elementsByTagName("recipe");

    data_list.clear();

    for (int i = 0; i < recipeList.count(); i++) {
        QDomNode curRecipe = recipeList.at(i);
        basicRecipe b;
        QDomElement n = curRecipe.toElement();

        b.id = n.attribute("id").toInt();
        b.style = n.attribute("style");
        b.title = n.attribute("name");
        b.brewer = n.attribute("brewer");
        b.iteration = n.attribute("iteration", "0").toInt();

        data_list.append(b);
    }

    rModel->dataList(&data_list);
    ui->errorLabel->setText("Recipe List updated.");
}

void RemoteRecipes::on_styleCombo_currentIndexChanged(const QString &style)
{
    listRecipesByStyle(style);
}

void RemoteRecipes::on_brewerCombo_currentIndexChanged(const QString &brewer)
{
    listRecipesByBrewer(brewer);
}


void RemoteRecipes::on_downloadButton_clicked()
{
    QModelIndexList indexes = ui->recipeTable->selectionModel()->selectedRows();
    QString error = "";

    // Do we have any indexes that're selected
    if (indexes.size() == 0) {
        error = "No Rows selected";
    }

    if (indexes.size() > 1) {
        error = "More than one row selected";
    }

    if (error != "") {
        ui->errorLabel->setText(error);
        return;
    }

    QModelIndex index = indexes.first();

    int rIndex = index.row();
    int id = data_list.at(rIndex).id;

    QString baseURL = getBaseURL();
    QUrl url(baseURL+"/recipes/"+QString::number(id));
    qDebug() << url.toString();

    QNetworkRequest request;
    request.setUrl(url);
    request.setRawHeader("User-agent", "StrangewbrewQT");


    QNetworkReply *reply = networkManager->get(request);
    ui->errorLabel->setText("Downloading Recipe...");
    connect(reply, SIGNAL(finished()), this, SLOT(recipeDownloaded()));
}

void RemoteRecipes::recipeDownloaded() {
    QModelIndexList indexes = ui->recipeTable->selectionModel()->selectedIndexes();
    QModelIndex index = indexes.first();
    basicRecipe r = data_list.at(index.row());
    QNetworkReply *reply = qobject_cast<QNetworkReply *> (sender());

    QString filename = r.title + " - " + QString::number(r.id) + ".xml";
    ui->errorLabel->setText("Writing recipe file: " + filename);
    QFile outputFile(filename);

    outputFile.open(QIODevice::WriteOnly);

    outputFile.write(reply->readAll());
    outputFile.close();
    recipeFileName = filename;
    emit accepted();
}

QString RemoteRecipes::getRecipeFileName() {
    return recipeFileName;
}
