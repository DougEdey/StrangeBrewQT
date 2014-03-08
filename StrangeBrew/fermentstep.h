#ifndef FERMENTSTEP_H
#define FERMENTSTEP_H

#include <QString>
#include <QSettings>
#include "options.h"
#include "constants.h"

class FermentStep
{
private:
    QString type;
    QString tempU;
    int time;
    double temp;

public:
    FermentStep();
    static int getTypeIndex(QString s);
    QString toXML();
    double getTemp() const;
    QString getTempU() const;
    int getTime() const;
    QString getType() const;
    void setTemp(double temp);
    void setTempU(QString tempU);
    void setTime(int time);
    void setType(QString type);
    static bool compareTo(FermentStep a, FermentStep b) {
        return a.getTypeIndex(a.getType()) < b.getTypeIndex(b.getType());
    }
    static bool moreThan(FermentStep a, FermentStep b) {
        // order by the ferment step
        if (a.getTypeIndex(a.getType()) == b.getTypeIndex(b.getType())) {
            return a.getTime() > b.getTime();
        } else
            return a.getTypeIndex(a.getType()) > b.getTypeIndex(b.getType());
    }

    static bool lessThan(FermentStep a, FermentStep b) {
        // order by the ferment step
        if (a.getTypeIndex(a.getType()) == b.getTypeIndex(b.getType())) {
            return a.getTime() < b.getTime();
        } else
            return a.getTypeIndex(a.getType()) < b.getTypeIndex(b.getType());
    }
    static std::vector<QString> initSteps();
};


//QSettings *FermentStep::opts = Options::getInstance();

#endif // FERMENTSTEP_H
