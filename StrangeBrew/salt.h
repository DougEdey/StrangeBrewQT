#ifndef SALT_H
#define SALT_H

#include <QString>
#include <vector>

#include "chemicaleffect.h"
#include "converter.h"
#include "sbstringutils.h"

class Salt
{
private:
    QString name;
    QString commonName;
    QString chemicalName;
    double amount;
    QString amountU;
    double gramsPerTsp;
    QList<ChemicalEffect> chemicalEffects;
public:



    Salt();
    Salt(QString name, QString commonName, QString chemicalName,
            double gramsPerTsp, QList<ChemicalEffect> chemEff);
    double getAmount() const;
    QString getAmountU() const;
    QString getChemicalName() const;
    QString getCommonName() const;
    QString getName() const;
    QList<ChemicalEffect> getChemicalEffects() const;
    void setAmount(double amount);
    QString toString();
    QString toXML(int indent);
    void setChemicalEffects(QList<ChemicalEffect> effs);
    void setChemicalName(QString chemicalName);
    void setCommonName(QString commonName);
    void setName(QString name);
    double getEffectByChem(QString chem);
    double getGramsPerTsp();
    static Salt getSaltByName(QString name);
    void setGramsPerTsp(double gramsPerTsp);
    QString getVolU();
    double getVol();
    static QList<Salt> initSalts();
    bool operator ==(Salt other);
};

extern QString MAGNESIUM;
extern QString CHLORINE;
extern QString SODIUM;
extern QString SULPHATE;
extern QString CARBONATE;
extern QString CALCIUM;
extern QString HARDNESS;
extern QString ALKALINITY;

extern QString MAGNESIUM_SULPHATE;
extern QString CALCIUM_CARBONATE;
extern QString SODIUM_CHLORIDE;
extern QString SODIUM_BICARBONATE;
extern QString CALCIUM_SULPHATE;
extern QString CALCIUM_CHLORIDE;

extern QString EPSOM_SALT;
extern QString GYPSUM;
extern QString SALT;
extern QString BAKING_SODA;
extern QString CHALK;
extern QList<Salt> salts;
#endif // SALT_H
