#include "misc.h"


QString MISC_MASH = "Mash";
QString MISC_BOIL = "Boil";
QString MISC_PRIMARY = "Primary";
QString MISC_SECONDARY = "Secondary";
QString MISC_BOTTLE = "Bottle";
QString MISC_KEG= "Keg";
QString MISC_stages[] = {MISC_MASH, MISC_BOIL, MISC_PRIMARY, MISC_SECONDARY, MISC_BOTTLE, MISC_KEG};

// default constructor
Misc::Misc() : Ingredient() {
    setForm("misc");
    //setName("");
    //setCost(0);
    //setDescription("");
    setTime(0);
    //setUnits(CONVERTER_G);
}

// get methods
QString Misc::getComments() const { return comments; }
QString Misc::getStage() const { return stage; }
int Misc::getTime() const { return time; }

// set methods
void Misc::setComments(QString c){ comments = c; }
void Misc::setStage(QString s){ stage = s; }
void Misc::setTime(int t){ time = t; }

QString Misc::toXML(){
    QString sb;
    sb.append( "    <ITEM>\n" );
    sb.append(SBStringUtils::xmlElement("NAME", getName(), 6));
    sb.append(SBStringUtils::xmlElement("AMOUNT", getAmountAs(getUnits()), 6));
    sb.append(SBStringUtils::xmlElement("UNITS", getUnits(), 6));
    sb.append(SBStringUtils::xmlElement("STAGE", stage, 6));
    sb.append(SBStringUtils::xmlElement("TIME", time, 6));
    sb.append(SBStringUtils::xmlElement("COMMENTS", SBStringUtils::subEntities(comments), 6));
    sb.append( "    </ITEM>\n" );
    return sb;
}
