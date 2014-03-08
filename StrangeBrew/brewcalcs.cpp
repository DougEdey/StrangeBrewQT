#include "brewcalcs.h"

int UTILIZATION[] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 3, 4, 5, 5, 6, 7, 9, 11, 13, 11, 13, 16, 13, 16, 19,
        15, 19, 23, 16, 20, 24, 17, 21, 25};
QString TINSETH = "Tinseth";
QString RAGER = "Rager";
QString GARETZ = "Garetz";
QString ibuMethods[] = {TINSETH, RAGER, GARETZ};

QString EBC = "EBC";
QString SRM = "SRM";
QString colourMethods[] = {EBC, SRM};

QString ALC_BY_WEIGHT = "Weight";
QString ALC_BY_VOLUME = "Volume";
QString alcMethods[] = { ALC_BY_WEIGHT, ALC_BY_VOLUME };

BrewCalcs::BrewCalcs()
{
}

//	 Hydrometer correction formula
double BrewCalcs::deltaSG(double TempC, double SG)
{  // hydrometer correction formula based on post by AJ DeLange
   // in HBD 3701
   double coeffic[][3] = {{56.084,   -0.17885,   -0.13063},    // 0-4.99
                        {69.685,   -1.367,     -0.10621},    // 5 - 9.99
                        {77.782,   -1.7288,    -0.10822},    // 10 - 14.99
                        {87.895,   -2.3601,    -0.10285},    // 15 - 19.99
                        {97.052,   -2.7729,    -0.10596}};   // 20 - 24.99

   double plato = SGToPlato(SG);
   int coefficIndex=4;
   if (plato < 20)
     coefficIndex = 3;
   else
   if (plato < 15)
     coefficIndex = 2;
   if (plato < 10)
     coefficIndex = 1;
   if (plato < 5)
     coefficIndex = 0;

   double deltaSG = (coeffic[coefficIndex][0])
                   + (coeffic[coefficIndex][1] * TempC)
                   + (coeffic[coefficIndex][2] * TempC * TempC);

   // changed + to - from original
   double CorrectedSG = platoToSG(plato - (deltaSG/100));
   return CorrectedSG;

}

double BrewCalcs::SGToPlato(double SG)
{ // function to convert a value in specific gravity as plato
  // equation based on HBD#3204 post by AJ DeLange
  double plato;
  plato = -616.989 + 1111.488*SG - 630.606*SG*SG + 136.10305*SG*SG*SG;
  return plato;
}

double BrewCalcs::platoToSG(double plato)
{  // function to convert a value in Plato to SG
   // equation based on HBD#3723 post by AJ DeLange

   double SG;
   SG = 1.0000131 + 0.00386777*plato + 1.27447E-5*plato*plato + 6.34964E-8*plato*plato*plato;
   return SG;
}

double BrewCalcs::sgToGU(double sg) {
    return (sg - 1) * 1000;
}

double BrewCalcs::guToSG(double gu) {
    return (gu / 1000 ) + 1;
}

double BrewCalcs::hydrometerCorrection(double tempC, double SG, double refTempC)
{
  double correctedSG = 0;
  if (refTempC == 20.0)
    correctedSG = deltaSG(tempC,SG);
  else
    correctedSG = SG * deltaSG(tempC, SG) / deltaSG(refTempC, SG);

  return correctedSG;

}

//	 Refractometer calculations

double BrewCalcs::brixToSG(double brix) {
    // apply the wort correction factor
    brix = brix/1.04;
    double sg =((brix)/(258.6-(((brix)/258.2)*227.1))+1);

  /*double sg = 1.000898 + 0.003859118*brix +
             0.00001370735*brix*brix + 0.00000003742517*brix*brix*brix;*/
  return sg;
}

double BrewCalcs::sgToBrix(double sg) {
    // apply the wort correction factor
    return (((182.4601 * sg -775.6821) * sg +1262.7794) * sg -669.5622);

}

double BrewCalcs::brixToFG(double ob, double fb){
    // apply wort correction
    ob = ob/1.04;
    fb = fb/1.04;
    // ABV from OB and FB
    double fg = 1.0000 - 0.00085683*ob + 0.0034941*fb;

  /*double fg = 1.001843 - 0.002318474*ob -
             0.000007775*ob*ob - 0.000000034*ob*ob*ob +
             0.00574*fb + 0.00003344*fb*fb + 0.000000086*fb*fb*fb;*/
  return fg;
}

