#ifndef NEWPRIMESUGAR_H
#define NEWPRIMESUGAR_H

#include <QDialog>
#include <QCompleter>

#include "../database.h"

namespace Ui {
class NewPrimeSugar;
}

class NewPrimeSugar : public QDialog
{
    Q_OBJECT
    QCompleter *primeCompleter;
    QStringList primeList;

public:
    explicit NewPrimeSugar(QWidget *parent = 0);
    ~NewPrimeSugar();

private slots:
    void on_buttonBox_accepted();

    void on_nameEditCombo_currentIndexChanged(const QString &primeName);

private:
    Ui::NewPrimeSugar *ui;
};

#endif // NEWPRIMESUGAR_H
