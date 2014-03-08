#include "maltpercentdialog.h"
#include "ui_maltpercentdialog.h"

MaltPercentDialog::MaltPercentDialog(QWidget *parent, Recipe *currentRecipe) :
    QDialog(parent),
    ui(new Ui::MaltPercentDialog)
{
    ui->setupUi(this);
    r = currentRecipe;

    mModel = new MaltModel(this, "percent");
    mModel->dataList(r->getMaltList());

    ui->maltTable->setModel(mModel);

    ui->weightSpin->setValue(r->getTotalMalt());
    ui->ogSpin->setValue(r->getEstOg());

    ui->weightUnitsCombo->addItems(CONVERTER_weightUnitsAbrv);
    ui->weightUnitsCombo->setCurrentText(
                Quantity::getAbrvFromUnit("weight", r->getMaltUnits()));
}

MaltPercentDialog::~MaltPercentDialog()
{
    delete ui;
}

double MaltPercentDialog::calcOG(double weightLbs){
    double OG=0;
    for (int i = 0; i < r->getMaltListSize(); i++) {
        double points = (r->getMaltPercent(i) / 100)
            * weightLbs
            * (r->getMaltPppg(i) - 1.0)
            / r->getPostBoilVol(CONVERTER_GAL);
        if (r->getMaltMashed(i))
            points *= r->getEfficiency() / 100;
        OG += points;
    }
    return OG;
}

void MaltPercentDialog::on_buttonBox_accepted()
{
    if (ui->ogCheck->isChecked()) {
        double targOG = ui->ogSpin->value();
        // "seed" value -- assume conservative 30 ppppg
        double totalPoints = (targOG - 1) * 1000 * r->getPostBoilVol(CONVERTER_GAL);
        double totalWeightLbs = (totalPoints / 30) * (r->getEfficiency() / 100);

        // brute force - just keep incrementing the total grain bill
        // by .1 lb until it's close to what we want (95%)
        // I need to work out a better way to do this
        // I think that working out the PPPG per lb based on % would work better
        // TODO: FIX THIS!
        while (calcOG(totalWeightLbs) < ((targOG -1))*0.95) {
            totalWeightLbs += 0.1;
        }

        while (calcOG(totalWeightLbs) < (targOG -1)) {
            totalWeightLbs += 0.01;
        }

        for (int k = 0; k < r->getMaltListSize(); k++) {
            double newAmount = totalWeightLbs * (r->getMaltPercent(k)/ 100);
            r->setMaltAmountAs(k, newAmount, CONVERTER_LB);
        }

    }

    if (ui->weightCheck->isChecked()) {
        double totalWeight = ui->weightSpin->value();
        // convert to lbs
        totalWeight = Quantity::convertUnit(ui->weightUnitsCombo->currentText(), CONVERTER_LB, totalWeight);
        for (int i = 0; i < r->getMaltListSize(); i++) {
            double newAmount = totalWeight * r->getMaltPercent(i) / 100;
            r->setMaltAmountAs(i, newAmount, CONVERTER_LB);
        }
    }

    r->calcMaltTotals();

}
