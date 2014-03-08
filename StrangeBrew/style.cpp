#include "style.h"

Style::Style()
{
    name = "";
    category = "";
    catNum = "";
    ogLow = 0.0;
    ogHigh = 0.0;
    fgLow = 0.0;
    fgHigh = 0.0;
    alcLow = 0.0;
    alcHigh = 0.0;
    ibuLow = 0.0;
    ibuHigh = 0.0;
    srmLow = 0.0;
    srmHigh = 0.0;
    ogFlexible = false;
    fgFlexible = false;
    ibuFlexible = false;
    srmFlexible = false;
    alcFlexible = false;
    examples = "";
    // QString description;

    aroma = "";
    appearance = "";
    flavour = "";
    mouthfeel = "";
    impression = "";
    comments = "";
    ingredients = "";
    year = "";
    type = "";
}

QString Style::getName() const {
    return name;
}

QString Style::getDescription() {
    QString s = "";
    if (impression != "")
        s.append("<b>Impression:</b> " + impression + "\n");
    if (comments != "")
        s.append("<b>Comments:</b> " + comments);

    return s;
}

/**
 * @return Returns the alcHigh.
 */
double Style::getAlcHigh() const {
    return alcHigh;
}
/**
 * @return Returns the alcLow.
 */
double Style::getAlcLow() const {
    return alcLow;
}
/**
 * @return Returns the category.
 */
QString Style::getCategory() const {
    return category;
}
/**
 * @return Returns the catNum.
 */
QString Style::getCatNum() const {
    return catNum;
}
/**
 * @return Returns the examples.
 */
QString Style::getExamples() const {
    return examples;
}

/**
 * @return Returns the ibuHigh.
 */
double Style::getIbuHigh() const {
    return ibuHigh;
}
/**
 * @return Returns the ibuLow.
 */
double Style::getIbuLow() const {
    return ibuLow;
}
/**
 * @return Returns the srmHigh.
 */
double Style::getSrmHigh() const {
    return srmHigh;
}
/**
 * @return Returns the srmLow.
 */
double Style::getSrmLow() const {
    return srmLow;
}
/**
 * @return Returns the ogHigh.
 */
double Style::getOgHigh() const {
    return ogHigh;
}
/**
 * @return Returns the ogLow.
 */
double Style::getOgLow() const {
    return ogLow;
}

/**
 * @return Returns the ogHigh.
 */
double Style::getFgHigh() const {
    return fgHigh;
}
/**
 * @return Returns the ogLow.
 */
double Style::getFgLow() const {
    return fgLow;
}

QString Style::getYear() const {
    return year;
}
// set methods:
void Style::setName(QString n) {
    name = n;
}

/**
 * @param alcHigh The alcHigh to set.
 */
void Style::setAlcHigh(double alcHigh) {
    this->alcHigh = alcHigh;
}
/**
 * @param alcLow The alcLow to set.
 */
void Style::setAlcLow(double alcLow) {
    this->alcLow = alcLow;
}
/**
 * @param category The category to set.
 */
void Style::setCategory(QString category) {
    this->category = category;
}
/**
 * @param catNum The catNum to set.
 */
void Style::setCatNum(QString catNum) {
    this->catNum = catNum;
}
/**
 * @param examples The examples to set.
 */
void Style::setExamples(QString commercialEx) {
    this->examples = commercialEx;
}
/**
 * @param ibuHigh The ibuHigh to set.
 */
void Style::setIbuHigh(double ibuHigh) {
    this->ibuHigh = ibuHigh;
}
/**
 * @param ibuLow The ibuLow to set.
 */
void Style::setIbuLow(double ibuLow) {
    this->ibuLow = ibuLow;
}
/**
 * @param srmHigh The srmHigh to set.
 */
void Style::setSrmHigh(double lovHigh) {
    this->srmHigh = lovHigh;
}
/**
 * @param srmLow The srmLow to set.
 */
void Style::setSrmLow(double lovLow) {
    this->srmLow = lovLow;
}
/**
 * @param ogHigh The ogHigh to set.
 */
void Style::setOgHigh(double ogHigh) {
    this->ogHigh = ogHigh;
}
/**
 * @param ogLow The ogLow to set.
 */
void Style::setOgLow(double ogLow) {
    this->ogLow = ogLow;
}
/**
 * @param fgHigh The fgHigh to set.
 */
void Style::setFgHigh(double fgHigh) {
    this->fgHigh = fgHigh;
}
/**
 * @param ogLow The ogLow to set.
 */
void Style::setFgLow(double fgLow) {
    this->fgLow = fgLow;
}

void Style::setYear(QString year) {
    this->year = year;
}

void Style::setComments(QString comments) {
    this->comments = comments;
}

QString Style::getComments() {
    return this->comments;
}

void Style::setAppearance(QString appearance) {
    this->appearance = appearance;
}

void Style::setAroma(QString aroma) {
    this->aroma = aroma;
}

void Style::setFlavour(QString flavour) {
    this->flavour = flavour;
}

