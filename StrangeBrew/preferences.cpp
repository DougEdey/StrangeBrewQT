#include "preferences.h"
#include "ui_preferences.h"
#include "hop.h"

Preferences::Preferences(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Preferences)
{
    ui->setupUi(this);
    Database::readStyleYears();

    // Initialize the drop boxes
    ui->bottleUnitCombo->addItem(CONVERTER_ML);
    ui->bottleUnitCombo->addItem(CONVERTER_FL_OZ);
    ui->bottleUnitCombo->addItem(CONVERTER_L);

    Q_FOREACH(PrimeSugar *p, Database::primeSugarDB) {
        ui->primeSugarCombo->addItem(p->getName());
    }

    ui->sugarUnitsCombo->addItems(CONVERTER_weightUnitsAbrv);

    ui->tubingIDCombo->addItem("3/16");
    ui->tubingIDCombo->addItem("1/4");


    ui->bjcpYearCombo->addItems(Database::styleYears);

    ui->maltUnitCombo->addItems(CONVERTER_weightUnitsAbrv);
    ui->hopUnitsCombo->addItems(CONVERTER_weightUnitsAbrv);
    ui->volumeCombo->addItems(CONVERTER_volUnitsAbrv);
    ui->mashVolCombo->addItems(CONVERTER_volUnitsAbrv);

    ui->mashRatioCombo->addItem(QT_PER_LB);
    ui->mashRatioCombo->addItem(L_PER_KG);

    ui->hopTypeCombo->addItems(HOP_forms);

    Q_FOREACH(WaterProfile *w, Database::waterDB) {
        ui->waterProfileCombo->addItem(w->getName());
    }

    loadSettings();
    updateUI();
}

