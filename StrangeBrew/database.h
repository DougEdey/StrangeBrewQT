#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QDate>
#include <QtSql/QtSql>
#include <QSettings>
#include <QMessageBox>
#include <QApplication>
#include <QFile>

#include <map>
#include <vector>

#include "options.h"
#include "fermentable.h"
#include "hop.h"
#include "misc.h"
#include "yeast.h"
#include "style.h"
#include "primesugar.h"
#include "waterprofile.h"

#include "sbstringutils.h"

using namespace QSql;
using namespace std;

class Database
{
private:

    static QSettings preferences;
    static QString dbPath;
    static QString lastErrorString;

public:
    static QList<Hop*> hopsDB;
    static QList<Hop*> stockHopsDB;

    static QList<Fermentable*> fermDB;
    static QList<Fermentable*> stockFermDB;

    static QList<Yeast*> yeastDB;
    static QList<Style*> styleDB;
    static QList<Misc*> miscDB;
    static QList<PrimeSugar*> primeSugarDB;
    static QList<WaterProfile*> waterDB;

    static QString dbName;
    static QString styleFileName;
    static QStringList styleYears;


    Database();
    ~Database();

    static Database &getInstance();
    static QSqlDatabase connectDB();
    static QString lastError();

    static int inDB(Yeast *o);
    static int inDB(Fermentable *o);
    static int inDB(Hop *o);
    static int inDB(Misc *o);
    static int inDB(Style *o);
    static int inDB(PrimeSugar *o);
    static int inDB(WaterProfile *o);

    static bool readDB(QString styleYear);

    static bool readFermentables();
    static bool writeFermentable(Fermentable &f);
    static bool writeFermentables(QList<Fermentable*> replacement);
    static bool writeFermentables();

    static bool readHops();
    static bool writeHop(Hop &h);
    static bool writeHops(QList<Hop*> replacement);
    static bool writeHops();

    static bool readYeast();
    static bool writeYeast();
    static bool writeYeast(Yeast &y);

    static bool readStyles();

    static bool readMisc();
    static bool writeMisc();
    static bool writeMisc(Misc &m);

    static bool readWater();

    static bool readStyleYears();
    static bool importStyles(QString year);

    static bool readPrimeSugar();
    static QStringList getPrimeSugarNameList();
    static PrimeSugar* findSugar(QString name);
    static bool writePrimeSugar(PrimeSugar &p);

    static Fermentable* findFermentable(QString name);
    static Hop *findHop(QString name);
    static Yeast *findYeast(QString name);
    static Misc* findMisc(QString name);
    static Style *findStyle(QString name);

    static void prepareMashProfileInsert(QSqlQuery connection, QString name, int step, int startTempF, int endTempF, int time, QString method);
    static bool setMashProfile(Mash *mash, QString name);
    static bool addMashProfile(Mash *mash, QString name);
    static QStringList getMashProfileNames();


};

#endif // DATABASE_H
