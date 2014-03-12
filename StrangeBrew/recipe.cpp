#include "recipe.h"

Recipe::Recipe()
{
    isDirty = false;
    acid = Acid::getAcidByName(CITRIC);

    QSettings opts("Doug Edey", "StrangeBrew");
    qDebug() << opts.fileName();
    mash = Mash();
    name = "My Recipe";
    created = QDate::currentDate();
    allowRecalcs = true;
    estOg = 1.000;
    estFermOg = 1.000;
    estFg = 1.000;
    filename = "";
    version = "7";
    primeSugar = new PrimeSugar();
    style = new Style();
    yeast = new Yeast();

    boilMinutes = opts.value("Times/BoilTime").toInt();

    efficiency = opts.value("Calculations/Efficiency", "75").toDouble();
    attenuation = opts.value("Calculations/Attenuation", "75").toDouble();
    ibuCalcMethod = opts.value("Calculations/IBUCalcMethod", TINSETH);
    ibuHopUtil = opts.value("Calculations/HopsUtil", "4.15");
    fwhTime = opts.value("Calculations/FWHTime", "1");
    mashHopTime = opts.value("Calculations/MashHopTime", "2");
    dryHopTime = opts.value("Calculations/DryHopTime", "0");
    hopUnits = opts.value("Calculations/HopsU", "oz");
    maltUnits = opts.value("Calculations/MaltU", "lb");
    evapMethod = opts.value("Calculations/EvapCalcMethod", "Constant");
    evap = opts.value("Calculations/Evaporation", "1.5").toDouble();
    alcMethod = opts.value("Calculations/AlcCalcMethod", ALC_BY_VOLUME);
    colourMethod = opts.value("Calculations/ColourMethod", "1");
    pelletHopPct = opts.value("Calculations/PelletHopsPct", "6");

    brewer = opts.value("Labels/Brewer", "Unknown").toString();

    bottleU = opts.value("Carbonation/BottleU", CONVERTER_FL_OZ);
    bottleSize = opts.value("Carbonation/BottleSize", "12");
    bottleTemp = opts.value("Carbonation/BottleTemp", "68");
    servTemp = opts.value("Carbonation/ServTemp", "45");
    targetVol = opts.value("Carbonation/VolsCO2");

    primeSugar->setUnits(opts.value("Carbonation/SugarU").toString());
    carbTempU = opts.value("Carbonation/CarbTempU");
    kegged = opts.value("Carbonation/Kegged").toBool();
    kegTubeID = opts.value("Carbonation/TubingID");
    kegTubeHeight = opts.value("Carbonation/HeightAboveKeg");

    otherCost = opts.value("Cost/Misc");

    QString sugarOption = opts.value("Carbonation/PrimingSugar").toString();
    PrimeSugar *findPS = Database::findSugar(sugarOption);
    if (findPS != NULL && findPS != Database::primeSugarDB.last()) {
        primeSugar = findPS;
    }

    // TODO Load default Salt options!
    sourceWater = WaterProfile(opts.value("Recipe/WaterProfile").toString());
    // brewingSalts.addAll(Database.getInstance().saltDB);

    QString units = opts.value("Recipe/SizeU").toString();
    setVolUnits(units);

    kegged = false;
    kegPSI = 0.0;
    kegTubeHeight = 0.0;
    kegTubeID = 0.0;

    qDebug() << "Recipe creation: " <<opts.value("Recipe/PostBoilVol").toDouble();
    // trigger the first re-calc, from the recipe size if available
    setPostBoil(Quantity(units, opts.value("Recipe/PostBoilVol").toDouble()));
    kettleLossVol = Quantity(units, opts.value("Loss/Kettle").toDouble());
    trubLossVol = Quantity(units, opts.value("Loss/Trub").toDouble());
    miscLossVol = Quantity(units, opts.value("Loss/Misc").toDouble());


}

/*Recipe::~Recipe() {
    fermentables.clear();
    hops.clear();
    misc.clear();
}*/

// Getters:
double Recipe::getIBUHopUtil() const {
    return ibuHopUtil.toDouble();
}

double Recipe::getAlcohol() const {
    return BrewCalcs::calcAlcohol(getAlcMethod(), estOg, getEstFg());
}

QString Recipe::getAlcMethod() const {
    return alcMethod.toString();
}

double Recipe::getAttenuation() const {
    return attenuation;
}

int Recipe::getBoilMinutes() const {
    return boilMinutes;
}

QString Recipe::getBottleU() const {
    return bottleU.toString();
}

double Recipe::getBottleSize() const {
    return bottleSize.toDouble();
}

double Recipe::getBUGU() const {
    double bugu = 0.0;
    if (estOg != 1.0) {
        bugu = ibu / ((estOg - 1) * 1000);
    }
    return bugu;
}

QString Recipe::getBrewer() const {
    return brewer;
}

QString Recipe::getComments() const {
    return comments;
}

double Recipe::getColour() {
    return getColour(getColourMethod());
}

double Recipe::getMcu() {
    double mcu = 0;
    for (int i = 0; i < fermentables.size(); i++) {
        Fermentable *m = fermentables[i];
        mcu += m->getAmountAs(CONVERTER_LB) * m->getLov() / getPostBoilVol(CONVERTER_GAL);
    }

    return mcu;
}

double Recipe::getColour(QString method) {
    return BrewCalcs::calcColour(getMcu(), method);
}

QString Recipe::getColourMethod() const {
    return colourMethod.toString();
}

QDate Recipe::getCreated() const {
    return created;
}

double Recipe::getEfficiency() const {
    return efficiency;
}

double Recipe::getEstOg() const {
    return estOg;
}

double Recipe::getEstFg() const {
    return estFg;
}

double Recipe::getEvap() const {
    return evap;
}

QString Recipe::getEvapMethod() const {
    return evapMethod.toString();
}

Mash *Recipe::getMash() {
    return &mash;
}

double Recipe::getIbu() const {
    return ibu;
}

QString Recipe::getIBUMethod() const {
    return ibuCalcMethod.toString();
}

QString Recipe::getMaltUnits() {
    return maltUnits.toString();
}

QString Recipe::getName() const {
    return name;
}

double Recipe::getOtherCost() const {
    return otherCost.toDouble();
}

double Recipe::getPelletHopPct() const {
    return pelletHopPct.toDouble();
}

// Water getters - the calculated version
QString Recipe::getKettleLossStr() const {
    return QString::number(getKettleLoss(getVolUnits()), 'f', 2);
}

double Recipe::getKettleLoss(QString s) const {
    return kettleLossVol.getValueAs(s);
}

QString Recipe::getMiscLossStr() const {
    return QString::number(getMiscLoss(getVolUnits()), 'f', 2);
}

double Recipe::getMiscLoss(QString s) const {
    return miscLossVol.getValueAs(s);
}

QString Recipe::getTotalWaterStr() {
    return QString::number(getTotalWaterVol(), 'f', 2);
}

double Recipe::getTotalWaterVol() {
    return getTotalWaterVol(getVolUnits());
}

double Recipe::getTotalWaterVol(QString s) {
    Quantity q = Quantity(CONVERTER_QT, mash.getTotalWaterQts() + mash.getSpargeVol());
    return q.getValueAs(s);
}

double Recipe::getChillShrinkVol(QString s) const {
    return getPostBoilVol(s) * chillPercent.toDouble();
}

QString Recipe::getPreBoilVolStr() const {
    return QString::number(getPreBoilVol(getVolUnits()), 'f', 2);
}

double Recipe::getPreBoilVol() const {
    return getPreBoilVol(getVolUnits());
}

double Recipe::getPreBoilVol(QString s) const {
    double vol = getPostBoilVol(s) + getEvapVol(s) + getChillShrinkVol(s);
    return vol;
}

QString Recipe::getFinalWortVolStr() {
    return QString::number(getFinalWortVol(), 'f', 2);
}

double Recipe::getFinalWortVol() const {
    return getFinalWortVol(this->getVolUnits());
}


double Recipe::getFinalWortVol(QString s) const {
    double vol = getPostBoilVol(s) - (getKettleLoss(s) + getTrubLoss(s) + getMiscLoss(s));
    return vol;
}

Quantity Recipe::getPostBoilVol() const {
    return postBoilVol;
}

double Recipe::getPostBoilVol(QString s) const {
    return postBoilVol.getValueAs(s);
}

QString Recipe::getTrubLossStr() const {
    return QString::number(getTrubLoss(getVolUnits()), 'f', 2);
}

double Recipe::getTrubLoss(QString s) const {
    return trubLossVol.getValueAs(s);
}

double Recipe::getEvapVol(QString s) const {
    // JvH changing the boiltime, changes the post boil volume (NOT the pre
    // boil)
    double e;
    if (evapMethod == "Constant" ) {
        e = getEvap() * getBoilMinutes() / 60;

        Quantity tVol;
        tVol.setUnits(getVolUnits());
        tVol.setAmount(e);
        return tVol.getValueAs(s);
    } else { // %
        e = getPostBoilVol(s) * (getEvap() / 100) * getBoilMinutes() / 60;
    }
    return e;
}