double BrewCalcs::SGBrixToABV(double sg, double fb){
//		return ((0.01/0.8192)*((C7/$E$3)-(0.1808*(C7/$E$3)+0.8192*(668.72*H7-463.37-205.347*H7^2)))/(2.0665-0.010665*(C7/$E$3))
    fb = fb/1.04;

    double ri  = 1.33302 + 0.001427193*fb + 0.000005791157*fb*fb;
    double abw = 1017.5596 - (277.4*sg) + ri*((937.8135*ri) - 1805.1228);
    double abv = abw * 1.25;
    return abv;
}

double BrewCalcs::OBFBtoABV(double ob, double fb){

    double cubic = 1.0178;
    double fg = brixToFG(ob, fb);
    fb = fb/1.04;
    ob = ob/1.04;
    double abv = 0.0;
    if(fb == 0.0) {
        qDebug() << "fb is 0.0";
        abv = ((0.01/0.8192)*((ob)-(0.1808*(ob)+0.8192*(668.72*cubic-463.37-205.347*pow(cubic,2))))/(2.0665-0.010665*(ob)));
    }
    else {
        qDebug() << "fb is set";
        abv = (0.01/0.8192)*(ob-(0.1808*(ob)+0.8192*(668.72*fg-463.37-205.347*pow(fg,2))))/(2.0665-0.010665*ob);
    }
    abv = abv*100;
    qDebug() << "OBFB: " << abv;
    return abv;

  /*double ri  = 1.33302 + 0.001427193*fb + 0.000005791157*fb*fb;
  double abw = 1017.5596 - (277.4*sg) + ri*((937.8135*ri) - 1805.1228);
  double abv = abw * 1.25;
  return abv;*/
}


double BrewCalcs::fToC(double tempF) {
    // routine to convert basic F temps to C
    return (5 * (tempF - 32)) / 9;
}

double BrewCalcs::cToF(double tempC) {
    // routine to convert Celcius to Farenheit
    return ((tempC * 9) / 5) + 32;
}

/*
 *  Carbonation calculations	 *
 */

double BrewCalcs::dissolvedCO2(double BottleTemp)
{
    // returns the amount of dissolved CO2 in beer at BottleTemp
    double disCO2 = (1.266789*BottleTemp) + 31.00342576 - (0.0000009243372*
        (sqrt((1898155717178L* pow(BottleTemp,2)) +
        91762600000000L*BottleTemp + 839352900000000L - 1710565000000L*14.5)));
    return disCO2;
}

double BrewCalcs::KegPSI(double Temp, double VolsCO2)
{
    // returns the PSI needed to carbonate beer at Temp at VolsCO2
    double PSI = -16.6999 - (0.0101059 * Temp) + (0.00116512 * pow(Temp,2)) + (0.173354 * Temp * VolsCO2)
        + (4.24267 * VolsCO2) - (0.0684226 * pow(VolsCO2,2));
    return PSI;
}

double BrewCalcs::PrimingSugarGL(double DisVolsCO2, double TargetVolsCO2, PrimeSugar sugar)
{
    // returns the priming sugar in grams/litre needed to
    // carbonate beer w/ a dissolved vols CO2 to reach the target vols CO2
    // based on an article by Dave Draper in the July/August 1996 issue of Brewing Techniques.
    double GramsPerLitre = (TargetVolsCO2 - DisVolsCO2) / 0.286;

    GramsPerLitre /= sugar.getYield();

    return GramsPerLitre;
}

