#ifndef HOP_H
#define HOP_H

#include <QString>
#include <QDebug>

#include <ingredient.h>
#include <sbstringutils.h>
#include "constants.h"

class Hop : public Ingredient
{
private:
    double alpha;
    QString add;
    int minutes;
    double storage;
    double IBU;

public:

    // Hops should know about hop types

    Hop();
    Hop(QString u, QString t);
    virtual ~Hop() {

    }

    QString getAdd() const;
    double getAlpha() const;
    double getIBU() const;
    int getMinutes() const;
    double getStorage() const;

    void setAdd(QString a);
    void setAlpha(double a);
    void setIBU(double i);
    void setMinutes(int m);
    void setStorage(double s);

    QString toXML();

    virtual bool operator <(const Hop &other) const;
    virtual bool operator >(const Hop &other) const;
    virtual bool operator ==(const Hop &other) const;
    virtual bool operator ==(const QString &other) const;
    static bool lessThan(Hop *a, Hop *b);
    static bool moreThan(Hop *a, Hop *b);
    QString toString();
};





#endif // HOP_H
