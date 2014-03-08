#include "cloudcontrol.h"

CloudControl::CloudControl(QObject *parent) : QObject(parent)
{

}

QString CloudControl::getBaseURL() {
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

void CloudControl::UploadRecipe(Recipe *recipe, QWidget *parent) {

    // Pushes this Recipe to the remote output
    QUrl url(getBaseURL()+"/recipes/");
    QString xml = recipe->toXML("");

    networkManager = new QNetworkAccessManager(parent);

    QNetworkRequest request;
    request.setUrl(url);
    request.setRawHeader("User-agent", "StrangewbrewQT");
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/octet-stream");

    QByteArray data (xml.toUtf8());
    qDebug() << xml.toUtf8();

    qDebug() << "Data length: " << data.size();
    uploadProgress = new QProgressDialog("Uploading recipe...", "Abort Upload", 0, data.size(), parent);
    uploadProgress->show();

    QNetworkReply *reply = networkManager->post(request, data);

    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(uploadComplete(QNetworkReply*)));
    connect(reply, SIGNAL(uploadProgress(qint64,qint64)), this, SLOT(uploadingData(qint64, qint64)));
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),
            this, SLOT(slotError(QNetworkReply::NetworkError)));
    connect(uploadProgress, SIGNAL(canceled()), this, SLOT(uploadCancelled()));
}

void CloudControl::uploadComplete(QNetworkReply *reply) {
    QString rId = reply->readAll();
    if (rId.contains("recipe id:")) {
        rId.replace("recipe id: ", "");
        QMessageBox::about(qobject_cast<QWidget*>(parent()), "Recipe Uploaded!", "Recipe uploaded, remote ID: " + rId);
    }

    reply->close();
    uploadProgress->close();
    uploadProgress->deleteLater();
}

void CloudControl::uploadingData(qint64 bytesSent, qint64 bytesTotal) {
    qDebug() << "Uploaded " << bytesSent << " of " << bytesTotal;

    //Q_UNUSED(bytesTotal);
    uploadProgress->setValue(bytesSent);
}

void CloudControl::uploadCancelled() {
    QNetworkReply *reply = qobject_cast<QNetworkReply *> (sender());
    if (reply != NULL) {
        reply->abort();
    }
    uploadProgress->close();
    uploadProgress->deleteLater();
}

void CloudControl::slotError(QNetworkReply::NetworkError e ) {
    qDebug() << e;
    QNetworkReply *reply = qobject_cast<QNetworkReply *> (sender());
    QString rep = reply->readAll();
    if (rep.contains("already exists", Qt::CaseInsensitive)) {
        QMessageBox::about(qobject_cast<QWidget*>(parent()), "Recipe Duplicate", "Recipe already exists with this name");
    }
    qDebug() << reply->errorString();
    qDebug() << reply->readAll();
}

//Recipe CloudControl::DownloadRecipe() {
//}