void Preferences::loadSettings() {
    QSettings settings("Doug Edey", "StrangeBrew");
    //Calculations
    ibuCalcMethod = settings.value("Calculations/IBUCalcMethod", TINSETH).toString();
    alcCalcMethod = settings.value("Calculations/AlcCalcMethod", ALC_BY_VOLUME).toString();
    colourMethod = settings.value("Calculations/ColourMethod", SRM).toString();
    evapCalcMethod = settings.value("Calculations/EvapCalcMethod", "Constant").toString();
    efficiency = settings.value("Calculations/Efficiency", "75").toInt();
    attenuation = settings.value("Calculations/Attenuation", "75").toInt();
    evaporation = settings.value("Calculations/Evaporation", "1.5").toDouble();
    pelletPct = settings.value("Calculations/PelletHopsPct", "6").toDouble();
    dryHopTime = settings.value("Calculations/DryHopTime", "0").toInt();
    fwhHopTime = settings.value("Calculations/FWHTime", "1").toInt();
    mashHopTime= settings.value("Calculations/MashHopTime", "2").toInt();
    hopsUtil = settings.value("Calculations/HopsUtil", "4.15").toDouble();
    hopForm = settings.value("Calculations/HopForm", HOP_LEAF).toString();

    // losses from various areas
    kettleLoss = settings.value("Losses/Kettle", "0").toDouble();
    trubLoss = settings.value("Losses/Trub", "0").toDouble();
    miscLoss = settings.value("Losses/Misc", "0").toDouble();


    // Recipe Defaults
    sizeU = Quantity::getAbrvFromUnit("volume", settings.value("Recipe/SizeU", CONVERTER_GALLONS_US).toString());
    qDebug() << "Reading : " << settings.value("Recipe/MaltU", CONVERTER_POUNDS).toString();
    maltU = Quantity::getAbrvFromUnit("weight", settings.value("Recipe/MaltU", CONVERTER_POUNDS).toString());
    qDebug() << "Abrv: " << maltU;
    hopsU = Quantity::getAbrvFromUnit("weight", settings.value("Recipe/HopsU", CONVERTER_OUNCES).toString());
    boilTime = settings.value("Recipe/BoilTime", "60").toInt();
    postBoil = settings.value("Recipe/PostBoilVol", "5").toDouble();
    preBoil = settings.value("Recipe/PreBoilVol", "6").toDouble();
    // = settings.value("Recipe/Mash", "true");
    hopsType = settings.value("Recipe/HopsType", HOP_LEAF).toString();
    waterProfile = settings.value("Recipe/WaterProfile", "Distilled/RO").toString();

    // Appearance
     //= settings.value("Appearance/FirstScreen", "");
    red = settings.value("Appearance/Red", "8").toInt();
    green = settings.value("Appearance/Green", "30").toInt();
    blue = settings.value("Appearance/Blue", "20").toInt();
    alpha = settings.value("Appearance/Alpha", "255").toInt();
    rgbMethod = settings.value("Appearance/RGBMethod", "1").toInt();

    miscCost = settings.value("Cost/Misc", "5.0").toDouble();

    // Display Labels
    name = settings.value("Labels/Brewer", "Your Name").toString();
    street  = settings.value("Labels/Street", "Your Street").toString();
    city  = settings.value("Labels/City", "Your City").toString();
    state = settings.value("Labels/Prov", "Your State/Prov").toString();
    code = settings.value("Labels/Code", "Your zip/postal code").toString();
    phone = settings.value("Labels/Phone", "Your Phone").toString();
    club = settings.value("Labels/Club", "Your Club").toString();
    country = settings.value("Labels/Country", "Your Country").toString();
    email = settings.value("Labels/Email", "Your Email").toString();

    recipeDIR = settings.value("Recipes/DIR", QDir::currentPath() + QDir::separator() + "data").toString();

    // Carbonation
    primeSugar = settings.value("Carbonation/PrimingSugar", "Corn Sugar").toString();
    sugarU = Quantity::getAbrvFromUnit("weight", settings.value("Carbonation/SugarU", CONVERTER_GRAMS).toString());
    bottleU = Quantity::getAbrvFromUnit("volume", settings.value("Carbonation/BottleU", CONVERTER_FL_OUNCES).toString());
    carbTempU = settings.value("Carbonation/CarbTempU", "F").toString();
    bottleSize = settings.value("Carbonation/BottleSize", "12").toInt();
    bottleTempF = settings.value("Carbonation/BottleTempF", "68").toInt();
    servTempF = settings.value("Carbonation/ServTempF", "45").toInt();
    volsCO2 = settings.value("Carbonation/VolsCO2", "2.4").toDouble();
    kegged = settings.value("Carbonation/Kegged", "true").toBool();
    tubingID = settings.value("Carbonation/TubingID", "3/16").toString();
    faucHeight = settings.value("Carbonation/HeightAboveKeg", "1").toDouble();


    // Mash Defaults
    mashVolU = Quantity::getAbrvFromUnit("volume", settings.value("Mash/VolU", CONVERTER_GALLONS_US).toString());
    mashTempU = settings.value("Mash/TempU", "F").toString();
    mashRatioU = settings.value("Mash/RatioU", QT_PER_LB).toString();
    mashRatio = settings.value("Mash/Ratio", "1.25").toDouble();
    grainTempF = settings.value("Mash/GrainTempF", "68").toInt();
    tunLossF = settings.value("Mash/TunLossF", "3").toInt();
    deadSpace = settings.value("Mash/DeadSpace", "0").toDouble();
    boilTempF = settings.value("Mash/BoilTempF", "212").toInt();
    thinDecoctRatio = settings.value("Mash/ThickDecoctRatio", "0.6").toDouble();
    thickDecoctRatio = settings.value("Mash/ThinDecoctRatio", "0.9").toDouble();

    // default ranges for mash steps - indicates the bottom of the range

    mashAcidF = settings.value("MashSteps/AcidTmpF", "85").toInt();
    mashGlucanF = settings.value("MashSteps/GlucanTmpF", "95").toInt();
    mashProteinF = settings.value("MashSteps/ProteinTmpF", "113").toInt();
    mashBetaF = settings.value("MashSteps/BetaTmpF", "131").toInt();
    mashAlphaF = settings.value("MashSteps/AlphaTmpF", "151").toInt();
    mashoutTempF = settings.value("MashSteps/MashoutTmpF", "161").toInt();
    spargeTempF = settings.value("MashSteps/SpargeTmpF", "170").toInt();
    mashCerealF = settings.value("MashSteps/CerealMashTmpF", "155").toInt();

    // Style
    style = settings.value("Style/Year", "2004").toString();

}

