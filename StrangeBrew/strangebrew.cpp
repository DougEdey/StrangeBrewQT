#include "strangebrew.h"

StrangeBrew::StrangeBrew(QWidget *parent) :
    //preferences(),
    QMainWindow(parent),
    ui(new Ui::StrangeBrew)
{
    ui->setupUi(this);

    qDebug() << CONVERTER_weightUnits.size();
    QUANTITY_volUnits = Quantity::initVolUnits();
    QUANTITY_weightUnits = Quantity::initWeightUnits();
    QUANTITY_pressureUnits = Quantity::initPressureUnits();
    CONVERTER_weightUnits = Converter::initWeights();
    CONVERTER_weightUnitsFull = Converter::initWeights("full");
    CONVERTER_weightUnitsAbrv = Converter::initWeights("abrv");



    ui->boilVolumeUnitsCombo->blockSignals(true);

    mcbid = NULL;
    miscid = NULL;
    mashid = NULL;
    fermid = NULL;
    hcbid = NULL;

    recipeXML = NULL;
    currentRecipe = NULL;

    QCoreApplication::setApplicationName("StrangeBrew");
    QCoreApplication::setOrganizationDomain("http://github.com/DougEdey/StrangeBrew");
    QCoreApplication::setOrganizationName("Doug Edey");

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    preferences = new QSettings("Doug Edey", "StrangeBrew");
    Database();
    Database::readDB(preferences->value("Style/Year", "2004").toString());

    if (preferences->value("Cloud/URL", "").toString() == "") {

        // First run, prompt for settings
        QMessageBox::about(this, "First run", "Since this is your first run, please check your preferences");
        Preferences *p = new Preferences();
        p->exec();
        delete p;
    }
    Database::readDB(preferences->value("Style/Year", "2004").toString());

    // Setup the comments filter for loss of focus
    ui->alcoholCombo->installEventFilter(this);
    ui->ibuCombo->installEventFilter(this);
    ui->colourCombo->installEventFilter(this);

    ui->commentsText->installEventFilter(this);
    ui->notesEdit->installEventFilter(this);
    ui->mashNameEdit->installEventFilter(this);
    ui->mashoutTempValue->installEventFilter(this);
    ui->ratioSpin->installEventFilter(this);
    ui->grainTempSpin->installEventFilter(this);
    ui->mashVolCombo->installEventFilter(this);
    ui->boilTempSpin->installEventFilter(this);
    ui->tempLossSpin->installEventFilter(this);
    ui->deadSpaceSpin->installEventFilter(this);

    ui->mashTempC->installEventFilter(this);
    ui->mashTempC->setAutoExclusive(true);
    ui->mashTempF->installEventFilter(this);
    ui->mashTempF->setAutoExclusive(true);

    ui->botTempSpin->installEventFilter(this);
    ui->servTempSpin->installEventFilter(this);
    ui->targetCO2Spin->installEventFilter(this);
    ui->primeSugarCombo->installEventFilter(this);
    ui->forceCarbCheck->installEventFilter(this);
    ui->tubingIDCombo->installEventFilter(this);
    ui->faucHeightSpin->installEventFilter(this);

    ui->waterFinalSpin->installEventFilter(this);
    ui->waterPostSpin->installEventFilter(this);
    ui->waterColSpin->installEventFilter(this);
    ui->waterTrubSpin->installEventFilter(this);
    ui->waterKetSpin->installEventFilter(this);
    ui->waterMiscSpin->installEventFilter(this);

    Options::SetDefaults();

    currentRecipe = new Recipe();
    currentRecipe->setDirty(false);
    hModel = new HopsModel(ui->hopsList);
    sModel = new StyleModel(ui->stylesList);
    miscModel = new MiscModel(ui->miscIngredientsList);
    mModel = new MaltModel(ui->fermentablesList);
    notesModel = new NotesModel(ui->notesList);
    mashModel = new MashModel(ui->mashStepsTable);
    fermModel = new FermModel(ui->fermTable);

    ui->fermentablesList->setModel(mModel);
    ui->miscIngredientsList->setModel(miscModel);
    ui->hopsList->setModel(hModel);
    ui->notesList->setModel(notesModel);
    ui->mashStepsTable->setModel(mashModel);
    ui->fermTable->setModel(fermModel);

    Q_FOREACH(Yeast *item, Database::yeastDB) {
        ui->yeastCombo->addItem(item->getName());
    }

    Q_FOREACH(Style *item, Database::styleDB) {
        ui->styleCombo->addItem(item->getName());
    }

    Q_FOREACH(PrimeSugar *item, Database::primeSugarDB) {
        ui->primeSugarCombo->addItem(item->getName());
    }

    // manual setup for the IDs
    ui->tubingIDCombo->addItem("3/16");
    ui->tubingIDCombo->addItem("1/4");

    // setup the volume combo
    ui->boilVolumeUnitsCombo->addItems(CONVERTER_volUnitsFull);

    // Setup the evaporation
    ui->evapType->addItem("Constant");
    ui->evapType->addItem("Percent");

    // Setup the notes type combo
    ui->noteCombo->addItems(NOTE_types);

    ui->mashVolCombo->addItems(CONVERTER_volUnitsAbrv);
    ui->ratioUnits->addItem(QT_PER_LB);
    ui->ratioUnits->addItem(L_PER_KG);

    // Setup the bottle combo
    ui->bottleSizeUnit->addItems(CONVERTER_volUnitsAbrv);

    setupProfileMenu();

    qDebug() << "Organization: " << QCoreApplication::organizationName();
    ui->boilVolumeUnitsCombo->blockSignals(false);
    setupConnections();
    qDebug() << "Connections setup";
    updateUI();
}

StrangeBrew::~StrangeBrew()
{
    //preferences->sync();
    //preferences->deleteLater();

//    hModel->deleteLater();
//    sModel->deleteLater();
//    miscModel->deleteLater();
//    mModel->deleteLater();
//    notesModel->deleteLater();
//    mashModel->deleteLater();
//    fermModel->deleteLater();

//    hcbid->deleteLater();
//    mcbid->deleteLater();
//    mashid->deleteLater();
//    fermid->deleteLater();
//    miscid->deleteLater();

    //delete currentRecipe;
    //delete recipeXML;
    delete ui;
}