QString Recipe::getVolUnits() const {
    return postBoilVol.getUnits();
}

QString Recipe::getVolUnitsAbrv() const {
    return postBoilVol.getAbrv();
}

double Recipe::getSparge() {
    // return (getVolConverted(spargeQTS));
    return mash.getSpargeVol();
}

QString Recipe::getStyle() const {
    return style->getName();
}

Style *Recipe::getStyleObj() const {
    return style;
}

double Recipe::getTotalHopsOz() const {
    return totalHopsOz.toDouble();
}

double Recipe::getTotalHops() const {
    return Quantity::convertUnit(CONVERTER_OZ, hopUnits.toString(), totalHopsOz.toDouble());
}

double Recipe::getTotalHopsCost() const {
    return totalHopsCost.toDouble();
}

double Recipe::getTotalMaltCost() const{
    return totalMaltCost.toDouble();
}

double Recipe::getTotalMashLbs() const {
    return totalMashLbs.toDouble();
}

double Recipe::getTotalMash() const {
    return Quantity::convertUnit(CONVERTER_LB, maltUnits.toString(), totalMashLbs.toDouble());
}

double Recipe::getTotalMalt() const {
    return totalMaltLbs.toDouble();
}

double Recipe::getTotalMaltLbs() {
    return Quantity::convertUnit(CONVERTER_LB, maltUnits.toString(), totalMaltLbs.toDouble());
}

double Recipe::getTotalMiscCost() const {
    return totalMiscCost.toDouble();
}

QString Recipe::getYeast() const {
    return yeast->getName();
}

Yeast *Recipe::getYeastObj() {
    return yeast;
}

bool Recipe::getDirty() const {
    return isDirty;
}

// Setters:

// Set saved flag
void Recipe::setDirty(bool d) {
    isDirty = d;
}

/*
 * Turn off allowRecalcs when you are importing a recipe, so that strange
 * things don't happen. BE SURE TO TURN BACK ON!
 */
void Recipe::setAllowRecalcs(bool b) {
    allowRecalcs = b;
    if (b) {
        getMash()->enableRecalcs();
    } else {
        getMash()->disableRecalcs();
    }
}

void Recipe::setIBUHopUtil(double d) {
    ibuHopUtil = d;
}

void Recipe::setAlcMethod(QString s) {
    if (alcMethod == s)
        return;
    isDirty = true;
    alcMethod = s;
}

void Recipe::setBoilMinutes(int b) {
    if (boilMinutes == b)
        return;
    isDirty = true;
    boilMinutes = b;
}

void Recipe::setBottleSize(double b) {
    if (bottleSize == b)
        return;
    isDirty = true;
    bottleSize = QVariant(b);
}

void Recipe::setBottleU(QString u) {
    if (bottleU == u)
        return;
    isDirty = true;
    bottleU = QVariant(u);
}

void Recipe::setBrewer(QString b) {
    if (brewer == b)
        return;
    isDirty = true;
    brewer = b;
}

void Recipe::setComments(QString c) {
    if (comments == c)
        return;
    isDirty = true;
    comments = c;
}

void Recipe::setColourMethod(QString c) {
    if (colourMethod == c)
        return;
    isDirty = true;
    colourMethod = c;
    calcMaltTotals();
}

void Recipe::setCreated(QDate d) {
    if (created == d)
        return;
    isDirty = true;
    created = d;
}

void Recipe::setEvap(double e) {
    if (evap == e)
        return;
    isDirty = true;
    evap = e;
    calcMaltTotals();
    calcHopsTotals();
}

void Recipe::setEvapMethod(QString e) {
    if (evapMethod == e)
        return;
    isDirty = true;
    evapMethod = QVariant(e);
}

void Recipe::setHopsUnits(QString h) {
    if (hopUnits == h)
        return;
    isDirty = true;
    hopUnits = QVariant(h);
}

void Recipe::setIBUMethod(QString s) {
    if (ibuCalcMethod == s)
        return;
    isDirty = true;
    ibuCalcMethod = QVariant(s);
    calcHopsTotals();
}

void Recipe::setKettleLoss(Quantity q) {
    if (kettleLossVol.getUnits() == q.getUnits()
            && kettleLossVol.getValue() == q.getValue())
        return;
    isDirty = true;
    kettleLossVol = q;
    calcMaltTotals();
}

void Recipe::setKettleLoss(double d) {
    if (kettleLossVol.getValue() == d || d < 0)
        return;
    isDirty = true;
    kettleLossVol.setAmount(d);
    calcMaltTotals();
}

void Recipe::setMaltUnits(QString m) {
    if (maltUnits == m)
        return;
    isDirty = true;
    maltUnits = QVariant(m);
}

void Recipe::setMashed(bool m) {
    if (mashed == m)
        return;
    isDirty = true;
    mashed = m;
}

void Recipe::setMashed(QString m) {
    bool newM;

    if (m.compare("yes", Qt::CaseInsensitive) == 0
        || m.compare("true", Qt::CaseInsensitive) == 0
        || m.compare("1", Qt::CaseInsensitive) == 0 )
        newM = true;
    else
        newM = false;

    if (newM == mashed)
        return;
    isDirty = true;
    mashed = newM;
}

void Recipe::setMashRatio(double m) {
    if (mash.getMashRatio() == m)
        return;
    isDirty = true;
    mash.setMashRatio(m);
}

void Recipe::setMashRatioU(QString u) {
    if (mash.getMashRatioU() == u)
        return;
    isDirty = true;
    mash.setMashRatioU(u);
}

void Recipe::setMiscLoss(double d) {
    if (miscLossVol.getValue() == d)
        return;
    isDirty = true;
    miscLossVol.setAmount(d);
    calcMaltTotals();
}

void Recipe::setMiscLoss(Quantity m) {
    if (miscLossVol.getUnits() == m.getUnits()
            && miscLossVol.getValue() == m.getValue())
        return;
    isDirty = true;
    miscLossVol = m;
    calcMaltTotals();
}

void Recipe::setName(QString n) {
    if (name == n)
        return;
    isDirty = true;
    name = n;
}

void Recipe::setOtherCost(double c) {
    if (otherCost == c)
        return;
    isDirty = true;
    otherCost = c;
}

void Recipe::setPelletHopPct(double p) {
    if (pelletHopPct == p)
        return;
    isDirty = true;
    pelletHopPct = p;
    calcHopsTotals();
}

void Recipe::setStyle(QString s) {
    if (style->getName() == s)
        return;
    isDirty = true;
    // Lookup the style
    Style *newStyle = Database::findStyle(s);
    if (newStyle == NULL) {
        style->setName(s);
    } else {
        setStyle(newStyle);
    }
}

void Recipe::setStyle(Style *s) {
    if (s->getName() == style->getName())
        return;
    isDirty = true;
    style = s;
}

void Recipe::setTrubLoss(double d) {
    if (trubLossVol.getValue() == d)
        return;
    isDirty = true;
    trubLossVol.setAmount(d);
    calcMaltTotals();
}

void Recipe::setTrubLoss(Quantity t) {
    if (trubLossVol.getUnits() == t.getUnits()
            && trubLossVol.getValue() == t.getValue())
        return;
    isDirty = true;
    trubLossVol = t;
    calcMaltTotals();
}

void Recipe::setYeastName(QString s) {
    if (yeast->getName() == s)
        return;
    isDirty = true;
    yeast->setName(s);
}

void Recipe::setYeast(Yeast *y) {
    if (yeast->getName() == y->getName())
        return;
    isDirty = true;
    yeast = y;
}

void Recipe::setVersion(QString v) {
    if (version == v)
        return;
    isDirty = true;
    version = v;
}

// Fermentation Steps
// Getters
QList<FermentStep> *Recipe::getFermentStepsList() {
    return &fermentationSteps;
}

int Recipe::getFermentStepSize() const {
    return fermentationSteps.size();
}

QString Recipe::getFermentStepType(int i) {
    return fermentationSteps[i].getType();
}

int Recipe::getFermentStepTime(int i) const  {
    return fermentationSteps[i].getTime();
}

double Recipe::getFermentStepTemp(int i) const {
    return fermentationSteps[i].getTemp();
}

QString Recipe::getFermentStepTempU(int i) const {
    return fermentationSteps[i].getTempU();
}

FermentStep Recipe::getFermentStep(int i) const {
    return fermentationSteps[i];
}

int Recipe::getTotalFermentTime() const {
    return totalFermentTime.toInt();
}

// Setters
void Recipe::setFermentStepType(int i, QString s) {
    if (fermentationSteps[i].getType() == s)
        return;
    isDirty = true;
    fermentationSteps[i].setType(s);
}

