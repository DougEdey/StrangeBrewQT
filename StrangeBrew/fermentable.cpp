#include "fermentable.h"

// constructors:
Fermentable::Fermentable() : Ingredient(){
    // default constructor
    setName("");
    pppg = 0;
    lov = 0;
    percent = 0;
    setCost(0);
    setStock(0);
    setAmount(1.0);
    QString unit = QSettings("StrangeBrew", "StrangeBrew").value("Recipe/MaltU").toString();
    setUnits(unit);
    mashed = true;
    prime = false;
    fermentable = true;
}

Fermentable::Fermentable(QString n, double p, double l, double a, QString u) : Ingredient() {
    setName(n);
    pppg = p;
    lov = l;
    setStock(0);
    setAmount(a);
    setUnits(u);
    mashed = true;
    prime = false;
    fermentable = true;
    percent = 0;
    setCost(0);
}


Fermentable::Fermentable(QString u) {
    setName("");
    percent = 0;
    pppg = 1.000;
    setCost(0);
    setUnits(u);
}


double Fermentable::getBasePppg() const {
    return basePppg;
}

// getter methods:
double Fermentable::getLov() const { return lov; }
bool Fermentable::getMashed() const { return mashed; }
double Fermentable::getPercent() const { return percent; }
double Fermentable::getPppg() const { return pppg; }
bool Fermentable::getSteep() const { return steeped; }
bool Fermentable::getPrime() const { return prime; }
bool Fermentable::ferments() const { return fermentable; }

// setter methods:
void Fermentable::setLov(double l) {
    lov = l;
}

void Fermentable::setMashed(bool m){ mashed = m; }
void Fermentable::setPercent(double p){ percent = p; }
void Fermentable::setPppg(double p){ pppg = p; }
void Fermentable::setSteep(bool s){ steeped = s; }
void Fermentable::setPrime(bool b) { prime = b; }
void Fermentable::ferments(bool f) { fermentable = f; }

void Fermentable::setMashed(QString f) {
    if (QString::compare(f, "yes", Qt::CaseInsensitive) == 0
        || QString::compare(f, "true", Qt::CaseInsensitive) == 0
        || QString::compare(f, "1", Qt::CaseInsensitive) == 0 )
        mashed = true;
    else
        mashed = false;
}

void Fermentable::setSteep(QString f) {
    if (QString::compare(f, "yes", Qt::CaseInsensitive) == 0
        || QString::compare(f, "true", Qt::CaseInsensitive) == 0
        || QString::compare(f, "1", Qt::CaseInsensitive) == 0 )
        steeped = true;
    else
        steeped= false;
}

void Fermentable::ferments(QString f) {
    if (QString::compare(f, "yes", Qt::CaseInsensitive) == 0
        || QString::compare(f, "true", Qt::CaseInsensitive) == 0
        || QString::compare(f, "1", Qt::CaseInsensitive) == 0 )
        fermentable = true;
    else
        fermentable = false;
}

// Need to add the spaces and type attributes to make this
// backwards-compatible with SB1.8:
QString Fermentable::toXML(){
    QString sb;
    sb.append( "    <ITEM>\n" );
    sb.append(SBStringUtils::xmlElement("MALT", getName(), 6));
    sb.append(SBStringUtils::xmlElement("AMOUNT", getAmountAs(getUnits()), 6));
    sb.append(SBStringUtils::xmlElement("PERCENT", SBStringUtils::format(percent, 1), 6));
    sb.append(SBStringUtils::xmlElement("UNITS", getUnitsAbrv(), 6));
    sb.append(SBStringUtils::xmlElement("POINTS", pppg, 6));
    sb.append(SBStringUtils::xmlElement("LOV", lov, 6));
    QString bVal = "True";
    if (mashed) { bVal = "true"; } else {bVal = "false";}
    sb.append(SBStringUtils::xmlElement("MASHED", bVal, 6));

    if (steeped) { bVal = "true"; } else {bVal = "false";}
    sb.append(SBStringUtils::xmlElement("STEEPED", bVal, 6));
    sb.append(SBStringUtils::xmlElement("COSTLB", getCostPerU(), 6));
    sb.append(SBStringUtils::xmlElement("DESCRIPTION", SBStringUtils::subEntities(getDescription()), 6));
    sb.append( "    </ITEM>\n" );
    return sb;
}

// No special Comparators for this, but I may add them in the future if I decide to
bool Fermentable::operator==(Fermentable other) const {
    return (this->getPppg() == other.getPppg()
            && Ingredient::operator==(other));
}

bool Fermentable::operator ==(QString other) const {
    return (this->getName().compare(other) == 0);
}

QString Fermentable::toString() {
    QString temp =  QString("%1 %2 %3 %4 %4 %5 %6%").arg(getName(), 30)
            .arg(SBStringUtils::format(getAmountAs(getUnits()), 2), 6)
            .arg(getUnitsAbrv(), 5).arg(getPppg())
            .arg(SBStringUtils::format(getLov(), 1), 6)
            .arg(SBStringUtils::format(getPercent(), 1), 5);
    return temp;
}
