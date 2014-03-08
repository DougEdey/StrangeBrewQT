#include "hydrodialog.h"
#include "ui_hydrodialog.h"

HydroDialog::HydroDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HydroDialog)
{
    ui->setupUi(this);
    QSettings settings("Doug Edey", "StrangeBrew");
    if (settings.value("Mash/TempU").toString() == "F") {
        ui->mTempUnit->setText("F");
        ui->cTempUnit->setText("F");
    }
}

HydroDialog::~HydroDialog()
{
    delete ui;
}

void HydroDialog::on_gravSpin_editingFinished()
{
    updateValues();
}

void HydroDialog::on_tempSpin_editingFinished()
{
    updateValues();
}

void HydroDialog::on_cTempSpin_editingFinished()
{
    updateValues();
}

void HydroDialog::updateValues() {
    double cSG;

    // Just ignore bad input
    double mSG = ui->gravSpin->value();
    double mT = ui->tempSpin->value();
    double calT = ui->cTempSpin->value();


    QSettings settings("Doug Edey", "StrangeBrew");
    // We do the calculation in C, but allow the user to specify F
    if (settings.value("Mash/TempU").toString() == "F") {
        mT = BrewCalcs::fToC(mT);
        calT = BrewCalcs::fToC(calT);
    }

    cSG = BrewCalcs::hydrometerCorrection(mT, mSG, calT);

    ui->cGravValue->setText(QString::number(cSG, 'f', 3));
}