void Recipe::setFermentStepTime(int i, int t) {
    if (fermentationSteps[i].getTime() == t)
        return;
    isDirty = true;
    fermentationSteps[i].setTime(t);
}

void Recipe::setFermentStepTemp(int i, double d) {
    if (fermentationSteps[i].getTemp() == d)
        return;
    isDirty = true;
    fermentationSteps[i].setTemp(d);
}

void Recipe::setFermentStepTempU(int i, QString s) {
    if (fermentationSteps[i].getTempU() == s)
        return;

    isDirty = true;
    fermentationSteps[i].setTempU(s);
}

void Recipe::addFermentStep(FermentStep fs) {
    isDirty = true;
    fermentationSteps.push_back(fs);
    std::sort(fermentationSteps.begin(), fermentationSteps.end(), FermentStep::compareTo);
    calcFermentTotals();
}

FermentStep Recipe::delFermentStep(int i) {
    isDirty = true;
    FermentStep temp;
    if (!fermentationSteps.empty() && (i > -1) && (i< fermentationSteps.size())) {
        fermentationSteps.erase(fermentationSteps.begin() + i);
        std::sort(fermentationSteps.begin(), fermentationSteps.end(), FermentStep::compareTo);
        calcFermentTotals();
    }

    return temp;
}

void Recipe::calcFermentTotals() {

    int FermentTime = 0;
    for (int i = 0; i < fermentationSteps.size(); i++) {
        FermentTime += fermentationSteps[i].getTime();
    }
    totalFermentTime = FermentTime;
}

// hop list get functions:
QString Recipe::getHopUnits() const {
    return hopUnits.toString();
}

QList<Hop*> *Recipe::getHopList() {
    return &hops;
}

Hop *Recipe::getHop(int i) const {
    if (i < hops.size()) {
        return hops[i];
    }

    throw "Invalid size";

}

int Recipe::getHopsListSize() const {
    return hops.size();
}

QString Recipe::getHopName(int i) const {
    return hops[i]->getName();
}

QString Recipe::getHopType(int i) const {
    return hops[i]->getType();
}

double Recipe::getHopAlpha(int i) const {
    return hops[i]->getAlpha();
}

QString Recipe::getHopUnits(int i) const {
    return hops[i]->getUnits();
}

QString Recipe::getHopAdd(int i) const {
    return hops[i]->getAdd();
}

int Recipe::getHopMinutes(int i) const {
    return hops[i]->getMinutes();
}

double Recipe::getHopIBU(int i) const {
    return hops[i]->getIBU();
}

double Recipe::getHopCostPerU(int i) const {
    return hops[i]->getCostPerU();
}

double Recipe::getHopAmountAs(int i, QString s) const {
    return hops[i]->getAmountAs(s);
}

QString Recipe::getHopDescription(int i) const {
    return hops[i]->getDescription();
}

// hop list set functions
void Recipe::setHopUnits(int i, QString u) {
    if (hops[i]->getUnits() == u)
        return;

    isDirty = true;
    hops[i]->setUnits(u);
}

void Recipe::setHopName(int i, QString n) {
    if (hops[i]->getName() == n)
        return;
    isDirty = true;
    hops[i]->setName(n);
}

void Recipe::setHopType(int i, QString t) {
    if (hops[i]->getType() == t)
        return;
    isDirty = true;
    hops[i]->setType(t);
}

void Recipe::setHopAdd(int i, QString a) {
    if (hops[i]->getAdd() == a)
        return;
    isDirty = true;
    hops[i]->setAdd(a);
}

void Recipe::setHopAlpha(int i, double a) {
    if (hops[i]->getAlpha() == a)
        return;
    isDirty = true;
    hops[i]->setAlpha(a);
}

void Recipe::setHopMinutes(int i, int m) {
    if (hops[i]->getMinutes() == m)
        return;
    isDirty = true;
    // have to re-sort hops
    hops[i]->setMinutes(m);
    // SORT HOPS
}

void Recipe::setHopCost(int i, QString c) {
    // TODO: Value string compare
    isDirty = true;
    hops[i]->setCost(c);
}

void Recipe::setHopAmount(int i, double a) {
    if (hops[i]->getAmount() == a)
        return;
    isDirty = true;
    hops[i]->setAmount(a);
}

// fermentable get methods
// ArrayList getFermentablesList() { return fermentables; }
Fermentable *Recipe::getFermentable(int i) {
    return fermentables[i];
}

QList<Fermentable*> *Recipe::getMaltList() {
    return &fermentables;
}

int Recipe::getMaltListSize() const {
    return fermentables.size();
}

QString Recipe::getMaltName(int i) const {
    return fermentables[i]->getName();
}

QString Recipe::getMaltUnits(int i) const {
    return fermentables[i]->getUnits();
}

double Recipe::getMaltPppg(int i) const {
    return fermentables[i]->getPppg();
}

double Recipe::getMaltLov(int i) const {
    return fermentables[i]->getLov();
}

double Recipe::getMaltCostPerU(int i) const {
    return fermentables[i]->getCostPerU();
}

double Recipe::getMaltCostPerUAs(int i, QString s) const {
    return fermentables[i]->getCostPerUAs(s);
}

double Recipe::getMaltPercent(int i) const {
    return fermentables[i]->getPercent();
}

double Recipe::getMaltAmountAs(int i, QString s) const {
    return fermentables[i]->getAmountAs(s);
}

QString Recipe::getMaltDescription(int i) const {
    return fermentables[i]->getDescription();
}

bool Recipe::getMaltMashed(int i) const {
    return fermentables[i]->getMashed();
}

bool Recipe::getMaltSteep(int i) const {
    return fermentables[i]->getSteep();
}

bool Recipe::getMaltFerments(int i) const {
    return fermentables[i]->ferments();
}

// fermentable set methods
void Recipe::setMaltName(int i, QString n) {
    if (fermentables[i]->getName() == n)
        return;
    // have to re-sort
    isDirty = true;
    fermentables[i]->setName(n);

}

void Recipe::setMaltUnits(int i, QString u) {
    if (fermentables[i]->getUnits() == u)
        return;
    isDirty = true;
    fermentables[i]->setUnits(u);
    fermentables[i]->setCost(fermentables[i]->getCostPerUAs(u));
}

void Recipe::setMaltAmount(int i, double a) {
    if (fermentables[i]->getAmount() == a)
        return;
    isDirty = true;
    fermentables[i]->setAmount(a);
    // TODO: SORT the fermentables list
    /*
    Comparator<Fermentable> c = new Comparator<Fermentable>()  {
        int compare(Fermentable h1, Fermentable h2){

            Debug.print("Comparing " + h1.getAmountAs(Quantity.LB) + " to " + h2.getAmountAs(Quantity.LB) );
            if(h1.getAmountAs(Quantity.LB) > h2.getAmountAs(Quantity.LB))
                return 1;
            if(h1.getAmountAs(Quantity.LB) < h2.getAmountAs(Quantity.LB))
                return -1;
            if(h1.getAmountAs(Quantity.LB) == h2.getAmountAs(Quantity.LB))
                // same amount, check later
                return 0;
            return 0;

        }

    };

    Collections.sort(fermentables, c);
    Collections.reverse(fermentables);
    */
}

void Recipe::setMaltAmountAs(int i, double a, QString u) {
    if (fermentables[i]->getAmountAs(u) == a)
        return;
    isDirty = true;
    fermentables[i]->setAmountAs(a, u);
    fermentables[i]->setCost(fermentables[i]->getCostPerUAs(u));
}

void Recipe::setMaltPppg(int i, double p) {
    if (fermentables[i]->getPppg() == p)
        return;
    isDirty = true;
    fermentables[i]->setPppg(p);
}

void Recipe::setMaltLov(int i, double l) {
    if (fermentables[i]->getLov() == l)
        return;
    isDirty = true;
    fermentables[i]->setLov(l);
}

void Recipe::setMaltCost(int i, QString c) {
    // TODO: Should be able to compare via string
    isDirty = true;
    fermentables[i]->setCost(c);
}

void Recipe::setMaltCost(int i, double c) {
    if (fermentables[i]->getCostPerU() == c)
        return;
    isDirty = true;
    fermentables[i]->setCost(c);
}

void Recipe::setMaltPercent(int i, double p) {
    if (fermentables[i]->getPercent() == p)
        return;
    isDirty = true;
    fermentables[i]->setPercent(p);
}

void Recipe::setMaltSteep(int i, bool c) {
    if (fermentables[i]->getSteep() == c)
        return;
    isDirty = true;
    fermentables[i]->setSteep(c);
}

void Recipe::setMaltMashed(int i, bool c) {
    if (fermentables[i]->getMashed() == c)
        return;
    isDirty = true;
    fermentables[i]->setMashed(c);
}

void Recipe::setMaltFerments(int i, bool c) {
    if (fermentables[i]->ferments() == c)
        return;
    isDirty = true;
    fermentables[i]->ferments(c);
}

