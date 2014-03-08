#include "newprimesugar.h"
#include "ui_newprimesugar.h"

NewPrimeSugar::NewPrimeSugar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewPrimeSugar)
{
    ui->setupUi(this);

    ui->costUnitsCombo->addItems(CONVERTER_weightUnitsAbrv);
    primeCompleter = new QCompleter(Database::getPrimeSugarNameList(), this);
}

NewPrimeSugar::~NewPrimeSugar()
{
    delete ui;
}

void NewPrimeSugar::on_buttonBox_accepted()
{
    PrimeSugar *newPrime = Database::findSugar(ui->nameEditCombo->currentText());
    if (newPrime == NULL) {
        newPrime = new PrimeSugar();
        newPrime->setName(ui->nameEditCombo->currentText());
        Database::primeSugarDB.append(*newPrime);
    }

    newPrime->setYield(ui->yieldSpin->value());
    newPrime->setUnits(ui->costUnitsCombo->currentText());
    newPrime->setCost(ui->costSpin->value());
    newPrime->setDescription(ui->descrEdit->document()->toPlainText());

    Database::writePrimeSugar(*newPrime);
}



void NewPrimeSugar::on_nameEditCombo_currentIndexChanged(const QString &primeName)
{
    PrimeSugar *newPrime = Database::findSugar(primeName);

    if (newPrime == NULL) {
        return;
    }

    ui->descrEdit->document()->setPlainText(newPrime->getDescription());
    ui->costUnitsCombo->setCurrentText(newPrime->getUnitsAbrv());
    ui->costSpin->setValue(newPrime->getCostPerU());
}
