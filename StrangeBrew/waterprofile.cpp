#include "waterprofile.h"

std::vector<WaterProfile> WaterProfile::profiles;

WaterProfile::WaterProfile()
{
    name = "Distilled/RO";
    ph = 5.80000019073486;
}

WaterProfile::WaterProfile(QString name) {
    // Creates a new water profile based on the name from the db
    for (size_t i = 0; i < profiles.size(); i++) {
        WaterProfile &p = profiles.at(i);
        if (p.getName() == name) {
            this->name = p.getName();
            this->description = p.getDescription();
            this->ca = p.getCa();
            this->mg = p.getMg();
            this->na = p.getNa();
            this->so4 = p.getSo4();
            this->hco3 = p.getHco3();
            this->cl = p.getCl();
            this->hardness = p.getHardness();
            this->tds = p.getTds();
            this->ph = p.getPh();
            this->alkalinity = p.getAlkalinity();

            return;
        }
    }

    this->name = "Distilled/RO";
    this->ph = 5.80000019073486;
}

void WaterProfile::setProfiles(std::vector<WaterProfile> newProfiles) {
    profiles = newProfiles;
}

double WaterProfile::getAlkalinity() {
    return alkalinity;
}

double WaterProfile::getCa() {
    return ca;
}

double WaterProfile::getCl() {
    return cl;
}

QString WaterProfile::getDescription() {
    return description;
}

double WaterProfile::getHardness() {
    return hardness;
}

double WaterProfile::getHco3() {
    return hco3;
}

double WaterProfile::getMg() {
    return mg;
}

double WaterProfile::getNa() {
    return na;
}

QString WaterProfile::getName() {
    return name;
}

double WaterProfile::getPh() {
    return ph;
}

double WaterProfile::getSo4() {
    return so4;
}

double WaterProfile::getTds() {
    return tds;
}

void WaterProfile::setAlkalinity(double alkalinity) {
    this->alkalinity = alkalinity;
}

void WaterProfile::setCa(double ca) {
    this->ca = ca;
}

void WaterProfile::setCl(double cl) {
    this->cl = cl;
}

void WaterProfile::setDescription(QString description) {
    this->description = description;
}

void WaterProfile::setHardness(double hardness) {
    this->hardness = hardness;
}

void WaterProfile::setHco3(double hco3) {
    this->hco3 = hco3;
}

void WaterProfile::setMg(double mg) {
    this->mg = mg;
}

void WaterProfile::setNa(double na) {
    this->na = na;
}

void WaterProfile::setName(QString name) {
    this->name = name;
}

void WaterProfile::setPh(double ph) {
    this->ph = ph;
}

void WaterProfile::setSo4(double so4) {
    this->so4 = so4;
}

void WaterProfile::setTds(double tds) {
    this->tds = tds;
}

QString WaterProfile::toString() {
    /*
    QString str = QString.format("%s => %3.1fCa %3.1fMg %3.1fNa %3.1fSo4 %3.1fHCO3 %3.1fCl %3.1fHardness %3.1fTDS %3.1fpH %3.1fAlk",
            new Object[] {name,
            new Double(ca),
            new Double(mg),
            new Double(na),
            new Double(so4),
            new Double(hco3),
            new Double(cl),
            new Double(hardness),
            new Double(tds),
            new Double(ph),
            new Double(alkalinity)
            });

    */
    QString str = "Doug needs to implement water profile to String";

    return str;
}

QString WaterProfile::toXML(int indent) {
    QString xml = "";

    xml.append(SBStringUtils::xmlElement("NAME", name, indent));
    xml.append(SBStringUtils::xmlElement("CA", QString::number(ca), indent));
    xml.append(SBStringUtils::xmlElement("MG", QString::number(mg), indent));
    xml.append(SBStringUtils::xmlElement("NA", QString::number(na), indent));
    xml.append(SBStringUtils::xmlElement("SO4", QString::number(so4), indent));
    xml.append(SBStringUtils::xmlElement("HCO3", QString::number(hco3), indent));
    xml.append(SBStringUtils::xmlElement("CL", QString::number(cl), indent));
    xml.append(SBStringUtils::xmlElement("HARDNESS", QString::number(hardness), indent));
    xml.append(SBStringUtils::xmlElement("TDS", QString::number(tds), indent));
    xml.append(SBStringUtils::xmlElement("PH", QString::number(ph), indent));
    xml.append(SBStringUtils::xmlElement("ALKALINITY", QString::number(alkalinity), indent));

    return xml;
}

int WaterProfile::compareTo(WaterProfile w) {
    return QString::compare(this->getName(), w.getName());
}

bool WaterProfile::operator==(const WaterProfile &other) const {
    return name == other.name;
}

bool WaterProfile::operator<(const WaterProfile &second) const {
    return (name < second.name);
}

bool WaterProfile::lessThan(WaterProfile *a, WaterProfile *b) {
    return a->getName() < b->getName();
}
