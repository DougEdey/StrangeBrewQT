#include "options.h"

QSettings properties;
Options::Options()
{

}



void Options::SetDefaults() {
    QSettings properties("StrangeBrew", "StrangeBrew");
    qDebug() << "Org: " << QCoreApplication::organizationName();
    //Calculations
    SetValueIfNotExists("Calculations/IBUCalcMethod", TINSETH);
    SetValueIfNotExists("Calculations/AlcCalcMethod", ALC_BY_VOLUME);
    SetValueIfNotExists("Calculations/ColourMethod", SRM);
    SetValueIfNotExists("Calculations/EvapCalcMethod", "Constant");
    SetValueIfNotExists("Calculations/Efficiency", "75");
    SetValueIfNotExists("Calculations/Attenuation", "75");
    SetValueIfNotExists("Calculations/Evaporation", "1.5");
    SetValueIfNotExists("Calculations/PelletHopsPct", "6");
    SetValueIfNotExists("Calculations/DryHopTime", "0");
    SetValueIfNotExists("Calculations/FWHTime", "1");
    SetValueIfNotExists("Calculations/MashHopTime", "2");
    SetValueIfNotExists("Calculations/HopsUtil", "4.15");
    SetValueIfNotExists("Calculations/ColourEfficiency", "false");
    SetValueIfNotExists("Calculations/HopForm", HOP_LEAF);

    // Recipe Defaults
    SetValueIfNotExists("Recipe/SizeU", CONVERTER_GALLONS_US);
    SetValueIfNotExists("Recipe/MaltU", CONVERTER_POUNDS);
    SetValueIfNotExists("Recipe/HopsU", CONVERTER_OUNCES);
    SetValueIfNotExists("Recipe/PostBoilVol", "5");
    SetValueIfNotExists("Recipe/PreBoilVol", "6");
    SetValueIfNotExists("Recipe/Mash", "true");
    SetValueIfNotExists("Recipe/HopsType", HOP_LEAF);
    SetValueIfNotExists("Recipe/WaterProfile", "Distilled/RO");


    // Carbonation
    SetValueIfNotExists("Carbonation/PrimingSugar", "Corn Sugar");
    SetValueIfNotExists("Carbonation/SugarU", CONVERTER_GRAMS);
    SetValueIfNotExists("Carbonation/BottleU", CONVERTER_FL_OUNCES);
    SetValueIfNotExists("Carbonation/CarbTempU", "F");
    SetValueIfNotExists("Carbonation/BottleSize", "12");
    SetValueIfNotExists("Carbonation/BottleTemp", "68");
    SetValueIfNotExists("Carbonation/ServTemp", "45");
    SetValueIfNotExists("Carbonation/VolsCO2", "2.4");
    SetValueIfNotExists("Carbonation/Kegged", "true");
    SetValueIfNotExists("Carbonation/TubingID", "3/16");
    SetValueIfNotExists("Carbonation/HeightAboveKeg", "1");

    // Water Profiles
    SetValueIfNotExists("Water/Source", "");
    SetValueIfNotExists("Water/Target", "");
    // TODO: Add specific water profile


    // Default fermentation settings
    SetValueIfNotExists("Fermentation/Type", PRIMARY);
    SetValueIfNotExists("Fermentation/Time", "7");
    SetValueIfNotExists("Fermentation/Temp", "68.0");
    SetValueIfNotExists("Fermentation/TempU", "F");

    // Display Labels
    SetValueIfNotExists("Labels/Brewer", "Your Name");
    SetValueIfNotExists("Labels/Street", "Your Street");
    SetValueIfNotExists("Labels/City", "Your City");
    SetValueIfNotExists("Labels/Prov", "Your State/Prov");
    SetValueIfNotExists("Labels/Code", "Your zip/postal code");
    SetValueIfNotExists("Labels/Phone", "Your Phone");
    SetValueIfNotExists("Labels/Club", "Your Club");
    SetValueIfNotExists("Labels/Country", "Your Country");
    SetValueIfNotExists("Labels/Email", "Your Email");
    SetValueIfNotExists("Labels/LocaleLang", "");
    SetValueIfNotExists("Labels/LocaleCountry", "");
    SetValueIfNotExists("Labels/LocaleVariant", "");

    // Appearance
    SetValueIfNotExists("Appearance/MaltSortOrder", "By Name");
    SetValueIfNotExists("Appearance/FirstScreen", "");
    SetValueIfNotExists("Appearance/Red", "8");
    SetValueIfNotExists("Appearance/Green", "30");
    SetValueIfNotExists("Appearance/Blue", "20");
    SetValueIfNotExists("Appearance/Alpha", "255");
    SetValueIfNotExists("Appearance/RGBMethod", "1");

    // Timer defaults
    SetValueIfNotExists("Times/BrewDayStart", "10:00");
    SetValueIfNotExists("Times/PrepTime", "31");
    SetValueIfNotExists("Times/SpargeTime", "60");
    SetValueIfNotExists("Times/GetToBoilTime", "45");
    SetValueIfNotExists("Times/ChillTime", "45");
    SetValueIfNotExists("Times/CleanTime", "120");
    SetValueIfNotExists("Times/BoilTime", "60");


    // losses from various areas
    SetValueIfNotExists("Losses/Kettle", "0");
    SetValueIfNotExists("Losses/Trub", "0");
    SetValueIfNotExists("Losses/Misc", "0");


    SetValueIfNotExists("Cost/Misc", "5.0");

    // Mash Defaults
    SetValueIfNotExists("Mash/VolU", CONVERTER_GALLONS_US);
    SetValueIfNotExists("Mash/TempU", "F");
    SetValueIfNotExists("Mash/RatioU", QT_PER_LB);
    SetValueIfNotExists("Mash/Ratio", "1.25");
    SetValueIfNotExists("Mash/GrainTemp", "68");
    SetValueIfNotExists("Mash/TunLossF", "3");
    SetValueIfNotExists("Mash/DeadSpace", "0");
    SetValueIfNotExists("Mash/BoilTempF", "212");
    SetValueIfNotExists("Mash/ThickDecoctRatio", "0.6");
    SetValueIfNotExists("Mash/ThinDecoctRatio", "0.9");

    // default ranges for mash steps - indicates the bottom of the range

    SetValueIfNotExists("MashSteps/AcidTmpF", "85");
    SetValueIfNotExists("MashSteps/GlucanTmpF", "95");
    SetValueIfNotExists("MashSteps/ProteinTmpF", "113");
    SetValueIfNotExists("MashSteps/BetaTmpF", "131");
    SetValueIfNotExists("MashSteps/AlphaTmpF", "151");
    SetValueIfNotExists("MashSteps/MashoutTmpF", "161");
    SetValueIfNotExists("MashSteps/SpargeTmpF", "170");
    SetValueIfNotExists("MashSteps/CerealMashTmpF", "155");

    // Style
    SetValueIfNotExists("Style/Year", "2004");


    // application window:
    SetValueIfNotExists("Application/timid", "True");
    SetValueIfNotExists("Application/winX", "0");
    SetValueIfNotExists("Application/winY", "0");
    SetValueIfNotExists("Application/winWidth", "600");
    SetValueIfNotExists("Application/winHeight", "650");
    SetValueIfNotExists("Application/maltTable0", "10");
    SetValueIfNotExists("Application/maltTable1", "10");
    SetValueIfNotExists("Application/maltTable2", "200");
    SetValueIfNotExists("Application/hopsTable0", "200");

    SetValueIfNotExists("Cloud/URL", "strangebrewcloud.appspot.com");

    // Force a sync to make sure the INI in the OS is good
    properties.sync();

}

void Options::SetValueIfNotExists(QString key, QString value) {
    QSettings properties("StrangeBrew", "StrangeBrew");
    if (!properties.contains(key)) {
        properties.setValue(key, value);
        properties.sync();
    }
}

