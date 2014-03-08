#ifndef MASH_H
#define MASH_H

#include <QString>
#include <QSettings>
#include <vector>
#include <QtDebug>
#include <QList>

#include "constants.h"
#include "quantity.h"
#include "mashstep.h"
#include "options.h"

class Mash
{
private:
    double maltWeightLbs;
    QString maltUnits;
    bool allowRecalcs;

    //options:
    double mashRatio;
    QString mashRatioU;
    QString tempUnits;
    QString volUnits;
    double grainTempF;
    double boilTempF;

    // private double thermalMass;
    double tunLossF;
    Quantity deadSpace;
    double thinDecoctRatio;
    double thickDecoctRatio;
    double cerealMashTemp;
    QString name;

    // calculated:
    double preBoilQts;
    double volQts;
    int totalTime;
    double absorbedQTS;
    double totalWaterQTS;
    double spargeQTS;

public:
    // steps:
    QList<MashStep> steps;

    // configurable temps, can be set by the user:
    // target temps are 1/2 between temp + next temp

    int ACIDTMPF;
    int GLUCANTMPF;
    int PROTEINTMPF;
    int BETATMPF;
    int ALPHATMPF;
    int MASHOUTTMPF;
    int SPARGETMPF;


    Mash();
    void addStep(QString type, double st, double et, QString m, int min, int rmin, double weight);
    int addStep();
    void delStep(int i);
    void setMashRatio(double mr);
    double getMashRatio();
    void setMashRatioU(QString u);
    QString getMashRatioU();
    void setMashVolUnits(QString u);
    void setMashTempUnits(QString t);
    void setGrainTemp(double t);
    void setBoilTemp(double t);
    void setTunLoss(double t);
    void setDeadSpace(double d);
    double getDeadSpace();
    void setDecoctRatio(QString type, double r);
    void setTempRange(QString type, double t);
    void setName(QString s);
    QString getVolConverted(double val);
    QString getMashVolUnits();
    QString getMashTempUnits();
    int getMashTotalTime();
    double getGrainTemp();
    double getBoilTemp();
    double getTempRange(QString type);
    double getSpargeVol();
    double getSpargeQts();
    double getTunLoss();
    QString getMashTotalVol();
    QString getAbsorbedStr();
    double getAbsorbedQts();
    QString getTotalWaterStr();
    double getTotalWaterQts();
    double getThickDecoctRatio();
    double getThinDecoctRatio();
    QString getName();
    int setStepType(int i, QString t);
    QString getStepType(int i);
    QString getStepDirections(int i);
    void setStepMethod(int i, QString m);
    QString getStepMethod(int i) const;
    void setStepStartTemp(int i, double t);
    double getStepStartTemp(int i);
    void setStepEndTemp(int i, double t);
    double getStepStartTempF(int i);
    double getStepEndTemp(int i);
    double getStepEndTempF(int i);
    void setStepStartTempF(int i, double t);
    void setStepEndTempF(int i, double t);
    void setStepRampMin(int i, int m);
    int getStepRampMin(int i);
    double getStepTemp(int i);
    double getStepWeight(int i);
    void setStepWeight(int i, double w);
    void setStepMin(int i, int m);
    int getStepMin(int i);
    double getStepInVol(int i);
    double getStepOutVol(int i);
    int getStepSize() const;
    void calcMashSchedule();
    double calcDecoction2(double targetTemp, double currentTemp, double waterVolQTS, double ratio, double weightLbs);
    QString calcStepType(double temp);
    double calcStepTemp(QString stepType);
    double calcMashVol(double grainWeightLBS, double ratio);
    double calcStrikeTemp(double targetTemp, double currentTemp, double ratio, double tunLossF);
    double calcWaterAddition(double targetTemp, double currentTemp, double mashVol, double boilTempF);
    QString toXml();
    void setMaltUnits(QString newUnits);
    void enableRecalcs();
    void disableRecalcs();
    double getMaltWeightLbs();
    void setMaltWeightLbs(double weight);
    void setPreBoil(Quantity in);
    void clear();

    QString getTempUnits();
    void setTempUnits(QString t);
    int getTotalTime();
    double getTotalWeight();
    QString getMashVolUnitsAbrv();
    void setSpargeTempF(double d);
    void setMashoutTempF(double d);
};


#endif // MASH_H
