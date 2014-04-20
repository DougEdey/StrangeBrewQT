#include "hop.h"

QString HOP_LEAF = "Leaf";
QString HOP_PELLET = "Pellet";
QString HOP_PLUG = "Plug";
QString HOP_BOIL = "Boil";
QString HOP_FWH = "FWH";
QString HOP_DRY = "Dry";
QString HOP_MASH = "Mash";

QString HOP_DEFAULT_TYPE = HOP_PELLET;
QString HOP_DEFAULT_ADD = HOP_BOIL;

QStringList HOP_forms = QStringList() << HOP_LEAF << HOP_PELLET << HOP_PLUG ;
QStringList HOP_addTypes = QStringList() << HOP_BOIL << HOP_FWH << HOP_DRY << HOP_MASH;
// Constructors:

Hop::Hop() : Ingredient() {
    // default constructor
    setForm("hop");
    setType(HOP_DEFAULT_TYPE);
    setAdd(HOP_DEFAULT_ADD);
    setUnits(CONVERTER_DEFAULT_WEIGHT);
    setAmount(0);
    setIBU(0);
    setAlpha(0);
    setMinutes(0);
}

Hop::Hop(QString u, QString t) {
    setForm("hop");
    setUnits(u);
    setType(t);
    setAmount(0);
    setAdd(HOP_BOIL);
    setIBU(0);
}

// get methods:
QString Hop::getAdd() const {
    return add;
}

double Hop::getAlpha() const {
    return alpha;
}

double Hop::getIBU() const {
    return IBU;
}

int Hop::getMinutes() const {
    return minutes;
}

double Hop::getStorage() const {
    return storage;
}

// Setter methods:

void Hop::setAdd(QString a) {
    add = a;
}

void Hop::setAlpha(double a) {
    alpha = a;
}

void Hop::setIBU(double i) {
    IBU = i;
}

void Hop::setMinutes(int m) {
    minutes = m;
}

void Hop::setStorage(double s) {
    storage = s;
}

QString Hop::toXML() {
    QString sb;
    sb.append("    <ITEM>\n");
    sb.append(SBStringUtils::xmlElement("HOP", getName(), 6));
    sb.append(SBStringUtils::xmlElement("AMOUNT", getAmountAs(getUnits()), 6));
    sb.append(SBStringUtils::xmlElement("TIME", getMinutes(), 6));
    sb.append(SBStringUtils::xmlElement("UNITS", getUnitsAbrv(), 6));
    sb.append(SBStringUtils::xmlElement("FORM", getType(), 6));
    sb.append(SBStringUtils::xmlElement("ALPHA", getAlpha(), 6));
    sb.append(SBStringUtils::xmlElement("COST_OZ", getCostPerU(), 6));
    sb.append(SBStringUtils::xmlElement("ADD", add, 6));
    sb.append("      <DESCRIPTION>"
            + SBStringUtils::subEntities(getDescription())
            + "</DESCRIPTION>\n");
    sb.append(SBStringUtils::xmlElement("DATE", getDate().toString("MM/dd/yyyy"), 6));
    sb.append("    </ITEM>\n");
    return sb;
}

bool Hop::operator<(const Hop &other) const {
    // Check to see if the additions are at the same time
    if (minutes == other.minutes) {
        // Check to see if we have dry hopping
        if (add == other.add) {
            // Same addition, continue the compare
            this->getName() < other.getName();
        } else {
            // Different addition type, so compare that. Boil is luckily
            // prior to Dry
            return add < other.add;

        }
    } else {
        // Times are not the same, straightforward comparrison
        return minutes < other.minutes;
    }
}

bool Hop::operator>(const Hop &other) const {
    // Check to see if the additions are at the same time
    if (minutes == other.minutes) {
        // Check to see if we have dry hopping
        if (add == other.add) {
            // Same addition, continue the compare
            this->getName() > other.getName();
        } else {
            // Different addition type, so compare that. Boil is luckily
            // prior to Dry
            return add > other.add;

        }
    } else {
        // Times are not the same, straightforward comparrison
        return minutes > other.minutes;
    }
}

bool Hop::operator==(const Hop &other) const {
    // Check to see if the additions are at the same time
    return (minutes == other.minutes
            && add == other.add
            && this->getName() == other.getName());
}

bool Hop::operator==(const QString &other) const {
    // Check to see if the additions are at the same time
    return (this->getName() == other);
}

bool Hop::lessThan(Hop *a, Hop *b) {
    if (a->minutes == b->minutes) {
        return a < b;
    }

    return a->minutes < b->minutes;
}


bool Hop::moreThan(Hop *a, Hop *b) {
    if (a->minutes == b->minutes) {
        return a > b;
    }

    return a->minutes > b->minutes;
}

QString Hop::toString() {
    QString temp = QString("%1 %2 %3 %4 %5 %6 %7\n").arg(getName() + " (" + getType()+")", 20)
                    .arg(SBStringUtils::format(getAmountAs(getUnits()), 2), 6)
                    .arg(getUnitsAbrv(), 5)
                    .arg(SBStringUtils::format(getAlpha(), 2), 6, ' ')
                    .arg(SBStringUtils::format(getMinutes(), 1), 6)
                    .arg(SBStringUtils::format(getIBU(), 1), 5);
    return temp;
}
