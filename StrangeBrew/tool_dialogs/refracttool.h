#ifndef REFRACTTOOL_H
#define REFRACTTOOL_H

#include <QDialog>
#include "../brewcalcs.h"

namespace Ui {
class RefractTool;
}

class RefractTool : public QDialog
{
    Q_OBJECT

public:
    explicit RefractTool(QWidget *parent = 0);
    ~RefractTool();

    void updateBrixBox();
    void updateFinalABV();
private slots:
    void on_brixSpin_editingFinished();

    void on_originalSpin_editingFinished();

    void on_finalSpin_editingFinished();

    void on_finalBrixSpin_editingFinished();

    void on_fgABVSpin_editingFinished();

private:
    Ui::RefractTool *ui;
};

#endif // REFRACTTOOL_H
