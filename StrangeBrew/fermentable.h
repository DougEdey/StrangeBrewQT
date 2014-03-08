#ifndef FERMENTABLE_H
#define FERMENTABLE_H

#include "ingredient.h"
#include "options.h"

class Fermentable : public Ingredient
{
    double pppg;
    double lov;
    bool mashed;
    bool steeped;
    bool fermentable;
    double percent;
    bool prime;
    double basePppg;

public:
    Fermentable();
    Fermentable(QString u);
    virtual ~Fermentable() {

    }

    double getBasePppg() const;
    double getLov() const;
    bool getMashed() const;
    double getPercent() const;
    double getPppg() const;
    bool getSteep() const;
    bool getPrime() const;
    bool ferments() const;

    void setLov(double l);
    void setMashed(bool m);
    void setPercent(double p);
    void setPppg(double p);
    void setSteep(bool s);
    void setPrime(bool b);
    void ferments(bool f);
    QString toXML();
    Fermentable(QString n, double p, double l, double a, QString u);
    void ferments(QString f);
    void setSteep(QString f);
    void setMashed(QString f);

    virtual bool operator ==(Fermentable other) const;
    virtual bool operator ==(QString other) const;
    QString toString();

};

#endif // FERMENTABLE_H
