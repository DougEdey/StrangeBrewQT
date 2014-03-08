#include "quantity.h"

Quantity::Quantity()
{
    unit = "";
    type = "";
    abrv = "";
}

QList<Converter> QUANTITY_volUnits = Quantity::initVolUnits();
QList<Converter> QUANTITY_weightUnits = Quantity::initWeightUnits();
QList<Converter> QUANTITY_pressureUnits = Quantity::initPressureUnits();
QString QUANTITY_WEIGHT = "weight";
QString QUANTITY_VOL = "volume";
QString QUANTITY_PRESSURE = "pressure";

QList<Converter> Quantity::initVolUnits() {
    QList<Converter> newVol;
    newVol.push_back(Converter(CONVERTER_BARREL_IMP, CONVERTER_BBL_IMP, 0.023129837));
    newVol.push_back(Converter(CONVERTER_BARREL_US, CONVERTER_BBL_US, 0.032258065));
    newVol.push_back(Converter(CONVERTER_FL_OUNCES, CONVERTER_FL_OZ, 128));
    newVol.push_back(Converter(CONVERTER_FL_OUNCES, CONVERTER_OZ, 128));
    newVol.push_back(Converter(CONVERTER_GALLONS_IMP, CONVERTER_GAL_IMP, 0.8327));
    newVol.push_back(Converter(CONVERTER_GALLONS_US, CONVERTER_GAL, 1));
    newVol.push_back(Converter(CONVERTER_LITRES, CONVERTER_L, 3.7854));
    newVol.push_back(Converter(CONVERTER_MILLILITERS, CONVERTER_ML, 3785.4118));
    newVol.push_back(Converter(CONVERTER_PINT_US, CONVERTER_PT_US, 8));
    newVol.push_back(Converter(CONVERTER_QUART_US, CONVERTER_QT, 4));
    return newVol;
}


QList<Converter> Quantity::initWeightUnits() {
    QList<Converter> newWeight;
    newWeight.push_back(Converter(CONVERTER_MILLIGRAMS, CONVERTER_MG, 4535.9237));
    newWeight.push_back(Converter(CONVERTER_GRAMS, CONVERTER_G, 453.59237));
    newWeight.push_back(Converter(CONVERTER_KILOGRAM, CONVERTER_KG, 0.45359237));
    newWeight.push_back(Converter(CONVERTER_OUNCES, CONVERTER_OZ, 16));
    newWeight.push_back(Converter(CONVERTER_POUNDS, CONVERTER_LB, 1));
    newWeight.push_back(Converter("ton S", "T", 0.0005));
    newWeight.push_back(Converter("tonne SI", "T SI", 0.000453592));
    return newWeight;
}

QList<Converter> Quantity::initPressureUnits() {
    QList<Converter> newPressure;
    newPressure.push_back(Converter("pounds per square inch", "psi", 1));
    newPressure.push_back(Converter("kilopascals", "KPa", 6.8947624));
    newPressure.push_back(Converter("bar", "bar", 0.068947635));
    newPressure.push_back(Converter("atmospheres", "atm", 0.0680460253));
    return newPressure;
}

Quantity::Quantity(QString u, double am){
    setUnits(u);
    setAmount(am);
}

/*Quantity::Quantity(Quantity q) {
    this.type = q.type;
    this.unit = q.getUnits();
    this.abrv = q.getAbrv();
    this.value = q.getValue();
}*/

// This sets a quantity's unit, abrv, and type:
void Quantity::setUnits(QString s){
    if (s.compare("") == 0) {
        return;
    }

    QString t = getTypeFromUnit(s);
    type = t;

    if (isAbrv(s)){
        QString u = getUnitFromAbrv(t, s);
        unit = u;
        abrv = s;
    }
    // it's a unit
    else {
        QString a;
        try {
            a = getAbrvFromUnit(t, s);
        } catch (...) {
            // Couldn't find an abbreviation for this unit, something like "stick"
            a = s;
        }

        unit = s;
        abrv = a;
    }
}

// set the amount only:
void Quantity::setAmount(double am){
    if (am < 0) {
        return;
    }
    value = am;
}

double Quantity::getValue() const { return value;	}
QString Quantity::getUnits() const { return unit; }
QString Quantity::getAbrv() const { return abrv; }

double Quantity::getValueAs(QString to) const {
    double fromBase = 0;
    double toBase = 0;
    QList<Converter> u;

    // don't do any work if we're converting to ourselves
    if (to == unit || type == abrv)
        return value;

    if (type == "volume")
        u = QUANTITY_volUnits;
    else if (type == "pressure")
        u = QUANTITY_pressureUnits;
    else // assume weight
        u = QUANTITY_weightUnits;

    fromBase = getBaseValue(u, unit);
    toBase = getBaseValue(u, to);

    return value * (toBase / fromBase);
}


void Quantity::add(double v, QString u){
    // convert v from u to current units
    // then add it
    Quantity q =  Quantity(u,v);
    double v2 = q.getValueAs(getUnits());
    value += v2;
}

void Quantity::convertTo(QString to){
    if(to != unit) {
        value = Quantity::convertUnit(unit, to, value);
        setUnits(to);
    }
}