WaterProfile BrewCalcs::calculateSalts(/*std::vector<Salt> salts, */WaterProfile waterNeeds, double sizeInGal) {
    // Start with Epsom and set for Mg
    WaterProfile result;

    if (waterNeeds.getMg() > 0) {
        try {
            Salt epsom = Salt::getSaltByName(MAGNESIUM_SULPHATE);
            epsom.setAmount(waterNeeds.getMg() / epsom.getEffectByChem(MAGNESIUM));
            updateWater(result, epsom, sizeInGal);
        } catch (QString e) {
            qDebug() << e;

        }
    }

    if (waterNeeds.getSo4() > 0 &&
        result.getSo4() < waterNeeds.getSo4()) {
        try {
            Salt gypsum = Salt::getSaltByName(CALCIUM_CARBONATE);
            gypsum.setAmount((waterNeeds.getSo4() - result.getSo4()) / gypsum.getEffectByChem(SULPHATE));
            updateWater(result, gypsum, sizeInGal);
        } catch (QString e) {
            qDebug() << e;
        }
    }

    // This stuff needs work!
    // TODO
    // It shoudl do some sort of itterative process to find ideal levels

    if (waterNeeds.getNa() > 0 &&
        result.getNa() < waterNeeds.getNa()) {
        try {
            Salt salt = Salt::getSaltByName(SODIUM_CHLORIDE);
            salt.setAmount((waterNeeds.getNa() - result.getNa()) / salt.getEffectByChem(SODIUM));
            updateWater(result, salt, sizeInGal);
        } catch (QString e) {
            qDebug() << e;
        }
    }

    if (waterNeeds.getHco3() > 0 &&
        result.getHco3() < waterNeeds.getHco3()) {
        try {
            Salt soda = Salt::getSaltByName(SODIUM_BICARBONATE);
            soda.setAmount((waterNeeds.getHco3() - result.getHco3()) / soda.getEffectByChem(CARBONATE));
            updateWater(result, soda, sizeInGal);
        } catch (QString e) {
            qDebug() << e;
        }
    }

    if (waterNeeds.getCa() > 0 &&
        result.getCa() < waterNeeds.getCa()) {
        try {
            Salt chalk = Salt::getSaltByName(CALCIUM_SULPHATE);
            chalk.setAmount((waterNeeds.getCa() - result.getCa()) / chalk.getEffectByChem(CALCIUM));
            updateWater(result, chalk, sizeInGal);
        } catch (QString e) {
            qDebug() << e;
        }
    }

    if (waterNeeds.getCa() > 0 &&
        result.getCa() < waterNeeds.getCa()) {
        try {
            Salt calChloride = Salt::getSaltByName(CALCIUM_CHLORIDE);
            calChloride.setAmount((waterNeeds.getCa() - result.getCa()) / calChloride.getEffectByChem(CALCIUM));
            updateWater(result, calChloride, sizeInGal);
        } catch (QString e) {
            qDebug() << e;
        }
    }

    return result;
}

void BrewCalcs::updateWater(WaterProfile w, Salt s, double sizeInGal) {
    QList<ChemicalEffect> effs = s.getChemicalEffects();
    for (int i = 0; i < effs.size(); i++) {
        ChemicalEffect eff = effs.at(i);

        if (eff.getElem() == MAGNESIUM) {
            w.setMg((w.getMg() + (eff.getEffect() *  s.getAmount())) * sizeInGal);
        } else if (eff.getElem() == CHLORINE) {
            w.setCl((w.getCl() + (eff.getEffect() *  s.getAmount())) * sizeInGal);
        } else if (eff.getElem() == SODIUM) {
            w.setNa((w.getNa() + (eff.getEffect() *  s.getAmount())) * sizeInGal);
        } else if (eff.getElem() == SULPHATE) {
            w.setSo4((w.getSo4() + (eff.getEffect() *  s.getAmount())) * sizeInGal);
        } else if (eff.getElem() == CARBONATE) {
            w.setHco3((w.getHco3() + (eff.getEffect() *  s.getAmount())) * sizeInGal);
        } else if (eff.getElem() == CALCIUM) {
            w.setCa((w.getCa() + (eff.getEffect() *  s.getAmount())) * sizeInGal);
        } else if (eff.getElem() == HARDNESS) {
            w.setHardness((w.getHardness() + (eff.getEffect() *  s.getAmount())) * sizeInGal);
        } else if (eff.getElem() == ALKALINITY) {
            w.setAlkalinity((w.getAlkalinity() + (eff.getEffect() * s.getAmount())) * sizeInGal);
        }
    }
}


double BrewCalcs::calcColour(double lov, QString method) {
    double colour = 0;

    // SRM
    colour = pow(lov, 0.6859) * 1.4922;

    if (method.compare(EBC, Qt::CaseInsensitive) == 0) {
        // Updaed

        colour *=  1.97;
    }

    if (lov < 0) {
        colour = 0;
    }

    return colour;

}