void StrangeBrew::openFile(QString fileName) {
    if (fileName == "") {
        QString recipesDIR = QSettings("Doug Edey", "StrangeBrew").value("Recipes/DIR").toString();
        fileName = QFileDialog::getOpenFileName(this, tr("Open Recipe File"),
                                                        recipesDIR, tr("XML Files (*.xml);; All Files (*.*)"));
    }

    if (fileName != "") {
        QString type = checkFileType(fileName);
        if (type == "") {
            // Couldn't detect the file type
            return;
        }
        if (recipeXML != NULL)
            delete recipeXML;

        recipeXML = new ImportXML(type);

        recipeXML->setType(type);
        //(currentRecipe)->~Recipe();
        //delete currentRecipe;
        currentRecipe = recipeXML->readFile(fileName);
        currentRecipe->setFileName(fileName);
        qDebug() << "Loaded Recipe from file: " << currentRecipe->getName();
        currentRecipe->calcMaltTotals();
        currentRecipe->calcEfficiency();
        currentRecipe->calcHopsTotals();
        currentRecipe->calcPrimeSugar();
        currentRecipe->getMash()->setMaltWeightLbs(currentRecipe->getTotalMaltLbs());
        currentRecipe->getMash()->calcMashSchedule();
        currentRecipe->setDirty(false);
        updateUI();
    }
}


/********************
 * Save File prompt,
 * use force=true to force a file save dialog.
 * ********************/
void StrangeBrew::saveFile(bool force) {
    if (force == true || currentRecipe->getFileName() == "") {
        QString recipesDIR = QSettings("Doug Edey", "StrangeBrew").value("Recipes/DIR").toString();
        QString fileName = QFileDialog::getSaveFileName(this, tr("Open Recipe File"),
                                                        recipesDIR, tr("XML Files (*.xml);; All Files (*.*)"));
        // the user cancelled
        if (fileName == "") {
            return;
        }
        currentRecipe->setFileName(fileName);
    }

    // Save to the filename
    QFile outfile(currentRecipe->getFullFileName());
    QTextStream out(&outfile);
    // anything written to out will go to the file (when we flush it)
    outfile.open(QFile::ReadWrite | QFile::Truncate | QIODevice::Text);

    out << currentRecipe->toXML("");
    outfile.flush();
    outfile.close();
    currentRecipe->setDirty(false);
    updateTopUI();

}

void StrangeBrew::updateUI() {
    // setup the hopslist
    hModel->dataList(currentRecipe->getHopList());

    //
    if (hcbid == NULL) {
        hcbid = new HopItemDelegate();
    }
    ui->hopsList->setItemDelegate(hcbid);
    //ui->hopsList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // setup the Malt list
    mModel->dataList(currentRecipe->getMaltList());
    if (mcbid == NULL) {
        mcbid = new MaltItemDelegate(ui->fermentablesList);
    }
    ui->fermentablesList->setItemDelegate(mcbid);
    //ui->fermentablesList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Setup the Misc list
    miscModel->dataList(currentRecipe->getMiscList());
    //
    if (miscid == NULL) {
        miscid = new MiscItemDelegate();
    }
    ui->miscIngredientsList->setItemDelegate(miscid);
    //ui->miscIngredientsList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Setup the Note List
    notesModel->dataList(currentRecipe->getNotes());

    // Setup the Mash list
    mashModel->dataList(currentRecipe->getMash());

    if (mashid == NULL) {
        mashid = new MashItemDelegate(ui->mashStepsTable);
    }
    ui->mashStepsTable->setItemDelegate(mashid);

    //ui->mashStepsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Setup the Fermentables List
    fermModel->dataList(currentRecipe->getFermentStepsList());
    if (fermid == NULL) {
        fermid = new FermItemDelegate(ui->fermTable);
    }
    ui->fermTable->setItemDelegate(fermid);
    ui->fermTable->horizontalHeader()->sectionResizeMode(QHeaderView::Stretch);

    updateTopUI();

}

void StrangeBrew::updateTopUI() {

    QString title = "StrangeBrew [";
    // No filename
    if (currentRecipe->getFileName() == "") {
        title += "<new>";
    } else {
        title += currentRecipe->getFileName();
    }

    title += " - " + currentRecipe->getName();

    if (currentRecipe->getDirty()) {
        qDebug() << "Recipe is dirty";
        title += "*]";
    } else {
        title += "]";
    }

    QWidget::setWindowTitle(title);
    //QApplication::setApplicationName(title);

    ui->nameEdit->setText(currentRecipe->getName());

    qDebug() << "Setting OG Spin: " << currentRecipe->getEstOg();
    ui->ogSpin->setValue(currentRecipe->getEstOg());
    ui->fgSpin->setValue(currentRecipe->getEstFg());

    // Alcohol
    int curIndex = ui->alcoholCombo->findText(currentRecipe->getAlcMethod());
    if (curIndex >= 0) {
        ui->alcoholCombo->setCurrentIndex(curIndex);
    }
    ui->alcoholNumber->setDecMode();
    ui->alcoholNumber->display(currentRecipe->getAlcohol());

    // IBU
    curIndex = ui->ibuCombo->findText(currentRecipe->getIBUMethod());
    if (curIndex >= 0) {
        ui->ibuCombo->setCurrentIndex(curIndex);
    }

    ui->ibuNumber->setDecMode();
    ui->ibuNumber->display(currentRecipe->getIbu());

    // Colour
    curIndex = ui->colourCombo->findText(currentRecipe->getColourMethod());
    if (curIndex >= 0) {
        ui->colourCombo->setCurrentIndex(curIndex);
    }
    ui->colourNumber->setDecMode();
    ui->colourNumber->display(currentRecipe->getColour());

    // Gotta get the SRM value for colour
    QString rgbColour = BrewCalcs::calcRGB(1, currentRecipe->getColour(SRM),
                              preferences->value("Appearance/Red", 8).toInt(),
                              preferences->value("Appearance/Green", 30).toInt(),
                              preferences->value("Appearance/Blue", 20).toInt(),
                              preferences->value("Appearance/Alpha", 255).toInt());

    ui->colourBox->setStyleSheet("background-color: rgba(" + rgbColour + ");");
    ui->colourBox->repaint();

    ui->brewerEdit->setText(currentRecipe->getBrewer());
    qDebug() << "Setting eff spinner to " << currentRecipe->getEfficiency();
    ui->efficiencySpin->setValue(currentRecipe->getEfficiency());
    ui->dateTimeEdit->setDate(currentRecipe->getCreated());

    int comboIndex = ui->styleCombo->findText(currentRecipe->getStyle());
    if (comboIndex > -1) {
        ui->styleCombo->setCurrentIndex(comboIndex);
    } else {
        // Style isn't found, Alert for debug?
        qDebug() << "Style not found: " << currentRecipe->getStyle();
    }

    comboIndex = ui->yeastCombo->findText(currentRecipe->getYeast());
    if (comboIndex > -1) {
        ui->yeastCombo->setCurrentIndex(comboIndex);
    } else {
        // Yeast isn't found, Alert for debug?
        qDebug() << "Yeast not found: " << currentRecipe->getYeast();
    }

    ui->preBoilSpin->setValue(currentRecipe->getPreBoilVol());
    ui->postBoilSpin->setValue(currentRecipe->getPostBoilVol().getValue());

    qDebug() << "Volume Unit: " << currentRecipe->getVolUnits();

    comboIndex = ui->boilVolumeUnitsCombo->findText(currentRecipe->getVolUnits());
    if (comboIndex > -1) {
        ui->boilVolumeUnitsCombo->setCurrentIndex(comboIndex);
    } else {
        // Volume isn't found, Alert for debug?
        qDebug() << "Volume  not found: " << currentRecipe->getVolUnits();
    }

    ui->boilTimeSpin->setValue(currentRecipe->getBoilMinutes());
    ui->evapSpin->setValue(currentRecipe->getEvap());

    comboIndex = ui->evapType->findText(currentRecipe->getEvapMethod());
    if (comboIndex > -1) {
        ui->evapType->setCurrentIndex(comboIndex);
    } else {
        qDebug() << "Couldn't find evap type: " << currentRecipe->getEvapMethod();
    }

    // Style panel
    updateStylePanel();
    updateMashDetails();
    updateCarbPanel();
    updateWaterPanel();
    updateCostPanel();
    updateSettingsPanel();
}

