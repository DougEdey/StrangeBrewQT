#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QString>

extern QString HOP_LEAF;
extern QString HOP_PELLET;
extern QString HOP_PLUG;
extern QString HOP_BOIL;
extern QString HOP_FWH;
extern QString HOP_DRY;
extern QString HOP_MASH;

extern QString HOP_DEFAULT_ADD;
extern QString HOP_DEFAULT_TYPE;

extern QStringList HOP_forms;
extern QStringList HOP_addTypes;

extern QString QT_PER_LB;
extern QString L_PER_KG;
extern QString ACID;
extern QString GLUCAN;
extern QString PROTEIN;
extern QString BETA;
extern QString ALPHA;
extern QString MASHOUT;
extern QString SPARGE;
extern QString INFUSION;
extern QString DECOCTION;
extern QString DECOCTION_THICK;
extern QString DECOCTION_THIN;
extern QString DIRECT;
extern QString CEREAL_MASH;
extern QString FLY;
extern QString BATCH;

extern QStringList mash_ratioUnits;// = {QT_PER_LB, L_PER_KG};
extern QStringList mash_types;// = {ACID, GLUCAN, PROTEIN, BETA, ALPHA, MASHOUT, SPARGE};
extern QStringList mash_methods;// = {INFUSION, DECOCTION, DECOCTION_THICK, DECOCTION_THIN, DIRECT, CEREAL_MASH};
extern QStringList mash_spargeMethods;// = {FLY, BATCH};


extern QString CONVERTER_TSP;
extern QString CONVERTER_TBSP;
extern QString CONVERTER_OZ;
extern QString CONVERTER_FL_OZ;
extern QString CONVERTER_FL_OUNCES;
extern QString CONVERTER_GALLONS_US;
extern QString CONVERTER_GAL;
extern QString CONVERTER_LITRES;
extern QString CONVERTER_L;
extern QString CONVERTER_MILLILITERS;
extern QString CONVERTER_ML;
extern QString CONVERTER_QUART_US;
extern QString CONVERTER_QT;
extern QString CONVERTER_BARREL_IMP;
extern QString CONVERTER_BBL_IMP;
extern QString CONVERTER_BARREL_US;
extern QString CONVERTER_BBL_US;
extern QString CONVERTER_GALLONS_IMP;
extern QString CONVERTER_GAL_IMP;
extern QString CONVERTER_PINT_US;
extern QString CONVERTER_PT_US;

extern QString CONVERTER_OUNCES;
extern QString CONVERTER_POUNDS;
extern QString CONVERTER_LB;
extern QString CONVERTER_MILLIGRAMS;
extern QString CONVERTER_MG;
extern QString CONVERTER_GRAMS;
extern QString CONVERTER_G;
extern QString CONVERTER_KG;
extern QString CONVERTER_KILOGRAM;

extern QString CONVERTER_DEFAULT_VOLUME;
extern QString CONVERTER_DEFAULT_WEIGHT;

extern QStringList CONVERTER_volUnits;
extern QStringList CONVERTER_volUnitsAbrv;
extern QStringList CONVERTER_volUnitsFull;

extern QStringList CONVERTER_weightUnits;
extern QStringList CONVERTER_weightUnitsAbrv;
extern QStringList CONVERTER_weightUnitsFull;

extern QString QUANTITY_WEIGHT;
extern QString QUANTITY_VOL;
extern QString QUANTITY_PRESSURE;


extern QString PRIMARY;
extern QString SECONDARY;
extern QString CLEARING;
extern QString AGEING;
extern QStringList ferment_types;

extern int UTILIZATION[];
extern QString TINSETH;
extern QString RAGER;
extern QString GARETZ;
extern QString ibuMethods[];

extern QString EBC;
extern QString SRM;
extern QString colourMethods[];

extern QString ALC_BY_WEIGHT;
extern QString ALC_BY_VOLUME;
extern QString alcMethods[];

#endif // CONSTANTS_H
