#include "newhop.h"
#include "ui_newhop.h"

NewHop::NewHop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewHop)
{
    ui->setupUi(this);
    allowRefresh = false;

    Q_FOREACH(Hop *h, Database::hopsDB) {
        hopList << h->getName();
    }

    hopCompleter = new QCompleter(hopList, this);
    hopCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    hopCompleter->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->nameCombo->setCompleter(hopCompleter);

    // Populate the settings with the defaults
    ui->stockUnitsCombo->addItems(CONVERTER_weightUnitsAbrv);

    //QSettings settings = QSettings("Doug Edey", "StrangeBrew");
    QString hopU = newHop.getUnitsAbrv();
    ui->stockUnitsCombo->setCurrentIndex(ui->stockUnitsCombo->findText(hopU));


    allowRefresh = true;
}

NewHop::~NewHop()
{
    delete ui;
}

void NewHop::on_nameCombo_currentIndexChanged(const QString &arg1)
{
    qDebug() << "Current text changed" << arg1;
    if (!allowRefresh)
        return;

    allowRefresh = false;
    // check to see if the fermentable exists
    Hop *toDB = Database::findHop(arg1);
    if (toDB != NULL) {
        // Ingredient Exists
        QString hopU = toDB->getUnitsAbrv();
        ui->stockUnitsCombo->setCurrentIndex(ui->stockUnitsCombo->findText(hopU));
        ui->stockSpin->setValue(toDB->getStock());


        ui->alphaSpin->setValue(toDB->getAlpha());

        ui->descriptionText->document()->setPlainText(toDB->getDescription());
        ui->costSpin->setValue(toDB->getCostPerU());

    }
    allowRefresh = true;
}

void NewHop::on_buttonBox_accepted()
{
    bool addHop= false;
    // check to see if the fermentable exists
    Hop *toDB = Database::findHop(ui->nameCombo->currentText());
    if (toDB == NULL) {
        toDB = new Hop();
        toDB->setName(ui->nameCombo->currentText());
        addHop = true;
    }


    toDB->setStockUnits(ui->stockUnitsCombo->currentText());
    toDB->setStock(ui->stockSpin->value());

    toDB->setAlpha(ui->alphaSpin->value());

    toDB->setDescription(ui->descriptionText->document()->toPlainText());
    toDB->setCost(ui->costSpin->value());

    if (addHop) {
        Database::hopsDB.append(toDB);
    }
    if (Database::writeHop(*toDB)) {
        qDebug() << Database::lastError();

        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Couldn't add hop to Database.\n" + Database::lastError());
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();

    }

    qDebug() << "Appended " << toDB->getName();
}
