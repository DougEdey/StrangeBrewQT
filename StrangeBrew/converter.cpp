#include "converter.h"

// volumes
QString CONVERTER_FL_OUNCES = "fl. ounces";
QString CONVERTER_FL_OZ = "fl. oz";
QString CONVERTER_GALLONS_US = "gallons US";
QString CONVERTER_GAL = "gal";
QString CONVERTER_LITRES = "litres";
QString CONVERTER_L = "l";
QString CONVERTER_MILLILITERS = "milliliters";
QString CONVERTER_ML = "ml";
QString CONVERTER_QUART_US = "quart US";
QString CONVERTER_QT = "qt";
QString CONVERTER_BARREL_IMP = "barrel Imp";
QString CONVERTER_BBL_IMP = "bbl Imp";
QString CONVERTER_BARREL_US = "barrel US";
QString CONVERTER_BBL_US = "bbl US";
QString CONVERTER_GALLONS_IMP = "gallons Imp";
QString CONVERTER_GAL_IMP = "gal Imp";
QString CONVERTER_PINT_US = "pint US";
QString CONVERTER_PT_US = "pt US";
QStringList CONVERTER_volUnits = Converter::initVolumes();
QStringList CONVERTER_volUnitsAbrv = Converter::initVolumes("abrv");
QStringList CONVERTER_volUnitsFull = Converter::initVolumes("full");

// weights
QString CONVERTER_TSP = "tsp";
QString CONVERTER_TBSP = "tbsp";
QString CONVERTER_OZ = "oz";
QString CONVERTER_OUNCES = "ounces";
QString CONVERTER_POUNDS = "pounds";
QString CONVERTER_LB = "lb";
QString CONVERTER_MILLIGRAMS = "milligrams";
QString CONVERTER_MG = "mg";
QString CONVERTER_GRAMS = "grams";
QString CONVERTER_G = "g";
QString CONVERTER_KG = "kg";
QString CONVERTER_KILOGRAM = "kilogram";

QString CONVERTER_DEFAULT_WEIGHT = CONVERTER_G;
QString CONVERTER_DEFAULT_VOLUME = CONVERTER_L;

QStringList CONVERTER_weightUnits = Converter::initWeights();
QStringList CONVERTER_weightUnitsAbrv = Converter::initWeights("abrv");
QStringList CONVERTER_weightUnitsFull = Converter::initWeights("full");

Converter::Converter(QString n, QString a, double t) {
    unit = n;
    abrv = a;
    toBase = t;
}


QStringList Converter::initVolumes(QString type) {
    QStringList volumes;

    if (type != "abrv") {
        volumes.push_back(CONVERTER_FL_OUNCES);
        volumes.push_back(CONVERTER_GALLONS_US);
        volumes.push_back(CONVERTER_LITRES);
        volumes.push_back(CONVERTER_QUART_US);
    }

    if (type != "full") {
        volumes.push_back(CONVERTER_ML);
        volumes.push_back(CONVERTER_FL_OZ);
        volumes.push_back(CONVERTER_L);
        volumes.push_back(CONVERTER_QT);
        volumes.push_back(CONVERTER_GAL);
    }

    return volumes;
}


QStringList Converter::initWeights(QString type) {
    QStringList weights;

    if (type != "abrv") {
        weights.push_back(CONVERTER_OUNCES);
        weights.push_back(CONVERTER_POUNDS);
        weights.push_back(CONVERTER_MILLIGRAMS);
        weights.push_back(CONVERTER_GRAMS);
        weights.push_back(CONVERTER_KILOGRAM);
    }

    if (type != "full") {
        weights.push_back(CONVERTER_MG);
        weights.push_back(CONVERTER_G);
        weights.push_back(CONVERTER_OZ);
        weights.push_back(CONVERTER_LB);
        weights.push_back(CONVERTER_KG);
    }

    return weights;
}

bool Converter::operator==(const QString &from) const
{
    return (unit == from || abrv == from);
}