QList<Misc*> *Recipe::getMiscList() {
    return &misc;
}

// misc get/set functions
int Recipe::getMiscListSize() const {
    return misc.size();
}

Misc *Recipe::getMisc(int i) const {
    return misc.at(i);
}

Misc *Recipe::getMiscPtr(int i) const {
    return misc[i];
}

QString Recipe::getMiscName(int i) const {
    return misc[i]->getName();
}

void Recipe::setMiscName(int i, QString n) {
    if (misc[i]->getName() == n)
        return;
    isDirty = true;
    misc[i]->setName(n);
}

double Recipe::getMiscAmount(int i) const {
    Misc *m = misc.at(i);
    return m->getAmountAs(m->getUnits());
}

void Recipe::setMiscAmount(int i, double a) {
    if (misc[i]->getAmount() == a)
        return;
    isDirty = true;
    misc[i]->setAmount(a);
    calcMiscCost();
}

QString Recipe::getMiscUnits(int i) const {
    return misc.at(i)->getUnits();
}

void Recipe::setMiscUnits(int i, QString u) {
    if (misc[i]->getUnits() == u)
        return;
    isDirty = true;
    misc[i]->setUnits(u);
    calcMiscCost();
}

double Recipe::getMiscCost(int i) const {
    return misc.at(i)->getCostPerU();
}

void Recipe::setMiscCost(int i, double c) {
    if (misc[i]->getCostPerU() == c)
        return;
    isDirty = true;
    misc[i]->setCost(c);
    calcMiscCost();
}

QString Recipe::getMiscStage(int i) {
    return misc[i]->getStage();
}

void Recipe::setMiscStage(int i, QString s) {
    if (misc[i]->getStage() == s)
        return;
    isDirty = true;
    misc[i]->setStage(s);
}

int Recipe::getMiscTime(int i) {
    return misc[i]->getTime();
}

void Recipe::setMiscTime(int i, int t) {
    if (misc[i]->getTime() == t)
        return;
    isDirty = true;
    misc[i]->setTime(t);
}

QString Recipe::getMiscDescription(int i) const {
    return misc.at(i)->getDescription();
}

void Recipe::setMiscComments(int i, QString c) {
    if (misc[i]->getComments() == c)
        return;
    isDirty = true;
    misc[i]->setComments(c);
}

QString Recipe::getMiscComments(int i) {
    return misc[i]->getComments();
}

QList<Note> *Recipe::getNotes() {
    return &notes;
}

// notes get/set methods
Note Recipe::getNote(int i) const {
    return notes[i];
}

int Recipe::getNotesListSize() const {
    return notes.size();
}

QDate Recipe::getNoteDate(int i) const {
    return notes[i].getDate();
}

void Recipe::setNoteDate(int i, QDate d) {
    if (notes[i].getDate() == d)
        return;
    isDirty = true;
    notes[i].setDate(d);
}

QString Recipe::getNoteType(int i) {
    return notes[i].getType();
}

void Recipe::setNoteType(int i, QString t) {
    if (notes[i].getType() == t)
        return;
    isDirty = true;
    if (i > -1) {
        notes[i].setType(t);
    }
}

void Recipe::setNoteNote(int i, QString n) {
    if (notes[i].getNote() == n)
        return;
    isDirty = true;
    notes[i].setNote(n);
}

QList<MashStep> *Recipe::getMashStepsList() {
    return &(getMash()->steps);
}

// Setters that need to do extra work:

void Recipe::setVolUnits(QString v)
{
    qDebug() << "Recipe set vol: " << v;
    if (kettleLossVol.getUnits() == v
            && postBoilVol.getUnits() == v
            && trubLossVol.getUnits() == v
            && miscLossVol.getUnits() == v)
        return;
    isDirty = true;
    kettleLossVol.convertTo(v);
    postBoilVol.convertTo(v);
    trubLossVol.convertTo(v);
    miscLossVol.convertTo(v);
    calcMaltTotals();
    calcHopsTotals();
}

void Recipe::setReadVolUnits(QString v) {
    if (kettleLossVol.getUnits() == v
            && postBoilVol.getUnits() == v
            && trubLossVol.getUnits() == v
            && miscLossVol.getUnits() == v)
        return;
    isDirty = true;
    kettleLossVol.setUnits(v);
    postBoilVol.setUnits(v);
    trubLossVol.setUnits(v);
    miscLossVol.setUnits(v);
    calcMaltTotals();
    calcHopsTotals();
}

void Recipe::setEstFg(double f) {
    if ((f != estFg) && (f > 0)) {
        isDirty = true;
        estFg = f;
        attenuation = 100 - ((estFg - 1) / (estOg - 1) * 100);
    }
}

void Recipe::setEstOg(double o) {
    if ((o != estOg) && (o > 0)) {
        isDirty = true;

        estOg = o;
        attenuation = 100 - ((estFg - 1) / (estOg - 1) * 100);
        qDebug() << "Setting Est OG: " << o << " Att: " << attenuation;
        calcEfficiency();
        qDebug() << "Setting Est OG: " << estOg << " Eff: " << efficiency;
    }
}

void Recipe::setEfficiency(double e) {
    if ((e != efficiency) && (e > 0)) {
        isDirty = true;
        efficiency = e;
        qDebug() << "EFficiency is set to " << e;
        calcMaltTotals();
    }
}

void Recipe::setAttenuation(double a) {
    if ((a != attenuation) && (a > 0)) {
        isDirty = true;
        attenuation = a;
        calcMaltTotals();
    }

}


void Recipe::setPreBoil(double u) {
    if (getPreBoilVol() == u)
        return;
    isDirty = true;

    // The one-true-volume is postBoil.. so calc it, and set it

    Quantity pre, post;
    pre.setUnits(getVolUnits());
    pre.setAmount(u);

    post.setUnits(getVolUnits());
    post.setAmount(pre.getValueAs(getVolUnits()) - getEvapVol(getVolUnits())
            - getChillShrinkVol(getVolUnits()));
    setPostBoil(post);
}


void Recipe::setPreBoil(Quantity p) {
    if (getPreBoilVol() == p.getValue()
            && getVolUnits() == p.getUnits())
        return;
    isDirty = true;

    // The one-true-volume is postBoil.. so calc it, and set it
    Quantity pre;
    pre.setUnits(getVolUnits());
    pre.setAmount(p.getValueAs(getVolUnits()) - getEvapVol(getVolUnits())
            - getChillShrinkVol(getVolUnits()));
    setPostBoil(pre);
}

void Recipe::setPostBoil(double p) {
    postBoilVol.setAmount(p);
    // Recalc all the bits
    calcMaltTotals();
    calcHopsTotals();
    calcPrimeSugar();
    calcKegPSI();
}

void Recipe::setPostBoil(Quantity p) {

    if (p.getUnits() == postBoilVol.getUnits()
            && p.getValue() == postBoilVol.getValue())
        return;
    isDirty = true;

    // One-true vol, set it and all the getters will go from there
    // Hack alert; chop off "double ugglyness" rounding errors at umtenth
    // decimal place
    // this is causing recalc problems:
    // long hackNumber = (long)(p.getValue() * 100);
    // p.setAmount((double)hackNumber / 100);
    postBoilVol = p;

    // Recalc all the bits
    calcMaltTotals();
    calcHopsTotals();
    calcPrimeSugar();
    calcKegPSI();
}

void Recipe::setFinalWortVol(double p) {
    // The one-true-volume is postBoil.. so calc it, and set it
    Quantity post;
    post.setUnits(getVolUnits());
    post.setAmount(p + getKettleLoss(getVolUnits())
            + getTrubLoss(getVolUnits()) + getMiscLoss(getVolUnits()));

    if (post.getValue() == p)
        return;
    isDirty = true;

    setPostBoil(post);
}

void Recipe::setFinalWortVol(Quantity p) {

    qDebug() << "Recalculating final wort to " << p.getValue();
    // The one-true-volume is postBoil.. so calc it, and set it
    Quantity post;
    post.setUnits(getVolUnits());
    post.setAmount(p.getValueAs(getVolUnits()) + getKettleLoss(getVolUnits())
            + getTrubLoss(getVolUnits()) + getMiscLoss(getVolUnits()));

    if (post.getValue() == p.getValue()
            && post.getUnits() == p.getUnits())
        return;

    isDirty = true;
    setPostBoil(post);
}

/*
 * Functions that add/remove from ingredient lists
 */

void Recipe::addMalt() {
    Fermentable *m = new Fermentable();
    fermentables.push_back(m);
    std::sort(fermentables.begin(), fermentables.end(), Ingredient::sortWeight);
}

