#ifndef CONVERTER_H
#define CONVERTER_H

#include <QString>
#include <QStringList>
#include <vector>

#include "constants.h"

class Converter
{
private:

public:
    QString abrv;
    QString unit;
    double toBase;

    Converter();
    Converter(QString n, QString a, double t);
    static QStringList initWeights(QString type="");
    static QStringList initVolumes(QString type="");
    bool operator ==(const QString &from) const;
};




#endif // CONVERTER_H