void Preferences::saveSettings() {
    QSettings settings("Doug Edey", "StrangeBrew");
    //Calculations

    settings.setValue("Calculations/IBUCalcMethod", ibuCalcMethod);
    settings.setValue("Calculations/AlcCalcMethod", alcCalcMethod);
    settings.setValue("Calculations/ColourMethod", colourMethod);
    settings.setValue("Calculations/EvapCalcMethod", evapCalcMethod);
    settings.setValue("Calculations/Efficiency", efficiency);
    settings.setValue("Calculations/Attenuation", attenuation);
    settings.setValue("Calculations/Evaporation", evaporation);
    settings.setValue("Calculations/PelletHopsPct", pelletPct);
    settings.setValue("Calculations/DryHopTime", dryHopTime);
    settings.setValue("Calculations/FWHTime", fwhHopTime);
    settings.setValue("Calculations/MashHopTime", mashHopTime);
    settings.setValue("Calculations/HopsUtil", hopsUtil);
    settings.setValue("Calculations/HopForm", hopForm);

    // losses from various areas
    settings.setValue("Losses/Kettle", kettleLoss);
    settings.setValue("Losses/Trub", trubLoss);
    settings.setValue("Losses/Misc", miscLoss);


    // Recipe Defaults
    settings.setValue("Recipe/SizeU", Quantity::getUnitFromAbrv("volume", sizeU));
    settings.setValue("Recipe/MaltU", Quantity::getUnitFromAbrv("weight", maltU));
    settings.setValue("Recipe/HopsU", Quantity::getUnitFromAbrv("weight", hopsU));
    settings.setValue("Recipe/BoilTime", boilTime);
    settings.setValue("Recipe/PostBoilVol", postBoil);
    settings.setValue("Recipe/PreBoilVol", preBoil);
    // = settings.setValue("Recipe/Mash", );
    settings.setValue("Recipe/HopsType", hopsType);
    settings.setValue("Recipe/WaterProfile", waterProfile);

    // Appearance
     //= settings.setValue("Appearance/FirstScreen", "");
    settings.setValue("Appearance/Red", red);
    settings.setValue("Appearance/Green", green);
    settings.setValue("Appearance/Blue", blue);
    settings.setValue("Appearance/Alpha", alpha);
    settings.setValue("Appearance/RGBMethod", rgbMethod);

    settings.setValue("Cost/Misc", miscCost);

    // Display Labels
    settings.setValue("Labels/Brewer", name);
    settings.setValue("Labels/Street", street);
    settings.setValue("Labels/City", city);
    settings.setValue("Labels/Prov", state);
    settings.setValue("Labels/Code", code);
    settings.setValue("Labels/Phone", phone);
    settings.setValue("Labels/Club", club);
    settings.setValue("Labels/Country", country);
    settings.setValue("Labels/Email", email);

    settings.setValue("Recipes/DIR", recipeDIR);

    // Carbonation
    settings.setValue("Carbonation/PrimingSugar", primeSugar);
    settings.setValue("Carbonation/SugarU", Quantity::getUnitFromAbrv("weight", sugarU));
    settings.setValue("Carbonation/BottleU", Quantity::getUnitFromAbrv("volume", bottleU));
    settings.setValue("Carbonation/CarbTempU", carbTempU);
    settings.setValue("Carbonation/BottleSize", bottleSize);
    settings.setValue("Carbonation/BottleTempF", bottleTempF);
    settings.setValue("Carbonation/ServTempF", servTempF);
    settings.setValue("Carbonation/VolsCO2", volsCO2);
    settings.setValue("Carbonation/Kegged", kegged);
    settings.setValue("Carbonation/TubingID", tubingID);
    settings.setValue("Carbonation/HeightAboveKeg", faucHeight);


    // Mash Defaults
    settings.setValue("Mash/VolU", Quantity::getUnitFromAbrv("volume", mashVolU));
    settings.setValue("Mash/TempU", mashTempU);
    settings.setValue("Mash/RatioU", mashRatioU);
    settings.setValue("Mash/Ratio", mashRatio);
    settings.setValue("Mash/GrainTempF", grainTempF);
    settings.setValue("Mash/TunLossF", tunLossF);
    settings.setValue("Mash/DeadSpace", deadSpace);
    settings.setValue("Mash/BoilTempF", boilTempF);
    settings.setValue("Mash/ThickDecoctRatio", thinDecoctRatio);
    settings.setValue("Mash/ThinDecoctRatio", thickDecoctRatio);

    // default ranges for mash steps - indicates the bottom of the range

    settings.setValue("MashSteps/AcidTmpF", mashAcidF);
    settings.setValue("MashSteps/GlucanTmpF", mashGlucanF);
    settings.setValue("MashSteps/ProteinTmpF", mashProteinF);
    settings.setValue("MashSteps/BetaTmpF", mashBetaF);
    settings.setValue("MashSteps/AlphaTmpF", mashAlphaF);
    settings.setValue("MashSteps/MashoutTmpF", mashoutTempF);
    settings.setValue("MashSteps/SpargeTmpF", spargeTempF);
    settings.setValue("MashSteps/CerealMashTmpF", mashCerealF);

    // Style
    settings.setValue("Style/Year", style);

    settings.sync();
}