void StrangeBrew::updateMashDetails() {
    Mash *m = currentRecipe->getMash();
    ui->mashNameEdit->setText(m->getName());
    ui->mashoutTempUnit->setText(m->getTempUnits());

    ui->ratioSpin->setValue(m->getMashRatio());
    ui->ratioUnits->setCurrentText(m->getMashRatioU());

    ui->mashVolCombo->setCurrentText(m->getMashTempUnits());

    ui->grainTempSpin->setValue(m->getGrainTemp());
    qDebug() << "BOIL! " << m->getBoilTemp();
    ui->boilTempSpin->setValue(m->getBoilTemp());
    ui->tempLossSpin->setValue(m->getTunLoss());
    ui->deadSpaceSpin->setValue(m->getDeadSpace());

    ui->grainTempUnit->setText(m->getMashTempUnits());
    ui->boilTempUnit->setText(m->getMashTempUnits());
    ui->tempLossUnit->setText(m->getMashTempUnits());

    ui->totalTimeValue->setText(QString::number(m->getMashTotalTime(), 'f', 0));
    ui->totalWeightValue->setText(QString::number(m->getTotalWeight(), 'f', 0));
    ui->totalWeightUnit->setText(m->getMashVolUnitsAbrv());
    ui->totalVolValue->setText(m->getMashTotalVol());
    ui->totalVolUnit->setText(m->getMashVolUnitsAbrv());

    if (m->getTempUnits() == "C") {
        ui->mashTempC->setChecked(true);
        ui->mashTempF->setChecked(false);
    } else {
        ui->mashTempF->setChecked(true);
        ui->mashTempC->setChecked(false);
    }
}

void StrangeBrew::updateCarbPanel() {
    ui->batchSizeValue->setText(currentRecipe->getFinalWortVolStr());
    ui->batchSizeUnit->setText(
                Quantity::getAbrvFromUnit(
                    "volume", currentRecipe->getVolUnits()));

    ui->botTempSpin->setValue(currentRecipe->getBottleTemp());
    ui->botTempUnit->setText(currentRecipe->getCarbTempU());
    ui->servTempSpin->setValue(currentRecipe->getServTemp());
    ui->servTempUnit->setText(currentRecipe->getCarbTempU());

    ui->targetCO2Spin->setValue(currentRecipe->getTargetVol());
    ui->styleCO2Text->setText("0.0");//currentRecipe->getStyleObj().getCO2Vol());

    ui->dissCO2Text->setText(QString::number(
                                 BrewCalcs::dissolvedCO2(currentRecipe->getBottleTemp()),
                                 'f', 1));

    int i = ui->primeSugarCombo->findText(currentRecipe->getPrimeSugarName());
    if (i != -1) {
        ui->primeSugarCombo->setCurrentIndex(i);
    }

    ui->primeValue->setDecMode();
    ui->primeValue->display(currentRecipe->getPrimeSugarAmt());
    ui->primeUnit->setText(currentRecipe->getPrimeSugarU());

    // Force Carbonation
    if (currentRecipe->isKegged()) {
        ui->forceCarbCheck->setChecked(true);
    } else {
        ui->forceCarbCheck->setChecked(false);
    }

    ui->keyPressureValue->setDecMode();
    ui->keyPressureValue->display(currentRecipe->getKegPSI());

    i = ui->tubingIDCombo->findText(currentRecipe->getKegTubeID());
    if (i != -1) {
        ui->tubingIDCombo->setCurrentIndex(i);
    }

    ui->faucHeightSpin->setValue(currentRecipe->getKegTubeHeight());

    ui->tubeLengthNumber->setDecMode();
    ui->lineVolNumber->setDecMode();
    ui->tubeLengthNumber->display(currentRecipe->getKegTubeLength());
    ui->lineVolNumber->display(currentRecipe->getKegTubeVol());
}

void StrangeBrew::updateWaterPanel() {
    ui->waterTotalLCD->display(currentRecipe->getTotalWaterVol());
    ui->waterTotalUnits->setText(currentRecipe->getVolUnitsAbrv());

    ui->waterMashLCD->display(Quantity::convertUnit(CONVERTER_QT,
                                                   currentRecipe->getVolUnits(),
                                                   currentRecipe->getMash()->getTotalWaterQts()));
    ui->waterMashUnits->setText(currentRecipe->getVolUnitsAbrv());

    ui->waterAbsorbedLCD->display(Quantity::convertUnit(CONVERTER_QT,
                                                        currentRecipe->getVolUnits(),
                                                        currentRecipe->getMash()->getAbsorbedQts()));
    ui->waterAbsorbedUnits->setText(currentRecipe->getVolUnitsAbrv());

    ui->waterSpargeLCD->display(Quantity::convertUnit(CONVERTER_QT,
                                                      currentRecipe->getVolUnits(),
                                                      currentRecipe->getMash()->getSpargeQts()));
    ui->waterSpargeUnits->setText(currentRecipe->getVolUnitsAbrv());

    ui->waterColSpin->setValue(currentRecipe->getPreBoilVol());
    ui->waterColUnit->setText(currentRecipe->getVolUnitsAbrv());

    ui->waterPostSpin->setValue(currentRecipe->getPostBoilVol(currentRecipe->getVolUnits()));
    ui->waterPostUnit->setText(currentRecipe->getVolUnitsAbrv());

    ui->waterFinalSpin->setValue(currentRecipe->getFinalWortVol());
    ui->waterFinalUnit->setText(currentRecipe->getVolUnitsAbrv());

    ui->waterChillValue->setText(QString::number(
                                     currentRecipe->getChillShrinkVol(
                                         currentRecipe->getVolUnits()),
                                     'f', 2));
    ui->waterChillUnit->setText(currentRecipe->getVolUnitsAbrv());

    ui->waterKetSpin->setValue(currentRecipe->getKettleLoss(currentRecipe->getVolUnits()));
    ui->waterKetUnit->setText(currentRecipe->getVolUnitsAbrv());

    ui->waterTrubSpin->setValue(currentRecipe->getTrubLoss(currentRecipe->getVolUnits()));
    ui->waterTrubUnit->setText(currentRecipe->getVolUnitsAbrv());

    ui->waterMiscSpin->setValue(currentRecipe->getMiscLoss(currentRecipe->getVolUnits()));
    ui->waterMiscUnit->setText(currentRecipe->getVolUnitsAbrv());

}

