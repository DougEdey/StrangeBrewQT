#ifndef NEWFERMENTABLE_H
#define NEWFERMENTABLE_H

#include <QDialog>
#include <QSettings>
#include <QCompleter>

#include "../fermentable.h"
#include "../converter.h"
#include "../database.h"

namespace Ui {
class NewFermentable;
}

class NewFermentable : public QDialog
{
    Q_OBJECT

public:
    explicit NewFermentable(QWidget *parent = 0);
    ~NewFermentable();
    Fermentable newFerm;
    bool allowRefresh;
    QStringList maltList;
    QCompleter *maltCompleter;

private slots:

    void on_buttonBox_accepted();

    void on_nameEdit_currentIndexChanged(const QString &arg1);


    void on_nameEdit_currentTextChanged(const QString &arg1);

private:
    Ui::NewFermentable *ui;
};

#endif // NEWFERMENTABLE_H