Fermentable* Recipe::addMalt(Fermentable *m) {
    isDirty = true;

    // TODO: Sort the fermentable List
    /*
    Comparator<Fermentable> c = new Comparator<Fermentable>()  {
        int compare(Fermentable h1, Fermentable h2){

            Debug.print("Comparing " + h1.getAmountAs(Quantity.LB) + " to " + h2.getAmountAs(Quantity.LB) );
            if(h1.getAmountAs(Quantity.LB) > h2.getAmountAs(Quantity.LB))
                return 1;
            if(h1.getAmountAs(Quantity.LB) < h2.getAmountAs(Quantity.LB))
                return -1;
            if(h1.getAmountAs(Quantity.LB) == h2.getAmountAs(Quantity.LB))
                return 0;
            return 0;

        }

    };
    Collections.sort(fermentables, c);
    Collections.reverse(fermentables);
    */

    fermentables.push_back(m);
    std::sort(fermentables.begin(), fermentables.end(), Ingredient::sortWeight);
    calcMaltTotals();
    return fermentables.last();
}

void Recipe::delMalt(int i) {
    isDirty = true;

    if (!fermentables.empty() && (i > -1) && (i < fermentables.size())) {
        fermentables.erase(fermentables.begin()+i);
        std::sort(fermentables.begin(), fermentables.end(), Ingredient::sortWeight);
        calcMaltTotals();
    }
}

void Recipe::addHop() {
    Hop *h = new Hop();
    isDirty = true;
    hops.append(h);
    // SORT HOPS
    calcHopsTotals();
}

Hop *Recipe::addHop(Hop *h) {
    isDirty = true;
    hops.append(h);
    // SORT HOPS
    calcHopsTotals();
    return hops.last();
}

void Recipe::delHop(int i) {
    isDirty = true;
    if (!hops.empty() && (i > -1) && (i< hops.size())) {
        hops.erase(hops.begin()+i);
        calcHopsTotals();
    }
}

Misc *Recipe::addMisc(Misc *m) {
    isDirty = true;
    misc.push_back(m);
    calcMiscCost();
    return misc.last();
}

void Recipe::delMisc(int i) {
    isDirty = true;
    if (!misc.empty() && (i > -1) && (i < misc.size())) {
        misc.erase(misc.begin()+i);
        calcMiscCost();
    }
}

void Recipe::calcMiscCost() {
    double MiscCost = 0;
    for (int i = 0; i < misc.size(); i++) {
        Misc *m = misc.at(i);
        MiscCost += m->getAmountAs(m->getUnits()) * m->getCostPerU();
    }
    totalMiscCost = MiscCost;
}

void Recipe::addNote(Note n) {
    isDirty = true;
    notes.push_back(n);
}

void Recipe::delNote(int i) {
    isDirty = true;
    if (!notes.empty() && (i > -1) && (i < notes.size())) {
        notes.erase(notes.begin()+i);
    }
}

/**
 * Handles a string of the form "d u", where d is a double amount, and u is
 * a string of units. For importing the quantity attribute from QBrew xml.
 *
 * @param a
 */
void Recipe::setAmountAndUnits(QString a) {
    int i = a.indexOf(" ");
    QString d = a.mid(0, i);
    QString u = a.mid(i);

    Quantity post;
    post.setUnits(u.trimmed());
    post.setAmount(d.trimmed().toDouble());

    if (post.getUnits() == postBoilVol.getUnits()
            && post.getValue() == postBoilVol.getValue())
        return;

    isDirty = true;
    setPostBoil(post);
}

/**
 * Calculate all the malt totals from the array of malt objects TODO: Other
 * things to implement: - cost tracking - hopped malt extracts (IBUs) - the %
 * that this malt represents - error checking
 *
 * @return
 */

// Calc functions.
void Recipe::calcEfficiency() {
    double possiblePoints = 0;
    for (int i = 0; i < fermentables.size(); i++) {
        Fermentable *m = fermentables[i];
        possiblePoints += (m->getPppg() - 1) * m->getAmountAs(CONVERTER_LB) / getPostBoilVol(CONVERTER_GAL);

    }
    qDebug() << estOg << " : " << possiblePoints;
    efficiency = (estOg - 1) / possiblePoints * 100;
    qDebug() << "Efficiency calc'd as " << efficiency;
}

void Recipe::calcMaltTotals() {
    if (!allowRecalcs) {
        return;
    }
    // Start off with a sort
    std::sort(fermentables.begin(), fermentables.end(), Fermentable::sortWeight);
    double maltPoints = 0;
    double fermentingMaltPoints = 0;
    double MaltLbs = 0;
    double MaltCost = 0;
    double MashLbs = 0;

    double curPoints = 0.0;

    // first figure out the total we're dealing with
    for (int i = 0; i < fermentables.size(); i++) {
        Fermentable *m = fermentables[i];
        if (m->getName().compare("") == 0
                || m->getAmountAs(CONVERTER_LB) <= 0.00) {
            continue;
        }
        MaltLbs += (m->getAmountAs(CONVERTER_LB));
        if (m->getMashed()) { // apply efficiency and add to mash weight
            curPoints = (m->getPppg() - 1) * m->getAmountAs(CONVERTER_LB) * getEfficiency()
                    / getPostBoilVol(CONVERTER_GAL);
            MashLbs += (m->getAmountAs(CONVERTER_LB));
        } else {
            curPoints = (m->getPppg() - 1) * m->getAmountAs(CONVERTER_LB) * 100 / getPostBoilVol(CONVERTER_GAL);
        }

        maltPoints += curPoints;

        // Check to see if we can ferment this sugar
        if (m->ferments()) {
            fermentingMaltPoints += curPoints;
        }



        MaltCost += m->getCostPerU() * m->getAmountAs(m->getUnits());
    }

    for (int i = 0; i < fermentables.size(); i++) {
        Fermentable *m = fermentables[i];
        // Malt % By Weight
        if (m->getAmountAs(CONVERTER_LB) == 0) {
            m->setPercent(0);
        } else {
            m->setPercent((m->getAmountAs(CONVERTER_LB) / MaltLbs * 100));
        }
    }

    totalMaltCost = MaltCost;
    totalMashLbs = MashLbs;
    totalMaltLbs = MaltLbs;

    mash.setMaltWeightLbs(MaltLbs);


    // set the fields in the object
    double effFactor = (efficiency / 100);
    estOg = (maltPoints / 100) + 1;
    // rounding
    estOg = floor(estOg*1000)/1000;
    qDebug() << "Calc'd estOG as " << estOg << " With " << maltPoints << " eff: " << getEfficiency();

    estFermOg = (fermentingMaltPoints/100) + 1;
    estFermOg = floor(estFermOg*1000)/1000;

    qDebug() << "Efficiency factor is " << effFactor;
    qDebug() << "Malt Points: " << maltPoints;


    double attGrav = (estFermOg - 1) * (attenuation / 100);

    // FG
    estFg = estOg - attGrav;

    if (estFg == estOg) {
        qDebug() << "Gravities are the same! Attenuation is: " << attenuation;
        qDebug() << "Fermenting: " << fermentingMaltPoints;
    }
    // mash.setMaltWeight(totalMashLbs);
    //emit dataChanged(new QModelIndex(), new QModelIndex());
}

void Recipe::calcHopsTotals() {

    if (!allowRecalcs) {
        return;
    }

    std::sort(hops.begin(), hops.end(), Ingredient::sortWeight);
    double ibuTotal = 0;
    double HopsCost = 0;
    double HopsOz = 0;

    for (int i = 0; i < hops.size(); i++) {
        // calculate the average OG of the boil
        // first, the OG at the time of addition:
        double adjPreSize, aveOg = 0;
        Hop *h = hops[i];

        int time = h->getMinutes();
        if (h->getAdd() == HOP_FWH) {
            time = time - fwhTime.toDouble();
        } else if (h->getAdd() == HOP_MASH) {
            time = mashHopTime.toDouble();
        } else if (h->getAdd() == HOP_DRY) {
            time = dryHopTime.toDouble();
        }

        if (h->getMinutes() > 0) {
            adjPreSize = getPostBoilVol(CONVERTER_GAL)
                    + (getPreBoilVol(CONVERTER_GAL) - getPostBoilVol(CONVERTER_GAL))
                    / (getBoilMinutes() / h->getMinutes());
        } else {
            adjPreSize = getPostBoilVol(CONVERTER_GAL);
        }

        aveOg = 1 + (((estOg - 1) + ((estOg - 1) / (adjPreSize / getPostBoilVol(CONVERTER_GAL)))) / 2);
        if (ibuCalcMethod.toString() == TINSETH) {
            h->setIBU(BrewCalcs::calcTinseth(h->getAmountAs(CONVERTER_OZ), getPostBoilVol(CONVERTER_GAL), aveOg, time,
                                             h->getAlpha(), ibuHopUtil.toDouble()));
        } else if (ibuCalcMethod.toString() == RAGER) {
            h->setIBU(BrewCalcs::CalcRager(h->getAmountAs(CONVERTER_OZ), getPostBoilVol(CONVERTER_GAL), aveOg, time,
                    h->getAlpha()));
        } else {
            h->setIBU(BrewCalcs::CalcGaretz(h->getAmountAs(CONVERTER_OZ), getPostBoilVol(CONVERTER_GAL), aveOg, time,
                    getPreBoilVol(CONVERTER_GAL), 1, h->getAlpha()));
        }
        if (h->getType() == HOP_PELLET) {
            h->setIBU(h->getIBU() * (1.0 + (getPelletHopPct() / 100)));
        }

        ibuTotal += h->getIBU();

        HopsCost += h->getCostPerU() * h->getAmountAs(h->getUnits());
        HopsOz += h->getAmountAs(CONVERTER_OZ);
    }

    totalHopsCost = HopsCost;
    totalHopsOz = HopsOz;
    ibu = ibuTotal;

}

