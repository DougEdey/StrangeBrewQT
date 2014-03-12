#include "tool_dialogs/resizerecipe.h"
#include "ui_resizerecipe.h"

ResizeRecipe::ResizeRecipe(QWidget *parent, Recipe *currentRecipe) :
    QDialog(parent),
    ui(new Ui::ResizeRecipe)
{
    recipe = currentRecipe;
    if (currentRecipe == NULL) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Invalid Recipe Pointer! This shouldn't happen!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();

        QMetaObject::invokeMethod(this, "close", Qt::QueuedConnection);
        return;
    }

    ui->setupUi(this);

    postBoil = new Quantity();
    qDebug() << "Recipe Units: " << recipe->getVolUnitsAbrv();
    qDebug() << "Recipe Volume: " << recipe->getPostBoilVol().getValue();

    ui->volUnitsCombo->addItems(CONVERTER_volUnitsAbrv);
    ui->maltUnitCombo->addItems(CONVERTER_weightUnitsAbrv);
    ui->hopUnitCombo->addItems(CONVERTER_weightUnitsAbrv);

    postBoil->setUnits(recipe->getVolUnitsAbrv());
    postBoil->setAmount(recipe->getPostBoilVol().getValue());

    ui->volSizeSpin->setValue(postBoil->getValue());
    ui->volUnitsCombo->setCurrentText(postBoil->getAbrv());
    ui->maltUnitCombo->setCurrentText(Quantity::getAbrvFromUnit("weight", recipe->getMaltUnits()));
    ui->hopUnitCombo->setCurrentText(Quantity::getAbrvFromUnit("weight", recipe->getHopUnits()));
}

ResizeRecipe::~ResizeRecipe()
{
    delete ui;
}


void ResizeRecipe::on_volUnitsCombo_currentIndexChanged(const QString &newUnits)
{
    // First update the current quantity amount, then convert
    postBoil->setAmount(ui->volSizeSpin->value());
    postBoil->convertTo(newUnits);
    ui->volSizeSpin->setValue(postBoil->getValue());
}

void ResizeRecipe::on_buttonBox_accepted()
{
    postBoil->setAmount(ui->volSizeSpin->value());
    recipe->scaleRecipe(*postBoil);

    QString newUnit;
    if (ui->maltCheck->isChecked()) {
        newUnit = ui->maltUnitCombo->currentText();
        QList<Fermentable*> *maltList = recipe->getMaltList();
        for (int i = 0; i < maltList->size(); i++ ) {
            Fermentable *f = maltList->at(i);
            f->convertTo(newUnit);
            maltList->replace(i, f);
        }
    }

    if (ui->hopCheck->isChecked()) {
        newUnit = ui->hopUnitCombo->currentText();
        QList<Hop*> *hopList = recipe->getHopList();
        for (int i = 0; i < hopList->size(); i++ ) {
            Hop *h = hopList->at(i);
            h->convertTo(newUnit);
            hopList->replace(i, h);
        }
    }
}