void StrangeBrew::updateSettingsPanel() {
    QString mRatio = currentRecipe->getMash()->getMashRatioU();
    ui->thickDecoctRatio->setText(mRatio);
    ui->thinDecoctRatio->setText(mRatio);

    ui->thinDecoctSpin->setValue(currentRecipe->getMash()->getThinDecoctRatio());
    ui->thickDecoctSpin->setValue(currentRecipe->getMash()->getThickDecoctRatio());

    ui->mashoutTempValue->setValue(currentRecipe->getMash()->MASHOUTTMPF);
    ui->spargeTempValue->setValue(currentRecipe->getMash()->SPARGETMPF);

    QString tempU = currentRecipe->getMash()->getTempUnits();
    ui->mashoutTempUnit->setText(tempU);
    ui->spargeTempUnit->setText(tempU);

    ui->addIBUValue->setValue(currentRecipe->getIBUHopUtil());
}

QString StrangeBrew::checkFileType(QString fileName) {

       if (fileName.endsWith(".rec"))
           return "promash";

       // let's open it up and have a peek
       // we'll only read 10 lines
        QFile in(fileName);
       if (fileName.endsWith(".qbrew") || (fileName.endsWith(".xml"))) {
           try {

                if (!in.open(QIODevice::ReadOnly | QIODevice::Text)) {

                    qDebug() << "Couldn't open file " << fileName;
                    qDebug() << in.errorString();
                    return "";
                }

                qDebug() << "Opened in: " << in.error();
               QTextStream inb(&in);

               QString c;
               int i = 0;
               while (i < 10) {
                   c = inb.readLine();
                   // check for an opening tag of Recipes too
                   if (c.indexOf("BeerXML Format") > -1 || c.indexOf("<RECIPES>") > -1 )
                       return "beerxml";
                   if (c.indexOf("STRANGEBREWRECIPE") > -1)
                       return "sb";
                   if ((c.indexOf("generator=\"qbrew\"") > -1) || (c.indexOf("application=\"qbrew\"") > -1))
                       return "qbrew";
                   i++;
               }
           } catch (...) {
               return("Unhandled error when checking file type " + in.error());

           }
       }
       return "";
   }

void StrangeBrew::hopsUpdated(const QModelIndex &from, const QModelIndex &to) {
    Q_UNUSED(from);
    Q_UNUSED(to);
    qDebug() << "Hop Updates Triggered";
    currentRecipe->calcHopsTotals();
    updateTopUI();
}

void StrangeBrew::maltUpdated(const QModelIndex &from, const QModelIndex &to) {
    Q_UNUSED(from);
    Q_UNUSED(to);
    qDebug() << "Malt Updates Triggered";
    currentRecipe->calcMaltTotals();
    updateTopUI();
}

void StrangeBrew::mashUpdated(const QModelIndex &from, const QModelIndex &to) {
    Q_UNUSED(from);
    Q_UNUSED(to);
    qDebug() << "Mash Updates Triggered";
    currentRecipe->getMash()->setMaltWeightLbs(currentRecipe->getTotalMaltLbs());
    currentRecipe->getMash()->calcMashSchedule();
    updateMashDetails();
}

void StrangeBrew::updateTopUI(const QModelIndex &from, const QModelIndex &to) {
    Q_UNUSED(from);
    Q_UNUSED(to);
    qDebug() << "Update top UI Slot Triggered";
    updateTopUI();
}

void StrangeBrew::boilUnitsUpdated(const QString& newUnits) {
    qDebug() << "Setting vol units: " << newUnits;
    currentRecipe->setVolUnits(newUnits);
    updateTopUI();
}

void StrangeBrew::mashSettingsUpdated() {
    Mash *m = currentRecipe->getMash();
    m->setMashVolUnits(
                ui->mashVolCombo->currentText());
    m->setMashRatio(ui->ratioSpin->value());
    m->setMashRatioU(ui->ratioUnits->currentText());
    m->setGrainTemp(ui->grainTempSpin->value());
    m->setBoilTemp(ui->boilTempSpin->value());
    m->setTunLoss(ui->tempLossSpin->value());
    m->setDeadSpace(ui->deadSpaceSpin->value());

    if (ui->mashTempC->isChecked()) {
        m->setTempUnits("C");
        m->calcMashSchedule();
    }

    if (ui->mashTempF->isChecked()) {
        m->setTempUnits("F");
        m->calcMashSchedule();
    }

    if (m->getTempUnits() == "C") {
        ui->mashTempC->setChecked(true);
        ui->mashTempF->setChecked(false);
    } else {
        ui->mashTempC->setChecked(false);
        ui->mashTempF->setChecked(true);
    }
    updateMashDetails();

}

void StrangeBrew::carbSettingsUpdated() {
    currentRecipe->setBottleTemp(ui->botTempSpin->value());
    currentRecipe->setServTemp(ui->servTempSpin->value());
    currentRecipe->setTargetVol(ui->targetCO2Spin->value());
    currentRecipe->setPrimeSugar(ui->primeSugarCombo->currentText());

    currentRecipe->setKegged(ui->forceCarbCheck->isChecked());
    currentRecipe->setKegTubeID(ui->tubingIDCombo->currentText());
    currentRecipe->setKegTubeHeight(ui->faucHeightSpin->value());
    currentRecipe->calcKegPSI();
    updateCarbPanel();
}

void StrangeBrew::waterSettingsUpdated() {
    // Is the post boil different and the target vol the same
    if (currentRecipe->getPostBoilVol(currentRecipe->getVolUnits())
                != ui->waterPostSpin->value()
            && currentRecipe->getPreBoilVol()
                == ui->waterColSpin->value()) {
        currentRecipe->setPostBoil(ui->waterPostSpin->value());
    } else if (currentRecipe->getPostBoilVol(currentRecipe->getVolUnits()) != ui->waterPostSpin->value()
          && currentRecipe->getPreBoilVol() == ui->waterColSpin->value()) {
        currentRecipe->setFinalWortVol(ui->waterFinalSpin->value());
    }

    currentRecipe->setTargetVol(ui->waterColSpin->value());
    currentRecipe->setKettleLoss(ui->waterKetSpin->value());
    currentRecipe->setTrubLoss(ui->waterTrubSpin->value());
    currentRecipe->setMiscLoss(ui->waterMiscSpin->value());

    updateWaterPanel();
}