// RGB estimation:
QString BrewCalcs::calcRGB(int method, double srm, int rConst, int gConst, int bConst,
        int aConst) {
    // estimates the RGB equivalent colour for beer based on SRM
    // NOTE: optRed, optGreen and optBlue need to be adjusted for different
    // monitors.
    // This is from the Windows version of SB
    // typical values are: r=8, g=30, b=20

    if (method == 1) {

        int R = 0, G = 0, B = 0, A = aConst;

        if (srm < 10) {
            R = 255;
        } else {
            R = 255 - ((srm - rConst) * 10);
        }

        if (gConst != 0)
            G = 250 - ((srm / gConst) * 250);
        else
            G = 250 - ((srm / 30) * 250);

        B = 200 - (srm * bConst);

        if (R < 0)
            R = 1;
        if (G < 0)
            G = 1;
        if (B < 0)
            B = 1;

        return QString::number(R) + ", " + QString::number(G) + ", " + QString::number(B) + ", " + QString::number(A);

    } else {
        // this is the "new" way, based on rbg screen samples from Gibby
        double R, G, B;

        if (srm < 11) {
            R = 259.13 + -7.42 * srm;
            G = 278.87 + -15.12 * srm;
            B = 82.73 + -4.48 * srm;
        } else if (srm >= 11 && srm < 21) {
            R = 335.27 + -11.73 * srm;
            G = 203.42 + -7.58 * srm;
            B = 92.50 + -2.90 * srm;
        } else {
            R = 220.20 + -7.20 * srm;
            G = 109.42 + -3.42 * srm;
            B = 50.75 + -1.33 * srm;
        }

        int r = round(R);
        int b = round(B);
        int g = round(G);

        if (r < 0)
            r = 0;
        if (r > 255)
            r = 255;
        if (g < 0)
            g = 0;
        if (g > 255)
            g = 255;
        if (b < 0)
            b = 0;
        if (b > 255)
            b = 255;

        return QString::number(r) + ", " + QString::number(g) + ", " + QString::number(b) + ", " + QString::number(aConst);
    }
}

/*
 * Hop IBU calculation methods:
 */
double BrewCalcs::calcTinseth(double amount, double size, double sg, double time, double aa,
        double HopsUtil) {
    double daautil; // decimal alpha acid utilization
    double bigness; // bigness factor
    double boil_fact; // boil time factor
    double mgl_aaa; // mg/l of added alpha units
    double ibu;

    bigness = 1.65 * (pow(0.000125, (sg - 1))); // 0.000125 original
    boil_fact = (1 - (exp(-0.04 * time))) / HopsUtil;
    daautil = bigness * boil_fact;
    mgl_aaa = (aa / 100) * amount * 7490 / size;
    ibu = daautil * mgl_aaa;
    return ibu;
}

// rager method of ibu calculation
// constant 7962 is corrected to 7490 as per hop faq
double BrewCalcs::CalcRager(double amount, double size, double sg, double time, double AA) {
    double ibu, utilization, ga;
    utilization = 18.11 + 13.86 * tanh((time - 31.32) / 18.27);
    ga = sg < 1.050 ? 0.0 : ((sg - 1.050) / 0.2);
    ibu = amount * (utilization / 100) * (AA / 100.0) * 7490;
    ibu /= size * (1 + ga);
    return ibu;
}



double BrewCalcs::CalcGaretz(double amount, double size, double sg, double time, double start_vol,
        int yeast_flocc, double AA) {
    // iterative value seed - adjust to loop through value
    double desired_ibu = CalcRager(amount, size, sg, time, AA);
    int elevation = 500; // elevation in feet - change for user setting
    double concentration_f = size / start_vol;
    double boil_gravity = (concentration_f * (sg - 1)) + 1;
    double gravity_f = ((boil_gravity - 1.050) / 0.2) + 1;
    double temp_f = (elevation / 550 * 0.02) + 1;

    // iterative loop, uses desired_ibu to define hopping_f, then seeds
    // itself
    double hopping_f, utilization, combined_f;
    double ibu = desired_ibu;
    int util_index;
    for (int i = 0; i < 5; i++) { // iterate loop 5 times
        hopping_f = ((concentration_f * desired_ibu) / 260) + 1;
        if (time > 50)
            util_index = 10;
        else
            util_index = (int) (time / 5.0);
        utilization = UTILIZATION[(util_index * 3) + yeast_flocc];
        combined_f = gravity_f * temp_f * hopping_f;
        ibu = (utilization * AA * amount * 0.749) / (size * combined_f);
        desired_ibu = ibu;
    }

    return ibu;
}

