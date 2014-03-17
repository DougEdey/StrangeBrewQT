#ifndef NEWMISC_H
#define NEWMISC_H

#include <QDialog>
#include <QCompleter>
#include "../database.h"

namespace Ui {
class NewMisc;
}

class NewMisc : public QDialog
{
    Q_OBJECT
    QCompleter *miscCompleter;
    QStringList miscList;

public:
    explicit NewMisc(QWidget *parent = 0);
    ~NewMisc();

private slots:
    void on_nameEditCombo_currentIndexChanged(const QString &miscName);

    void on_buttonBox_accepted();

private:
    Ui::NewMisc *ui;
};

#endif // NEWMISC_H
