#include "refracttool.h"
#include "ui_refracttool.h"

RefractTool::RefractTool(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RefractTool)
{
    ui->setupUi(this);
}

RefractTool::~RefractTool()
{
    delete ui;
}

void RefractTool::on_brixSpin_editingFinished()
{
    // Update the FG value
    double brix = ui->brixSpin->value();
    double fg = BrewCalcs::brixToSG(brix);
    ui->fgValue->setText(QString::number(fg, 'f', 2));
}

void RefractTool::on_originalSpin_editingFinished()
{
    updateBrixBox();
}

void RefractTool::on_finalSpin_editingFinished()
{
    updateBrixBox();
}

void RefractTool::on_finalBrixSpin_editingFinished()
{
    updateFinalABV();
}

void RefractTool::on_fgABVSpin_editingFinished()
{
    updateFinalABV();
}

void RefractTool::updateBrixBox() {
    double oBrix = ui->originalSpin->value();
    double fBrix = ui->finalSpin->value();
    double fg = BrewCalcs::brixToFG(oBrix, fBrix);
    double abv = BrewCalcs::OBFBtoABV(oBrix, fBrix);

    ui->fgBrixValue->setText(QString::number(fg, 'f', 2));
    ui->abvBrixLabel->setText(QString::number(abv, 'f', 2));
}

void RefractTool::updateFinalABV() {
    double fBrix = ui->finalBrixSpin->value();
    double fGrav = ui->fgABVSpin->value();

    double abv = BrewCalcs::SGBrixToABV(fGrav, fBrix);

    ui->abvFinalValue->setText(QString::number(abv, 'f', 2));
}
