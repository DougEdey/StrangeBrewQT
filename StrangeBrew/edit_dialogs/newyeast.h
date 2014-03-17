#ifndef NEWYEAST_H
#define NEWYEAST_H

#include <QDialog>
#include <QCompleter>

#include "../database.h"

namespace Ui {
class NewYeast;
}

class NewYeast : public QDialog
{
    Q_OBJECT
    QCompleter *yeastCompleter;
    QStringList yeastList;
public:
    explicit NewYeast(QWidget *parent = 0);
    ~NewYeast();

private slots:
    void on_nameEditCombo_currentIndexChanged(const QString &yeastName);

    void on_buttonBox_accepted();

private:
    Ui::NewYeast *ui;
};

#endif // NEWYEAST_H
