#include "newingrdialog.h"
#include "ui_newingrdialog.h"
#include "newingrtable.h"
#include "newingrdelegate.h"


NewIngrDialog::NewIngrDialog(QList<Ingredient *> *newData, std::vector<bool> *boolList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewIngrDialog)
{
    dataList = newData;
    ui->setupUi(this);
    bList = boolList;//.resize(newData.size(), true);
    NewIngrTable *nTable = new NewIngrTable(ui->ingredientsView);

    qDebug() << "Setting model";
    ui->ingredientsView->setModel(nTable);
    qDebug() << "Model Set " << &bList;
    nTable->dataList(newData, bList);

    NewIngrDelegate *nDelegate = new NewIngrDelegate(ui->ingredientsView);
    ui->ingredientsView->setItemDelegate(nDelegate);

    ui->ingredientsView->setEditTriggers(QAbstractItemView::SelectedClicked);

    nDelegate->deleteLater();
    nTable->deleteLater();
}

NewIngrDialog::~NewIngrDialog()
{
    delete ui;
}

void NewIngrDialog::on_miscIngrButtons_accepted()
{
    bool newFerm = false, newHop = false, newYeast = false, newMisc = false;

    // iterate the boolean list
    qDebug() << bList->size();
    for (size_t i = 0; i < bList->size(); i++) {
        if (bList->at(i)) {
            Ingredient *ingr = dataList->at(i);
            //try {
            Hop *h = dynamic_cast<Hop*>(ingr);
            if(h != NULL) {
                // Save the hop
                Database::hopsDB.append(h);
                newHop = true;
                continue;
            //} catch (std::bad_cast) {
            //    qDebug() << "Couldn't cast to hop";
            }

            //try {
            Fermentable *f = dynamic_cast<Fermentable*>(dataList->at(i));
            if (f != NULL) {
                    // Save the Fermentable
                Database::fermDB.append(f);
                newFerm = true;
                continue;
            //} catch (std::bad_cast) {
            //    qDebug() << "Couldn't cast to ferm";
            }

//                const Yeast &y = static_cast<const Yeast&>(ingr);
            Yeast *y = dynamic_cast<Yeast*>(dataList->at(i));
            if (y != NULL ){
                // Save the yeast
                Database::yeastDB.append(y);
                newYeast = true;
                continue;
            }

                //const Misc &m = static_cast<const Misc&>(ingr);
            Misc *m = dynamic_cast<Misc*>(dataList->at(i));
            if (m != NULL) {
                // Save the misc
                Database::miscDB.append(m);
                newMisc = true;
                continue;
            }
        } else {
            qDebug() << "Ignoring " << dataList->at(i)->getName();
        }
    }

    if (newHop) {
        qDebug() << "Writing hops";
        Database::writeHops(); }
    if (newMisc) { qDebug() << "Writing Misc"; Database::writeMisc(); }
    if (newFerm) { qDebug() << "Writing Ferm"; Database::writeFermentables(); }
    if (newYeast) { qDebug() << "Writing Yeast"; Database::writeYeast(); }
}