void StrangeBrew::setMashProfile() {
    QAction *originalAction = qobject_cast<QAction*>(QObject::sender());
    QString name = originalAction->data().toString();

    Database::setMashProfile(currentRecipe->getMash(), name);

    mashModel->dataList(currentRecipe->getMash());
    ui->mashNameEdit->setText(name);
}

void StrangeBrew::saveMashProfile() {

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,
               "Save Mash?",
               "Save the current Mash steps as " + ui->mashNameEdit->text(),
              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) {
        return;
    }

    Database::addMashProfile(currentRecipe->getMash(), ui->mashNameEdit->text());
    setupProfileMenu();
}

void StrangeBrew::setupConnections() {

    if (!connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openFile()))) {
        qDebug() << "Couldn't connect openFile trigger";
    }
    if (!connect(hModel, SIGNAL(dataChanged( const QModelIndex &, const QModelIndex & )), this, SLOT(hopsUpdated(const QModelIndex &, const QModelIndex &)))) {
        qDebug() << "Couldn't connect hops datachanged trigger";
    }
    if (!connect(mModel, SIGNAL(dataChanged( const QModelIndex &, const QModelIndex & )), this, SLOT(maltUpdated(const QModelIndex &, const QModelIndex &)))) {
        qDebug() << "Couldn't connect malt datachanged trigger";
    }
    if (!connect(mashModel, SIGNAL(dataChanged( const QModelIndex &, const QModelIndex & )), this, SLOT(mashUpdated(const QModelIndex &, const QModelIndex &)))) {
        qDebug() << "Couldn't connect mash datachanged trigger";
    }

    if (!connect(ui->boilVolumeUnitsCombo, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(boilUnitsUpdated(const QString&)))) {
        qDebug() << "Couldn't connect boil volume units trigger";
    }

    if (!connect(ui->saveMashSteps, SIGNAL(clicked()), this, SLOT(saveMashProfile()))) {
        qDebug() << "Couldn't connect boil volume units trigger";
    }

//    if (!connect(ui->commentsText, SIGNAL(focusOutEvent( const QModelIndex &, const QModelIndex & )), this, SLOT(updateTopUI(const QModelIndex &, const QModelIndex &)))) {
//        qDebug() << "Couldn't connect malt datachanged trigger";
//    }
}

void StrangeBrew::setupProfileMenu() {
    QStringList mashProfiles = Database::getMashProfileNames();
    //qDebug() << "Found " << mashProfiles.size();
    QMenu *mashProfileMenu = new QMenu();

    QAction *newAction = NULL;
    Q_FOREACH(QString mashName, mashProfiles) {
        qDebug() << "Adding profile: " << mashName;
        newAction = mashProfileMenu->addAction(mashName);
        newAction->setData(mashName);
        connect(newAction, SIGNAL(triggered()), this, SLOT(setMashProfile()));

    }
    ui->mashProfiles->setMenu(mashProfileMenu);
    ui->mashProfiles->setPopupMode(QToolButton::InstantPopup);

    //ui->mashProfiles->addAction(mashProfileMenu->menuAction());

}

// Use an event filter to detect if we're mouse in or out, may look into breaking this out into a seperate class?
bool StrangeBrew::eventFilter(QObject *object, QEvent *event)
{

    // did we lose focus on the Mash Name?
    if (object == ui->mashNameEdit) {
        if (event->type() == QEvent::FocusOut) {
            currentRecipe->getMash()->setName(ui->mashNameEdit->text());
        }
        return false;
    }

    if (object->parent() == ui->mashSettings ) {
        if (event->type() == QEvent::FocusOut) {
            // The parent of the current object is a mash setting
            mashSettingsUpdated();
            return true;
        }
    }

    if (object == ui->mashTempC || object == ui->mashTempF) {
        if (event->type() == QEvent::ActionChanged) {
            updateMashDetails();
            return true;
        }
    }

    if (object->parent() == ui->primeFrame
            || object->parent() == ui->carbBatch
            || object->parent() == ui->forceCarbFrame) {
        if (event->type() == QEvent::FocusOut) {
            // the parent of the current object is a carbonation panel
            carbSettingsUpdated();
            return true;
        }
    }

    if (object->parent() == ui->waterUseBox || object->parent() == ui->waterLossesBox) {
        if (event->type() == QEvent::FocusOut) {
            waterSettingsUpdated();
            return true;
        }
    }

    if (object == ui->commentsText) {
        if (event->type() == QEvent::FocusOut) {
            QModelIndexList selectedRows = ui->miscIngredientsList->selectionModel()->selectedIndexes();
            for (int i = 0; i < selectedRows.length(); i++) {
                int curRow = selectedRows.at(i).row();
                Misc *mSelected = currentRecipe->getMisc(curRow);

                if (mSelected->getComments().compare(ui->commentsText->toPlainText()) == 0)
                    return false;

                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this,
                                               "Save Comment?",
                                               "Update comments for misc ingredient " + mSelected->getName(),
                                              QMessageBox::Yes | QMessageBox::No);

                if (reply == QMessageBox::Yes) {
                    mSelected->setComments(ui->commentsText->toPlainText());
                } else {
                    ui->commentsText->setText(mSelected->getComments());
                }

                currentRecipe->getMiscList()->replace(curRow, mSelected);

            }
        }
        return true;
    }


    // Are we acting on the Notes Editor? We will assume the status will be set first
    if (object == ui->notesEdit) {
        if (event->type() == QEvent::FocusOut) {
            QModelIndexList selectedRows = ui->notesList->selectionModel()->selectedIndexes();
            for (int i = 0; i < selectedRows.length(); i++) {
                int curRow = selectedRows.at(i).row();
                Note mSelected = currentRecipe->getNote(curRow);

                if (mSelected.getNote().compare(ui->notesEdit->toPlainText()) == 0
                        && mSelected.getType().compare(ui->noteCombo->currentText()) == 0
                        && mSelected.getDate() == ui->noteDate->date())
                    return false;

                //qDebug() << "CurRow " << curRow;
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this,
                                               "Save Comment?",
                                               QString("Update comments for note ").append(ui->noteCombo->currentText()).append(" at ").append(ui->noteDate->date().toString()),
                                              QMessageBox::Yes | QMessageBox::No);

                if (reply == QMessageBox::Yes) {
                    mSelected.setNote(ui->notesEdit->toPlainText());
                    mSelected.setType(ui->noteCombo->currentText());
                    mSelected.setDate(ui->noteDate->date());
                } else {
                    ui->commentsText->setText(mSelected.getNote());
                    ui->noteCombo->setCurrentText(mSelected.getType());
                    ui->noteDate->setDate(mSelected.getDate());
                }

                currentRecipe->getNotes()->replace(curRow, mSelected);

            }
            return true;
        }
        return false;
    }

    return false;
}

