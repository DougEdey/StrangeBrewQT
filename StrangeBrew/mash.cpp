#include "mash.h"


QString QT_PER_LB = "qt/lb";
QString L_PER_KG = "l/kg";
QString ACID = "acid";
QString GLUCAN = "glucan";
QString PROTEIN = "protein";
QString BETA = "beta";
QString ALPHA = "alpha";
QString MASHOUT = "mashout";
QString SPARGE = "sparge";
QString INFUSION = "infusion";
QString DECOCTION = "decoction";
QString DECOCTION_THICK = "decoction thick";
QString DECOCTION_THIN = "decoction thin";
QString DIRECT = "direct";
QString CEREAL_MASH = "cereal mash";
QString FLY = "fly";
QString BATCH = "batch";

QStringList mash_ratioUnits = QStringList() << QT_PER_LB << L_PER_KG;
QStringList mash_types = QStringList() << ACID << GLUCAN << PROTEIN << BETA << ALPHA << MASHOUT << SPARGE;
QStringList mash_methods = QStringList() << INFUSION << DECOCTION << DECOCTION_THICK << DECOCTION_THIN << DIRECT << CEREAL_MASH;
QStringList mash_spargeMethods = QStringList() << FLY << BATCH;


Mash::Mash()
{
    totalTime = 0.0;

    absorbedQTS = 0.0;
    preBoilQts = 0.0;
     QSettings opts("Doug Edey", "StrangeBrew");
     mashRatio = opts.value("Mash/Ratio").toDouble();
     mashRatioU = opts.value("Mash/RatioU").toString();
     tempUnits = opts.value("Mash/TempU").toString();

     volUnits = opts.value("Mash/VolU").toString();
     volQts = 0.0;
     spargeQTS = 0.0;

     grainTempF = opts.value("Mash/GrainTemp").toDouble();
     boilTempF = opts.value("Mash/BoilTempF").toDouble();

     ACIDTMPF = opts.value("MashSteps/AcidTmpF", 85).toDouble();
     GLUCANTMPF = opts.value("MashSteps/GlucanTmpF", 95).toDouble();
     PROTEINTMPF = opts.value("MashSteps/ProteinTmpF", 113).toDouble();
     BETATMPF = opts.value("MashSteps/BetaTmpF", 131).toDouble();
     ALPHATMPF = opts.value("MashSteps/AlphaTmpF", 151).toDouble();
     MASHOUTTMPF = opts.value("MashSteps/MashoutTmpF", 161).toDouble();
     SPARGETMPF = opts.value("MashSteps/SpargeTmpF", 170).toDouble();
     cerealMashTemp = opts.value("MashSteps/CerealMashTmpF").toDouble();

     thickDecoctRatio = opts.value("Mash/ThickDecoctRatio").toDouble();
     thinDecoctRatio = opts.value("Mash/ThinDecoctRatio").toDouble();

     deadSpace.setAmount(opts.value("Mash/DeadSpace").toDouble());
     deadSpace.setUnits(volUnits);

     tunLossF = opts.value("Mash/TunLossF", "0").toDouble();
     name = "Mash";
     allowRecalcs = true;

}

void Mash::setSpargeTempF(double d) {
    SPARGETMPF = d;
}

void Mash::setMashoutTempF(double d) {
    MASHOUTTMPF = d;
}

void Mash::setMaltUnits(QString newUnits) {
    if (Quantity::validWeight(newUnits)) {
        this->maltUnits = newUnits;
    }
}

void Mash::addStep(QString type, double st, double et, QString m, int min,
        int rmin, double weight) {
    MashStep step(type, st, et, m, min, rmin);
    if (m == CEREAL_MASH)
        step.setWeightLbs(weight);
    steps.append(step);
    qDebug() << "Added Mash step for " << type << " : " << steps.size();
    calcMashSchedule();
}

int Mash::addStep(){
    MashStep step;
    // calcStepType(temp);

    if (!steps.empty()) {
        MashStep *lastStep = &steps[steps.size() -1];
        step.setStartTemp(lastStep->getEndTemp() + 1);
        step.setEndTemp(step.getStartTemp());
        step.setType(calcStepType(step.getStartTemp()));
    }

    steps.append(step);
    int i = steps.size();
    calcMashSchedule();
    // return the index of the last added step:
    return i-1;

}

void Mash::delStep(int i){
    if (steps.size()>i && !steps.empty() && i > -1){
        steps.erase(steps.begin()+i);
        calcMashSchedule();
    }

}

