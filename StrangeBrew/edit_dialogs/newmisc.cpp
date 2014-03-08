#include "newmisc.h"
#include "ui_newmisc.h"

NewMisc::NewMisc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewMisc)
{
    ui->setupUi(this);


    ui->stockUnitsCombo->addItems(CONVERTER_weightUnitsAbrv);

    miscList = QStringList();

    Q_FOREACH(Misc m, Database::miscDB) {
        miscList << m.getName();
    }

    miscCompleter = new QCompleter(miscList, this);
    miscCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    miscCompleter->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->nameEditCombo->setCompleter(miscCompleter);

    Misc newMisc;
    QString miscU = newMisc.getUnitsAbrv();
    ui->stockUnitsCombo->setCurrentIndex(ui->stockUnitsCombo->findText(miscU));


}

NewMisc::~NewMisc()
{
    delete ui;
}

void NewMisc::on_nameEditCombo_currentIndexChanged(const QString &miscName)
{
    Misc *newMisc = Database::findMisc(miscName);
    ui->stockSpin->setValue(newMisc->getStock());

    ui->stockUnitsCombo->setCurrentIndex(
                ui->stockUnitsCombo->findText(
                    newMisc->getUnitsAbrv()));

    ui->costSpin->setValue(newMisc->getCostPerU());

    ui->commentsEdit->document()->setPlainText(newMisc->getDescription());
}

void NewMisc::on_buttonBox_accepted()
{
    // Save the ingredient
    Misc *newMisc = Database::findMisc(ui->nameEditCombo->currentText());

    if (newMisc == NULL) {
        newMisc = new Misc();
        newMisc->setName(ui->nameEditCombo->currentText());
        Database::miscDB.append(*newMisc);
    }

    newMisc->setCost(ui->costSpin->value());
    newMisc->setDescription(ui->commentsEdit->document()->toPlainText());
    newMisc->setStockUnits(ui->stockUnitsCombo->currentText());
    newMisc->setStock(ui->stockSpin->value());

    if (!Database::writeMisc(*newMisc)) {
        qDebug() << "Couldn't add new Misc ingredient: " << Database::lastError();
    }
}