void StrangeBrew::updateStylePanel() {
    ui->ibuRecipe->setText("Recipe IBU: " + QString::number(currentRecipe->getIbu(), 'f', 2));
    ui->ibuProgress->setValue(QString::number(currentRecipe->getIbu(), 'f', 0).toInt());

    ui->colourRecipe->setText("Recipe Colour: " + QString::number(currentRecipe->getColour("SRM"), 'f', 2));
    ui->colourProgress->setValue(QString::number(currentRecipe->getColour(SRM) * 10, 'f', 0).toInt());

    ui->abvRecipe->setText("Recipe ABV: " + QString::number(currentRecipe->getAlcohol(), 'f', 2));
    ui->abvProgress->setValue(QString::number(currentRecipe->getAlcohol() * 10, 'f', 0).toInt());

    ui->ogRecipe->setText("Recipe OG: " + QString::number(currentRecipe->getEstOg(), 'f', 3));
    ui->ogProgress->setValue(QString::number(currentRecipe->getEstOg() * 1000, 'f', 0).toInt());
    ui->ogbuValue->setText(QString::number(currentRecipe->getBUGU(), 'f', 2));
    styleMatches = getStyleMatches();

    sModel->dataList(&styleMatches);
    ui->stylesList->setModel(sModel);
}

void StrangeBrew::updateCostPanel() {
    double totalCost = 0.0;
    double temp = currentRecipe->getTotalMaltCost();
    totalCost += temp;
    ui->costGrainValue->setText(QString::number(temp, 'f', 2));

    temp = currentRecipe->getTotalHopsCost();
    totalCost += temp;
    ui->costHopsValue->setText(QString::number(temp, 'f', 2));

    temp = currentRecipe->getTotalMiscCost();
    totalCost += temp;
    ui->costMiscValue->setText(QString::number(temp, 'f', 2));

    temp = currentRecipe->getYeastObj()->getCostPerU();
    totalCost += temp;
    ui->costYeastSpin->setValue(temp);

    temp = currentRecipe->getOtherCost();
    totalCost += temp;
    ui->costOtherSpin->setValue(temp);

    ui->costTotalValue->setText(QString::number(totalCost, 'f', 2));

    // Bottle side
    ui->bottleSizeSpin->setValue(
                    currentRecipe->getBottleSize());
    int index = ui->bottleSizeUnit->findText(currentRecipe->getBottleU());
    if (index > -1) {
        ui->bottleSizeUnit->setCurrentIndex(index);
    }

    ui->finalVolValue->setText(QString::number(
                                   currentRecipe->getFinalWortVol(), 'f', 1));
    ui->finalVolUnit->setText(currentRecipe->getVolUnitsAbrv());

    double numBottles =
            currentRecipe->getFinalWortVol(currentRecipe->getBottleU());
    numBottles = numBottles / currentRecipe->getBottleSize();
    //numBottles = ceil(numBottles);

    ui->bottleCountValue->setText(QString::number(numBottles, 'f', 0));

    double bottleCost = totalCost / numBottles;
    ui->bottleCostValue->setText(QString::number(bottleCost, 'f', 2));
}

QList<Style*> StrangeBrew::getStyleMatches(){

    QList<Style*> styles;
    Style *s;

    for (int i=0; i< Database::styleDB.size(); i++){
        s = Database::styleDB[i];

        if (currentRecipe->getEstOg() > s->getOgLow() && currentRecipe->getEstOg() < s->getOgHigh()
            && currentRecipe->getAlcohol() > s->getAlcLow() && currentRecipe->getAlcohol() < s->getAlcHigh()
            && currentRecipe->getColour(SRM) > s->getSrmLow() && currentRecipe->getColour(SRM) < s->getSrmHigh()
            && currentRecipe->getIbu() > s->getIbuLow() && currentRecipe->getIbu() < s->getIbuHigh() ) {
            styles.append(s);
        }

    }

    return styles;
}

void StrangeBrew::on_stylesList_activated(const QModelIndex &index)
{
    // Activated a style in the list view
    qDebug() << "Style list activated: " << index.row();
    Style *s = styleMatches[index.row()];
    qDebug() << ui->ibuProgress->value();
    ui->ibuStyleLow->setText(QString::number(s->getIbuLow(), 'f', 2));
    ui->ibuStyleHigh->setText(QString::number(s->getIbuHigh(), 'f', 2));
    ui->ibuProgress->setMinimum(QString::number(s->getIbuLow(), 'f', 0).toInt());
    ui->ibuProgress->setMaximum(QString::number(s->getIbuHigh(), 'f', 0).toInt());
    qDebug() << ui->ibuProgress->value();


    ui->colourStyleLow->setText(QString::number(s->getSrmLow(), 'f', 2));
    ui->colourStyleHigh->setText(QString::number(s->getSrmHigh(), 'f', 2));
    ui->colourProgress->setRange(QString::number(s->getSrmLow()*10, 'f', 0).toInt(),
                                QString::number(s->getSrmHigh()*10, 'f', 0).toInt());
    ui->colourProgress->setValue(QString::number(currentRecipe->getColour("SRM") * 10, 'f', 0).toInt());


    ui->abvStyleLow->setText(QString::number(s->getAlcLow(), 'f', 2));
    ui->abvStyleHigh->setText(QString::number(s->getAlcHigh(), 'f', 2));
    ui->abvProgress->setRange(QString::number(s->getAlcLow()*100, 'f', 0).toInt(),
                            QString::number(s->getAlcHigh()*100, 'f', 0).toInt());
    ui->abvProgress->setValue(QString::number(currentRecipe->getAlcohol() * 100, 'f', 0).toInt());


    ui->ogStyleLow->setText(QString::number(s->getOgLow(), 'f', 3));
    ui->ogStyleHigh->setText(QString::number(s->getOgHigh(), 'f', 3));
    ui->ogProgress->setMinimum(QString::number(s->getOgLow()*1000, 'f', 0).toInt());
    ui->ogProgress->setMaximum(QString::number(s->getOgHigh()*1000, 'f', 0).toInt());
    ui->ogProgress->setValue(QString::number(currentRecipe->getEstOg() * 1000, 'f', 0).toInt());

}

/*********************
 * Fermentable buttons
 * ********************/

void StrangeBrew::on_addMalt_clicked()
{
    mModel->insertRow(currentRecipe->getMaltListSize());
    currentRecipe->getMash()->setMaltWeightLbs(currentRecipe->getTotalMaltLbs());
}

