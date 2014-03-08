#include "acid.h"

QString ACETIC = "Acetic";
QString CITRIC = "Citric";
QString HYDROCHLORIC = "Hydrochloric";
QString LACTIC = "Lactic";
QString PHOSPHORIC = "Phosphoric";
QString SULFURIC = "Sulfuric";
QString TARTRIC = "Tartric";
QString acidNames[] = {ACETIC, CITRIC, HYDROCHLORIC, LACTIC, PHOSPHORIC, SULFURIC, TARTRIC};

std::vector<Acid> acids = Acid::initAcids();

Acid::Acid()
{

}

Acid::Acid(QString name, double pK1, double pK2, double pK3, double molWt, double mgPerML) {
    this->name = name;
    this->pK1 = pK1;
    this->pK2 = pK2;
    this->pK3 = pK3;
    this->molWt = molWt;
    this->mgPerML = mgPerML;
}

std::vector<Acid> Acid::initAcids() {
    std::vector<Acid> newAcids;

    newAcids.push_back(Acid(ACETIC, 4.75, 20, 20, 60.05, 0));
    newAcids.push_back(Acid(CITRIC, 3.14, 4.77, 6.39, 192.13, 0));
    newAcids.push_back(Acid(HYDROCHLORIC, -10, 20, 20, 36.46, 319.8)); // 28% hcl
    newAcids.push_back(Acid(LACTIC, 3.08, 20, 20, 90.08, 1068)); // 88% lactic
    newAcids.push_back(Acid(PHOSPHORIC, 2.12, 7.20, 12.44, 98.00, 292.5)); // 25% phosphoric
    newAcids.push_back(Acid(SULFURIC, -10, 1.92, 20, 98.07, 0));
    newAcids.push_back(Acid(TARTRIC, 2.98, 4.34, 20, 150.09, 0));

    return newAcids;
}

double Acid::getMolWt() {
    return molWt;
}

QString Acid::getName() {
    return name;
}

double Acid::getPK1() {
    return pK1;
}

double Acid::getPK2() {
    return pK2;
}

double Acid::getPK3() {
    return pK3;
}

double Acid::getMgPerL() {
    return mgPerML;
}

bool Acid::isLiquid() {
    if (mgPerML == 0) {
        return false;
    } else {
        return true;
    }
}

QString Acid::getAcidUnit() {
    if (isLiquid()) {
        return CONVERTER_ML;
    } else {
        return CONVERTER_MG;
    }
}

Acid Acid::getAcidByName(QString name) {
    for (size_t i = 0; i < acids.size(); i++) {
        if (acids.at(i).getName() == name) {
            return acids.at(i);
        }
    }
    return Acid();
}
