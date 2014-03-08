#ifndef NEWINGRDIALOG_H
#define NEWINGRDIALOG_H

#include <QDialog>
#include "typeinfo"
#include "ingredient.h"
#include "database.h"

namespace Ui {
class NewIngrDialog;
}

class NewIngrDialog : public QDialog
{
    Q_OBJECT
    std::vector<bool> *bList;
    QList<Ingredient*> *dataList;
public:
    explicit NewIngrDialog(QList<Ingredient*> *newData, std::vector<bool> *boolList, QWidget *parent = 0 );
    ~NewIngrDialog();

private slots:
    void on_miscIngrButtons_accepted();

private:
    Ui::NewIngrDialog *ui;
};

#endif // NEWINGRDIALOG_H
