#ifndef MALTPERCENTDIALOG_H
#define MALTPERCENTDIALOG_H

#include <QDialog>
#include "../recipe.h"
#include "../maltmodel.h"

namespace Ui {
class MaltPercentDialog;
}

class MaltPercentDialog : public QDialog
{
    Q_OBJECT
    Recipe *r;
    MaltModel *mModel;

public:
    explicit MaltPercentDialog(QWidget *parent = 0, Recipe *currentRecipe = 0);
    ~MaltPercentDialog();

    double calcOG(double weightLbs);
private slots:

    void on_buttonBox_accepted();

private:
    Ui::MaltPercentDialog *ui;
};

#endif // MALTPERCENTDIALOG_H