// set methods:
// public void setMaltWeight(double mw) {	maltWeightLbs = mw;	}
void Mash::setMashRatio(double mr){
    mashRatio = mr;
    calcMashSchedule();
}

double Mash::getMashRatio(){
    return mashRatio;
}

void Mash::setMashRatioU(QString u){
    mashRatioU = u;
    calcMashSchedule();
}

QString Mash::getMashRatioU(){
    return mashRatioU;
}

void Mash::setMashVolUnits(QString u){
    volUnits = u;
    calcMashSchedule();
}

void Mash::setMashTempUnits(QString t){
    tempUnits = t;
    calcMashSchedule();
}

// TODO hardcoded temp strings should be a static somewhere
void Mash::setGrainTemp(double t){
    if (tempUnits == "F")
        grainTempF = t;
    else
        grainTempF = BrewCalcs::cToF(t);
    calcMashSchedule();
}

void Mash::setBoilTemp(double t){
    qDebug() << tempUnits << " value " << t;
    if (tempUnits == "F")
        boilTempF = t;
    else
        boilTempF = BrewCalcs::cToF(t);
    calcMashSchedule();
}

void Mash::setTunLoss(double t){
    if (tempUnits == "F")
        tunLossF = t;
    else
        tunLossF = t * 1.8;
    calcMashSchedule();
}

void Mash::setDeadSpace(double d) {
    deadSpace.setAmount(d);
}

double Mash::getDeadSpace() {
    return deadSpace.getValue();
}

void Mash::setDecoctRatio(QString type, double r){
    if (type == DECOCTION_THICK)
        thickDecoctRatio = r;
    else
        thinDecoctRatio = r;
    calcMashSchedule();
}



void Mash::setName(QString s) { name = s; }

/**
 *
 * @param val Value to convert to a string
 * @return Val converted to the mash vol, formated to 1 decimal
 */
QString Mash::getVolConverted(double val){
    double d = Quantity::convertUnit(CONVERTER_QT, volUnits, val);
    QString s = SBStringUtils::format(d, 1);
    return s;
}

// get methods:
QString Mash::getMashVolUnits(){ return volUnits; }
QString Mash::getMashVolUnitsAbrv(){ return Quantity::getAbrvFromUnit("vol", volUnits); }
QString Mash::getMashTempUnits(){ return tempUnits; }
int Mash::getMashTotalTime(){ return totalTime; }

double Mash::getGrainTemp() {
    if (tempUnits == "F")
    {return grainTempF;}
    else
    {       return BrewCalcs::fToC(grainTempF);}
}

double Mash::getBoilTemp() {
    if (tempUnits == "F")
    {    return boilTempF;}
    else
    {return BrewCalcs::fToC(boilTempF);}
}

double Mash::getTempRange(QString type){
    double t=0;
    if (type == MASHOUT)
        t = MASHOUTTMPF;
    else if (type == SPARGE)
        t = SPARGETMPF;
    if (tempUnits == "C")
        t = BrewCalcs::fToC(t);

    return t;
}

double Mash::getSpargeVol(){
    return Quantity::convertUnit(CONVERTER_QT, volUnits, spargeQTS);
}

double Mash::getSpargeQts(){ return spargeQTS; }

double Mash::getTunLoss() {
    if (tempUnits == "F")
        return tunLossF;
    else
        return ( tunLossF / 1.8 );
    }

/**
 *
 * @return A string, which is the total converted to the mash units
 * + the units.
 */
QString Mash::getMashTotalVol() {
    double d = Quantity::convertUnit(CONVERTER_QT, volUnits, volQts);
    QString s = SBStringUtils::format(d, 1);
    return s;
}

QString Mash::getAbsorbedStr() {
    return getVolConverted(absorbedQTS);
}
double Mash::getAbsorbedQts() {
    return absorbedQTS;
}

QString Mash::getTotalWaterStr() {
    return getVolConverted(totalWaterQTS);
}
double Mash::getTotalWaterQts() {
    return totalWaterQTS;
}
double Mash::getThickDecoctRatio() {
    return thickDecoctRatio;
}
double Mash::getThinDecoctRatio() {
    return thinDecoctRatio;
}

QString Mash::getName(){ return name; }

QString Mash::getTempUnits() { return tempUnits; }
void Mash::setTempUnits(QString t) {
    tempUnits = t;
}

int Mash::getTotalTime() { return totalTime; }

double Mash::getTotalWeight() {
    return Quantity::convertUnit(CONVERTER_LB, this->maltUnits, maltWeightLbs);
}

