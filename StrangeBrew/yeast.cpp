#include "yeast.h"

Yeast::Yeast()
{
}

Yeast::Yeast(QString name) : Ingredient(name) {

}

Yeast *Yeast::getAlternate() {
    return altYeast;
}

void Yeast::setAlternate(Yeast *alt) {
   altYeast = alt;
}
