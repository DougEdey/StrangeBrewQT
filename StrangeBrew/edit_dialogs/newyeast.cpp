#include "newyeast.h"
#include "ui_newyeast.h"

NewYeast::NewYeast(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewYeast)
{
    ui->setupUi(this);

    yeastList = QStringList();

    Q_FOREACH(Yeast y, Database::yeastDB) {
        yeastList << y.getName();
    }

    yeastCompleter = new QCompleter(yeastList, this);
    yeastCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    yeastCompleter->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    ui->nameEditCombo->setCompleter(yeastCompleter);


}

NewYeast::~NewYeast()
{
    delete ui;
}

void NewYeast::on_nameEditCombo_currentIndexChanged(const QString &yeastName)
{
    Yeast *newYeast = Database::findYeast(yeastName);

    ui->costSpin->setValue(newYeast->getCostPerU());
    ui->descrEdit->document()->setPlainText(newYeast->getDescription());
}

void NewYeast::on_buttonBox_accepted()
{
    Yeast *newYeast = Database::findYeast(ui->nameEditCombo->currentText());

    if (newYeast == NULL) {
        newYeast = new Yeast();
        newYeast->setName(ui->nameEditCombo->currentText());
        Database::yeastDB.append(*newYeast);
    }

    newYeast->setCost(ui->costSpin->value());
    newYeast->setDescription(ui->descrEdit->document()->toPlainText());

    if (!Database::writeYeast(*newYeast)) {
        qDebug() << Database::lastError();
    }
}