Preferences::~Preferences()
{
    delete ui;
}

// long method to update the panels
void Preferences::updateUI() {
    updateCalculations();
    updateCostCarb();
    updateBrewer();
    updateStyle();
    updateAppearance();
    updateColourBoxes();
    updateNewRecipe();
}

void Preferences::updateCalculations() {
    if (ibuCalcMethod == TINSETH) {
        ui->tinsethRadio->setChecked(true);
    } else if (ibuCalcMethod == GARETZ) {
        ui->garetzRadio->setChecked(true);
    } else if (ibuCalcMethod == RAGER) {
        ui->ragerRadio->setChecked(true);
    }

    if (alcCalcMethod == ALC_BY_VOLUME) {
        ui->alcVolRadio->setChecked(true);
    } else if (alcCalcMethod == ALC_BY_WEIGHT) {
        ui->alcWeightRadio->setChecked(true);
    }

    if (colourMethod == EBC) {
        ui->ebcRadio->setChecked(true);
    } else if (colourMethod == SRM) {
        ui->srmRadio->setChecked(true);
    }

    if (evapCalcMethod == "Constant") {
        ui->evapRateLabel->setText(sizeU + "/hour");
        ui->evapConsRadio->setChecked(true);
    } else if (evapCalcMethod == "Percent") {
        ui->evapRateLabel->setText("%");
        ui->evapPercRadio->setChecked(true);
    }
    ui->evapRateSpin->setValue(evaporation);

    ui->pelletHopsSpin->setValue(pelletPct);
    ui->tinsethSpin->setValue(hopsUtil);

    ui->drySpin->setValue(dryHopTime);
    ui->FWHSpin->setValue(fwhHopTime);
    ui->mashSpin->setValue(mashHopTime);

    ui->kettLossSpin->setValue(kettleLoss);
    ui->miscLossSpin->setValue(miscLoss);
    ui->trubLossSpin->setValue(trubLoss);
}

void Preferences::updateCostCarb() {
    ui->otherCostSpin->setValue(miscCost);
    ui->bottleSizeSpin->setValue(bottleSize);

   int i = ui->bottleUnitCombo->findText(bottleU);
   if (i > -1) {
       ui->bottleUnitCombo->setCurrentIndex(i);
   }

   i = ui->primeSugarCombo->findText(primeSugar);
   if (i > -1) {
       ui->primeSugarCombo->setCurrentIndex(i);
   }

   i = ui->sugarUnitsCombo->findText(sugarU);
   if (i > -1) {
       ui->sugarUnitsCombo->setCurrentIndex(i);
   }

   i = ui->tubingIDCombo->findText(tubingID);
   if (i > -1) {
       ui->tubingIDCombo->setCurrentIndex(i);
   }

   ui->servTempSpin->setValue(servTempF);
   ui->bottleTempSpin->setValue(bottleTempF);
   ui->targetCO2Spin->setValue(volsCO2);
   ui->faucHeightSpin->setValue(faucHeight);

   if (carbTempU == "F") {
       ui->carbUnitF->setChecked(true);
   } else if (carbTempU == "C") {
       ui->carbUnitC->setChecked(true);
   }

   if (kegged) {
       ui->keggedCheck->setChecked(true);
   } else {
       ui->keggedCheck->setChecked(false);
   }
}

