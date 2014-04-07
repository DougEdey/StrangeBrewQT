#ifndef RECIPE_H
#define RECIPE_H

#include <QObject>
#include <QString>
#include <QSettings>
#include <QList>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QPushButton>


#include <vector>

#include "ingredient.h"
#include "misc.h"
#include "hop.h"
#include "fermentable.h"
#include "yeast.h"
#include "primesugar.h"
#include "quantity.h"
#include "options.h"
#include "mash.h"
#include "style.h"
#include "fermentstep.h"
#include "note.h"
#include "waterprofile.h"
#include "salt.h"
#include "acid.h"
#include "brewcalcs.h"
#include "sbstringutils.h"
#include "database.h"
#include "mashstep.h"

using namespace std;

class Recipe: public QObject
{
    Q_OBJECT

public:
    Recipe(QObject *parent = 0);

    double getAlcohol() const;
    QString getAlcMethod() const;
    double getAttenuation() const;
    int getBoilMinutes() const;
    QString getBottleU() const;
    double getBottleSize() const;
    double getBUGU() const;
    QString getBrewer() const;
    QString getComments() const;
    double getColour();
    double getMcu();
    double getColour(QString method);
    QString getColourMethod() const;
    QDate getCreated() const;
    double getEfficiency() const;
    double getEstOg() const;
    double getEstFg() const;
    double getEvap() const;
    QString getEvapMethod() const;
    Mash *getMash();
    double getIbu() const;
    QString getIBUMethod() const;
    QString getMaltUnits();
    QString getName() const;
    double getOtherCost() const;
    double getPelletHopPct() const;
    double getKettleLoss(QString s) const;
    double getMiscLoss(QString s) const;
    double getTotalWaterVol(QString s);
    double getChillShrinkVol(QString s) const;
    double getPreBoilVol(QString s) const;
    double getFinalWortVol() const;
    Quantity getPostBoilVol() const;
    double getPostBoilVol(QString s) const;
    double getTrubLoss(QString s) const;
    double getEvapVol(QString s) const;
    QString getVolUnits() const;
    double getSparge();
    QString getStyle() const;
    Style *getStyleObj() const;
    double getTotalHopsOz() const;
    double getTotalHops() const;
    double getTotalHopsCost() const;
    double getTotalMaltCost() const;
    double getTotalMashLbs() const;
    double getTotalMash() const;
    double getTotalMaltLbs() ;
    double getTotalMalt() const;
    double getTotalMiscCost() const;
    QString getYeast() const;
    Yeast *getYeastObj();
    bool getDirty() const;
    void setDirty(bool d);
    void setAllowRecalcs(bool b);
    void setAlcMethod(QString s);
    void setBoilMinutes(int b);
    void setBottleSize(double b);
    void setBottleU(QString u);
    void setBrewer(QString b);
    void setComments(QString c);
    void setColourMethod(QString c);
    void setCreated(QDate d);
    void setEvap(double e);
    void setEvapMethod(QString e);
    void setHopsUnits(QString h);
    void setIBUMethod(QString s);
    void setKettleLoss(double d);
    void setMaltUnits(QString m);
    void setMashed(bool m);
    void setMashed(QString m);
    void setMashRatio(double m);
    void setMashRatioU(QString u);
    void setMiscLoss(Quantity m);
    void setName(QString n);
    void setOtherCost(double c);
    void setPelletHopPct(double p);
    void setStyle(QString s);
    void setStyle(Style *s);
    void setTrubLoss(Quantity t);
    void setYeastName(QString s);
    void setYeast(Yeast *y);
    int getFermentStepSize() const;
    QString getFermentStepType(int i);
    void setVersion(QString v);
    int getFermentStepTime(int i) const;
    double getFermentStepTemp(int i) const;
    QString getFermentStepTempU(int i) const;
    FermentStep getFermentStep(int i) const;
    int getTotalFermentTime() const;
    void setFermentStepType(int i, QString s);
    void setFermentStepTime(int i, int t);
    void setFermentStepTemp(int i, double d);
    void setFermentStepTempU(int i, QString s);
    void addFermentStep(FermentStep fs);
    FermentStep delFermentStep(int i);
    void calcFermentTotals();
    QString getHopUnits() const;
    Hop *getHop(int i) const;
    int getHopsListSize() const;
    QString getHopName(int i) const;
    QString getHopType(int i) const;
    double getHopAlpha(int i) const;
    QString getHopUnits(int i) const;
    QString getHopAdd(int i) const;
    int getHopMinutes(int i) const;
    double getHopIBU(int i) const;
    double getHopCostPerU(int i) const;
    double getHopAmountAs(int i, QString s) const;
    QString getHopDescription(int i) const;
    void setHopUnits(int i, QString u);
    void setHopName(int i, QString n);
    void setHopType(int i, QString t);
    void setHopAdd(int i, QString a);
    void setHopAlpha(int i, double a);
    void setHopMinutes(int i, int m);
    void setHopCost(int i, QString c);
    void setHopAmount(int i, double a);
    Fermentable *getFermentable(int i);
    int getMaltListSize() const;
    QString getMaltName(int i) const;
    QString getMaltUnits(int i) const;
    double getMaltPppg(int i) const;
    double getMaltLov(int i) const;
    double getMaltCostPerU(int i) const;
    double getMaltCostPerUAs(int i, QString s) const;
    double getMaltPercent(int i) const;
    double getMaltAmountAs(int i, QString s) const;
    QString getMaltDescription(int i) const;
    bool getMaltMashed(int i) const;
    bool getMaltSteep(int i) const;
    bool getMaltFerments(int i) const;
    void setMaltName(int i, QString n);
    void setMaltUnits(int i, QString u);
    void setMaltAmount(int i, double a);
    void setMaltAmountAs(int i, double a, QString u);
    void setMaltPppg(int i, double p);
    void setMaltLov(int i, double l);
    void setMaltCost(int i, QString c);
    void setMaltCost(int i, double c);
    void setMaltPercent(int i, double p);
    void setMaltSteep(int i, bool c);
    void setMaltMashed(int i, bool c);
    void setMaltFerments(int i, bool c);
    int getMiscListSize() const;
    Misc *getMisc(int i) const;

