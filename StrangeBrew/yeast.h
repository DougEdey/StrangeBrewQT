#ifndef YEAST_H
#define YEAST_H

#include "ingredient.h"

class Yeast : public Ingredient
{
private:
    Yeast *altYeast;

public:
    Yeast();
    Yeast(QString name);
    virtual ~Yeast() {

    }

    Yeast getAlternate();
    void setAlternate(Yeast alt);
};

#endif // YEAST_H