// mash step methods:
int Mash::setStepType(int i, QString t){
    if (steps.size() < i || steps.empty())
        return -1;
    MashStep *ms = &steps[i];
    ms->setType(t);
    ms->setStartTemp(calcStepTemp(t));
    ms->setEndTemp(calcStepTemp(t));
    return 0;
}

QString Mash::getStepType(int i) {
    if (steps.size() < i || steps.empty())
        return "";
    MashStep ms = steps.at(i);
    return ms.getType();
}


QString Mash::getStepDirections(int i){
    return steps.at(i).getDirections();
}

void Mash::setStepMethod(int i, QString m){
    (&steps[i])->setMethod(m);

    if (m == CEREAL_MASH)
        (&steps[i])->setWeightLbs(0);
    calcMashSchedule();
}

QString Mash::getStepMethod(int i) const {
    return steps[i].getMethod();
}

void Mash::setStepStartTemp(int i, double t){
    if (tempUnits == "C"){
        t = BrewCalcs::cToF(t);
    }
    setStepStartTempF(i, t);
}

void Mash::setStepStartTempF(int i, double t){
    if (tempUnits == "C"){
        t = BrewCalcs::cToF(t);
    }
    MashStep *ms = &steps[i];
    ms->setStartTemp(t);
    double tLoss = getTunLoss() * (ms->getMinutes()/60);
    ms->setEndTemp(t - tLoss);
    ms->setType(calcStepType(t));

    calcMashSchedule();
}

double Mash::getStepStartTemp(int i) {
    if (tempUnits == "C")
        return BrewCalcs::fToC(steps.at(i).getStartTemp());
    else
        return steps.at(i).getStartTemp();
}

double Mash::getStepStartTempF(int i) {
    return steps.at(i).getStartTemp();
}

void Mash::setStepEndTemp(int i, double t){
    if (i == 0) {
        return;
    }
    MashStep *ms = &steps[i];
    if (tempUnits == "C")
        ms->setEndTemp(BrewCalcs::cToF(t));
    else
        ms->setEndTemp(t);
    calcMashSchedule();
}

void Mash::setStepEndTempF(int i, double t){
    if (i == 0) {
        return;
    }
    (&steps[i])->setEndTemp(t);
    calcMashSchedule();
}

double Mash::getStepEndTemp(int i) {
    if (tempUnits == "C")
        return BrewCalcs::fToC(steps.at(i).getEndTemp());
    else
        return steps.at(i).getEndTemp();
}

double Mash::getStepEndTempF(int i) {
    return steps.at(i).getEndTemp();
}

void Mash::setStepRampMin(int i, int m){
    (&steps[i])->setRampMin(m);
}

int Mash::getStepRampMin(int i) {
    return steps.at(i).getRampMin();
}

double Mash::getStepTemp(int i) {
    if (steps.at(i).getStrikeTemp() == 0)
        return 0;
    if (tempUnits == "F")
        return steps.at(i).getStrikeTemp();
    else
        return BrewCalcs::fToC(steps.at(i).getStrikeTemp());
}

double Mash::getStepWeight(int i) {
    double w = 	steps.at(i).getWeightLbs();
    return Quantity::convertUnit(CONVERTER_LB, this->maltUnits, w);

}

void Mash::setStepWeight(int i, double w){
    // you can only set the weight on a cereal mash step
    MashStep *s = (&steps[i]);
    if (s->getMethod() == CEREAL_MASH){
        double w2 = Quantity::convertUnit(this->maltUnits, CONVERTER_LB, w);
        s->setWeightLbs(w2);
        calcMashSchedule();
    }
}

void Mash::setStepMin(int i, int m){
    (&steps[i])->setMinutes(m);
}

int Mash::getStepMin(int i) {
    return steps.at(i).getMinutes();
}

double Mash::getStepInVol(int i) {
    double vol = steps[i].getInVol()->getValue();
    return Quantity::convertUnit(CONVERTER_QT, volUnits, vol);
}

double Mash::getStepOutVol(int i) {
    double vol = steps[i].getOutVol()->getValue();
    return Quantity::convertUnit(CONVERTER_QT, volUnits, vol);
}

void Mash::clear() {
    steps.clear();
}

int Mash::getStepSize() const {
    return steps.size();
}

void Mash::enableRecalcs() {
    this->allowRecalcs = true;
}

void Mash::disableRecalcs() {
    this->allowRecalcs = false;
}

void Mash::setMaltWeightLbs(double weight) {
    this->maltWeightLbs = weight;
}

double Mash::getMaltWeightLbs() {
    return this->maltWeightLbs;
}

void Mash::setPreBoil(Quantity in) {
    // we want this as a QT value
    this->preBoilQts = in.getValueAs(CONVERTER_QT);
}

