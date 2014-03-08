#ifndef MISC_H
#define MISC_H

#include <ingredient.h>

#include "sbstringutils.h"
class Misc : public Ingredient
{
private:
    QString comments;
    QString stage;
    int time;

public:

    Misc();
    virtual ~Misc() {

    }

    QString getComments() const;
    QString getStage() const;
    int getTime() const;
    QString toXML();
    void setComments(QString c);
    void setStage(QString s);
    void setTime(int t);
};

extern QString MISC_MASH;
extern QString MISC_BOIL;
extern QString MISC_PRIMARY;
extern QString MISC_SECONDARY;
extern QString MISC_BOTTLE;
extern QString MISC_KEG;
extern QString MISC_stages[];

#endif // MISC_H
