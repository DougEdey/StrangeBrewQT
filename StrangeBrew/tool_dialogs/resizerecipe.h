#ifndef RESIZERECIPE_H
#define RESIZERECIPE_H

#include <QDialog>
#include "../recipe.h"


namespace Ui {
class ResizeRecipe;
}

class ResizeRecipe : public QDialog
{
    Q_OBJECT
    Recipe *recipe;
    Quantity *postBoil;
public:
    explicit ResizeRecipe(QWidget *parent = 0, Recipe *currentRecipe=NULL);
    ~ResizeRecipe();

private slots:
    void on_volUnitsCombo_currentIndexChanged(const QString &newUnits);

    void on_buttonBox_accepted();

private:
    Ui::ResizeRecipe *ui;
};

#endif // RESIZERECIPE_H