// Introducing: the big huge mash calc method!

void Mash::calcMashSchedule() {
    // Method to run through the mash table and calculate values
    if (!this->allowRecalcs) {
        return;
    }

    double strikeTemp = 0;
    double targetTemp = 0;
    double waterAddedQTS = 0;
    double waterEquiv = 0;
    double mr = mashRatio;
    double currentTemp = getGrainTemp();

    double displTemp = 0;
    double tunLoss; // figure out a better way to do this, eg: themal mass
    double decoct = 0;
    int totalMashTime = 0;
    int totalSpargeTime = 0;
    double mashWaterQTS = 0;
    double mashVolQTS = 0;
    int numSparge = 0;
    double totalWeightLbs = 0;
    double totalCerealLbs = 0;


    // convert mash ratio to qts/lb if in l/kg
    if (mashRatioU.compare(L_PER_KG) == 0) {
        mr *= 0.479325;
    }

    // convert CurrentTemp to F
    if (tempUnits == "C") {
        currentTemp = BrewCalcs::cToF(currentTemp);
        tunLoss = tunLossF * 1.8;
    }
    else
        tunLoss = tunLossF;

    // perform calcs on first record
    if (steps.empty())
        return;

    // sort the list
    //Collections.sort(steps);

    // add up the cereal mash lbs
    for (int i = 1; i < steps.size(); i++) {
        MashStep *stp = &steps[i];
        if (stp->getMethod() == "cereal mash"){
            totalCerealLbs += stp->getWeightLbs();
        }
    }
    totalWeightLbs = maltWeightLbs - totalCerealLbs;


    // the first step is always an infusion
    MashStep *stp = &steps[0];
    targetTemp = stp->getStartTemp();
    strikeTemp = calcStrikeTemp(targetTemp, currentTemp, mr, tunLoss);
    waterAddedQTS = mr * totalWeightLbs;
    waterEquiv = totalWeightLbs * (0.192 + mr);
    mashVolQTS = calcMashVol(totalWeightLbs, mr);
    totalMashTime += stp->getMinutes();
    mashWaterQTS += waterAddedQTS;
    stp->getInVol()->setUnits(CONVERTER_QT);
    stp->getInVol()->setAmount(waterAddedQTS);
    stp->setStrikeTemp(strikeTemp);
    stp->setMethod(INFUSION);
    stp->setWeightLbs(totalWeightLbs);

    qDebug() << "Subtracting cereal " <<  totalCerealLbs << " from " <<maltWeightLbs;
    totalWeightLbs = maltWeightLbs - totalCerealLbs;
    // subtract the water added from the Water Equiv so that they are correct when added in the next part of the loop
    waterEquiv -= waterAddedQTS;

    // Updated the water added

    if (tempUnits == "C") {
        strikeTemp = BrewCalcs::fToC(strikeTemp);
    }

    stp->setDirections("Mash in with " + SBStringUtils::format(stp->getInVol()->getValueAs(volUnits),1 ) + " " + volUnits
            + " of water at " + SBStringUtils::format(strikeTemp, 1) + " " + tempUnits);

    // set TargetTemp to the end temp
    targetTemp = stp->getEndTemp();

    for (int i = 1; i < steps.size(); i++) {
        stp = &steps[i];
        currentTemp = targetTemp; // switch
        targetTemp = stp->getStartTemp();

        // if this is a former sparge step that's been changed, change
        // the method to infusion
        qDebug() << "Mash step Type: " << stp->getType() << " Method: " << stp->getMethod();
        if (stp->getType() != SPARGE && ( stp->getMethod() == FLY || stp->getMethod() == BATCH))
                stp->setMethod(INFUSION);

        // do calcs
        if (stp->getMethod() == INFUSION) { // calculate an infusion step
            decoct = 0;
            waterEquiv += waterAddedQTS; // add previous addition to get WE
            strikeTemp = boilTempF; // boiling water

            // Updated the water added
            waterAddedQTS = calcWaterAddition(targetTemp, currentTemp,
                    waterEquiv, boilTempF);

            stp->getOutVol()->setAmount(0);
            stp->getInVol()->setUnits(CONVERTER_QT);
            stp->getInVol()->setAmount(waterAddedQTS);
            stp->setStrikeTemp(strikeTemp);
            stp->setWeightLbs(totalWeightLbs);

            if (tempUnits == "C")
                strikeTemp = 100;
            stp->setDirections("Add " + SBStringUtils::format(stp->getInVol()->getValueAs(volUnits), 1) + " " + volUnits
                    + " of water at " + SBStringUtils::format(strikeTemp, 1) + " " + tempUnits);

            mashWaterQTS += waterAddedQTS;
            mashVolQTS += waterAddedQTS;

        }

        else if (stp->getMethod() == DECOCTION) { // calculate a decoction step
            waterEquiv += waterAddedQTS; // add previous addition to get WE
            waterAddedQTS = 0;
            strikeTemp = boilTempF; // boiling water
            double ratio=0.75;

            if (stp->getMethod() == DECOCTION_THICK)
                ratio = thickDecoctRatio;
            else if (stp->getMethod() == DECOCTION_THIN)
                ratio = thinDecoctRatio;

            // Calculate volume (qts) of mash to remove
            decoct = calcDecoction2(targetTemp, currentTemp, mashWaterQTS, ratio, totalWeightLbs);
            stp->getOutVol()->setUnits(CONVERTER_QT);
            stp->getOutVol()->setAmount(decoct);
            stp->getInVol()->setAmount(0);
            stp->setStrikeTemp(boilTempF);
            stp->setWeightLbs(totalWeightLbs);

            // Updated the decoction, convert to right units & make directions
            stp->setDirections("Remove " + SBStringUtils::format(stp->getOutVol()->getValueAs(volUnits), 1) + " " + volUnits
                    + " of mash, boil, and return to mash.");

        } else if (stp->getMethod() == DIRECT) { // calculate a direct heat step
            decoct = 0;
            waterEquiv += waterAddedQTS; // add previous addition to get WE
            waterAddedQTS = 0;
            displTemp = stp->getStartTemp();
            if (tempUnits == "C")
                displTemp = BrewCalcs::fToC(displTemp);
            stp->setDirections("Add direct heat until mash reaches " + QString::number(displTemp)
                    + " " + tempUnits + ".");
            stp->getInVol()->setAmount(0);
            stp->getOutVol()->setAmount(0);
            stp->setStrikeTemp(0);
            stp->setWeightLbs(totalWeightLbs);

        } else if (stp->getMethod() == CEREAL_MASH) { // calculate a cereal mash step

            waterEquiv += waterAddedQTS; // add previous addition to get WE
            waterAddedQTS = 0;
            targetTemp = stp->getStartTemp();
            double extraWaterQTS = 0;
            double cerealTemp = boilTempF;
            double cerealTargTemp = cerealMashTemp;
            QString addStr = "";

            /*
             * 1. check the temp of the mash when you add the boiling cereal mash @ default ratio back
             * 2. if it's > than the step temp, adjust the step temp
             * 3. if it's < than the step temp, add extra water to increase the "heat equivalencey" of the cereal mash
             */

            double cerealWaterEquiv = stp->getWeightLbs() * (0.192 + mr);
            waterAddedQTS = mr * stp->getWeightLbs();
            strikeTemp = calcStrikeTemp(cerealMashTemp, grainTempF, mr, 0);

            double newTemp = ((waterEquiv * currentTemp) + (cerealWaterEquiv * cerealTemp)) / (waterEquiv + cerealWaterEquiv);

            if (newTemp > targetTemp){
                stp->setStartTemp(newTemp);
            }

            if (newTemp < targetTemp){
                double addQts = ((waterEquiv * (targetTemp - currentTemp)) / (cerealTemp - targetTemp)) - 0.192;
                extraWaterQTS = addQts - waterAddedQTS;
                addStr = " Add " + SBStringUtils::format(Quantity::convertUnit(CONVERTER_QT, volUnits, extraWaterQTS), 1)
                  + " " + volUnits + " water to the cereal mash.";
            }

            // Calculate final temp of cereal mash
            // cerealTemp = (targetTemp * (waterEquiv + cerealWaterEquiv) - (waterEquiv * currentTemp)) / cerealWaterEquiv;
            totalMashTime += stp->getMinutes();
            mashWaterQTS += waterAddedQTS + extraWaterQTS;
            stp->getInVol()->setUnits(CONVERTER_QT);
            stp->getInVol()->setAmount(waterAddedQTS);
            stp->getOutVol()->setAmount(0);
            stp->setStrikeTemp(strikeTemp);

            // make directions

            QString weightStr = SBStringUtils::format(Quantity::convertUnit(CONVERTER_LB, this->maltUnits, stp->getWeightLbs()), 1)
            + " " + this->maltUnits;
            QString volStr = SBStringUtils::format(Quantity::convertUnit(CONVERTER_QT, volUnits, waterAddedQTS), 1)
            + " " + volUnits;

            if (tempUnits == "C"){
                strikeTemp = BrewCalcs::fToC(strikeTemp);
                cerealTemp = BrewCalcs::fToC(cerealTemp);
                targetTemp = BrewCalcs::fToC(targetTemp);
                cerealTargTemp = BrewCalcs::fToC(cerealTargTemp);
            }

            QString tempStr = SBStringUtils::format(strikeTemp, 1) + tempUnits;
            QString tempStr2 = SBStringUtils::format(cerealTemp, 1) + tempUnits;
            QString tempStr3 = SBStringUtils::format(targetTemp, 1) + tempUnits;
            QString tempStr4 = SBStringUtils::format(cerealTargTemp, 1) + tempUnits;
            QString newDirection = "Cereal mash: mash " + weightStr + " grain with " + volStr + " water at " +
                tempStr + " to hit " + tempStr4 + " and rest.";
            newDirection.append(addStr);
            newDirection.append(" Raise to " +  tempStr2 + " and add to the main mash to reach " + tempStr3);

            stp->setDirections(newDirection);
            // add cereal mash to total weight
            totalWeightLbs += stp->getWeightLbs();

        } else {

            qDebug() << "Unrecognised mash step: " << stp->getMethod();
        }

        if (stp->getType() == SPARGE)
            numSparge++;
        else {
            totalMashTime += stp->getMinutes();
        }
        // set target temp to end temp for next step
        targetTemp = stp->getEndTemp();

    } // for steps.size()

    waterEquiv += waterAddedQTS; // add previous addition to get WE
    totalTime = totalMashTime;
    volQts = mashVolQTS;

    // water use stats:
    qDebug() << "Total Weight " << totalWeightLbs;
    absorbedQTS = totalWeightLbs * 0.52; // figure from HBD

    // spargeTotalQTS = (myRecipe.getPreBoilVol("qt")) - (mashWaterQTS - absorbedQTS);
    totalWaterQTS = mashWaterQTS;
    spargeQTS = this->preBoilQts -
            (mashWaterQTS - absorbedQTS - deadSpace.getValueAs(CONVERTER_QT));
    qDebug() << "Sparge QTs: " << spargeQTS;
    // Now let's figure out the sparging:
    if (numSparge == 0)
        return;

    // Amount to collect per sparge
    double col = this->preBoilQts / numSparge;
    QList<double> charge = QList<double>();
    QList<double> collect = QList<double>();

    for (int i = 0; i < numSparge; i++) {
        charge.append(0.0);
        collect.append(0.0);
    }
    double totalCollectQts = this->preBoilQts;


    // do we need to add more water to charge up
    // is the amount we need to collect less than the initial mash volume - absorbption
    if (col <= (mashWaterQTS - absorbedQTS)) {
        charge[0] = 0;
        collect[0] = mashWaterQTS - absorbedQTS; // how much is left over from the mash
        totalCollectQts = totalCollectQts - collect[0];
    } else {
        charge[0] = col - (mashWaterQTS - absorbedQTS); // add the additional water to get out the desired first collection amount PER sparge
        collect[0] = col;
        totalCollectQts = totalCollectQts - collect[0];
    }

   // do we need any more steps?
    if(numSparge > 1) {
        /*
        batch_1_sparge_liters = (boil_size_l/<total number of steps> ) - mash_water_l + grain_wt_kg * 0.625)
                batch_2_liters = boil_size_l / <total number of steps>
            */
        for (int i = 1; i < numSparge; i++) {
            charge[i] = col;
            collect[i] = col;
        }
    }

    int j=0;
    for (int i = 1; i < steps.size(); i++) {
        stp = &steps[i];
        if (stp->getType() == SPARGE) {

            stp->getInVol()->setUnits(CONVERTER_QT);
            stp->getInVol()->setAmount(charge[j]);

            stp->getOutVol()->setUnits(CONVERTER_QT);
            stp->getOutVol()->setAmount(collect[j]);

            stp->setStrikeTemp(SPARGETMPF);
            totalSpargeTime += stp->getMinutes();
            QString collectStr = SBStringUtils::format(Quantity::convertUnit(CONVERTER_QT, volUnits, collect[j]), 2) +
            " " + volUnits;
            QString tempStr = "";

            if (tempUnits == "F"){
                tempStr = "" + SBStringUtils::format(SPARGETMPF, 1) + "F";
            } else {
                tempStr = SBStringUtils::format(BrewCalcs::fToC(SPARGETMPF), 1) + "C";
            }

            if (numSparge > 1){
                stp->setMethod(BATCH);
                QString add = SBStringUtils::format(Quantity::convertUnit(CONVERTER_QT, volUnits, charge[j]), 2) +
                " " + volUnits;
                stp->setDirections("Add " + add + " at " + tempStr + " to collect " + collectStr);

            } else {
                stp->getInVol()->setUnits(CONVERTER_QT);
                stp->getInVol()->setAmount(spargeQTS);

                stp->getOutVol()->setUnits(CONVERTER_QT);
                stp->getOutVol()->setAmount(collect[j]);

                stp->setMethod(FLY);
                stp->setDirections("Sparge with " +
                        SBStringUtils::format(Quantity::convertUnit(CONVERTER_QT, volUnits, spargeQTS), 1) +
                        " " + volUnits + " at " + tempStr + " to collect " + collectStr);
            }
            j++;
        }
    }
}