    QString getMiscName(int i) const;
    void setMiscName(int i, QString n);
    double getMiscAmount(int i) const;
    void setMiscAmount(int i, double a);
    QString getMiscUnits(int i) const;
    void setMiscUnits(int i, QString u);
    double getMiscCost(int i) const;
    void setMiscCost(int i, double c);
    QString getMiscStage(int i);
    void setMiscStage(int i, QString s);
    int getMiscTime(int i);
    void setMiscTime(int i, int t);
    QString getMiscDescription(int i) const;
    void setMiscComments(int i, QString c);
    QString getMiscComments(int i);
    Note getNote(int i) const;
    int getNotesListSize() const;
    QDate getNoteDate(int i) const;
    void setNoteDate(int i, QDate d);
    QString getNoteType(int i);
    void setNoteType(int i, QString t);
    QString getNoteText(int i) const;
    void setNoteNote(int i, QString n);
    void setVolUnits(QString v);
    void setReadVolUnits(QString v);
    void setEstFg(double f);
    void setEstOg(double o);
    void setEfficiency(double e);
    void setAttenuation(double a);
    void setPreBoil(double u);
    void setPostBoil(Quantity p);
    void setFinalWortVol(Quantity p);
    Fermentable *addMalt(Fermentable *m);
    void delMalt(int i);
    Hop *addHop(Hop *h);
    void delHop(int i);
    Misc* addMisc(Misc *m);
    void delMisc(int i);
    void calcMiscCost();
    void addNote(Note n);
    void delNote(int i);
    void setAmountAndUnits(QString a);
    void calcEfficiency();
    void calcMaltTotals();
    void calcHopsTotals();
    QString addXMLHeader(QString in);
    QString toXML(QString printOptions);
    QString padLeft(QString str, int fullLength, QChar ch) const;
    QString padRight(QString str, int fullLength, QChar ch) const;
    QString buildString(char ch, int length) const;
    QString toText();
    QString toText(bool detailed);
    void scaleRecipe(Quantity newSize);
    double getBottleTemp();
    void setBottleTemp(double bottleTemp);
    QString getCarbTempU() const;
    void setCarbTempU(QString carbU);
    bool isKegged() const;
    void setKegged(bool kegged);
    void setKegged(QString f);
    double getKegPSI() const;
    void setKegPSI(double psi);
    double getKegTubeLength() const;
    double getKegTubeVol();
    double getKegTubeHeight() const;
    QString getKegTubeID() const;
    QString getPrimeSugarName() const;
    QString getPrimeSugarU() const;
    void setPrimeSugarU(QString primeU);
    double getPrimeSugarAmt() const;
    void calcPrimeSugar();
    void calcKegPSI();
    void setPrimeSugarName(QString n);
    void setPrimeSugarAmount(double q);
    double getServTemp() const;
    void setServTemp(double serv);
    double getTargetVol() const;
    void setTargetVol(double target);
    PrimeSugar *getPrimeSugar() const;
    void setPrimeSugar(PrimeSugar *primeSugar);
    WaterProfile getSourceWater() const;
    WaterProfile getTargetWater() const;
    void setSourceWater(WaterProfile sourceWater);
    void setTargetWater(WaterProfile targetWater);
    WaterProfile getWaterDifference();
    void addSalt(Salt s);
    void delSalt(Salt s);
    void delSalt(int i);
    void setSalts(QList<Salt> s);
    QList<Salt> getSalts();
    Salt getSalt(int i) const;
    Salt getSaltByName(QString name) const;
    Acid getAcid() const;
    void setAcid(Acid acid);
    double getAcidAmount();
    double getAcidAmount5_2();
    void substractIngredients();
    bool pushRecipe();
    void replaceHop(int &i, Hop *h);