void StrangeBrew::on_deleteMalt_clicked()
{
    QModelIndexList selectedRows = ui->fermentablesList->selectionModel()->selectedIndexes();
    for (int i = 0; i < selectedRows.length(); i++) {
        mModel->removeRow(selectedRows.at(i).row());
    }
    currentRecipe->getMash()->setMaltWeightLbs(currentRecipe->getTotalMaltLbs());
    //ui->fermentablesList->dataChanged();

}

/***************
 * Hop Buttons
 *
 */

void StrangeBrew::on_addHop_clicked()
{
    hModel->insertRow(currentRecipe->getHopsListSize());
}

void StrangeBrew::on_deleteHop_clicked()
{
    QModelIndexList selectedRows = ui->hopsList->selectionModel()->selectedIndexes();
    for (int i = 0; i < selectedRows.length(); i++) {
        hModel->removeRow(selectedRows.at(i).row());
    }
}
/*******
 * Slots for the Misc Ingredients panel list
 *******/
void StrangeBrew::on_miscIngredientsList_clicked(const QModelIndex &index)
{
    // Set the Comments text to this items comments
    ui->commentsText->setPlainText(currentRecipe->getMisc(index.row())->getComments());
}

void StrangeBrew::on_delMisc_clicked()
{
    QModelIndexList selectedRows = ui->miscIngredientsList->selectionModel()->selectedIndexes();
    for (int i = 0; i < selectedRows.length(); i++) {
        miscModel->removeRow(selectedRows.at(i).row());
    }
}

void StrangeBrew::on_addMisc_clicked()
{
    miscModel->insertRow(currentRecipe->getMiscListSize());
}

/******************
 * Slots for the Notes panel
 ******************/

void StrangeBrew::on_notesList_clicked(const QModelIndex &index) {
    on_notesList_activated(index);
}

void StrangeBrew::on_notesList_activated(const QModelIndex &index)
{
    // set the notes content
    Note n = currentRecipe->getNote(index.row());
    ui->notesEdit->setText(n.getNote());
    qDebug() << "Notes edit is read only: " << ui->notesEdit->isReadOnly();
    ui->notesEdit->setFocus();
    ui->notesEdit->setEnabled(true);
    // and the combo box
    int i = ui->noteCombo->findText(n.getType());
    if (i != -1) {
        ui->noteCombo->setCurrentIndex(i);
    }

    ui->noteDate->setDate(n.getDate());
}

void StrangeBrew::on_addNote_clicked()
{
    notesModel->insertRow(currentRecipe->getNotesListSize());
}

void StrangeBrew::on_delNote_clicked()
{
    if (currentRecipe->getNotesListSize() == 0) {
        return;
    }

    QItemSelectionModel *selectModel = ui->notesList->selectionModel();
    if (selectModel == NULL) {
        return;
    }

    QModelIndexList selectedRows = selectModel->selectedIndexes();
    for (int i = 0; i < selectedRows.length(); i++) {
        notesModel->removeRow(selectedRows.at(i).row());
    }

}

// Mash Steps Related work
void StrangeBrew::on_addMashStep_clicked()
{
    mashModel->insertRow(currentRecipe->getMash()->getStepSize());
}

void StrangeBrew::on_delMashStep_clicked()
{
    if (currentRecipe->getMash()->getStepSize() == 0) {
        return;
    }

    QItemSelectionModel *selectModel = ui->mashStepsTable->selectionModel();
    if (selectModel == NULL) {
        return;
    }

    QModelIndexList selectedRows = selectModel->selectedIndexes();
    for (int i = 0; i < selectedRows.length(); i++) {
        mashModel->removeRow(selectedRows.at(i).row());
    }
}

// Fermentation panel
void StrangeBrew::on_addFermStep_clicked()
{
    fermModel->insertRow(currentRecipe->getFermentStepSize());
}

void StrangeBrew::on_delFermStep_clicked()
{
    if (currentRecipe->getFermentStepSize() == 0) {
        return;
    }

    QItemSelectionModel *selectModel = ui->fermTable->selectionModel();
    if (selectModel == NULL) {
        return;
    }

    QModelIndexList selectedRows = selectModel->selectedIndexes();
    for (int i = 0; i < selectedRows.length(); i++) {
        fermModel->removeRow(selectedRows.at(i).row());
    }

}

/*************************************
 * Slots for the Main Recipe combos  *
 ************************************/

void StrangeBrew::on_alcoholCombo_currentIndexChanged(const QString &arg1)
{
    currentRecipe->setAlcMethod(arg1);
    updateTopUI();

}

void StrangeBrew::on_ibuCombo_currentIndexChanged(const QString &arg1)
{
    currentRecipe->setIBUMethod(arg1);
    updateTopUI();
}

void StrangeBrew::on_colourCombo_currentIndexChanged(const QString &arg1)
{
    currentRecipe->setColourMethod(arg1);
    updateTopUI();
}

void StrangeBrew::on_evapType_currentIndexChanged(const QString &arg1)
{
    currentRecipe->setEvapMethod(arg1);
    updateTopUI();

}

/****************************
 * Slots for the Cost Panel *
 * *************************/

void StrangeBrew::on_costYeastSpin_editingFinished()
{
    currentRecipe->getYeastObj()->setCost(ui->costYeastSpin->value());
    updateCostPanel();
}

void StrangeBrew::on_bottleSizeSpin_editingFinished()
{
    currentRecipe->setBottleSize(ui->bottleSizeSpin->value());
    updateCostPanel();
}

void StrangeBrew::on_bottleSizeUnit_currentIndexChanged(const QString &arg1)
{
    currentRecipe->setBottleU(arg1);
    updateCostPanel();
}

void StrangeBrew::on_costOtherSpin_editingFinished()
{
    currentRecipe->setOtherCost(ui->costOtherSpin->value());
    updateCostPanel();
}

/*******************************
 * Slots for the setting panel *
 ******************************/

void StrangeBrew::on_thinDecoctSpin_editingFinished()
{
    currentRecipe->getMash()->setDecoctRatio(DECOCTION_THIN, ui->thinDecoctSpin->value());
    updateTopUI();
}

void StrangeBrew::on_thickDecoctSpin_editingFinished()
{
    currentRecipe->getMash()->setDecoctRatio(DECOCTION_THICK, ui->thickDecoctSpin->value());
    updateTopUI();
}

void StrangeBrew::on_mashoutTempValue_editingFinished()
{
    double temp = ui->mashoutTempValue->value();
    if (currentRecipe->getMash()->getTempUnits().compare("C", Qt::CaseInsensitive) == 0) {
        temp = BrewCalcs::cToF(temp);
    }
    currentRecipe->getMash()->setMashoutTempF(temp);
    updateTopUI();
}

