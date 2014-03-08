#ifndef MASHSTEP_H
#define MASHSTEP_H

#include <QString>
#include <QSettings>

#include "quantity.h"
#include "brewcalcs.h"
#include "converter.h"

class MashStep
{
private:
    QString type;
    double startTemp;
    double endTemp;
    QString method;
    int minutes;
    int rampMin;
    QString directions;
    double temp;
    double weightLbs;
    QString maltUnits;


        // public Quantity decoctVol = new Quantity();
public:

    Quantity inVol;
    Quantity outVol;
    MashStep(QString type, double startTemp, double endTemp, QString method, int min, int rmin);
    MashStep();
    QString getDirections() const;
    void setDirections(QString directions);
    Quantity *getInVol();
    void setInVol(Quantity vol);
    Quantity *getOutVol();
    void setOutVol(Quantity vol);
    QString getMethod() const;
    void setMethod(QString method);
    int getMinutes() const;
    void setMinutes(int minutes);
    int getRampMin() const;
    void setRampMin(int rampMin);
    double getStartTemp() const;
    double getEndTemp() const;
    double getStrikeTemp() const;
    void setStartTemp(double startTemp);
    void setEndTemp(double endTemp);
    void setStrikeTemp(double sTemp);
    QString getType();
    void setType(QString s);
    void setWeightLbs(double inWeight);
    void setMaltUnits(QString inUnit);
    double getWeightLbs() const;
    double getWeight() const;

    int compareTo(MashStep m);
    static int lessThan(MashStep a, MashStep b);
    static int moreThan(MashStep a, MashStep b);
    QString toString();
};

#endif // MASHSTEP_H