QString Recipe::addXMLHeader(QString in) {
    in = "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\n" + in;
    return in;
}

QString Recipe::toXML(QString printOptions){
    QString sb = "";
    sb.append("<STRANGEBREWRECIPE version = \"" + version + "\">\n");
    sb.append("<!-- This is a SBQT export.  StrangeBrew 1.8 will not import it. -->\n");
    if (printOptions != "") {
        sb.append(printOptions);
    }
    sb.append("  <DETAILS>\n");
    sb.append(SBStringUtils::xmlElement("NAME", SBStringUtils::subEntities(name), 3));
    sb.append(SBStringUtils::xmlElement("BREWER", SBStringUtils::subEntities(brewer), 3));
    sb.append(SBStringUtils::xmlElement("NOTES", SBStringUtils::subEntities(comments), 3));
    sb.append(SBStringUtils::xmlElement("EFFICIENCY",  efficiency, 3));
    sb.append(SBStringUtils::xmlElement("OG", SBStringUtils::format(estOg, 3), 3));
    sb.append(SBStringUtils::xmlElement("FG", SBStringUtils::format(estFg, 3), 3));
    sb.append(SBStringUtils::xmlElement("STYLE", style->getName(),3));
    if (mashed)
        sb.append(SBStringUtils::xmlElement("MASH", "True", 3));
    else
        sb.append(SBStringUtils::xmlElement("MASH", "False", 3));

    // TODO: ebc vs srm
    sb.append(SBStringUtils::xmlElement("LOV", SBStringUtils::format(getColour(SRM), 1), 3));
    sb.append(SBStringUtils::xmlElement("IBU", SBStringUtils::format(ibu, 1), 3));
    sb.append(SBStringUtils::xmlElement("ALC", SBStringUtils::format(getAlcohol(), 1), 3));
    sb.append("  <!-- SBJ1.0 Extensions: -->\n");
    sb.append(SBStringUtils::xmlElement("EVAP", evap, 3));
    sb.append(SBStringUtils::xmlElement("EVAP_METHOD", evapMethod.toString(), 3));
    sb.append("  <!-- END SBJ1.0 Extensions -->\n");
    sb.append(SBStringUtils::xmlElement("BOIL_TIME", boilMinutes, 3));
    sb.append(SBStringUtils::xmlElement("PRESIZE", getPreBoilVolStr(), 3));
    sb.append(SBStringUtils::xmlElement("SIZE", getFinalWortVolStr(), 3));
    sb.append(SBStringUtils::xmlElement("SIZE_UNITS", getVolUnits(), 3));
    sb.append(SBStringUtils::xmlElement("MALT_UNITS", maltUnits.toString(), 3));
    sb.append(SBStringUtils::xmlElement("HOPS_UNITS", hopUnits.toString(), 3));
    sb.append(SBStringUtils::xmlElement("YEAST", yeast->getName(), 3));

    sb.append(SBStringUtils::xmlElement("RECIPE_DATE", created.toString("MM/dd/yyyy"), 3));
    sb.append(SBStringUtils::xmlElement("ATTENUATION", attenuation, 3));
    sb.append("  <!-- SBJ1.0 Extensions: -->\n");
    sb.append(SBStringUtils::xmlElement("ALC_METHOD", getAlcMethod(), 3));
    sb.append(SBStringUtils::xmlElement("IBU_METHOD", ibuCalcMethod.toString(), 3));
    sb.append(SBStringUtils::xmlElement("COLOUR_METHOD", colourMethod.toString(), 3));
    sb.append(SBStringUtils::xmlElement("KETTLE_LOSS", getKettleLossStr(), 3));
    sb.append(SBStringUtils::xmlElement("TRUB_LOSS", getTrubLossStr(), 3));
    sb.append(SBStringUtils::xmlElement("MISC_LOSS", getMiscLossStr(), 3));
    sb.append(SBStringUtils::xmlElement("PELLET_HOP_PCT", pelletHopPct.toString(), 3));
    sb.append(SBStringUtils::xmlElement("YEAST_COST", yeast->getCostPerU(), 3));
    sb.append(SBStringUtils::xmlElement("OTHER_COST", otherCost.toString(), 3));
    sb.append("  <!-- END SBJ1.0 Extensions -->\n");
    sb.append("  </DETAILS>\n");

    // fermentables list:
    sb.append("  <FERMENTABLES>\n");
    sb.append(SBStringUtils::xmlElement("TOTAL",
                                       Quantity::convertUnit(CONVERTER_LB, maltUnits.toString(), totalMaltLbs.toDouble()), 4));
    for (int i = 0; i < fermentables.size(); i++) {
        Fermentable *m = fermentables[i];
        sb.append(m->toXML());
    }
    sb.append("  </FERMENTABLES>\n");

    // hops list:
    sb.append("  <HOPS>\n");
    sb.append(SBStringUtils::xmlElement("TOTAL",
                                       Quantity::convertUnit(CONVERTER_OZ, hopUnits.toString(), totalHopsOz.toDouble()), 4));
    for (int i = 0; i < hops.size(); i++) {
        Hop *h = hops[i];
        sb.append(h->toXML());
    }
    sb.append("  </HOPS>\n");

    // misc ingredients list:
    sb.append("  <MISC>\n");
    for (int i = 0; i < misc.size(); i++) {
        Misc *mi = misc.at(i);
        sb.append(mi->toXML());
    }
    sb.append("  </MISC>\n");

    sb.append(mash.toXml());

    // Fermentation Schedule
    sb.append("   <FERMENTATION_SCHEDULE>\n");
    for (int i = 0; i < fermentationSteps.size(); i++) {
        sb.append(fermentationSteps[i].toXML());
    }
    sb.append("   </FERMENTATION_SCHEDULE>\n");

    // Carb
    sb.append("   <CARB>\n");
    sb.append("      <BOTTLETEMP>" + SBStringUtils::format(bottleTemp.toDouble(), 1) + "</BOTTLETEMP>\n");
    sb.append("      <SERVTEMP>" + SBStringUtils::format(servTemp.toDouble(), 1) + "</SERVTEMP>\n");
    sb.append("      <VOL>" + SBStringUtils::format(targetVol.toDouble(), 1) + "</VOL>\n");
    sb.append("      <SUGAR>" + primeSugar->getName() + "</SUGAR>\n");
    sb.append("      <AMOUNT>" + SBStringUtils::format(primeSugar->getAmountAs(primeSugar->getUnits()), 1)
            + "</AMOUNT>\n");
    sb.append("      <SUGARU>" + primeSugar->getUnitsAbrv() + "</SUGARU>\n");
    sb.append("      <TEMPU>" + carbTempU.toString() + "</TEMPU>\n");

    if (kegged)
        sb.append("      <KEG>True</KEG>\n");
    else
        sb.append("      <KEG>False</KEG>\n");

    sb.append("      <PSI>" + SBStringUtils::format(kegPSI.toDouble(), 2) + "</PSI>\n");
    sb.append("   </CARB>\n");

    if ((sourceWater.getName() != "") || (targetWater.getName() != "")) {
        sb.append("   <WATER_PROFILE>\n");
        if (sourceWater.getName() != "") {
            sb.append("      <SOURCE_WATER>\n");
            sb.append(sourceWater.toXML(9));
            sb.append("      </SOURCE_WATER>\n");
        }
        if (targetWater.getName() != "") {
            sb.append("      <TARGET_WATER>\n");
            sb.append(targetWater.toXML(9));
            sb.append("      </TARGET_WATER>\n");
        }

        if (brewingSalts.size() > 0) {
            sb.append("      <SALTS>\n");
            for (int i = 0; i < brewingSalts.size(); i++) {
                sb.append("         <SALT>\n");
                sb.append(brewingSalts[i].toXML(12));
                sb.append("         </SALT>\n");
            }
            sb.append("      </SALTS>\n");
        }
        sb.append("      <ACID>\n");
        sb.append("         <NAME>" + acid.getName() + "</NAME>\n");
        sb.append("         <AMT>" + SBStringUtils::format(getAcidAmount(), 2) + "</AMT>\n");
        sb.append("         <ACIDU>" + acid.getAcidUnit() + "</ACIDU>\n");
        sb.append("      </ACID>\n");

        sb.append("   </WATER_PROFILE>\n");
    }

    // notes list:
    sb.append("  <NOTES>\n");
    for (int i = 0; i < notes.size(); i++) {
        sb.append(notes[i].toXML());
    }
    sb.append("  </NOTES>\n");

    // style xml:
    sb.append(style->toXML());

    sb.append("</STRANGEBREWRECIPE>");

    return addXMLHeader(sb);
}

