#ifndef QUANTITY_H
#define QUANTITY_H

#include <vector>
#include <map>

#include <QString>
#include <QDebug>

#include "converter.h"
#include "constants.h"
#include "sbstringutils.h"

class Quantity
{
private:
    QString type; // can be vol, weight, or temp
    QString unit; // must match one of the known units
    QString abrv; // ditto
    double value;

public:
    static QList<Converter> initPressureUnits();
    static QList<Converter> initWeightUnits();
    static QList<Converter> initVolUnits();
    Quantity();
    Quantity(QString u, double am);

    void setAmount(double am);
    void add(double v, QString u);
    void convertTo(QString to);
    void setUnits(QString s);

    QString getName() const;
    static QString getUnitFromAbrv(QString type, QString abrv);
    static QString getAbrvFromUnit(QString type, QString unit);
    QString getTypeFromUnit(QString s) const;
    QString getVolAbrv(QString unit) const;

    double getBaseValue(QList<Converter> u, QString n) const;
    double getValueAs(QString to) const;
    static double convertUnit(QString from, QString to, double value);

    bool isAbrv(QString a);

    QList<QString> getListofUnits(QString type, bool abrv) const;
    QList<QString> getListofUnits(QString type) const;

    QString getUnits() const;
    double getValue() const;
    QString getAbrv() const;

    static bool validWeight(QString toCheck) ;
    static bool validPressure(QString toCheck) ;
    static bool validVolume(QString toCheck) ;
    QString toString();
};

extern QList<Converter> QUANTITY_volUnits;
extern QList<Converter> QUANTITY_weightUnits;
extern QList<Converter> QUANTITY_pressureUnits;


#endif // QUANTITY_H