// private methods:

/* from John Palmer:
 * 		Vd (quarts) = [(T2 - T1)(.4G + 2W)] / [(Td - T1)(.4g + w)]
        Where:
        Vd = decoction volume
        T1 = initial mash temperature
        T2 = target mash temperature
        Td = decoction temperature (212F)
        G = Grainbill weight
        W = volume of water in mash (i.e. initial infusion volume)
        g = pounds of grain per quart of decoction = 1/(Rd + .32)
        w = quarts of water per quart of decoction = g*Rd*water density = 2gRd
        Rd = ratio of grain to water in the decoction volume (range of .6 to 1
        quart/lb)
        thick decoctions will have a ratio of .6-.7, thinner decoctions will
       have a ratio of .8-.9
 */

double Mash::calcDecoction2(double targetTemp, double currentTemp, double waterVolQTS, double ratio, double weightLbs){
    double decoctQTS=0;

    double g = 1 / (ratio + .32);
    double w = 2 * g * ratio;

    decoctQTS = ((targetTemp - currentTemp) * ((0.4 * weightLbs) + (2 * waterVolQTS)))
        / ((boilTempF - currentTemp) * (0.4 * g + w));


    return decoctQTS;
}


QString Mash::calcStepType(double temp) {
    QString stepType = "none";
    // less than 90, none
    // 86 - 95 - acid
    if (temp >= ACIDTMPF && temp < GLUCANTMPF)
        stepType = ACID;
    // 95 - 113 - glucan
    else if (temp < PROTEINTMPF)
        stepType = GLUCAN;
    // 113 - 131 protein
    else if (temp < BETATMPF)
        stepType = PROTEIN;
    // 131 - 150 beta
    else if (temp < ALPHATMPF)
        stepType = BETA;
    // 150-162 alpha
    else if (temp < MASHOUTTMPF)
        stepType = ALPHA;
    // 163-169, mashout
    else if (temp < SPARGETMPF)
        stepType = MASHOUT;
    // over 170, sparge
    else if (temp >= SPARGETMPF)
        stepType = SPARGE;

    return stepType;
}

