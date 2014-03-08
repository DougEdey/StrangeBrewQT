#ifndef OPTIONS_H
#define OPTIONS_H

#include <QString>
#include <QSettings>
#include <QCoreApplication>

#include "brewcalcs.h"
#include "hop.h"
#include "fermentstep.h"
#include "mash.h"

class Options
{
public:
    Options();
    static void SetDefaults();
    static void SetValueIfNotExists(QString key, QString value);

private:
    // Singelton Instance
    //	declare global variables, set hard defaults
    QString type;
};



#endif // OPTIONS_H
