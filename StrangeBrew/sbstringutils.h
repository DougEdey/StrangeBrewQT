#ifndef SBSTRINGUTILS_H
#define SBSTRINGUTILS_H

#include <QString>
#include <QDir>

class SBStringUtils
{
public:
    SBStringUtils();
    static QString multiLineToolTip(int len, QString input);
    static QString subEntities(QString input);
    static QString format(double value, int decimal);
    static QString xmlElement(QString elem, QString content, int i);
    static QString getAppPath(QString type);
    static QString capitalize(QString orig);
    static double round(double d, int decimalPlace);
    static QString xmlElement(QString elem, double content, int i);
    static std::map<QString, QString> initSubEntities();

};
extern std::map<QString, QString> string_subEntities;

#endif // SBSTRINGUTILS_H
