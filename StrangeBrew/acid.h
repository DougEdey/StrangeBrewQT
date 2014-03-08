#ifndef ACID_H
#define ACID_H

#include <QString>
#include "converter.h"

class Acid
{
private:
    QString name;
    double pK1;
    double pK2;
    double pK3;
    double molWt;
    double mgPerML;

public:
    Acid();
    static std::vector<Acid> initAcids();
    Acid(QString name, double pK1, double pK2, double pK3, double molWt, double mgPerML);
    double getMolWt();
    QString getName();
    double getPK1();
    double getPK2();
    double getPK3();
    double getMgPerL();
    bool isLiquid();
    QString getAcidUnit();
    static Acid getAcidByName(QString name);
};

extern QString ACETIC;
extern QString CITRIC;
extern QString HYDROCHLORIC;
extern QString LACTIC;
extern QString PHOSPHORIC;
extern QString SULFURIC;
extern QString TARTRIC;
extern QString acidNames[];

extern std::vector<Acid> acids;
#endif // ACID_H