// Alcohol calculations
double BrewCalcs::calcAlcohol(QString method, double og, double fg) {
    double alc = 0;

    if (method == "" ||
        method == ALC_BY_WEIGHT) {
        double oPlato = BrewCalcs::SGToPlato(og);
        double fPlato = BrewCalcs::SGToPlato(fg);
        double q = 0.22 + 0.001 * oPlato;
        double re = (q * oPlato + fPlato) / (1.0 + q);
        // calculate by weight:
        alc = (oPlato - re) / (2.0665 - 0.010665 * oPlato);
    } else if (method == ALC_BY_VOLUME) {
        alc = calcAlcohol(ALC_BY_WEIGHT, og, fg) * fg / 0.794;
    }

    return alc;
}

// Acid calcs
// From http://hbd.org/brewery/library/AcidifWaterAJD0497.html by A.J. deLange
//
// Determines acid millequivelants per liter needed to alter ph to target
double BrewCalcs::acidMillequivelantsPerLiter(double pHo, double alko, double pHTarget) {
    // Compute the mole fractions of carbonic (f1o), bicarbonate (f2o) and carbonate(f3o)
    // at the water sample's pH
    double r1o = pow(10, pHo - 6.38);
    double r2o = pow(10, pHo - 10.33);
    double d_o = 1 + r1o + (r1o * r2o);
    double f1o = 1 / d_o;
    //double f2o = r1o / d_o;
    double f3o = r1o * r2o / d_o;

    // Compute the mole fractions at pHb = 4.3 (the pH which defines alkalinity).
    double pHb = 4.3;
    double r1b = pow(10, pHb - 6.38);
    double r2b = pow(10, pHb - 10.33);
    double db = 1 + r1b + (r1b * r2b);
    double f1b = 1 / db;
    //double f2b = r1b / db;
    double f3b = r1b * r2b / db;

    // Convert the sample alkalinity (in ppm CoCO3 to milliequivalents/L
    double alk = alko / 50;
    double Ct = alk / ((f1b - f1o) + (f3o - f3b));

    // Compute mole fractions at desired pH (example: pH 5)
    double r1c = pow(10, pHTarget - 6.38);
    double r2c = pow(10, pHTarget - 10.33);
    double dc = 1 + r1c + r1c*r2c;
    double f1c = 1 / dc;
    //double f2c = r1c / dc;
    double f3c = r1c * r2c / dc;

    // Use these to compute the milliequivalents acid required per liter (mEq/L)
    double acidMillies = Ct * (  ( f1c - f1o) + (f3o - f3c) ) +
                pow(10, -pHTarget) - pow(10, -pHo);

    return acidMillies;
}

// Determines moles of given acid required to shift to target ph given amount of acid millieuivelants
double BrewCalcs::molesByAcid(Acid acid, double millequivs, double pH) {
    double r1d = pow(10, pH - acid.getPK1());
    double r2d = pow(10, pH - acid.getPK2());
    double r3d = pow(10, pH - acid.getPK3());
    double dd = 1/(1 + r1d + (r1d * r2d) + (r1d * r2d * r3d));
    //double f1d = dd;
    double f2d = r1d * dd;
    double f3d = r1d * r2d * dd;
    double f4d = r1d * r2d * r3d * dd;
    double frac = f2d + (2 * f3d) + (3 * f4d);
    double moles = millequivs / frac;

    return moles;
}

// Determines weight or volume of acid in ml or mg from moles
double BrewCalcs::acidAmountPerL(Acid acid, double moles) {
    double amnt = moles * acid.getMolWt();
    if (acid.isLiquid()) {
        amnt = amnt / acid.getMgPerL();
    }

    return amnt;
}
