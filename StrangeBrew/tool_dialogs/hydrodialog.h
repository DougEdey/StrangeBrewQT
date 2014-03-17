#ifndef HYDRODIALOG_H
#define HYDRODIALOG_H

#include <QDialog>
#include <QSettings>

#include "../brewcalcs.h"
namespace Ui {
class HydroDialog;
}

class HydroDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HydroDialog(QWidget *parent = 0);
    ~HydroDialog();

    void updateValues();
private slots:
    void on_gravSpin_editingFinished();

    void on_tempSpin_editingFinished();

    void on_cTempSpin_editingFinished();

private:
    Ui::HydroDialog *ui;
};

#endif // HYDRODIALOG_H