    QList<Hop *> *getHopList();
    QList<Fermentable *> *getMaltList();
    QList<Misc *> *getMiscList();
    QList<FermentStep> *getFermentStepsList();
    QList<MashStep> *getMashStepsList();
    QList<Note> *getNotes();

    double getPreBoilVol() const;
    void addHop();
    void addMalt();
   // ~Recipe();
    void replaceMisc(int &i, Misc *m);
    Misc *getMiscPtr(int i) const;
    void setKegTubeID(QString id);
    void setKegTubeHeight(double height);
    QString getFinalWortVolStr();
    void setPrimeSugar(QString prime);
    double getFinalWortVol(QString s) const;
    void setMiscLoss(double d);
    double getTotalWaterVol();
    void setPostBoil(double p);
    void setFinalWortVol(double p);
    void setTrubLoss(double d);
    void setKettleLoss(Quantity q);
    QString getVolUnitsAbrv() const;
    double getIBUHopUtil() const;
    void setIBUHopUtil(double d);
    void setFileName(QString f);
    QString getFileName();

    QString getPreBoilVolStr() const;
    QString getMiscLossStr() const;
    QString getKettleLossStr() const;
    QString getTotalWaterStr();
    QString getTrubLossStr() const;
    void setPreBoil(Quantity p);
    QString getFilePath();
    QString getFullFileName();

    bool sendMashToElsinore();


    void sendMashProfile(QUrl url, QString output);
private:
    // Basics
    QNetworkAccessManager *nam = NULL;
    QFileInfo fileinfo;
    QString version;
    QString filename;
    bool isDirty;
    bool allowRecalcs;
    bool mashed;

    double attenuation;
    int boilMinutes;
    QString brewer;
    QString comments;
    QDate created;
    double efficiency;
    double estOg;
    double estFermOg; // Used to take into account the non fermentables
    double estFg;
    double evap;
    double ibu;

    QString name;
    Style *style;
    Yeast *yeast;
    WaterProfile sourceWater;
    WaterProfile targetWater;
    QList<Salt> brewingSalts;
    Acid acid;
    Mash mash;

    // water use:
    Quantity postBoilVol;
    Quantity kettleLossVol;
    Quantity trubLossVol;
    Quantity miscLossVol;
    // this could be user-configurable:
    QVariant chillPercent;

    // Carbonation
    QVariant bottleTemp;
    QVariant servTemp;
    QVariant targetVol;
    PrimeSugar *primeSugar;
    QVariant carbTempU;
    bool kegged;
    QVariant kegPSI;
    QVariant kegTubeID;
    QVariant kegTubeHeight;

    // options:
    QVariant colourMethod;
    QVariant hopUnits;
    QVariant maltUnits;
    QVariant ibuCalcMethod;
    QVariant evapMethod;
    QVariant alcMethod;
    QVariant bottleU;

    QVariant bottleSize;
    QVariant otherCost;
    QVariant ibuHopUtil;
    QVariant pelletHopPct;

    // Hop Related timings
    QVariant fwhTime;
    QVariant dryHopTime;
    QVariant mashHopTime;

    // totals:
    QVariant totalMaltCost;
    QVariant totalHopsCost;
    QVariant totalMiscCost;
    QVariant totalMaltLbs;
    QVariant totalHopsOz;
    QVariant totalMashLbs;
    QVariant totalFermentTime;

    // ingredients
    QList<Hop*> hops;
    QList<Fermentable*> fermentables;
    QList<Misc*> misc;
    QList<FermentStep> fermentationSteps;
    // notes
    QList<Note> notes;

private slots:
    void validateElsinoreFinished(QNetworkReply*);
    void mashProfileSent(QNetworkReply *networkReply);
};


#endif // RECIPE_H