void StrangeBrew::on_spargeTempValue_editingFinished()
{
    double temp = ui->spargeTempValue->value();
    if (currentRecipe->getMash()->getTempUnits().compare("C", Qt::CaseInsensitive) == 0) {
        temp = BrewCalcs::cToF(temp);
    }
    currentRecipe->getMash()->setSpargeTempF(temp);
    updateTopUI();
}

void StrangeBrew::on_addIBUValue_editingFinished()
{
    currentRecipe->setIBUHopUtil(ui->addIBUValue->value());
    updateUI();
}

void StrangeBrew::on_actionPreferences_triggered()
{
    Preferences *prefs = new Preferences();
    prefs->exec();
}

void StrangeBrew::on_actionNew_triggered()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,
               "Save Recipe?",
               "Save the current recipe?",
              QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

    if (reply == QMessageBox::Cancel) {
        return;
    }

    if (reply == QMessageBox::Yes) {
        // Todo: Save the recipe
        //saveRecipe();
    }

    // Now we can clear the recipe
    currentRecipe = new Recipe();
    currentRecipe->setDirty(false);
    updateUI();
}

void StrangeBrew::on_actionSave_triggered()
{
    saveFile(false);
}


void StrangeBrew::on_actionCopy_to_Clipboard_triggered()
{
    QClipboard *clip = QApplication::clipboard();
    clip->setText(currentRecipe->toText());
}

void StrangeBrew::on_actionNew_Fermentable_triggered()
{
    NewFermentable *newFerm = new NewFermentable();
    newFerm->exec();
    delete newFerm;
}

void StrangeBrew::on_actionNew_Hop_triggered()
{
    NewHop *newHop = new NewHop();
    newHop->exec();
    delete newHop;

}

void StrangeBrew::on_actionNew_Yeast_triggered()
{
    NewYeast *newYeast = new NewYeast();
    newYeast->exec();
    delete newYeast;
}

void StrangeBrew::on_actionNew_Misc_triggered()
{
    NewMisc *newMisc = new NewMisc();
    newMisc->exec();
    delete newMisc;
}

void StrangeBrew::on_actionNew_Prime_Sugar_triggered()
{
    NewPrimeSugar *newPrime = new NewPrimeSugar();
    newPrime->exec();
    delete newPrime;
}

/************************************************
 * Triggers when updating the main recipe panel *
 ***********************************************/

void StrangeBrew::on_brewerEdit_editingFinished()
{
    currentRecipe->setBrewer(ui->brewerEdit->text());
    updateTopUI();
}

void StrangeBrew::on_efficiencySpin_editingFinished()
{

}

void StrangeBrew::on_efficiencySpin_valueChanged(int arg1)
{
    currentRecipe->setEfficiency(arg1);
    updateTopUI();
}

void StrangeBrew::on_attenuationSpin_valueChanged(int arg1)
{
    currentRecipe->setAttenuation(arg1);
    updateTopUI();
}

void StrangeBrew::on_dateTimeEdit_dateChanged(const QDate &date)
{
    currentRecipe->setCreated(date);
    updateTopUI();
}

void StrangeBrew::on_styleCombo_currentIndexChanged(const QString &arg1)
{
    if (arg1.compare("Style", Qt::CaseInsensitive) != 0)  {
        currentRecipe->setStyle(arg1);
    }
    updateTopUI();
}

void StrangeBrew::on_yeastCombo_currentIndexChanged(const QString &arg1)
{
    if (arg1.compare("Yeast", Qt::CaseInsensitive) != 0)  {
        currentRecipe->setYeast(Database::findYeast(arg1));
    }
    updateTopUI();
}

void StrangeBrew::on_preBoilSpin_editingFinished()
{
    currentRecipe->setPreBoil(ui->preBoilSpin->value());
    updateTopUI();
}

void StrangeBrew::on_postBoilSpin_editingFinished()
{
    currentRecipe->setPostBoil(ui->postBoilSpin->value());
    updateTopUI();
}


void StrangeBrew::on_boilVolumeUnitsCombo_currentIndexChanged(const QString &arg1)
{
    currentRecipe->setVolUnits(arg1);
    updateTopUI();
}

void StrangeBrew::on_boilTimeSpin_editingFinished()
{
    currentRecipe->setBoilMinutes(ui->boilTimeSpin->value());
    updateTopUI();
}

void StrangeBrew::on_evapSpin_valueChanged(double arg1)
{
    currentRecipe->setEvap(arg1);
    updateTopUI();
}


void StrangeBrew::on_ogSpin_editingFinished()
{
    currentRecipe->setEstOg(ui->ogSpin->value());
    updateTopUI();
}

void StrangeBrew::on_fgSpin_editingFinished()
{
    currentRecipe->setEstFg(ui->fgSpin->value());
    updateTopUI();
}

void StrangeBrew::on_actionResize_Convert_triggered()
{
    ResizeRecipe *resize = new ResizeRecipe(this, currentRecipe);
    resize->exec();
    updateUI();
    delete resize;
}

void StrangeBrew::on_actionRefractometer_triggered()
{
    RefractTool *refract = new RefractTool(this);
    refract->exec();
    delete refract;
}

void StrangeBrew::on_actionMalt_Percent_triggered()
{
    MaltPercentDialog *percent = new MaltPercentDialog(this, this->currentRecipe);
    percent->exec();
    updateUI();
    delete percent;
}

void StrangeBrew::on_actionExtract_Tool_triggered()
{
    ExtractDialog *extract = new ExtractDialog(this);
    extract->exec();
    delete extract;
}



void StrangeBrew::on_actionHydrometer_triggered()
{
    HydroDialog *hydro = new HydroDialog(this);
    hydro->exec();
    delete hydro;
}

void StrangeBrew::on_actionConversion_triggered()
{
    ConversionTool *convert = new ConversionTool(this);
    convert->exec();
    delete convert;
}


void StrangeBrew::recipeDownloaded() {
    RemoteRecipes *rRecipe = qobject_cast<RemoteRecipes *> (sender());
    QString filename = rRecipe->getRecipeFileName();
    if (filename != "") {
        this->openFile(filename);
    }
    rRecipe->close();
    return;
}

void StrangeBrew::on_actionBrowse_triggered()
{
    RemoteRecipes *rRecipe = new RemoteRecipes(this);
    connect(rRecipe, SIGNAL(accepted()), this, SLOT(recipeDownloaded()));
    rRecipe->exec();
    delete rRecipe;
}

void StrangeBrew::on_actionUpload_triggered()
{
    CloudControl *cControl = new CloudControl(this);
    cControl->UploadRecipe(this->currentRecipe);
    // Auto deletes itself when done
}

void StrangeBrew::on_actionSave_As_triggered()
{
    saveFile(true);
}
