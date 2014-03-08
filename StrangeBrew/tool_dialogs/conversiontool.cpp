#include "conversiontool.h"
#include "ui_conversiontool.h"

ConversionTool::ConversionTool(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConversionTool)
{
    ui->setupUi(this);
}

ConversionTool::~ConversionTool()
{
    delete ui;
}

/*********************
 * Temperature Panel *
 ********************/

void ConversionTool::on_celsiusSpin_editingFinished()
{
    ui->fahrenheitSpin->setValue(BrewCalcs::cToF(ui->celsiusSpin->value()));
}

void ConversionTool::on_fahrenheitSpin_editingFinished()
{
    ui->celsiusSpin->setValue(BrewCalcs::fToC(ui->fahrenheitSpin->value()));
}

/******************
 * Pressure Panel *
 *****************/

void ConversionTool::on_psiSpin_editingFinished()
{
    double psi = ui->psiSpin->value();
    ui->kpSpin->setValue(Quantity::convertUnit("psi", "KPa", psi));
    ui->barSpin->setValue(Quantity::convertUnit("psi", "bar", psi));
    ui->atmoSpin->setValue(Quantity::convertUnit("psi", "atm", psi));
}

void ConversionTool::on_kpSpin_editingFinished()
{
    double kpa = ui->kpSpin->value();
    ui->psiSpin->setValue(Quantity::convertUnit("KPa", "psi", kpa));
    ui->barSpin->setValue(Quantity::convertUnit("KPa", "bar", kpa));
    ui->atmoSpin->setValue(Quantity::convertUnit("KPa", "atm", kpa));
}

void ConversionTool::on_barSpin_editingFinished()
{
    double bar = ui->barSpin->value();
    ui->psiSpin->setValue(Quantity::convertUnit("bar", "psi", bar));
    ui->kpSpin->setValue(Quantity::convertUnit("bar", "KPa", bar));
    ui->atmoSpin->setValue(Quantity::convertUnit("bar", "atm", bar));
}

void ConversionTool::on_atmoSpin_editingFinished()
{
    double atm = ui->atmoSpin->value();
    ui->psiSpin->setValue(Quantity::convertUnit("atm", "psi", atm));
    ui->kpSpin->setValue(Quantity::convertUnit("atm", "KPa", atm));
    ui->barSpin->setValue(Quantity::convertUnit("atm", "bar", atm));
}

/****************
 * Weight Panel *
 ***************/

void ConversionTool::on_tonneSpin_editingFinished()
{
    double tonne = ui->tonneSpin->value();
    displayWeights(Quantity::convertUnit("T SI", CONVERTER_LB, tonne));

}

void ConversionTool::on_tonSpin_editingFinished()
{
    double ton = ui->tonSpin->value();
    displayWeights(Quantity::convertUnit("T", CONVERTER_LB, ton));

}

void ConversionTool::on_kiloSpin_editingFinished()
{
    double kilo = ui->kiloSpin->value();
    displayWeights(Quantity::convertUnit(CONVERTER_KG, CONVERTER_LB, kilo));
}

void ConversionTool::on_poundSpin_editingFinished()
{
    double pound = ui->poundSpin->value();
    displayWeights(pound);

}

void ConversionTool::on_ounceSpin_editingFinished()
{
    double ounce = ui->ounceSpin->value();
    displayWeights(Quantity::convertUnit(CONVERTER_OZ, CONVERTER_LB, ounce));
}

void ConversionTool::on_gramSpin_editingFinished()
{
    double gram = ui->gramSpin->value();
    displayWeights(Quantity::convertUnit(CONVERTER_G, CONVERTER_LB, gram));
}

