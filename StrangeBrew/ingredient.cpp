#include "ingredient.h"


Ingredient::Ingredient() {
    modified = true;
    description = "";
    modified = false;
    type = "";
    costPerU = 0.0;
    name = "";
}

Ingredient::Ingredient(QString name) {
    modified = true;
    description = "";
    modified = false;
    type = "";
    costPerU = 0.0;
    this->name = name;
}




double Ingredient::getAmountAs(QString s) const { return amount.getValueAs(s); }
double Ingredient::getAmount() const { return amount.getValue(); }
double Ingredient::getStockAs(QString s) const  { return stock.getValueAs(s); }
double Ingredient::getStock() const  { return stock.getValue(); }

// Get methods:
double Ingredient::getCostPerU() const { return costPerU; }
QDate Ingredient::getDate() const { return dateBought; }
QString Ingredient::getDescription() const { return description; }
bool Ingredient::getModified() const { return modified; }
QString Ingredient::getName() const { return name; }
QString Ingredient::getType() const { return type; }
QString Ingredient::getUnits() const { return amount.getUnits(); }

double Ingredient::getCostPerUAs(QString to) const{
    // current value / new value * cost
    return costPerU;
}

QString Ingredient::getUnitsAbrv() const { return amount.getAbrv(); }

void Ingredient::setAmount(double a){ amount.setAmount(a); }
void Ingredient::setStock(double a){
    if(a < 0.00)
        stock.setAmount(0);
    else
        stock.setAmount(a);
}

QString Ingredient::getStockUnits() { return stock.getUnits(); }
void Ingredient::setStockUnits(QString u) {
    stock.setUnits(u);
}

/**
 * Handles a string of the form "d u", where d is a double
 * amount, and u is a string of units.  For importing the
 * quantity attribute from QBrew xml.
 * @param a
 */

void Ingredient::setAmountAndUnits(QString a){

    QString d = a.section(" ", 0);
    QString u = a.section(" ", 1);
    double dAmount = 0.0;

    dAmount = QLocale::system().toDouble(d);

    amount.setAmount(dAmount);
    amount.setUnits(u.trimmed());
}

void Ingredient::setAmountAs(double a, QString u) {
    double converted = Quantity::convertUnit(u, amount.getUnits(), a);
    amount.setAmount(converted);
}

void Ingredient::setCost(double c){ costPerU = c; }
void Ingredient::setCost(QString c){
    if (c.startsWith("$")) {
        c = c.midRef(1).toString(); // trim leading "$"
    }
    costPerU = QLocale::system().toDouble(c);
}

void Ingredient::setDate(QString d){
    dateBought = QDate::fromString(d, "MM/dd/yyyy");
}

void Ingredient::setDescription(QString d){ description = d; }

// Setter methods:
void Ingredient::setModified(bool b){ modified = b; }
void Ingredient::setName(QString n){
    name = n;
}
void Ingredient::setType(QString t){ type = t; }
void Ingredient::setUnits(QString a){ amount.setUnits(a); }

void Ingredient::convertTo(QString newUnits){
    setCost(Quantity::convertUnit(newUnits, getUnits(), getCostPerU()));

    amount.convertTo(newUnits);
}


// Comparators for Sort
bool Ingredient::lessThan(Ingredient a, Ingredient b) {
    return a < b;
}

bool Ingredient::moreThan(Ingredient a, Ingredient b) {
    return a > b;
}



bool Ingredient::sortWeight(Ingredient a, Ingredient b) {
    return a.getAmount() > b.getAmount();
}
