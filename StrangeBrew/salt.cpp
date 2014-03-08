#include "salt.h"

QString MAGNESIUM = "Mg";
QString CHLORINE = "Cl";
QString SODIUM = "Na";
QString SULPHATE = "So4";
QString CARBONATE = "Co3";
QString CALCIUM = "Ca";
QString HARDNESS = "Hardness";
QString ALKALINITY = "Alkalinity";

QString MAGNESIUM_SULPHATE = "Magnesium Sulfate";
QString CALCIUM_CARBONATE = "Calcium Carbonate";
QString SODIUM_CHLORIDE = "Sodium Chloride";
QString SODIUM_BICARBONATE = "Sodium Bicarbonate";
QString CALCIUM_SULPHATE = "Calcium Sulphate";
QString CALCIUM_CHLORIDE = "Calcium Chloride";

QString EPSOM_SALT = "Epsom Salt";
QString GYPSUM = "Gypsum";
QString SALT = "Salt";
QString BAKING_SODA = "Baking Soda";
QString CHALK = "Chalk";

QList<Salt> salts = Salt::initSalts();

Salt::Salt()
{

}

Salt::Salt(QString name, QString commonName, QString chemicalName,
        double gramsPerTsp, QList<ChemicalEffect> chemEff) {

    this->name = name;
    this->commonName = commonName;
    this->chemicalName = chemicalName;
    this->amount = 0.0;
    this->amountU = CONVERTER_G;
    this->gramsPerTsp = gramsPerTsp;
    // this->chemicalEffects = Arrays.copyOf(chemEff, chemEff.length);
    this->chemicalEffects = chemEff;
}

QList<Salt> Salt::initSalts() {
    QList<Salt> newSalts;
    QList<ChemicalEffect> curEffect;

    curEffect.push_back(ChemicalEffect(SULPHATE, 103.0));
    curEffect.push_back(ChemicalEffect(MAGNESIUM, 26.1));
    curEffect.push_back(ChemicalEffect(HARDNESS, 107.8));

    newSalts.push_back(Salt(MAGNESIUM_SULPHATE, EPSOM_SALT, "MgSo4", 4.5, curEffect));

    curEffect.clear();

    curEffect.push_back(ChemicalEffect(CALCIUM, 61.5));
    curEffect.push_back(ChemicalEffect(SULPHATE, 147.4));
    curEffect.push_back(ChemicalEffect(HARDNESS, 153.6));

    newSalts.push_back(Salt(CALCIUM_CARBONATE, GYPSUM, "CaCo3", 1.8, curEffect));

    curEffect.clear();

    curEffect.push_back(ChemicalEffect(SODIUM, 103.9));
    curEffect.push_back(ChemicalEffect(CHLORINE, 160.3));
    curEffect.push_back(ChemicalEffect(HARDNESS, 107.8));

    newSalts.push_back(Salt(SODIUM_CHLORIDE, SALT, "NaCl", 6.5, curEffect));

    curEffect.clear();

    curEffect.push_back(ChemicalEffect(SODIUM, 72.3));
    curEffect.push_back(ChemicalEffect(CARBONATE, 188.7));
    curEffect.push_back(ChemicalEffect(ALKALINITY, 157.4));

    newSalts.push_back(Salt(SODIUM_BICARBONATE, BAKING_SODA, "NaHCo3", 4.4, curEffect));

    curEffect.clear();

    curEffect.push_back(ChemicalEffect(CALCIUM, 105.8));
    curEffect.push_back(ChemicalEffect(CARBONATE, 158.4));
    curEffect.push_back(ChemicalEffect(HARDNESS, 264.2));
    curEffect.push_back(ChemicalEffect(ALKALINITY, 264.2));

    newSalts.push_back(Salt(CALCIUM_SULPHATE, CHALK, "CaSo4", 4.0, curEffect));

    curEffect.clear();

    curEffect.push_back(ChemicalEffect(CALCIUM, 72.0));
    curEffect.push_back(ChemicalEffect(CARBONATE, 127.4));
    curEffect.push_back(ChemicalEffect(HARDNESS, 179.8));

    newSalts.push_back(Salt(CALCIUM_CHLORIDE, CALCIUM_CHLORIDE, "CaCl2", 3.4, curEffect));

    return newSalts;
}

double Salt::getAmount() const {
    return amount;
}

QString Salt::getAmountU() const {
    return amountU;
}

QString Salt::getChemicalName() const {
    return chemicalName;
}

QString Salt::getCommonName() const {
    return commonName;
}

QString Salt::getName() const {
    return name;
}

QList<ChemicalEffect> Salt::getChemicalEffects() const {
    return chemicalEffects;
}

void Salt::setAmount(double amount) {
    this->amount = amount;
}

QString Salt::toString() {
    /*mf = new MessageFormat(name + "(" + commonName + ") {0,number,0.000}" + amountU);
    Object[] objs = {new Double(amount)};

    return mf.format(objs);*/
    return "Doug to finish Salt To String()";
}

QString Salt::toXML(int indent) {
    QString xml = "";

    xml.append(SBStringUtils::xmlElement("NAME", name, indent));
    xml.append(SBStringUtils::xmlElement("COMMONNAME", commonName, indent));
    xml.append(SBStringUtils::xmlElement("CHEM", chemicalName, indent));
    xml.append(SBStringUtils::xmlElement("AMOUNT", SBStringUtils::format(amount, 2), indent));
    xml.append(SBStringUtils::xmlElement("AMOUNTU", amountU, indent));

    return xml;
}

// TODO currently only in grams
/*void setAmountU(QString amountU) {
    this->amountU = amountU;
}*/

void Salt::setChemicalEffects(QList<ChemicalEffect> effs) {
    // this->chemicalEffects = Arrays.copyOf(effs, effs.length);
    this->chemicalEffects = effs;
}

void Salt::setChemicalName(QString chemicalName) {
    this->chemicalName = chemicalName;
}

void Salt::setCommonName(QString commonName) {
    this->commonName = commonName;
}

void Salt::setName(QString name) {
    this->name = name;
}

double Salt::getEffectByChem(QString chem) {
    for (int i = 0; i < chemicalEffects.size(); i++) {
        if (chemicalEffects[i].getElem() == chem) {
            return chemicalEffects[i].getEffect();
        }
    }

    return 0;
}

Salt Salt::getSaltByName(QString name) {

    for (int i = 0; i < salts.size(); i++) {
        if (salts.at(i).getName() == name ) {
            return salts.at(i);
        }
    }

    throw "Salt " + name + " not found";
}

double Salt::getGramsPerTsp() {
    return gramsPerTsp;
}

void Salt::setGramsPerTsp(double gramsPerTsp) {
    this->gramsPerTsp = gramsPerTsp;
}

QString Salt::getVolU() {
    return "tsp";
}

double Salt::getVol() {
    double grams = this->getAmount();
    double tsp = 0;

    tsp = grams / this->getGramsPerTsp();

    return tsp;
}

bool Salt::operator==(Salt other) {
    return (this->getName() == other.getName() &&
            this->getAmount() == other.getAmount());
}
