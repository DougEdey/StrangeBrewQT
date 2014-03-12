#include "primesugar.h"

PrimeSugar::PrimeSugar(QObject *parent) : Ingredient(parent)
{
    yield = 1.0;
}

double PrimeSugar::getYield() { return yield; }

void PrimeSugar::setYield(double y) { yield = y;}