void Style::setMouthfeel(QString mouthfeel) {
    this->mouthfeel = mouthfeel;
}

void Style::setImpression(QString impression) {
    this->impression = impression;
}

void Style::setIngredients(QString ingredients) {
    this->ingredients = ingredients;
}

QString Style::toXML() {
    QString sb;
    int indent = 0;
    sb.append(" <style>\n");
    // this is the BJCP style dtd:
    sb.append("  <subcategory id=\"" + catNum + "\">");
    indent = 4;
    sb.append(SBStringUtils::xmlElement("name", name, indent));
    sb.append(SBStringUtils::xmlElement("aroma", aroma, indent));
    sb.append(SBStringUtils::xmlElement("appearance", appearance, indent));
    sb.append(SBStringUtils::xmlElement("flavor", flavour, indent));
    sb.append(SBStringUtils::xmlElement("mouthfeel", mouthfeel, indent));
    sb.append(SBStringUtils::xmlElement("impression", impression, indent));
    sb.append(SBStringUtils::xmlElement("comments", comments, indent));
    sb.append(SBStringUtils::xmlElement("ingredients", ingredients, indent));
    sb.append(" <stats>\n");
    sb.append("  <og flexible=\"" + QString::number(ogFlexible) + "\">\n");

    indent = 6;
    sb.append(SBStringUtils::xmlElement("low", ogLow, indent));
    sb.append(SBStringUtils::xmlElement("high", ogHigh, indent));
    sb.append("  </og>\n");
    sb.append("  <fg flexible=\"" + QString::number(fgFlexible) + "\">\n");
    sb.append(SBStringUtils::xmlElement("low", fgLow, indent));
    sb.append(SBStringUtils::xmlElement("high", fgHigh, indent));
    sb.append("  </fg>\n");
    sb.append("  <ibu flexible=\"" + QString::number(ibuFlexible) + "\">\n");
    sb.append(SBStringUtils::xmlElement("low", ibuLow, indent));
    sb.append(SBStringUtils::xmlElement("high", ibuHigh, indent));
    sb.append("  </ibu>\n");
    sb.append("  <srm flexible=\"" + QString::number(srmFlexible) + "\">\n");
    sb.append(SBStringUtils::xmlElement("low", srmLow, indent));
    sb.append(SBStringUtils::xmlElement("high", srmHigh, indent));
    sb.append("  </srm>\n");
    sb.append("  <abv flexible=\"" + QString::number(alcFlexible) + "\">\n");
    sb.append(SBStringUtils::xmlElement("low", alcLow, indent));
    sb.append(SBStringUtils::xmlElement("high", alcHigh, indent));
    sb.append("  </abv>\n");
    sb.append("</stats>\n");
    indent = 4;
    sb.append(SBStringUtils::xmlElement("examples", examples, indent));
    sb.append("  </subcategory>\n");
    sb.append(" </style>\n");
    return sb;
}

QString Style::toText() {
    QString sb;

    sb.append("Name: " + catNum + ":" + getName() + "\n");
    sb.append("Category: " + category + "\n");
    sb.append("Class: " + type + "\n");
    sb.append("OG: " + QString::number(ogLow) + "-" + QString::number(ogHigh) + "\n");
    sb.append("IBU: " + QString::number(ibuLow) + "-" + QString::number(ibuHigh) + "\n");
    sb.append("SRM: " + QString::number(srmLow) + "-" + QString::number(srmHigh) + "\n");
    sb.append("Alc: " + QString::number(alcLow) + "-" + QString::number(alcHigh) + "\n");
    sb.append("Aroma: " + aroma + "\n");
    sb.append("Appearance: " + appearance + "\n");
    sb.append("Flavour: " + flavour + "\n");
    sb.append("Mouthfeel: " + mouthfeel + "\n");
    sb.append("Impression: " + impression + "\n");
    sb.append("Comments: " + comments + "\n");
    sb.append("Ingredients: " + ingredients + "\n");
    sb.append("Examples: " + examples + "\n");
    return sb;
}

QString Style::toString() {
    return getName();
}

bool Style::compareTo(Style s) {
    return getName() == s.getName();

}

/*********
 * Set the style as complete so any values can be switched
 */
void Style::setComplete() {
    double temp = 0.0;

    // Check the IBU
    if (ibuHigh < ibuLow) {
        temp = ibuHigh;
        ibuHigh = ibuLow;
        ibuLow = temp;
    }

    // check the SRM
    if (srmHigh < srmLow) {
        temp = srmHigh;
        srmHigh = srmLow;
        srmLow = temp;
    }

    // check the OG
    if (ogHigh < ogLow) {
        temp = ogHigh;
        ogHigh = ogLow;
        ogLow = temp;
    }

    // check the ALC
    if (alcHigh < alcLow) {
        temp = alcHigh;
        alcHigh = alcLow;
        alcLow = temp;
    }

}

bool Style::operator==(const Style &other) const {
    return name == other.name;
}

bool Style::operator<(const Style &other) const {
    return name < other.name;
}

bool Style::operator>(const Style &other) const {
    return name > other.name;
}
