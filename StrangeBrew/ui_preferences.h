/********************************************************************************
** Form generated from reading UI file 'preferences.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCES_H
#define UI_PREFERENCES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Preferences
{
public:
    QDialogButtonBox *buttonBox;
    QTabWidget *preferencesTabs;
    QWidget *calcTab;
    QGridLayout *gridLayout_8;
    QGroupBox *ibuCalcBox;
    QGridLayout *gridLayout_2;
    QRadioButton *tinsethRadio;
    QRadioButton *ragerRadio;
    QRadioButton *garetzRadio;
    QGroupBox *hopsGroup;
    QGridLayout *gridLayout;
    QLabel *pelletHopsLabel;
    QDoubleSpinBox *pelletHopsSpin;
    QLabel *tinsethLabel;
    QDoubleSpinBox *tinsethSpin;
    QGroupBox *hopTimeBox;
    QGridLayout *gridLayout_6;
    QSpinBox *drySpin;
    QLabel *FWHlabel;
    QSpinBox *FWHSpin;
    QSpinBox *mashSpin;
    QLabel *mashLabel;
    QLabel *dryLabel;
    QGroupBox *alcoholBox;
    QGridLayout *gridLayout_3;
    QRadioButton *alcVolRadio;
    QRadioButton *alcWeightRadio;
    QGroupBox *colourMethBox;
    QGridLayout *gridLayout_4;
    QRadioButton *ebcRadio;
    QRadioButton *srmRadio;
    QGroupBox *waterUseBox;
    QGridLayout *gridLayout_7;
    QLabel *kettLossLabel;
    QLabel *miscLossLabel;
    QLabel *trubLossLabel;
    QDoubleSpinBox *kettLossSpin;
    QDoubleSpinBox *miscLossSpin;
    QDoubleSpinBox *trubLossSpin;
    QGroupBox *evapBox;
    QGridLayout *gridLayout_5;
    QRadioButton *evapConsRadio;
    QRadioButton *evapPercRadio;
    QDoubleSpinBox *evapRateSpin;
    QLabel *evapRateLabel;
    QWidget *costTab;
    QGridLayout *gridLayout_11;
    QGroupBox *costGroup;
    QGridLayout *gridLayout_9;
    QLabel *otherLabel;
    QDoubleSpinBox *otherCostSpin;
    QLabel *bottleLabel;
    QDoubleSpinBox *bottleSizeSpin;
    QComboBox *bottleUnitCombo;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_10;
    QLabel *primSugarLabel;
    QComboBox *primeSugarCombo;
    QLabel *sugarUnitsLabel;
    QComboBox *sugarUnitsCombo;
    QLabel *servTempLabel;
    QSpinBox *servTempSpin;
    QLabel *carbTempLabel;
    QRadioButton *carbUnitF;
    QRadioButton *carbUnitC;
    QLabel *bottleTempLabel;
    QSpinBox *bottleTempSpin;
    QLabel *targetCO2Label;
    QDoubleSpinBox *targetCO2Spin;
    QLabel *faucHeightLabel;
    QLabel *tubingIDLabel;
    QComboBox *tubingIDCombo;
    QCheckBox *keggedCheck;
    QDoubleSpinBox *faucHeightSpin;
    QWidget *brewerTab;
    QGridLayout *gridLayout_21;
    QGroupBox *brewerGroup;
    QGridLayout *gridLayout_12;
    QLabel *nameLabel;
    QLineEdit *nameEdit;
    QLabel *phoneLabel;
    QLineEdit *phoneEdit;
    QLabel *clubLabel;
    QLineEdit *clubEdit;
    QLabel *emailLabel;
    QLineEdit *emailEdit;
    QLabel *RecipeLabel;
    QPushButton *pushButton;
    QLineEdit *recipeDirEdit;
    QGroupBox *brewHouseGroup;
    QGridLayout *gridLayout_20;
    QLabel *efficiencyLabel;
    QSpinBox *efficiencySpin;
    QLabel *attenuationLabel;
    QSpinBox *attenuationSpin;
    QWidget *styleTab;
    QGridLayout *gridLayout_14;
    QGroupBox *bjcpGroup;
    QGridLayout *gridLayout_13;
    QComboBox *bjcpYearCombo;
    QWidget *appearanceTab;
    QGroupBox *colourBox;
    QGridLayout *gridLayout_15;
    QRadioButton *method1Radio;
    QRadioButton *method2Radio;
    QLabel *redLabel;
    QSpinBox *redSpin;
    QLabel *greenLabel;
    QSpinBox *greenSpin;
    QLabel *blueLabel;
    QSpinBox *blueSpin;
    QLabel *alphaLabel;
    QSpinBox *alphaSpin;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QFrame *strawFrame;
    QFrame *paleFrame;
    QFrame *amberFrame;
    QFrame *copperFrame;
    QFrame *brownFrame;
    QFrame *blackFrame;
    QWidget *newRecipeTab;
    QGridLayout *gridLayout_19;
    QGroupBox *sizeFrame;
    QGridLayout *gridLayout_16;
    QLabel *maltUnitsLabel;
    QComboBox *maltUnitCombo;
    QLabel *hopUnitsTime;
    QComboBox *hopUnitsCombo;
    QLabel *volumeLabel;
    QComboBox *volumeCombo;
    QLabel *batchSizeLabel;
    QDoubleSpinBox *batchSizeSpin;
    QLabel *boilTimeLabel;
    QSpinBox *boilTimeSpin;
    QGroupBox *miscGroup;
    QGridLayout *gridLayout_18;
    QLabel *hopTypeLabel;
    QComboBox *hopTypeCombo;
    QLabel *waterProfileLabel;
    QComboBox *waterProfileCombo;
    QGroupBox *mashGroup;
    QGridLayout *gridLayout_17;
    QLabel *mashVolLabel;
    QComboBox *mashVolCombo;
    QLabel *mashTempLabel;
    QRadioButton *mashTempF;
    QRadioButton *mashTempC;
    QLabel *boilTempLabel;
    QSpinBox *boilTempSpin;
    QLabel *mashRatioLabel;
    QDoubleSpinBox *mashRatioSpin;
    QLabel *deadSpaceLbl;
    QDoubleSpinBox *deadSpaceSpin;
    QComboBox *mashRatioCombo;
    QLabel *deadSpaceUnit;
    QButtonGroup *carbTempGroup;
    QButtonGroup *evapGroup;
    QButtonGroup *colourGroup;
    QButtonGroup *colourMethGroup;
    QButtonGroup *ibuCalcGroup;
    QButtonGroup *alcCalcGroup;

    void setupUi(QDialog *Preferences)
    {
        if (Preferences->objectName().isEmpty())
            Preferences->setObjectName(QStringLiteral("Preferences"));
        Preferences->resize(557, 639);
        QIcon icon;
        icon.addFile(QStringLiteral(":/menu/brew_png"), QSize(), QIcon::Normal, QIcon::Off);
        Preferences->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(Preferences);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(180, 550, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        preferencesTabs = new QTabWidget(Preferences);
        preferencesTabs->setObjectName(QStringLiteral("preferencesTabs"));
        preferencesTabs->setGeometry(QRect(10, 10, 541, 520));
        calcTab = new QWidget();
        calcTab->setObjectName(QStringLiteral("calcTab"));
        gridLayout_8 = new QGridLayout(calcTab);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        ibuCalcBox = new QGroupBox(calcTab);
        ibuCalcBox->setObjectName(QStringLiteral("ibuCalcBox"));
        gridLayout_2 = new QGridLayout(ibuCalcBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tinsethRadio = new QRadioButton(ibuCalcBox);
        ibuCalcGroup = new QButtonGroup(Preferences);
        ibuCalcGroup->setObjectName(QStringLiteral("ibuCalcGroup"));
        ibuCalcGroup->addButton(tinsethRadio);
        tinsethRadio->setObjectName(QStringLiteral("tinsethRadio"));

        gridLayout_2->addWidget(tinsethRadio, 0, 0, 1, 1);

        ragerRadio = new QRadioButton(ibuCalcBox);
        ibuCalcGroup->addButton(ragerRadio);
        ragerRadio->setObjectName(QStringLiteral("ragerRadio"));

        gridLayout_2->addWidget(ragerRadio, 1, 0, 1, 1);

        garetzRadio = new QRadioButton(ibuCalcBox);
        ibuCalcGroup->addButton(garetzRadio);
        garetzRadio->setObjectName(QStringLiteral("garetzRadio"));

        gridLayout_2->addWidget(garetzRadio, 2, 0, 1, 1);


        gridLayout_8->addWidget(ibuCalcBox, 0, 0, 2, 1);

        hopsGroup = new QGroupBox(calcTab);
        hopsGroup->setObjectName(QStringLiteral("hopsGroup"));
        gridLayout = new QGridLayout(hopsGroup);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pelletHopsLabel = new QLabel(hopsGroup);
        pelletHopsLabel->setObjectName(QStringLiteral("pelletHopsLabel"));

        gridLayout->addWidget(pelletHopsLabel, 0, 0, 1, 1);

        pelletHopsSpin = new QDoubleSpinBox(hopsGroup);
        pelletHopsSpin->setObjectName(QStringLiteral("pelletHopsSpin"));

        gridLayout->addWidget(pelletHopsSpin, 0, 1, 1, 2);

        tinsethLabel = new QLabel(hopsGroup);
        tinsethLabel->setObjectName(QStringLiteral("tinsethLabel"));

        gridLayout->addWidget(tinsethLabel, 1, 0, 1, 2);

        tinsethSpin = new QDoubleSpinBox(hopsGroup);
        tinsethSpin->setObjectName(QStringLiteral("tinsethSpin"));

        gridLayout->addWidget(tinsethSpin, 1, 2, 1, 1);


        gridLayout_8->addWidget(hopsGroup, 0, 1, 1, 2);

        hopTimeBox = new QGroupBox(calcTab);
        hopTimeBox->setObjectName(QStringLiteral("hopTimeBox"));
        gridLayout_6 = new QGridLayout(hopTimeBox);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        drySpin = new QSpinBox(hopTimeBox);
        drySpin->setObjectName(QStringLiteral("drySpin"));

        gridLayout_6->addWidget(drySpin, 0, 1, 1, 1);

        FWHlabel = new QLabel(hopTimeBox);
        FWHlabel->setObjectName(QStringLiteral("FWHlabel"));

        gridLayout_6->addWidget(FWHlabel, 1, 0, 1, 1);

        FWHSpin = new QSpinBox(hopTimeBox);
        FWHSpin->setObjectName(QStringLiteral("FWHSpin"));

        gridLayout_6->addWidget(FWHSpin, 1, 1, 1, 1);

        mashSpin = new QSpinBox(hopTimeBox);
        mashSpin->setObjectName(QStringLiteral("mashSpin"));

        gridLayout_6->addWidget(mashSpin, 2, 1, 1, 1);

        mashLabel = new QLabel(hopTimeBox);
        mashLabel->setObjectName(QStringLiteral("mashLabel"));

        gridLayout_6->addWidget(mashLabel, 2, 0, 1, 1);

        dryLabel = new QLabel(hopTimeBox);
        dryLabel->setObjectName(QStringLiteral("dryLabel"));

        gridLayout_6->addWidget(dryLabel, 0, 0, 1, 1);


        gridLayout_8->addWidget(hopTimeBox, 1, 1, 3, 2);

        alcoholBox = new QGroupBox(calcTab);
        alcoholBox->setObjectName(QStringLiteral("alcoholBox"));
        gridLayout_3 = new QGridLayout(alcoholBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        alcVolRadio = new QRadioButton(alcoholBox);
        alcCalcGroup = new QButtonGroup(Preferences);
        alcCalcGroup->setObjectName(QStringLiteral("alcCalcGroup"));
        alcCalcGroup->addButton(alcVolRadio);
        alcVolRadio->setObjectName(QStringLiteral("alcVolRadio"));

        gridLayout_3->addWidget(alcVolRadio, 0, 0, 1, 1);

        alcWeightRadio = new QRadioButton(alcoholBox);
        alcCalcGroup->addButton(alcWeightRadio);
        alcWeightRadio->setObjectName(QStringLiteral("alcWeightRadio"));

        gridLayout_3->addWidget(alcWeightRadio, 1, 0, 1, 1);


        gridLayout_8->addWidget(alcoholBox, 2, 0, 1, 1);

        colourMethBox = new QGroupBox(calcTab);
        colourMethBox->setObjectName(QStringLiteral("colourMethBox"));
        gridLayout_4 = new QGridLayout(colourMethBox);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        ebcRadio = new QRadioButton(colourMethBox);
        colourGroup = new QButtonGroup(Preferences);
        colourGroup->setObjectName(QStringLiteral("colourGroup"));
        colourGroup->addButton(ebcRadio);
        ebcRadio->setObjectName(QStringLiteral("ebcRadio"));

        gridLayout_4->addWidget(ebcRadio, 0, 0, 1, 1);

        srmRadio = new QRadioButton(colourMethBox);
        colourGroup->addButton(srmRadio);
        srmRadio->setObjectName(QStringLiteral("srmRadio"));

        gridLayout_4->addWidget(srmRadio, 1, 0, 1, 1);


        gridLayout_8->addWidget(colourMethBox, 3, 0, 2, 1);

        waterUseBox = new QGroupBox(calcTab);
        waterUseBox->setObjectName(QStringLiteral("waterUseBox"));
        gridLayout_7 = new QGridLayout(waterUseBox);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        kettLossLabel = new QLabel(waterUseBox);
        kettLossLabel->setObjectName(QStringLiteral("kettLossLabel"));

        gridLayout_7->addWidget(kettLossLabel, 0, 0, 1, 1);

        miscLossLabel = new QLabel(waterUseBox);
        miscLossLabel->setObjectName(QStringLiteral("miscLossLabel"));

        gridLayout_7->addWidget(miscLossLabel, 1, 0, 1, 1);

        trubLossLabel = new QLabel(waterUseBox);
        trubLossLabel->setObjectName(QStringLiteral("trubLossLabel"));

        gridLayout_7->addWidget(trubLossLabel, 2, 0, 1, 1);

        kettLossSpin = new QDoubleSpinBox(waterUseBox);
        kettLossSpin->setObjectName(QStringLiteral("kettLossSpin"));

        gridLayout_7->addWidget(kettLossSpin, 0, 1, 1, 1);

        miscLossSpin = new QDoubleSpinBox(waterUseBox);
        miscLossSpin->setObjectName(QStringLiteral("miscLossSpin"));

        gridLayout_7->addWidget(miscLossSpin, 1, 1, 1, 1);

        trubLossSpin = new QDoubleSpinBox(waterUseBox);
        trubLossSpin->setObjectName(QStringLiteral("trubLossSpin"));

        gridLayout_7->addWidget(trubLossSpin, 2, 1, 1, 1);


        gridLayout_8->addWidget(waterUseBox, 4, 2, 2, 1);

        evapBox = new QGroupBox(calcTab);
        evapBox->setObjectName(QStringLiteral("evapBox"));
        gridLayout_5 = new QGridLayout(evapBox);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        evapConsRadio = new QRadioButton(evapBox);
        evapGroup = new QButtonGroup(Preferences);
        evapGroup->setObjectName(QStringLiteral("evapGroup"));
        evapGroup->addButton(evapConsRadio);
        evapConsRadio->setObjectName(QStringLiteral("evapConsRadio"));

        gridLayout_5->addWidget(evapConsRadio, 0, 0, 1, 2);

        evapPercRadio = new QRadioButton(evapBox);
        evapGroup->addButton(evapPercRadio);
        evapPercRadio->setObjectName(QStringLiteral("evapPercRadio"));

        gridLayout_5->addWidget(evapPercRadio, 1, 0, 1, 2);

        evapRateSpin = new QDoubleSpinBox(evapBox);
        evapRateSpin->setObjectName(QStringLiteral("evapRateSpin"));

        gridLayout_5->addWidget(evapRateSpin, 2, 0, 1, 1);

        evapRateLabel = new QLabel(evapBox);
        evapRateLabel->setObjectName(QStringLiteral("evapRateLabel"));

        gridLayout_5->addWidget(evapRateLabel, 2, 1, 1, 1);


        gridLayout_8->addWidget(evapBox, 5, 0, 1, 2);

        preferencesTabs->addTab(calcTab, QString());
        costTab = new QWidget();
        costTab->setObjectName(QStringLiteral("costTab"));
        gridLayout_11 = new QGridLayout(costTab);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        costGroup = new QGroupBox(costTab);
        costGroup->setObjectName(QStringLiteral("costGroup"));
        gridLayout_9 = new QGridLayout(costGroup);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        otherLabel = new QLabel(costGroup);
        otherLabel->setObjectName(QStringLiteral("otherLabel"));

        gridLayout_9->addWidget(otherLabel, 0, 0, 1, 1);

        otherCostSpin = new QDoubleSpinBox(costGroup);
        otherCostSpin->setObjectName(QStringLiteral("otherCostSpin"));

        gridLayout_9->addWidget(otherCostSpin, 0, 1, 1, 1);

        bottleLabel = new QLabel(costGroup);
        bottleLabel->setObjectName(QStringLiteral("bottleLabel"));

        gridLayout_9->addWidget(bottleLabel, 1, 0, 1, 1);

        bottleSizeSpin = new QDoubleSpinBox(costGroup);
        bottleSizeSpin->setObjectName(QStringLiteral("bottleSizeSpin"));

        gridLayout_9->addWidget(bottleSizeSpin, 1, 1, 1, 1);

        bottleUnitCombo = new QComboBox(costGroup);
        bottleUnitCombo->setObjectName(QStringLiteral("bottleUnitCombo"));

        gridLayout_9->addWidget(bottleUnitCombo, 1, 2, 1, 1);


        gridLayout_11->addWidget(costGroup, 0, 0, 1, 1);

        groupBox = new QGroupBox(costTab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_10 = new QGridLayout(groupBox);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        primSugarLabel = new QLabel(groupBox);
        primSugarLabel->setObjectName(QStringLiteral("primSugarLabel"));

        gridLayout_10->addWidget(primSugarLabel, 0, 0, 1, 1);

        primeSugarCombo = new QComboBox(groupBox);
        primeSugarCombo->setObjectName(QStringLiteral("primeSugarCombo"));

        gridLayout_10->addWidget(primeSugarCombo, 0, 1, 1, 1);

        sugarUnitsLabel = new QLabel(groupBox);
        sugarUnitsLabel->setObjectName(QStringLiteral("sugarUnitsLabel"));

        gridLayout_10->addWidget(sugarUnitsLabel, 0, 2, 1, 1);

        sugarUnitsCombo = new QComboBox(groupBox);
        sugarUnitsCombo->setObjectName(QStringLiteral("sugarUnitsCombo"));

        gridLayout_10->addWidget(sugarUnitsCombo, 0, 3, 1, 1);

        servTempLabel = new QLabel(groupBox);
        servTempLabel->setObjectName(QStringLiteral("servTempLabel"));

        gridLayout_10->addWidget(servTempLabel, 1, 0, 1, 1);

        servTempSpin = new QSpinBox(groupBox);
        servTempSpin->setObjectName(QStringLiteral("servTempSpin"));
        servTempSpin->setMaximum(212);

        gridLayout_10->addWidget(servTempSpin, 1, 1, 1, 1);

        carbTempLabel = new QLabel(groupBox);
        carbTempLabel->setObjectName(QStringLiteral("carbTempLabel"));

        gridLayout_10->addWidget(carbTempLabel, 1, 2, 1, 1);

        carbUnitF = new QRadioButton(groupBox);
        carbTempGroup = new QButtonGroup(Preferences);
        carbTempGroup->setObjectName(QStringLiteral("carbTempGroup"));
        carbTempGroup->addButton(carbUnitF);
        carbUnitF->setObjectName(QStringLiteral("carbUnitF"));

        gridLayout_10->addWidget(carbUnitF, 1, 3, 1, 1);

        carbUnitC = new QRadioButton(groupBox);
        carbTempGroup->addButton(carbUnitC);
        carbUnitC->setObjectName(QStringLiteral("carbUnitC"));

        gridLayout_10->addWidget(carbUnitC, 1, 4, 1, 1);

        bottleTempLabel = new QLabel(groupBox);
        bottleTempLabel->setObjectName(QStringLiteral("bottleTempLabel"));

        gridLayout_10->addWidget(bottleTempLabel, 2, 0, 1, 1);

        bottleTempSpin = new QSpinBox(groupBox);
        bottleTempSpin->setObjectName(QStringLiteral("bottleTempSpin"));
        bottleTempSpin->setMaximum(212);

        gridLayout_10->addWidget(bottleTempSpin, 2, 1, 1, 1);

        targetCO2Label = new QLabel(groupBox);
        targetCO2Label->setObjectName(QStringLiteral("targetCO2Label"));

        gridLayout_10->addWidget(targetCO2Label, 2, 2, 1, 1);

        targetCO2Spin = new QDoubleSpinBox(groupBox);
        targetCO2Spin->setObjectName(QStringLiteral("targetCO2Spin"));

        gridLayout_10->addWidget(targetCO2Spin, 2, 3, 1, 1);

        faucHeightLabel = new QLabel(groupBox);
        faucHeightLabel->setObjectName(QStringLiteral("faucHeightLabel"));

        gridLayout_10->addWidget(faucHeightLabel, 3, 0, 1, 1);

        tubingIDLabel = new QLabel(groupBox);
        tubingIDLabel->setObjectName(QStringLiteral("tubingIDLabel"));

        gridLayout_10->addWidget(tubingIDLabel, 3, 2, 1, 1);

        tubingIDCombo = new QComboBox(groupBox);
        tubingIDCombo->setObjectName(QStringLiteral("tubingIDCombo"));

        gridLayout_10->addWidget(tubingIDCombo, 3, 3, 1, 1);

        keggedCheck = new QCheckBox(groupBox);
        keggedCheck->setObjectName(QStringLiteral("keggedCheck"));

        gridLayout_10->addWidget(keggedCheck, 4, 0, 1, 1);

        faucHeightSpin = new QDoubleSpinBox(groupBox);
        faucHeightSpin->setObjectName(QStringLiteral("faucHeightSpin"));

        gridLayout_10->addWidget(faucHeightSpin, 3, 1, 1, 1);


        gridLayout_11->addWidget(groupBox, 1, 0, 1, 1);

        preferencesTabs->addTab(costTab, QString());
        brewerTab = new QWidget();
        brewerTab->setObjectName(QStringLiteral("brewerTab"));
        gridLayout_21 = new QGridLayout(brewerTab);
        gridLayout_21->setObjectName(QStringLiteral("gridLayout_21"));
        brewerGroup = new QGroupBox(brewerTab);
        brewerGroup->setObjectName(QStringLiteral("brewerGroup"));
        gridLayout_12 = new QGridLayout(brewerGroup);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        nameLabel = new QLabel(brewerGroup);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        gridLayout_12->addWidget(nameLabel, 0, 0, 1, 2);

        nameEdit = new QLineEdit(brewerGroup);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout_12->addWidget(nameEdit, 0, 2, 1, 2);

        phoneLabel = new QLabel(brewerGroup);
        phoneLabel->setObjectName(QStringLiteral("phoneLabel"));

        gridLayout_12->addWidget(phoneLabel, 0, 4, 1, 1);

        phoneEdit = new QLineEdit(brewerGroup);
        phoneEdit->setObjectName(QStringLiteral("phoneEdit"));

        gridLayout_12->addWidget(phoneEdit, 0, 5, 1, 1);

        clubLabel = new QLabel(brewerGroup);
        clubLabel->setObjectName(QStringLiteral("clubLabel"));

        gridLayout_12->addWidget(clubLabel, 1, 0, 1, 1);

        clubEdit = new QLineEdit(brewerGroup);
        clubEdit->setObjectName(QStringLiteral("clubEdit"));

        gridLayout_12->addWidget(clubEdit, 1, 1, 1, 3);

        emailLabel = new QLabel(brewerGroup);
        emailLabel->setObjectName(QStringLiteral("emailLabel"));

        gridLayout_12->addWidget(emailLabel, 1, 4, 1, 1);

        emailEdit = new QLineEdit(brewerGroup);
        emailEdit->setObjectName(QStringLiteral("emailEdit"));

        gridLayout_12->addWidget(emailEdit, 1, 5, 1, 1);

        RecipeLabel = new QLabel(brewerGroup);
        RecipeLabel->setObjectName(QStringLiteral("RecipeLabel"));

        gridLayout_12->addWidget(RecipeLabel, 2, 0, 1, 3);

        pushButton = new QPushButton(brewerGroup);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_12->addWidget(pushButton, 2, 3, 1, 2);

        recipeDirEdit = new QLineEdit(brewerGroup);
        recipeDirEdit->setObjectName(QStringLiteral("recipeDirEdit"));
        recipeDirEdit->setEnabled(false);

        gridLayout_12->addWidget(recipeDirEdit, 3, 0, 1, 5);


        gridLayout_21->addWidget(brewerGroup, 0, 0, 1, 1);

        brewHouseGroup = new QGroupBox(brewerTab);
        brewHouseGroup->setObjectName(QStringLiteral("brewHouseGroup"));
        gridLayout_20 = new QGridLayout(brewHouseGroup);
        gridLayout_20->setObjectName(QStringLiteral("gridLayout_20"));
        efficiencyLabel = new QLabel(brewHouseGroup);
        efficiencyLabel->setObjectName(QStringLiteral("efficiencyLabel"));

        gridLayout_20->addWidget(efficiencyLabel, 0, 0, 1, 1);

        efficiencySpin = new QSpinBox(brewHouseGroup);
        efficiencySpin->setObjectName(QStringLiteral("efficiencySpin"));

        gridLayout_20->addWidget(efficiencySpin, 0, 1, 1, 1);

        attenuationLabel = new QLabel(brewHouseGroup);
        attenuationLabel->setObjectName(QStringLiteral("attenuationLabel"));

        gridLayout_20->addWidget(attenuationLabel, 1, 0, 1, 1);

        attenuationSpin = new QSpinBox(brewHouseGroup);
        attenuationSpin->setObjectName(QStringLiteral("attenuationSpin"));

        gridLayout_20->addWidget(attenuationSpin, 1, 1, 1, 1);


        gridLayout_21->addWidget(brewHouseGroup, 1, 0, 1, 1);

        preferencesTabs->addTab(brewerTab, QString());
        styleTab = new QWidget();
        styleTab->setObjectName(QStringLiteral("styleTab"));
        gridLayout_14 = new QGridLayout(styleTab);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        bjcpGroup = new QGroupBox(styleTab);
        bjcpGroup->setObjectName(QStringLiteral("bjcpGroup"));
        gridLayout_13 = new QGridLayout(bjcpGroup);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        bjcpYearCombo = new QComboBox(bjcpGroup);
        bjcpYearCombo->setObjectName(QStringLiteral("bjcpYearCombo"));

        gridLayout_13->addWidget(bjcpYearCombo, 0, 0, 1, 1);


        gridLayout_14->addWidget(bjcpGroup, 0, 0, 1, 1);

        preferencesTabs->addTab(styleTab, QString());
        appearanceTab = new QWidget();
        appearanceTab->setObjectName(QStringLiteral("appearanceTab"));
        colourBox = new QGroupBox(appearanceTab);
        colourBox->setObjectName(QStringLiteral("colourBox"));
        colourBox->setGeometry(QRect(20, 10, 471, 291));
        gridLayout_15 = new QGridLayout(colourBox);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        method1Radio = new QRadioButton(colourBox);
        colourMethGroup = new QButtonGroup(Preferences);
        colourMethGroup->setObjectName(QStringLiteral("colourMethGroup"));
        colourMethGroup->addButton(method1Radio);
        method1Radio->setObjectName(QStringLiteral("method1Radio"));

        gridLayout_15->addWidget(method1Radio, 0, 0, 1, 3);

        method2Radio = new QRadioButton(colourBox);
        colourMethGroup->addButton(method2Radio);
        method2Radio->setObjectName(QStringLiteral("method2Radio"));

        gridLayout_15->addWidget(method2Radio, 0, 3, 1, 3);

        redLabel = new QLabel(colourBox);
        redLabel->setObjectName(QStringLiteral("redLabel"));

        gridLayout_15->addWidget(redLabel, 1, 0, 1, 2);

        redSpin = new QSpinBox(colourBox);
        redSpin->setObjectName(QStringLiteral("redSpin"));

        gridLayout_15->addWidget(redSpin, 1, 2, 1, 1);

        greenLabel = new QLabel(colourBox);
        greenLabel->setObjectName(QStringLiteral("greenLabel"));

        gridLayout_15->addWidget(greenLabel, 1, 3, 1, 1);

        greenSpin = new QSpinBox(colourBox);
        greenSpin->setObjectName(QStringLiteral("greenSpin"));

        gridLayout_15->addWidget(greenSpin, 1, 4, 1, 2);

        blueLabel = new QLabel(colourBox);
        blueLabel->setObjectName(QStringLiteral("blueLabel"));

        gridLayout_15->addWidget(blueLabel, 2, 0, 1, 1);

        blueSpin = new QSpinBox(colourBox);
        blueSpin->setObjectName(QStringLiteral("blueSpin"));

        gridLayout_15->addWidget(blueSpin, 2, 1, 1, 2);

        alphaLabel = new QLabel(colourBox);
        alphaLabel->setObjectName(QStringLiteral("alphaLabel"));

        gridLayout_15->addWidget(alphaLabel, 2, 3, 1, 1);

        alphaSpin = new QSpinBox(colourBox);
        alphaSpin->setObjectName(QStringLiteral("alphaSpin"));

        gridLayout_15->addWidget(alphaSpin, 2, 4, 1, 2);

        label = new QLabel(colourBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_15->addWidget(label, 3, 0, 1, 1);

        label_2 = new QLabel(colourBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_15->addWidget(label_2, 3, 2, 1, 1);

        label_3 = new QLabel(colourBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_15->addWidget(label_3, 3, 3, 1, 2);

        label_4 = new QLabel(colourBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_15->addWidget(label_4, 3, 5, 1, 1);

        label_5 = new QLabel(colourBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_15->addWidget(label_5, 3, 6, 1, 1);

        label_6 = new QLabel(colourBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_15->addWidget(label_6, 3, 7, 1, 1);

        strawFrame = new QFrame(colourBox);
        strawFrame->setObjectName(QStringLiteral("strawFrame"));
        strawFrame->setFrameShape(QFrame::StyledPanel);
        strawFrame->setFrameShadow(QFrame::Raised);

        gridLayout_15->addWidget(strawFrame, 4, 0, 1, 1);

        paleFrame = new QFrame(colourBox);
        paleFrame->setObjectName(QStringLiteral("paleFrame"));
        paleFrame->setFrameShape(QFrame::StyledPanel);
        paleFrame->setFrameShadow(QFrame::Raised);

        gridLayout_15->addWidget(paleFrame, 4, 1, 1, 2);

        amberFrame = new QFrame(colourBox);
        amberFrame->setObjectName(QStringLiteral("amberFrame"));
        amberFrame->setFrameShape(QFrame::StyledPanel);
        amberFrame->setFrameShadow(QFrame::Raised);

        gridLayout_15->addWidget(amberFrame, 4, 3, 1, 2);

        copperFrame = new QFrame(colourBox);
        copperFrame->setObjectName(QStringLiteral("copperFrame"));
        copperFrame->setFrameShape(QFrame::StyledPanel);
        copperFrame->setFrameShadow(QFrame::Raised);

        gridLayout_15->addWidget(copperFrame, 4, 5, 1, 1);

        brownFrame = new QFrame(colourBox);
        brownFrame->setObjectName(QStringLiteral("brownFrame"));
        brownFrame->setFrameShape(QFrame::StyledPanel);
        brownFrame->setFrameShadow(QFrame::Raised);

        gridLayout_15->addWidget(brownFrame, 4, 6, 1, 1);

        blackFrame = new QFrame(colourBox);
        blackFrame->setObjectName(QStringLiteral("blackFrame"));
        blackFrame->setFrameShape(QFrame::StyledPanel);
        blackFrame->setFrameShadow(QFrame::Raised);

        gridLayout_15->addWidget(blackFrame, 4, 7, 1, 1);

        preferencesTabs->addTab(appearanceTab, QString());
        newRecipeTab = new QWidget();
        newRecipeTab->setObjectName(QStringLiteral("newRecipeTab"));
        gridLayout_19 = new QGridLayout(newRecipeTab);
        gridLayout_19->setObjectName(QStringLiteral("gridLayout_19"));
        sizeFrame = new QGroupBox(newRecipeTab);
        sizeFrame->setObjectName(QStringLiteral("sizeFrame"));
        gridLayout_16 = new QGridLayout(sizeFrame);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        maltUnitsLabel = new QLabel(sizeFrame);
        maltUnitsLabel->setObjectName(QStringLiteral("maltUnitsLabel"));

        gridLayout_16->addWidget(maltUnitsLabel, 0, 0, 1, 1);

        maltUnitCombo = new QComboBox(sizeFrame);
        maltUnitCombo->setObjectName(QStringLiteral("maltUnitCombo"));

        gridLayout_16->addWidget(maltUnitCombo, 0, 1, 1, 1);

        hopUnitsTime = new QLabel(sizeFrame);
        hopUnitsTime->setObjectName(QStringLiteral("hopUnitsTime"));

        gridLayout_16->addWidget(hopUnitsTime, 1, 0, 1, 1);

        hopUnitsCombo = new QComboBox(sizeFrame);
        hopUnitsCombo->setObjectName(QStringLiteral("hopUnitsCombo"));

        gridLayout_16->addWidget(hopUnitsCombo, 1, 1, 1, 1);

        volumeLabel = new QLabel(sizeFrame);
        volumeLabel->setObjectName(QStringLiteral("volumeLabel"));

        gridLayout_16->addWidget(volumeLabel, 2, 0, 1, 1);

        volumeCombo = new QComboBox(sizeFrame);
        volumeCombo->setObjectName(QStringLiteral("volumeCombo"));

        gridLayout_16->addWidget(volumeCombo, 2, 1, 1, 1);

        batchSizeLabel = new QLabel(sizeFrame);
        batchSizeLabel->setObjectName(QStringLiteral("batchSizeLabel"));

        gridLayout_16->addWidget(batchSizeLabel, 3, 0, 1, 1);

        batchSizeSpin = new QDoubleSpinBox(sizeFrame);
        batchSizeSpin->setObjectName(QStringLiteral("batchSizeSpin"));
        batchSizeSpin->setSingleStep(0.1);

        gridLayout_16->addWidget(batchSizeSpin, 3, 1, 1, 1);

        boilTimeLabel = new QLabel(sizeFrame);
        boilTimeLabel->setObjectName(QStringLiteral("boilTimeLabel"));

        gridLayout_16->addWidget(boilTimeLabel, 4, 0, 1, 1);

        boilTimeSpin = new QSpinBox(sizeFrame);
        boilTimeSpin->setObjectName(QStringLiteral("boilTimeSpin"));

        gridLayout_16->addWidget(boilTimeSpin, 4, 1, 1, 1);


        gridLayout_19->addWidget(sizeFrame, 0, 0, 1, 1);

        miscGroup = new QGroupBox(newRecipeTab);
        miscGroup->setObjectName(QStringLiteral("miscGroup"));
        gridLayout_18 = new QGridLayout(miscGroup);
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        hopTypeLabel = new QLabel(miscGroup);
        hopTypeLabel->setObjectName(QStringLiteral("hopTypeLabel"));

        gridLayout_18->addWidget(hopTypeLabel, 0, 0, 1, 1);

        hopTypeCombo = new QComboBox(miscGroup);
        hopTypeCombo->setObjectName(QStringLiteral("hopTypeCombo"));

        gridLayout_18->addWidget(hopTypeCombo, 0, 1, 1, 1);

        waterProfileLabel = new QLabel(miscGroup);
        waterProfileLabel->setObjectName(QStringLiteral("waterProfileLabel"));

        gridLayout_18->addWidget(waterProfileLabel, 1, 0, 1, 1);

        waterProfileCombo = new QComboBox(miscGroup);
        waterProfileCombo->setObjectName(QStringLiteral("waterProfileCombo"));

        gridLayout_18->addWidget(waterProfileCombo, 1, 1, 1, 1);


        gridLayout_19->addWidget(miscGroup, 2, 0, 1, 1);

        mashGroup = new QGroupBox(newRecipeTab);
        mashGroup->setObjectName(QStringLiteral("mashGroup"));
        gridLayout_17 = new QGridLayout(mashGroup);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        mashVolLabel = new QLabel(mashGroup);
        mashVolLabel->setObjectName(QStringLiteral("mashVolLabel"));

        gridLayout_17->addWidget(mashVolLabel, 0, 0, 1, 1);

        mashVolCombo = new QComboBox(mashGroup);
        mashVolCombo->setObjectName(QStringLiteral("mashVolCombo"));

        gridLayout_17->addWidget(mashVolCombo, 0, 1, 1, 1);

        mashTempLabel = new QLabel(mashGroup);
        mashTempLabel->setObjectName(QStringLiteral("mashTempLabel"));

        gridLayout_17->addWidget(mashTempLabel, 1, 0, 1, 1);

        mashTempF = new QRadioButton(mashGroup);
        mashTempF->setObjectName(QStringLiteral("mashTempF"));

        gridLayout_17->addWidget(mashTempF, 1, 1, 1, 1);

        mashTempC = new QRadioButton(mashGroup);
        mashTempC->setObjectName(QStringLiteral("mashTempC"));

        gridLayout_17->addWidget(mashTempC, 1, 2, 1, 1);

        boilTempLabel = new QLabel(mashGroup);
        boilTempLabel->setObjectName(QStringLiteral("boilTempLabel"));

        gridLayout_17->addWidget(boilTempLabel, 2, 0, 1, 1);

        boilTempSpin = new QSpinBox(mashGroup);
        boilTempSpin->setObjectName(QStringLiteral("boilTempSpin"));
        boilTempSpin->setMaximum(222);

        gridLayout_17->addWidget(boilTempSpin, 2, 1, 1, 1);

        mashRatioLabel = new QLabel(mashGroup);
        mashRatioLabel->setObjectName(QStringLiteral("mashRatioLabel"));

        gridLayout_17->addWidget(mashRatioLabel, 3, 0, 1, 1);

        mashRatioSpin = new QDoubleSpinBox(mashGroup);
        mashRatioSpin->setObjectName(QStringLiteral("mashRatioSpin"));
        mashRatioSpin->setSingleStep(0.01);

        gridLayout_17->addWidget(mashRatioSpin, 3, 1, 1, 1);

        deadSpaceLbl = new QLabel(mashGroup);
        deadSpaceLbl->setObjectName(QStringLiteral("deadSpaceLbl"));

        gridLayout_17->addWidget(deadSpaceLbl, 4, 0, 1, 1);

        deadSpaceSpin = new QDoubleSpinBox(mashGroup);
        deadSpaceSpin->setObjectName(QStringLiteral("deadSpaceSpin"));
        deadSpaceSpin->setSingleStep(0.1);

        gridLayout_17->addWidget(deadSpaceSpin, 4, 1, 1, 1);

        mashRatioCombo = new QComboBox(mashGroup);
        mashRatioCombo->setObjectName(QStringLiteral("mashRatioCombo"));

        gridLayout_17->addWidget(mashRatioCombo, 3, 2, 1, 1);

        deadSpaceUnit = new QLabel(mashGroup);
        deadSpaceUnit->setObjectName(QStringLiteral("deadSpaceUnit"));

        gridLayout_17->addWidget(deadSpaceUnit, 4, 2, 1, 1);

        boilTempSpin->raise();
        mashVolLabel->raise();
        mashVolCombo->raise();
        mashTempLabel->raise();
        mashTempF->raise();
        mashTempC->raise();
        boilTempLabel->raise();
        mashRatioLabel->raise();
        mashRatioSpin->raise();
        deadSpaceLbl->raise();
        deadSpaceSpin->raise();
        mashRatioCombo->raise();
        deadSpaceUnit->raise();

        gridLayout_19->addWidget(mashGroup, 1, 0, 1, 1);

        preferencesTabs->addTab(newRecipeTab, QString());

        retranslateUi(Preferences);
        QObject::connect(buttonBox, SIGNAL(accepted()), Preferences, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Preferences, SLOT(reject()));

        preferencesTabs->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(Preferences);
    } // setupUi

    void retranslateUi(QDialog *Preferences)
    {
        Preferences->setWindowTitle(QApplication::translate("Preferences", "Preferences", 0));
        ibuCalcBox->setTitle(QApplication::translate("Preferences", "IBU Calc Method", 0));
        tinsethRadio->setText(QApplication::translate("Preferences", "Tinseth", 0));
        ragerRadio->setText(QApplication::translate("Preferences", "Rager", 0));
        garetzRadio->setText(QApplication::translate("Preferences", "Garetz", 0));
        hopsGroup->setTitle(QApplication::translate("Preferences", "Hops", 0));
        pelletHopsLabel->setText(QApplication::translate("Preferences", "Pellet Hops +%", 0));
        tinsethLabel->setText(QApplication::translate("Preferences", "Tinseth Utilization Factor", 0));
        hopTimeBox->setTitle(QApplication::translate("Preferences", "Hop Times", 0));
        FWHlabel->setText(QApplication::translate("Preferences", "FWH,  boil minus min", 0));
        mashLabel->setText(QApplication::translate("Preferences", "Mash, min", 0));
        dryLabel->setText(QApplication::translate("Preferences", "Dry, min", 0));
        alcoholBox->setTitle(QApplication::translate("Preferences", "Alcohol Calc", 0));
        alcVolRadio->setText(QApplication::translate("Preferences", "Volume", 0));
        alcWeightRadio->setText(QApplication::translate("Preferences", "Weight", 0));
        colourMethBox->setTitle(QApplication::translate("Preferences", "Colour Method", 0));
        ebcRadio->setText(QApplication::translate("Preferences", "EBC", 0));
        srmRadio->setText(QApplication::translate("Preferences", "SRM", 0));
        waterUseBox->setTitle(QApplication::translate("Preferences", "Water Usage", 0));
        kettLossLabel->setText(QApplication::translate("Preferences", "Left in Kettle", 0));
        miscLossLabel->setText(QApplication::translate("Preferences", "Misc Losses", 0));
        trubLossLabel->setText(QApplication::translate("Preferences", "Lost In Trub", 0));
        evapBox->setTitle(QApplication::translate("Preferences", "Evaporation", 0));
        evapConsRadio->setText(QApplication::translate("Preferences", "Constant", 0));
        evapPercRadio->setText(QApplication::translate("Preferences", "Percent", 0));
        evapRateLabel->setText(QApplication::translate("Preferences", "TextLabel", 0));
        preferencesTabs->setTabText(preferencesTabs->indexOf(calcTab), QApplication::translate("Preferences", "Calculations", 0));
        costGroup->setTitle(QApplication::translate("Preferences", "Cost", 0));
        otherLabel->setText(QApplication::translate("Preferences", "Other", 0));
        bottleLabel->setText(QApplication::translate("Preferences", "Bottle Size", 0));
        groupBox->setTitle(QApplication::translate("Preferences", "Carbonation", 0));
        primSugarLabel->setText(QApplication::translate("Preferences", "Prime Sugar", 0));
        sugarUnitsLabel->setText(QApplication::translate("Preferences", "Sugar Units", 0));
        servTempLabel->setText(QApplication::translate("Preferences", "Serving Temp", 0));
        carbTempLabel->setText(QApplication::translate("Preferences", "Carb Temp Units", 0));
        carbUnitF->setText(QApplication::translate("Preferences", "F", 0));
        carbUnitC->setText(QApplication::translate("Preferences", "C", 0));
        bottleTempLabel->setText(QApplication::translate("Preferences", "Bottle Temp", 0));
        targetCO2Label->setText(QApplication::translate("Preferences", "Target CO2", 0));
        faucHeightLabel->setText(QApplication::translate("Preferences", "Height to Faucet", 0));
        tubingIDLabel->setText(QApplication::translate("Preferences", "Tubing ID", 0));
        keggedCheck->setText(QApplication::translate("Preferences", "Kegged", 0));
        preferencesTabs->setTabText(preferencesTabs->indexOf(costTab), QApplication::translate("Preferences", "Cost & Carb", 0));
        brewerGroup->setTitle(QApplication::translate("Preferences", "Brewer", 0));
        nameLabel->setText(QApplication::translate("Preferences", "Name", 0));
        phoneLabel->setText(QApplication::translate("Preferences", "Phone", 0));
        clubLabel->setText(QApplication::translate("Preferences", "Club", 0));
        emailLabel->setText(QApplication::translate("Preferences", "Email", 0));
        RecipeLabel->setText(QApplication::translate("Preferences", "Recipe Directory", 0));
        pushButton->setText(QApplication::translate("Preferences", "Select", 0));
        brewHouseGroup->setTitle(QApplication::translate("Preferences", "Brew House", 0));
        efficiencyLabel->setText(QApplication::translate("Preferences", "Efficiency", 0));
        attenuationLabel->setText(QApplication::translate("Preferences", "Attenuation", 0));
        preferencesTabs->setTabText(preferencesTabs->indexOf(brewerTab), QApplication::translate("Preferences", "Brewer", 0));
        bjcpGroup->setTitle(QApplication::translate("Preferences", "BJCP Year", 0));
        preferencesTabs->setTabText(preferencesTabs->indexOf(styleTab), QApplication::translate("Preferences", "Style", 0));
        colourBox->setTitle(QApplication::translate("Preferences", "Colour Swatch", 0));
        method1Radio->setText(QApplication::translate("Preferences", "Method 1", 0));
        method2Radio->setText(QApplication::translate("Preferences", "Method 2", 0));
        redLabel->setText(QApplication::translate("Preferences", "Red", 0));
        greenLabel->setText(QApplication::translate("Preferences", "Green", 0));
        blueLabel->setText(QApplication::translate("Preferences", "Blue", 0));
        alphaLabel->setText(QApplication::translate("Preferences", "Alpha", 0));
        label->setText(QApplication::translate("Preferences", "Straw (2)", 0));
        label_2->setText(QApplication::translate("Preferences", "Pale (4)", 0));
        label_3->setText(QApplication::translate("Preferences", "Amber (8)", 0));
        label_4->setText(QApplication::translate("Preferences", "Copper (15)", 0));
        label_5->setText(QApplication::translate("Preferences", "Brown (20)", 0));
        label_6->setText(QApplication::translate("Preferences", "Black (30", 0));
        preferencesTabs->setTabText(preferencesTabs->indexOf(appearanceTab), QApplication::translate("Preferences", "Appearance", 0));
        sizeFrame->setTitle(QApplication::translate("Preferences", "Units", 0));
        maltUnitsLabel->setText(QApplication::translate("Preferences", "Malt Units", 0));
        hopUnitsTime->setText(QApplication::translate("Preferences", "Hop Units", 0));
        volumeLabel->setText(QApplication::translate("Preferences", "Volume Units", 0));
        batchSizeLabel->setText(QApplication::translate("Preferences", "Batch Size", 0));
        boilTimeLabel->setText(QApplication::translate("Preferences", "Boil Time", 0));
        miscGroup->setTitle(QApplication::translate("Preferences", "Misc", 0));
        hopTypeLabel->setText(QApplication::translate("Preferences", "Hop Type", 0));
        waterProfileLabel->setText(QApplication::translate("Preferences", "Water Profile", 0));
        mashGroup->setTitle(QApplication::translate("Preferences", "Mash", 0));
        mashVolLabel->setText(QApplication::translate("Preferences", "Volume Units", 0));
        mashTempLabel->setText(QApplication::translate("Preferences", "Temp Units", 0));
        mashTempF->setText(QApplication::translate("Preferences", "F", 0));
        mashTempC->setText(QApplication::translate("Preferences", "C", 0));
        boilTempLabel->setText(QApplication::translate("Preferences", "Boil Temp", 0));
        mashRatioLabel->setText(QApplication::translate("Preferences", "Ratio", 0));
        deadSpaceLbl->setText(QApplication::translate("Preferences", "Dead Space", 0));
        deadSpaceUnit->setText(QApplication::translate("Preferences", "TextLabel", 0));
        preferencesTabs->setTabText(preferencesTabs->indexOf(newRecipeTab), QApplication::translate("Preferences", "New Recipe", 0));
    } // retranslateUi

};

namespace Ui {
    class Preferences: public Ui_Preferences {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCES_H
