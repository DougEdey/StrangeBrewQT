#ifndef CONVERSIONTOOL_H
#define CONVERSIONTOOL_H

#include <QDialog>

#include "brewcalcs.h"

namespace Ui {
class ConversionTool;
}

class ConversionTool : public QDialog
{
    Q_OBJECT

public:
    explicit ConversionTool(QWidget *parent = 0);
    ~ConversionTool();

    void displayWeights(double lbIn);
    void displayVolumes(double litreIn);
private slots:
    void on_celsiusSpin_editingFinished();

    void on_fahrenheitSpin_editingFinished();

    void on_psiSpin_editingFinished();

    void on_kpSpin_editingFinished();

    void on_barSpin_editingFinished();

    void on_atmoSpin_editingFinished();

    void on_tonneSpin_editingFinished();

    void on_tonSpin_editingFinished();

    void on_kiloSpin_editingFinished();

    void on_poundSpin_editingFinished();

    void on_ounceSpin_editingFinished();

    void on_gramSpin_editingFinished();

    void on_barrelImpSpin_editingFinished();

    void on_barrelUSSpin_editingFinished();

    void on_gallonImpSpin_editingFinished();

    void on_gallonUSSpin_editingFinished();

    void on_litersSpin_editingFinished();

    void on_quartSpin_editingFinished();

    void on_pintUSSpin_editingFinished();


    void on_gravSpin_editingFinished();

    void on_platoSpin_editingFinished();

    void on_brixSpin_editingFinished();

private:
    Ui::ConversionTool *ui;
};

#endif // CONVERSIONTOOL_H