double Mash::calcStepTemp(QString stepType) {
    float stepTempF = 0;
    if (stepType == ACID)
        stepTempF = (ACIDTMPF + GLUCANTMPF) / 2;
    else if (stepType == GLUCAN)
        stepTempF = (GLUCANTMPF + PROTEINTMPF) / 2;
    else if (stepType == PROTEIN)
        stepTempF = (PROTEINTMPF + BETATMPF) / 2;
    else if (stepType == BETA)
        stepTempF = (BETATMPF + ALPHATMPF) / 2;
    else if (stepType == ALPHA)
        stepTempF = (ALPHATMPF + MASHOUTTMPF) / 2;
    else if (stepType == MASHOUT)
        stepTempF = (MASHOUTTMPF + SPARGETMPF) / 2;
    else if (stepType == SPARGE)
        stepTempF = SPARGETMPF;

    return stepTempF;
}

double Mash::calcMashVol(double grainWeightLBS, double ratio) {
    // given lbs and ratio, what is the volume of the grain in quarts?
    // note: this calc is for the first record only, and returns the heat equivalent of
    // grain + water added for first infusion
    // HBD posts indicate 0.32, but reality is closer to 0.42

    return (grainWeightLBS * (0.42 + ratio));
}

double Mash::calcStrikeTemp(double targetTemp, double currentTemp, double ratio,
        double tunLossF) {
    // calculate strike temp
    // Ratio is in quarts / lb, TunLoss is in F

    // this uses thermal mass:
    // double strikeTemp = (maltWeightLbs + thermalMass)*( targetTemp - currentTemp )/( boilTempF - targetTemp );

    return (targetTemp + 0.192 * (targetTemp - currentTemp) / ratio)
            + tunLossF;
}

