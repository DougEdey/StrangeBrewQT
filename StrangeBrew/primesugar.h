#ifndef PRIMESUGAR_H
#define PRIMESUGAR_H

#include "ingredient.h"

class PrimeSugar : public Ingredient
{
private:
    double yield;

public:
    explicit PrimeSugar(QObject *parent = 0);
    double getYield();
    void setYield(double y);
};

#endif // PRIMESUGAR_H
