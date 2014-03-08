#ifndef EXTRACTDIALOG_H
#define EXTRACTDIALOG_H

#include <QDialog>

namespace Ui {
class ExtractDialog;
}

class ExtractDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExtractDialog(QWidget *parent = 0);
    ~ExtractDialog();

    void calcValues();
private slots:
    void on_extractSpin_editingFinished();

    void on_moistureSpin_editingFinished();

private:
    Ui::ExtractDialog *ui;
};

#endif // EXTRACTDIALOG_H
