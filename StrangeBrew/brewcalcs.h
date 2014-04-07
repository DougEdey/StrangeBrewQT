#ifndef BREWCALCS_H
#define BREWCALCS_H

#include <math.h>
#include "constants.h"
#include "waterprofile.h"
#include "salt.h"
#include "acid.h"
#include "primesugar.h"

class BrewCalcs
{
public:


    BrewCalcs();
    static double deltaSG(double TempC, double SG);
    static double SGToPlato(double SG);
    static double platoToSG(double plato);
    static double sgToGU(double sg);
    static double guToSG(double gu);
    static double hydrometerCorrection(double tempC, double SG, double refTempC);
    static double brixToSG(double brix);
    static double brixToFG(double ob, double fb);
    static double SGBrixToABV(double sg, double fb);
    static double OBFBtoABV(double ob, double fb);
    static double fToC(double tempF);
    static double cToF(double tempC);
    static double dissolvedCO2(double BottleTemp);
    static double KegPSI(double Temp, double VolsCO2);
    static double PrimingSugarGL(double DisVolsCO2, double TargetVolsCO2, PrimeSugar *sugar);
    static WaterProfile calculateSalts(WaterProfile waterNeeds, double sizeInGal);
    static void updateWater(WaterProfile w, Salt s, double sizeInGal);
    static double calcColour(double lov, QString method);
    static QString calcRGB(int method, double srm, int rConst, int gConst, int bConst, int aConst);
    static double calcTinseth(double amount, double size, double sg, double time, double aa, double HopsUtil);
    static double CalcRager(double amount, double size, double sg, double time, double AA);
    static double CalcGaretz(double amount, double size, double sg, double time, double start_vol, int yeast_flocc, double AA);
    static double calcAlcohol(QString method, double og, double fg);
    static double acidMillequivelantsPerLiter(double pHo, double alko, double pHTarget);
    static double molesByAcid(Acid acid, double millequivs, double pH);
    static double acidAmountPerL(Acid acid, double moles);
    static double sgToBrix(double sg);
#ifdef WIN32
    static int round(double r);
#endif
};

// utilization table for average floc yeast




#endif // BREWCALCS_H