void ConversionTool::displayWeights(double lbIn) {
    ui->tonneSpin->setValue(Quantity::convertUnit(CONVERTER_LB, "T SI", lbIn));
    ui->tonSpin->setValue(Quantity::convertUnit(CONVERTER_LB, "T", lbIn));
    ui->kiloSpin->setValue(Quantity::convertUnit(CONVERTER_LB, CONVERTER_KG, lbIn));
    ui->poundSpin->setValue(Quantity::convertUnit(CONVERTER_LB, CONVERTER_LB, lbIn));
    ui->ounceSpin->setValue(Quantity::convertUnit(CONVERTER_LB, CONVERTER_OZ, lbIn));
    ui->gramSpin->setValue(Quantity::convertUnit(CONVERTER_LB, CONVERTER_G, lbIn));
}

void ConversionTool::on_barrelImpSpin_editingFinished()
{
    double b = ui->barrelImpSpin->value();
    displayVolumes(Quantity::convertUnit(CONVERTER_BBL_IMP, CONVERTER_L, b));
}

void ConversionTool::on_barrelUSSpin_editingFinished()
{
    double b = ui->barrelUSSpin->value();
    displayVolumes(Quantity::convertUnit(CONVERTER_BBL_US, CONVERTER_L, b));
}

void ConversionTool::on_gallonImpSpin_editingFinished()
{
    double b = ui->gallonImpSpin->value();
    displayVolumes(Quantity::convertUnit(CONVERTER_GAL_IMP, CONVERTER_L, b));
}

void ConversionTool::on_gallonUSSpin_editingFinished()
{
    double b = ui->gallonUSSpin->value();
    displayVolumes(Quantity::convertUnit(CONVERTER_GAL, CONVERTER_L, b));
}

void ConversionTool::on_litersSpin_editingFinished()
{
    double b = ui->litersSpin->value();
    displayVolumes(b);
}

void ConversionTool::on_quartSpin_editingFinished()
{
    double b = ui->quartSpin->value();
    displayVolumes(Quantity::convertUnit(CONVERTER_QT, CONVERTER_L, b));
}

void ConversionTool::on_pintUSSpin_editingFinished()
{
    double b = ui->pintUSSpin->value();
    displayVolumes(Quantity::convertUnit(CONVERTER_PT_US, CONVERTER_L, b));

}

void ConversionTool::displayVolumes(double litreIn) {
    ui->barrelImpSpin->setValue(Quantity::convertUnit(CONVERTER_L, CONVERTER_BBL_IMP, litreIn));
    ui->barrelUSSpin->setValue(Quantity::convertUnit(CONVERTER_L, CONVERTER_BBL_US, litreIn));
    ui->gallonImpSpin->setValue(Quantity::convertUnit(CONVERTER_L, CONVERTER_GAL_IMP, litreIn));
    ui->gallonUSSpin->setValue(Quantity::convertUnit(CONVERTER_L, CONVERTER_GAL, litreIn));
    ui->litersSpin->setValue(Quantity::convertUnit(CONVERTER_L, CONVERTER_L, litreIn));
    ui->quartSpin->setValue(Quantity::convertUnit(CONVERTER_L, CONVERTER_QT, litreIn));
    ui->pintUSSpin->setValue(Quantity::convertUnit(CONVERTER_L, CONVERTER_PT_US, litreIn));

}

/*****************
 * Gravity Panel *
 ****************/

void ConversionTool::on_gravSpin_editingFinished()
{
    double grav = ui->gravSpin->value();
    ui->platoSpin->setValue(BrewCalcs::SGToPlato(grav));
    ui->brixSpin->setValue(BrewCalcs::brixToSG(grav));
}

void ConversionTool::on_platoSpin_editingFinished()
{
    double plato = ui->platoSpin->value();
    double sg = BrewCalcs::platoToSG(plato);
    ui->gravSpin->setValue(sg);
    ui->brixSpin->setValue(BrewCalcs::sgToBrix(sg));
}

void ConversionTool::on_brixSpin_editingFinished()
{
    double brix = ui->brixSpin->value();
    double sg = BrewCalcs::brixToSG(brix);
    ui->gravSpin->setValue(sg);
    ui->platoSpin->setValue(BrewCalcs::SGToPlato(sg));
}