void Preferences::updateBrewer() {
    ui->nameEdit->setText(name);
    ui->phoneEdit->setText(phone);
    ui->clubEdit->setText(club);
    ui->emailEdit->setText(email);
    ui->recipeDirEdit->setText(recipeDIR);
    ui->efficiencySpin->setValue(efficiency);
    ui->attenuationSpin->setValue(attenuation);
}

void Preferences::updateStyle() {
    int i = ui->bjcpYearCombo->findText(style);
    if (i > -1) {
        ui->bjcpYearCombo->setCurrentIndex(i);
    } else {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Couldn't find BJCP Year: " + style);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();

    }
}

void Preferences::updateAppearance() {
    if (rgbMethod == 1) {
        ui->method1Radio->setChecked(true);
    } else if (rgbMethod == 2) {
        ui->method2Radio->setChecked(true);
    }

    ui->redSpin->setValue(red);
    ui->greenSpin->setValue(green);
    ui->blueSpin->setValue(blue);
    ui->alphaSpin->setValue(alpha);
    updateColourBoxes();
}

void Preferences::updateColourBoxes() {
    QString rgbColour = BrewCalcs::calcRGB(rgbMethod, 2,
                              red, green, blue, alpha);
    ui->strawFrame->setStyleSheet("background-color: rgba(" + rgbColour + ");");

    rgbColour = BrewCalcs::calcRGB(rgbMethod, 4,
                                  red, green, blue, alpha);
    ui->paleFrame->setStyleSheet("background-color: rgba(" + rgbColour + ");");

    rgbColour = BrewCalcs::calcRGB(rgbMethod, 8,
                                  red, green, blue, alpha);
    ui->amberFrame->setStyleSheet("background-color: rgba(" + rgbColour + ");");

    rgbColour = BrewCalcs::calcRGB(rgbMethod, 15,
                                  red, green, blue, alpha);
    ui->copperFrame->setStyleSheet("background-color: rgba(" + rgbColour + ");");

    rgbColour = BrewCalcs::calcRGB(rgbMethod, 20,
                                  red, green, blue, alpha);
    ui->brownFrame->setStyleSheet("background-color: rgba(" + rgbColour + ");");

    rgbColour = BrewCalcs::calcRGB(rgbMethod, 30,
                                  red, green, blue, alpha);

    ui->blackFrame->setStyleSheet("background-color: rgba(" + rgbColour + ");");
}

