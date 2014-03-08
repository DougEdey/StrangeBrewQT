#include "newfermentable.h"
#include "ui_newfermentable.h"

NewFermentable::NewFermentable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewFermentable)
{
    ui->setupUi(this);
    allowRefresh = false;

    Q_FOREACH(Fermentable m, Database::fermDB) {
        maltList << m.getName();
    }

    maltCompleter = new QCompleter(maltList, this);
    maltCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    maltCompleter->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->nameEdit->setCompleter(maltCompleter);

    // Populate the settings with the defaults
    ui->stockUnits->addItems(CONVERTER_weightUnitsAbrv);

    //QSettings settings = QSettings("Doug Edey", "StrangeBrew");
    QString maltU = newFerm.getUnitsAbrv();
    ui->stockUnits->setCurrentIndex(ui->stockUnits->findText(maltU));

    ui->mashedCheck->setChecked(newFerm.getMashed());
    ui->steepedCheck->setChecked(newFerm.getSteep());
    ui->fermentsCheck->setChecked(newFerm.ferments());
    allowRefresh = true;
}

NewFermentable::~NewFermentable()
{
    delete ui;
}



void NewFermentable::on_buttonBox_accepted()
{

    // check to see if the fermentable exists
    Fermentable *toDB = Database::findFermentable(ui->nameEdit->currentText());
    if (toDB == NULL) {
        toDB = new Fermentable();
        toDB->setName(ui->nameEdit->currentText());
        Database::fermDB.append(*toDB);

    }


    toDB->setStockUnits(ui->stockUnits->currentText());
    toDB->setStock(ui->stockSpin->value());

    toDB->setLov(ui->lovSpin->value());
    toDB->setPppg(ui->yieldSpin->value());
    toDB->setDescription(ui->descriptionText->document()->toPlainText());
    toDB->setCost(ui->costSpin->value());

    toDB->setMashed(ui->mashedCheck->isChecked());
    toDB->setSteep(ui->steepedCheck->isChecked());
    toDB->ferments(ui->fermentsCheck->isChecked());

    if (!Database::writeFermentable(*toDB)) {
        // Failed to Write, we should've received an error message, so we can clear it using qDebug() for now.
        qDebug() << "Failed to add fermentable: " << Database::lastError();
    }
    qDebug() << "Appended " << toDB->getName();
}


void NewFermentable::on_nameEdit_currentIndexChanged(const QString &arg1)
{
    qDebug() << "Current text changed" << arg1;
    if (!allowRefresh)
        return;

    allowRefresh = false;
    // check to see if the fermentable exists
    Fermentable *toDB = Database::findFermentable(arg1);
    if (toDB != NULL) {
        // Ingredient Exists
        QString maltU = toDB->getUnitsAbrv();
        ui->stockUnits->setCurrentIndex(ui->stockUnits->findText(maltU));
        ui->stockSpin->setValue(toDB->getStock());

        ui->mashedCheck->setChecked(toDB->getMashed());
        ui->steepedCheck->setChecked(toDB->getSteep());
        ui->fermentsCheck->setChecked(toDB->ferments());

        ui->lovSpin->setValue(toDB->getLov());
        ui->yieldSpin->setValue(toDB->getPppg());
        ui->descriptionText->document()->setPlainText(toDB->getDescription());
        ui->costSpin->setValue(toDB->getCostPerU());
    }

    allowRefresh = true;
}

void NewFermentable::on_nameEdit_currentTextChanged(const QString &arg1)
{
    qDebug() << "Current text changed" << arg1;
}