double Mash::calcWaterAddition(double targetTemp, double currentTemp,
        double mashVol, double boilTempF) {
    // calculate amount of boiling water to add to raise mash to new temp
    return (mashVol * (targetTemp - currentTemp) / (boilTempF - targetTemp));
}



 QString Mash::toXml() {

    calcMashSchedule();
    QString sb;
    sb.append("  <MASH>\n");
    sb.append(SBStringUtils::xmlElement("NAME", name, 4));
    sb.append(SBStringUtils::xmlElement("MASH_VOLUME", SBStringUtils::format(Quantity::convertUnit(CONVERTER_QT, volUnits, volQts), 2) , 4));
    sb.append(SBStringUtils::xmlElement("MASH_VOL_U", volUnits, 4));
    sb.append(SBStringUtils::xmlElement("MASH_RATIO", mashRatio, 4));
    sb.append(SBStringUtils::xmlElement("MASH_RATIO_U", mashRatioU, 4));
    sb.append(SBStringUtils::xmlElement("MASH_TIME", totalTime, 4));
    sb.append(SBStringUtils::xmlElement("MASH_TMP_U", tempUnits, 4));
    sb.append(SBStringUtils::xmlElement("THICK_DECOCT_RATIO", thickDecoctRatio, 4));
    sb.append(SBStringUtils::xmlElement("THIN_DECOCT_RATIO", thinDecoctRatio, 4));
    if (tempUnits == "C"){
        sb.append(SBStringUtils::xmlElement("MASH_TUNLOSS_TEMP", (tunLossF/1.8), 4));
        sb.append(SBStringUtils::xmlElement("GRAIN_TEMP", BrewCalcs::fToC(grainTempF), 4));
        sb.append(SBStringUtils::xmlElement("BOIL_TEMP", BrewCalcs::fToC(boilTempF), 4));
    }
    else {
        sb.append(SBStringUtils::xmlElement("MASH_TUNLOSS_TEMP", tunLossF, 4));
        sb.append(SBStringUtils::xmlElement("GRAIN_TEMP", grainTempF, 4));
        sb.append(SBStringUtils::xmlElement("BOIL_TEMP", boilTempF, 4));
    }

    for (int i = 0; i < steps.size(); i++) {
        MashStep st = steps.at(i);
        sb.append("    <ITEM>\n");
        sb.append(SBStringUtils::xmlElement("TYPE", st.getType(), 6));
        sb.append(SBStringUtils::xmlElement("TEMP", st.getStartTemp(), 6));

        double sTemp;
        double eTemp;

        if (tempUnits == "C") {
            sTemp = BrewCalcs::fToC(st.getStartTemp());
            eTemp = BrewCalcs::fToC(st.getEndTemp());
        } else {
            sTemp = st.getStartTemp();
            eTemp = st.getEndTemp();
        }

        sb.append(SBStringUtils::xmlElement("DISPL_TEMP", SBStringUtils::format(sTemp, 1), 6));

        sb.append(SBStringUtils::xmlElement("END_TEMP", st.getEndTemp(), 6));
        sb.append(SBStringUtils::xmlElement("DISPL_END_TEMP", SBStringUtils::format(eTemp, 1), 6));

        sb.append(SBStringUtils::xmlElement("MIN", st.getMinutes(), 6));
        sb.append(SBStringUtils::xmlElement("RAMP_MIN", st.getRampMin(), 6));
        sb.append(SBStringUtils::xmlElement("METHOD", st.getMethod(), 6));
        sb.append(SBStringUtils::xmlElement("WEIGHT_LBS", st.getWeightLbs(), 6));
        sb.append(SBStringUtils::xmlElement("DIRECTIONS", st.getDirections(), 6));
        sb.append("    </ITEM>\n");
    }

    sb.append("  </MASH>\n");
    return sb;
}


QJsonObject Mash::toJSONObject() {
    QJsonObject output;
    output.insert("temp_unit", QJsonValue::fromVariant(tempUnits));

    for (int i = 0; i < steps.size(); i++) {
        MashStep st = steps.at(i);
        QJsonObject step;
        step.insert("type", QJsonValue::fromVariant(st.getType()));
        step.insert("method", QJsonValue::fromVariant(st.getMethod()));
        step.insert("temp", QJsonValue::fromVariant(st.getStartTemp()));
        step.insert("duration", QJsonValue::fromVariant(st.getMinutes()));
        output.insert(QString::number(i), step);
    }

    return output;
}

QString Mash::toJSONString() {
    QJsonDocument doc(toJSONObject());

    return doc.toJson();
}