void Preferences::updateNewRecipe() {
    int i = ui->maltUnitCombo->findText(maltU);
    qDebug() << "Malt U: " << maltU;
    if (i > -1) {
        ui->maltUnitCombo->setCurrentIndex(i);
    } else {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Couldn't find Malt Unit: " + maltU);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }

    i = ui->hopUnitsCombo->findText(hopsU);
    if (i > -1) {
        ui->hopUnitsCombo->setCurrentIndex(i);
    } else {
        // todo error alert
    }

    i = ui->volumeCombo->findText(sizeU);
    if (i > -1) {
        ui->volumeCombo->setCurrentIndex(i);
    } else {
        // todo error alert
    }

    i = ui->mashVolCombo->findText(mashVolU);
    if (i > -1) {
        ui->mashVolCombo->setCurrentIndex(i);
    } else {
        // todo error alert
    }

    i = ui->mashRatioCombo->findText(mashRatioU);
    if (i > -1) {
        ui->mashRatioCombo->setCurrentIndex(i);
    } else {
        // todo error alert
    }

    i = ui->hopTypeCombo->findText(hopsType);
    if (i > -1) {
        ui->hopTypeCombo->setCurrentIndex(i);
    } else {
        // todo error alert
    }

    i = ui->waterProfileCombo->findText(waterProfile);
    if (i > -1) {
        ui->waterProfileCombo->setCurrentIndex(i);
    } else {
        // todo error alert
    }

    if (mashTempU == "F") {
        ui->mashTempF->setChecked(true);
        ui->boilTempSpin->setValue(boilTempF);
    } else if (mashTempU == "C") {
        ui->mashTempC->setChecked(true);
        ui->boilTempSpin->setValue(BrewCalcs::fToC(boilTempF));
    }

    ui->batchSizeSpin->setValue(postBoil);
    ui->boilTimeSpin->setValue(boilTime);
    ui->mashRatioSpin->setValue(mashRatio);
    ui->deadSpaceSpin->setValue(deadSpace);
    ui->deadSpaceUnit->setText(mashVolU);

}

// IBU Method
void Preferences::on_tinsethRadio_clicked()
{
    ibuCalcMethod = TINSETH;
}

void Preferences::on_garetzRadio_clicked()
{
    ibuCalcMethod = GARETZ;
}

void Preferences::on_ragerRadio_clicked()
{
    ibuCalcMethod = RAGER;
}

// Alcohol Method
void Preferences::on_alcVolRadio_clicked()
{
    alcCalcMethod = ALC_BY_VOLUME;
}

void Preferences::on_alcWeightRadio_clicked()
{
    alcCalcMethod = ALC_BY_WEIGHT;
}

void Preferences::on_ebcRadio_clicked()
{
    colourMethod = EBC;
}

void Preferences::on_srmRadio_clicked()
{
    colourMethod = SRM;
}

void Preferences::on_evapConsRadio_clicked()
{
    evapCalcMethod = "Constant";
    ui->evapRateLabel->setText(sizeU + "/hour");
}

void Preferences::on_evapPercRadio_clicked()
{
    evapCalcMethod = "Percent";
    ui->evapRateLabel->setText("%");
}

void Preferences::on_evapRateSpin_editingFinished()
{
    evaporation =  ui->evapRateSpin->value();
}

void Preferences::on_pelletHopsSpin_editingFinished()
{
    pelletPct = ui->pelletHopsSpin->value();
}

void Preferences::on_tinsethSpin_editingFinished()
{
    hopsUtil = ui->tinsethSpin->value();
}

void Preferences::on_drySpin_editingFinished()
{
    dryHopTime = ui->drySpin->value();
}

void Preferences::on_FWHSpin_editingFinished()
{
    fwhHopTime = ui->FWHSpin->value();
}

void Preferences::on_mashSpin_editingFinished()
{
    mashHopTime = ui->mashSpin->value();
}

void Preferences::on_kettLossSpin_editingFinished()
{
    kettleLoss = ui->kettLossSpin->value();
}

void Preferences::on_miscLossSpin_editingFinished()
{
    miscLoss = ui->miscLossSpin->value();
}

void Preferences::on_trubLossSpin_editingFinished()
{
    trubLoss = ui->trubLossSpin->value();
}

void Preferences::on_otherCostSpin_editingFinished()
{
    miscCost = ui->otherCostSpin->value();
}

void Preferences::on_bottleSizeSpin_editingFinished()
{
    bottleSize = ui->bottleSizeSpin->value();
}

void Preferences::on_bottleUnitCombo_currentIndexChanged(const QString &newSize)
{
    bottleU = newSize;
}

void Preferences::on_primeSugarCombo_currentIndexChanged(const QString &sugar)
{
    primeSugar = sugar;
}

void Preferences::on_sugarUnitsCombo_currentIndexChanged(const QString &newUnits)
{
    sugarU = newUnits;
}

void Preferences::on_servTempSpin_editingFinished()
{
    servTempF = ui->servTempSpin->value();
}

void Preferences::on_carbUnitF_clicked()
{
    carbTempU = "F";
}

void Preferences::on_carbUnitC_clicked()
{
    carbTempU = "C";
}

void Preferences::on_bottleTempSpin_editingFinished()
{
    bottleTempF = ui->bottleTempSpin->value();
}

void Preferences::on_faucHeightSpin_editingFinished()
{
    faucHeight = ui->faucHeightSpin->value();
}

void Preferences::on_targetCO2Spin_editingFinished()
{
    volsCO2 = ui->targetCO2Spin->value();
}

void Preferences::on_tubingIDCombo_currentIndexChanged(const QString &newID)
{
    tubingID = newID;
}

void Preferences::on_keggedCheck_clicked()
{
    if (ui->keggedCheck->checkState() == Qt::Checked) {
        kegged = true;
    } else {
        kegged = false;
    }
}

void Preferences::on_nameEdit_editingFinished()
{
    name = ui->nameEdit->text();
}

void Preferences::on_phoneEdit_editingFinished()
{
    phone = ui->phoneEdit->text();
}

void Preferences::on_clubEdit_editingFinished()
{
    club = ui->clubEdit->text();
}

void Preferences::on_emailEdit_editingFinished()
{
    email = ui->emailEdit->text();
}

void Preferences::on_pushButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 recipeDIR,
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
    qDebug() << "New DIR: " << dir;
    if (dir != "") {
        recipeDIR = dir;
    }

    ui->recipeDirEdit->setText(recipeDIR);


}

