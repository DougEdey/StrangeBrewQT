#ifndef CHEMICALEFFECT_H
#define CHEMICALEFFECT_H

#include <QString>
#include <QDebug>

class ChemicalEffect
{
private:
    QString elem;
    double effect;

public:
    ChemicalEffect(QString elem, double effect) {
        this->elem = elem;
        this->effect = effect;
    }

    double getEffect() {
        return effect;
    }

    QString getElem() {
        return elem;
    }
    ChemicalEffect();
};

#endif // CHEMICALEFFECT_H
