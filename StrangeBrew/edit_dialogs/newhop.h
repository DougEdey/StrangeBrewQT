#ifndef NEWHOP_H
#define NEWHOP_H

#include <QDialog>
#include <QCompleter>

#include "database.h"
#include "quantity.h"

namespace Ui {
class NewHop;
}

class NewHop : public QDialog
{
    Q_OBJECT

public:
    explicit NewHop(QWidget *parent = 0);
    ~NewHop();
    QStringList hopList;
    QCompleter *hopCompleter;
    Hop newHop;
    bool allowRefresh;

private slots:
    void on_nameCombo_currentIndexChanged(const QString &arg1);

    void on_buttonBox_accepted();

private:
    Ui::NewHop *ui;
};

#endif // NEWHOP_H
