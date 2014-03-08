#include "extractdialog.h"
#include "ui_extractdialog.h"

ExtractDialog::ExtractDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExtractDialog)
{
    ui->setupUi(this);
}

ExtractDialog::~ExtractDialog()
{
    delete ui;
}

void ExtractDialog::on_extractSpin_editingFinished()
{
    calcValues();
}

void ExtractDialog::on_moistureSpin_editingFinished()
{
    calcValues();
}

void ExtractDialog::calcValues() {
    double dbgc =  ui->extractSpin->value() / 100;
    double mc = ui->moistureSpin->value() / 100;
    double plato = (dbgc - mc - 0.002) * 11.486;
    double ppppg =  1 + (((dbgc - mc - 0.002) * 46.214) / 1000);
    ui->ppppgValue->setText(QString::number(ppppg, 'f', 3));
    ui->platoValue->setText(QString::number(plato, 'f', 2));
}