QString Recipe::toText() {
    return toText(false);
}

QString Recipe::toText(bool detailed) {
    //MessageFormat mf;
    QString sb;
    sb.append("StrangeBrew QT v." + version + " recipe text output\n\n");
    sb.append("Details:\n");
    sb.append("Name: " + name + "\n");
    sb.append("Brewer: " + brewer  + "\n");
    sb.append("Size: " + SBStringUtils::format(getPostBoilVol(getVolUnits()), 1) + " " + getVolUnits() + "\n");
    sb.append("Style: " + style->getName() + "\n");

    QString temp = QString("OG: %1,\tFG:%2, \tAlc:%3, \tIBU:%4\n").arg(SBStringUtils::format(estOg, 3), SBStringUtils::format(estFg, 3),
              SBStringUtils::format(getAlcohol(), 2), SBStringUtils::format(ibu,2));
    sb.append(temp);
    //Object[] objs = { new Double(estOg), new Double(estFg), new Double(getAlcohol()), new Double(ibu) };
    //sb.append(mf.format(objs));
    sb.append("(Alc method: by " + getAlcMethod() + "; IBU method: " + ibuCalcMethod.toString() + ")\n");
    sb.append("\nYeast: " + yeast->getName() + "\n");
    sb.append("\nFermentables:\n");
    temp = QString("%1 %2 %3 %4 %4 %5 %6\n").arg("Name", 30)
            .arg("amount", 6)
            .arg("units", 5).arg("pppg")
            .arg("lov", 6)
            .arg("%", 5);
    sb.append(temp);
    //mf = new MessageFormat("{0} {1} {2} {3,number,0.000} {4} {5}%\n");
    for (int i = 0; i < fermentables.size(); i++) {
        Fermentable *f = fermentables[i];
        sb.append(f->toString());
        sb.append("\n");
    }

    sb.append("\nHops:\n");
    temp = QString("%1 amount units  Alpha    Min   IBU\n").arg("Name", 20);
    sb.append(temp);

    for (int i = 0; i < hops.size(); i++) {
        Hop *h = hops[i];
        sb.append(h->toString());
    }

    if (mash.getStepSize() > 0) {
        sb.append("\nMash:\n");
        //sb.append(Recipe.padLeft("Step ", 10, ' ') + "  Temp   End    Ramp    Min	Input	Output	Water Temp\n");

        //mf = new MessageFormat("{0} {1} {2} {3} {4} {5} {6} {7}\n");
        for (int i = 0; i < mash.getStepSize(); i++) {
            sb.append(mash.steps[i].toString());
            /*
            Object[] objm = { Recipe.padLeft(mash.getStepType(i), 10, ' '),
                    Recipe.padRight(" " + mash.getStepStartTemp(i), 6, ' '),
                    Recipe.padRight(" " + mash.getStepEndTemp(i), 6, ' '),
                    Recipe.padRight(" " + mash.getStepRampMin(i), 4, ' '),
                    Recipe.padRight(" " + mash.getStepMin(i), 6, ' '),
                    Recipe.padRight(" " + SBStringUtils::format(mash.getStepInVol(i), 2) , 6, ' '),
                    Recipe.padRight(" " + SBStringUtils::format(mash.getStepOutVol(i), 2), 6, ' '),
                    Recipe.padRight(" " + mash.getStepTemp(i), 6, ' ')};

            sb.append(mf.format(objm));
            */
        }
    }

    if (notes.size() > 0) {
        sb.append("\nNotes:\n");
        for (int i = 0; i < notes.size(); i++) {
            sb.append(notes[i].toString());
        }
    }

    // only print this stuff for detailed text output:

    if (detailed) {
        // Fermentation Schedule
        if (fermentationSteps.size() > 0) {
            sb.append("\nFermentation Schedule:\n");
            sb.append("Step  Time   Days\n");
            //mf = new MessageFormat("{0} {1} {2}\n");
            for (int i = 0; i < fermentationSteps.size(); i++) {
                FermentStep f = fermentationSteps[i];
                //sb.append(f.toString());
                /*
                 * Object[] objm = { Recipe.padLeft(f.getType(), 10, ' '),
                        Recipe.padRight(" " + f.getTime(), 6, ' '),
                        Recipe.padRight(" " + f.getTemp() + f.getTempU(), 6, ' ') };
                sb.append(mf.format(objm));
                */
            }
        }

        // Carb
        sb.append("\nCarbonation:  " + targetVol.toString() + " volumes CO2\n");
        sb.append(" Bottle Temp: " + bottleTemp.toString() + carbTempU.toString() +
                  "  Serving Temp:" + servTemp.toString() + carbTempU.toString() + "\n");
        sb.append(" Priming: " + SBStringUtils::format(primeSugar->getAmountAs(primeSugar->getUnits()), 1)
                + primeSugar->getUnitsAbrv() + " of " + primeSugar->getName() + "\n");
        sb.append(" Or keg at: " + kegPSI.toString() + "PSI\n");

        if ((sourceWater.getName() != "") || (targetWater.getName() != "")) {
            sb.append("\nWater Profile\n");
            sb.append(" Source Water: " + sourceWater.toString() + "\n");
            sb.append(" Target Water: " + targetWater.toString() + "\n");

            if (brewingSalts.size() > 0) {
                sb.append(" Salt Additions per Gal\n");
                for (int i = 0; i < brewingSalts.size(); i++) {
                    sb.append("  " + brewingSalts[i].toString() + "\n");
                }
            }
            sb.append(" Acid: " + SBStringUtils::format(getAcidAmount(), 2) + acid.getAcidUnit() + " per gal of "
                    + acid.getName() + " Acid\n");
        }
    }

    return sb;
}

/*
 * Scale the recipe up or down, so that the new OG = old OG, and new IBU =
 * old IBU
 */
void Recipe::scaleRecipe(Quantity newSize) {
    double currentSize = getPostBoilVol(newSize.getUnits());
    double conversionFactor = newSize.getValue() / currentSize;

    if (conversionFactor != 1) {
        // TODO: figure out a way to make sure old IBU = new IBU
        for (int i = 0; i < getHopsListSize(); i++) {
            Hop *h = getHop(i);
            h->setAmount(h->getAmountAs(h->getUnits()) * conversionFactor);
            hops.replace(i, h);
        }
        for (int i = 0; i < getMaltListSize(); i++) {
            Fermentable *f = getFermentable(i);
            f->setAmount(f->getAmountAs(f->getUnits()) * conversionFactor);
            fermentables.replace(i, f);
        }
        setPostBoil(newSize);
        setVolUnits(newSize.getUnits());
    }
}

double Recipe::getBottleTemp() {
    return bottleTemp.toDouble();
}

void Recipe::setBottleTemp(double b) {
    if (bottleTemp == b)
        return;

    isDirty = true;
    this->bottleTemp = b;
    calcPrimeSugar();
}

QString Recipe::getCarbTempU() const {
    return carbTempU.toString();
}

void Recipe::setCarbTempU(QString carbU) {
    if (carbTempU == carbU)
        return;

    isDirty = true;
    carbTempU = carbU;
}

bool Recipe::isKegged() const {
    return kegged;
}

void Recipe::setKegged(bool k) {
    if (kegged == k)
        return;
    isDirty = true;
    this->kegged = k;
    calcKegPSI();
}

void Recipe::setKegged(QString f) {
    bool newK;
    if (f.compare("yes", Qt::CaseInsensitive) == 0
        || f.compare("true", Qt::CaseInsensitive) == 0
        || f.compare("1", Qt::CaseInsensitive) == 0 )
        newK = true;
    else
        newK = false;

    if (newK == kegged)
        return;

    isDirty = true;
    calcKegPSI();
}

double Recipe::getKegPSI() const {
    return this->kegPSI.toDouble();
}

void Recipe::setKegPSI(double psi) {
    if (kegPSI == psi)
        return;
    isDirty = true;
    this->kegPSI = psi;
}


double Recipe::getKegTubeLength() const {
    double resistance = 1;
    if (getKegTubeID() == "3/16") {
        resistance = 2.4;
    } else {
        resistance = 0.7;
    }
    return (getKegPSI() - (getKegTubeHeight() * 0.5) - 1) / resistance;
}

double Recipe::getKegTubeVol() {
    double mlPerFoot = 1;
    if (getKegTubeID() == "3/16") {
        mlPerFoot = 4.9;
    } else {
        mlPerFoot = 9.9;
    }

    return getKegTubeLength() * mlPerFoot;
}