void Preferences::on_efficiencySpin_editingFinished()
{
    efficiency = ui->efficiencySpin->value();
}

void Preferences::on_attenuationSpin_editingFinished()
{
    attenuation = ui->attenuationSpin->value();
}

void Preferences::on_bjcpYearCombo_currentIndexChanged(const QString &newYear)
{
    style = newYear;
}

void Preferences::on_method1Radio_clicked()
{
    colourMethod = "1";
}

void Preferences::on_method2Radio_clicked()
{
    colourMethod = "2";
}

void Preferences::on_redSpin_editingFinished()
{
    red = ui->redSpin->value();
}

void Preferences::on_greenSpin_editingFinished()
{
    green = ui->greenSpin->value();
}

void Preferences::on_blueSpin_editingFinished()
{
    blue = ui->blueSpin->value();
}

void Preferences::on_alphaSpin_editingFinished()
{
    alpha = ui->alphaSpin->value();
}

void Preferences::on_maltUnitCombo_currentIndexChanged(const QString &newU)
{
    qDebug() << "Reading new Malt U: " << newU;
    maltU = newU;
}

void Preferences::on_hopUnitsCombo_currentIndexChanged(const QString &arg1)
{
    hopsU = arg1;
}

void Preferences::on_volumeCombo_currentIndexChanged(const QString &arg1)
{
    sizeU = arg1;
}

void Preferences::on_batchSizeSpin_editingFinished()
{
    postBoil = ui->batchSizeSpin->value();
}

void Preferences::on_boilTimeSpin_editingFinished()
{
    boilTime = ui->boilTimeSpin->value();
}

void Preferences::on_mashVolCombo_currentIndexChanged(const QString &arg1)
{
    mashVolU = arg1;
}

void Preferences::on_mashTempF_clicked()
{
    mashTempU = "F";
}

void Preferences::on_mashTempC_clicked()
{
    mashTempU = "C";
}

void Preferences::on_boilTempSpin_editingFinished()
{
    double temp = ui->boilTempSpin->value();
    if (mashTempU == "C") {
        temp = BrewCalcs::cToF(temp);
    }
    boilTempF = temp;
}

void Preferences::on_mashRatioSpin_editingFinished()
{
    mashRatio = ui->mashRatioSpin->value();
}

void Preferences::on_deadSpaceSpin_editingFinished()
{
    deadSpace = ui->deadSpaceSpin->value();
}

void Preferences::on_mashRatioCombo_currentIndexChanged(const QString &arg1)
{
    mashRatioU = arg1;
}

void Preferences::on_hopTypeCombo_activated(const QString &arg1)
{
    hopsType = arg1;
}

void Preferences::on_waterProfileCombo_currentIndexChanged(const QString &arg1)
{
    waterProfile = arg1;
}

void Preferences::on_buttonBox_accepted()
{
    saveSettings();
}