//	 implement to support comboboxes in Swing:
QString Quantity::getName() const{
    return unit;
}

// private functions:
double Quantity::getBaseValue(QList<Converter> u, QString n) const{
    int i=0;
    while (i < u.size()
            && !(u.at(i).abrv == n)
            && !(u.at(i).unit == n)) {
        i++;
    }
    if (i >= u.size())
        return 1;
    else
        return u.at(i).toBase;
}

QString Quantity::getUnitFromAbrv(QString type, QString abrv){
    int i=0;
    QList<Converter> *u;

    if (type == "volume")
        u = &QUANTITY_volUnits;
    else if ( type == "pressure")
        u = &QUANTITY_pressureUnits;
    else // assume weight
        u = &QUANTITY_weightUnits;

    while (i < u->size()
            && u->at(i).abrv != abrv) {
        i++;
    }

    return u->at(i).unit;
}


bool Quantity::isAbrv(QString a){

    QList<Converter> *u;
    QString t = getTypeFromUnit(a);
    if (t == "volume")
        u = &QUANTITY_volUnits;
    else if ( t == "pressure")
        u = &QUANTITY_pressureUnits;
    else // assume weight
        u = &QUANTITY_weightUnits;

    for (int  i=0; i<u->size(); i++){
        if (u->at(i).abrv == a)
            return true;

    }
    return false;

}

QString Quantity::getAbrvFromUnit(QString type, QString unit){
    int i=0;
    QList<Converter> *u;

    if (type == "volume")
        u = &QUANTITY_volUnits;
    else if (type == "pressure")
        u = &QUANTITY_pressureUnits;
    else // assume weight
        u = &QUANTITY_weightUnits;

    while (i < u->size()
            && u->at(i).unit.compare(unit, Qt::CaseInsensitive) != 0) {
        i++;
    }
    if (i >= u->size()) {
        // Assume we're already Abrv
        return unit;
    }
    return u->at(i).abrv;
}

QString Quantity::getTypeFromUnit(QString s) const{

    for (int i = 0; i < QUANTITY_weightUnits.size(); i++) {
        if (QUANTITY_weightUnits.at(i).unit == s ||
                QUANTITY_weightUnits.at(i).abrv == s) {
            return QUANTITY_WEIGHT;
        }
    }

    for (int i = 0; i < QUANTITY_volUnits.size(); i++) {
        if (QUANTITY_volUnits.at(i).unit == s ||
                QUANTITY_volUnits.at(i).abrv == s) {
            return QUANTITY_VOL;
        }
    }

    for (int i = 0; i < QUANTITY_pressureUnits.size(); i++) {
        if (QUANTITY_pressureUnits.at(i).unit == s ||
                QUANTITY_pressureUnits.at(i).abrv == s) {
            return QUANTITY_PRESSURE;
        }
    }

    return "";
}

/*
 * These are "generic" functions you can call on any quantity object (or just
 * create a new one).  No!.. we have static functions for a reason. Creating and garbage
 * collecting objects bad.
 */

QList<QString> Quantity::getListofUnits(QString type, bool abrv) const {
    QList<QString> list;
    int i = 0;
    if (QString::compare(type,"weight")) {
        for (i = 0; i < QUANTITY_weightUnits.size(); i++)
            if (abrv)
                list.push_back(QUANTITY_weightUnits.at(i).abrv);
            else
                list.push_back(QUANTITY_weightUnits.at(i).unit);
    } else if (QString::compare(type,"pressure")) {
        for (i = 0; i < QUANTITY_pressureUnits.size(); i++)
            if (abrv)
                list.push_back(QUANTITY_pressureUnits.at(i).abrv);
            else
                list.push_back(QUANTITY_pressureUnits.at(i).unit);
    } else {
        for (i = 0; i < QUANTITY_volUnits.size(); i++)
            if (abrv)
                list.push_back(QUANTITY_volUnits.at(i).abrv);
            else
                list.push_back(QUANTITY_volUnits.at(i).unit);
    }

    return list;
}

QList<QString> Quantity::getListofUnits(QString type) const {
    return (getListofUnits(type, false));
}

QString Quantity::getVolAbrv(QString unit) const {
    Quantity q;
    q.setUnits(unit);
    return q.abrv;
}

// let's just convert a unit from something to something else
double Quantity::convertUnit(QString from, QString to, double value) {
    Quantity q(from, value);
    return q.getValueAs(to);
}

bool Quantity::validWeight(QString toCheck) {
    return std::find(QUANTITY_weightUnits.begin(), QUANTITY_weightUnits.end(), toCheck)
            != QUANTITY_weightUnits.end();
}

/*
bool Quantity::validPressure(QString toCheck) {
    return std::find(Quantity::pressureUnits.begin(), Quantity::pressureUnits.end(), toCheck)
            != Quantity::pressureUnits.end();
}*/

bool Quantity::validVolume(QString toCheck) {
    return std::find(CONVERTER_volUnits.begin(), CONVERTER_volUnits.end(), toCheck)
            != CONVERTER_volUnits.end();
}

QString Quantity::toString() {
    QString temp = QString("%1%2").arg(SBStringUtils::format(getValue(), 2)).arg(getAbrv());
    return temp;
}