void Recipe::setKegTubeHeight(double height) {
    kegTubeHeight = height;
}

double Recipe::getKegTubeHeight() const {
    return kegTubeHeight.toDouble();
}

void Recipe::setKegTubeID(QString id) {
    kegTubeID = id;
}

QString Recipe::getKegTubeID() const {
    return this->kegTubeID.toString();
}

QString Recipe::getPrimeSugarName() const {
    return primeSugar->getName();
}

QString Recipe::getPrimeSugarU() const {
    return primeSugar->getUnitsAbrv();
}

void Recipe::setPrimeSugarU(QString primeU) {
    if (primeU == primeSugar->getUnits())
        return;
    isDirty = true;
    this->primeSugar->setUnits(primeU);
    calcPrimeSugar();
}

double Recipe::getPrimeSugarAmt() const {
    return primeSugar->getAmountAs(primeSugar->getUnitsAbrv());
}

void Recipe::calcPrimeSugar() {
    double dissolvedCO2 = BrewCalcs::dissolvedCO2(getBottleTemp());
    double primeSugarGL = BrewCalcs::PrimingSugarGL(dissolvedCO2, getTargetVol(), getPrimeSugar());

    // Convert to selected Units
    double neededPrime = Quantity::convertUnit(CONVERTER_G, getPrimeSugarU(), primeSugarGL);
    neededPrime *= Quantity::convertUnit(CONVERTER_L, getVolUnits(), primeSugarGL);
    neededPrime *= getFinalWortVol(getVolUnits());

    primeSugar->setAmount(neededPrime);
}

void Recipe::calcKegPSI() {
    double psi = BrewCalcs::KegPSI(servTemp.toDouble(), getTargetVol());
    kegPSI = psi;
}

void Recipe::setPrimeSugarName(QString n) {
    if (n == primeSugar->getName())
        return;
    isDirty = true;
    this->primeSugar->setName(n);
    // Name comes with Yeild! set it too
    QList<PrimeSugar*> db = Database::primeSugarDB;
    for (int i = 0; i < db.size(); i++) {
        if (n == db[i]->getName()) {
            primeSugar->setYield(db[i]->getYield());
            calcPrimeSugar();
        }
    }
}

void Recipe::setPrimeSugarAmount(double q) {
    if (q == primeSugar->getAmount())
        return;
    isDirty = true;
    primeSugar->setAmount(q);
}

double Recipe::getServTemp() const {
    return servTemp.toDouble();
}

void Recipe::setServTemp(double serv) {
    if (servTemp == serv)
        return;
    isDirty = true;
    servTemp = serv;
    calcKegPSI();
}

double Recipe::getTargetVol() const {
    return targetVol.toDouble();
}

void Recipe::setTargetVol(double target) {
    if (target == targetVol)
        return;

    isDirty = true;
    this->targetVol = target;
    calcPrimeSugar();
    calcKegPSI();
}

PrimeSugar *Recipe::getPrimeSugar() const {
    return primeSugar;
}

void Recipe::setPrimeSugar(QString prime) {
    PrimeSugar *ps = Database::findSugar(prime);

    if (ps == NULL)
        return;

    setPrimeSugar(ps);
}

void Recipe::setPrimeSugar(PrimeSugar *primeSugar) {
    this->primeSugar = primeSugar;
    calcPrimeSugar();
}

WaterProfile Recipe::getSourceWater() const {
    return sourceWater;
}

WaterProfile Recipe::getTargetWater() const {
    return targetWater;
}

void Recipe::setSourceWater(WaterProfile sourceWater) {
    this->sourceWater = sourceWater;
}

void Recipe::setTargetWater(WaterProfile targetWater) {
    this->targetWater = targetWater;
}

WaterProfile Recipe::getWaterDifference() {
    WaterProfile diff;
    diff.setCa(getTargetWater().getCa() - getSourceWater().getCa());
    diff.setCl(getTargetWater().getCl() - getSourceWater().getCl());
    diff.setMg(getTargetWater().getMg() - getSourceWater().getMg());
    diff.setNa(getTargetWater().getNa() - getSourceWater().getNa());
    diff.setSo4(getTargetWater().getSo4() - getSourceWater().getSo4());
    diff.setHco3(getTargetWater().getHco3() - getSourceWater().getHco3());
    diff.setHardness(getTargetWater().getHardness() - getSourceWater().getHardness());
    diff.setAlkalinity(getTargetWater().getAlkalinity() - getSourceWater().getAlkalinity());
    diff.setTds(getTargetWater().getTds() - getSourceWater().getTds());
    diff.setPh(getTargetWater().getPh() - getSourceWater().getPh());

    return diff;
}

void Recipe::addSalt(Salt s) {
    // Check if ths salt already exists!
    try {
        Salt temp = getSaltByName(s.getName());
        this->delSalt(temp);
    } catch (const QString &errmsg) {
        qDebug() << errmsg;
        // Doesn't exist
    } catch (...) {
        qDebug() << "Uncaught exception when getting a salt";
    }

    this->brewingSalts.push_back(s);
}

void Recipe::delSalt(Salt s) {
    Salt current;
    for (int i = 0; i < brewingSalts.size(); i++) {
        current = brewingSalts[i];
        if (current == s)
            this->brewingSalts.erase(brewingSalts.begin() + i);
    }
}

void Recipe::delSalt(int i) {
    if(!brewingSalts.empty() && (i > -1) && (i < brewingSalts.size()))
        this->brewingSalts.erase(brewingSalts.begin() + i);
}

void Recipe::setSalts(QList<Salt> s) {
    this->brewingSalts = s;
}

QList<Salt> Recipe::getSalts() {
    return this->brewingSalts;
}

Salt Recipe::getSalt(int i) const {
    return this->brewingSalts[i];
}

Salt Recipe::getSaltByName(QString name) const{
    for (int i = 0; i < brewingSalts.size(); i++) {

        if (brewingSalts[i].getName() == name) {
            return brewingSalts[i];
        }
    }
    throw "Couldn't find salt " + name;
}

Acid Recipe::getAcid() const {
    return acid;
}

void Recipe::setAcid(Acid acid) {
    this->acid = acid;
}

double Recipe::getAcidAmount() {
    double millEs = BrewCalcs::acidMillequivelantsPerLiter(getSourceWater().getPh(), getSourceWater()
            .getAlkalinity(), getTargetWater().getPh());
    double moles = BrewCalcs::molesByAcid(getAcid(), millEs, getTargetWater().getPh());
    double acidPerL = BrewCalcs::acidAmountPerL(getAcid(), moles);
    return Quantity::convertUnit(CONVERTER_GAL, CONVERTER_L, acidPerL);
}

double Recipe::getAcidAmount5_2() {
    double millEs = BrewCalcs::acidMillequivelantsPerLiter(getSourceWater().getPh(), getSourceWater()
            .getAlkalinity(), 5.2);
    double moles = BrewCalcs::molesByAcid(getAcid(), millEs, 5.2);
    double acidPerL = BrewCalcs::acidAmountPerL(getAcid(), moles);
    return Quantity::convertUnit(CONVERTER_GAL, CONVERTER_L, acidPerL);
}

void Recipe::substractIngredients() {
    // THe user wants to subtract the ingredients from their pantry
    // we have to slowly iterate the list, because someone may change the AA and therefore
    // an object match doesn't work
    QList<Fermentable*> fDB = Database::fermDB;

    for (int i = 0; i < fermentables.size(); i++) {
        int j = 0;
        // double iteration because there's no choice :(

        while(j < fDB.size()) {
            if(fDB[j]->getName() == fermentables[i]->getName()) {
                fDB[j]->setStock(fDB[j]->getStock() - fermentables[i]->getAmountAs(fDB[j]->getUnits()));
                break;
            }
            j++;
        }
    }

    Database::getInstance().writeFermentables(fDB);


    QList<Hop*> hDB = Database::hopsDB;

    for (int i = 0; i < hops.size(); i++) {

        int j = 0;
        // double iteration because there's no choice :(
        while(j < hDB.size()) {

            if(hDB[j]->getName() == hops[i]->getName()) {
                hDB[j]->setStock(hDB[j]->getStock() - hops[i]->getAmountAs(hDB[j]->getUnits()));
                break;
            }
            j++;
        }
    }

    Database::getInstance().writeHops(hDB);
}

bool Recipe::pushRecipe() {


    return true;
}

void Recipe::replaceHop(int &i, Hop *h)
{
    hops[i] = h;
}

void Recipe::replaceMisc(int &i, Misc *m)
{
    misc.replace(i, m);
}

QString Recipe::getFilePath() {
    return fileinfo.absolutePath();
}

QString Recipe::getFullFileName() {
    return fileinfo.canonicalFilePath();
}

QString Recipe::getFileName() {
    return fileinfo.fileName();
}

void Recipe::setFileName(QString f) {
    fileinfo.setFile(f);
}
