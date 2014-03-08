#ifndef PROMASHIMPORT_H
#define PROMASHIMPORT_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QtDebug>

#include "recipe.h"

class ProMashImport
{
public:
    ProMashImport();
    Recipe readRecipe(QString inputFileName);
    QString readString(QTextStream fs, int b);
    int readInt(QTextStream fs);
    long readLong(QTextStream fs);
    int readShort(QTextStream fs);
    float readFloat(QTextStream fs);
};

#endif // PROMASHIMPORT_H
