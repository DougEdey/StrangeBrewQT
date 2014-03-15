/********************************************************************************
** Form generated from reading UI file 'strangebrew.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STRANGEBREW_H
#define UI_STRANGEBREW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StrangeBrew
{
public:
    QAction *actionOpen;
    QAction *actionNew;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionExport;
    QAction *actionPrint;
    QAction *actionExit;
    QAction *actionPreferences;
    QAction *actionCopy_to_Clipboard;
    QAction *actionNew_Fermentable;
    QAction *actionNew_Hop;
    QAction *actionNew_Yeast;
    QAction *actionNew_Misc;
    QAction *actionNew_Prime_Sugar;
    QAction *actionPantry;
    QAction *actionResize_Convert;
    QAction *actionRefractometer;
    QAction *actionMalt_Percent;
    QAction *actionExtract_Tool;
    QAction *actionHydrometer;
    QAction *actionConversion;
    QAction *actionBrowse;
    QAction *actionUpload;
    QWidget *centralWidget;
    QGridLayout *gridLayout_15;
    QLineEdit *nameEdit;
    QSplitter *splitter_3;
    QTabWidget *recipeTabs;
    QWidget *details;
    QGridLayout *gridLayout;
    QLabel *brewerLabel;
    QLineEdit *brewerEdit;
    QLabel *efficiencyLabel;
    QSpinBox *efficiencySpin;
    QLabel *ogLabel;
    QDoubleSpinBox *ogSpin;
    QLabel *alcoholLabel;
    QLCDNumber *alcoholNumber;
    QComboBox *alcoholCombo;
    QLabel *dateLabel;
    QDateTimeEdit *dateTimeEdit;
    QLabel *attenuationLabel;
    QSpinBox *attenuationSpin;
    QLabel *fgLabel;
    QDoubleSpinBox *fgSpin;
    QLabel *ibuLabel;
    QLCDNumber *ibuNumber;
    QComboBox *ibuCombo;
    QComboBox *styleCombo;
    QLabel *colourLabel;
    QLCDNumber *colourNumber;
    QComboBox *colourCombo;
    QComboBox *yeastCombo;
    QFrame *colourBox;
    QLabel *preBoilLabel;
    QDoubleSpinBox *preBoilSpin;
    QComboBox *boilVolumeUnitsCombo;
    QLabel *boilTimeLabel;
    QSpinBox *boilTimeSpin;
    QLabel *postBoilLabel;
    QDoubleSpinBox *postBoilSpin;
    QLabel *evapLabel;
    QDoubleSpinBox *evapSpin;
    QComboBox *evapType;
    QWidget *style;
    QGridLayout *gridLayout_3;
    QListView *stylesList;
    QLabel *abvStyleLabel;
    QLabel *ogRecipe;
    QLabel *abvStyleHigh;
    QLabel *ibuStyleLabel;
    QLabel *abvRecipe;
    QGridLayout *gridLayout_2;
    QLabel *ogbuLabel;
    QLabel *ogbuValue;
    QLabel *ogStyleLabel;
    QLabel *colourStyleLabel;
    QProgressBar *colourProgress;
    QLabel *colourRecipe;
    QLabel *ogStyleHigh;
    QLabel *abvStyleLow;
    QLabel *matchedLabel;
    QLabel *ogStyleLow;
    QLabel *ibuStyleHigh;
    QLabel *colourStyleLow;
    QLabel *ibuRecipe;
    QLabel *colourStyleHigh;
    QLabel *ibuStyleLow;
    QProgressBar *ibuProgress;
    QProgressBar *abvProgress;
    QProgressBar *ogProgress;
    QWidget *misc;
    QGridLayout *gridLayout_27;
    QLabel *commentsLabel;
    QSpacerItem *horizontalSpacer_6;
    QTextEdit *commentsText;
    QSplitter *splitter;
    QPushButton *addMisc;
    QPushButton *delMisc;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_5;
    QTableView *miscIngredientsList;
    QWidget *notes;
    QGridLayout *gridLayout_4;
    QListView *notesList;
    QComboBox *noteCombo;
    QDateEdit *noteDate;
    QTextEdit *notesEdit;
    QPushButton *addNote;
    QPushButton *delNote;
    QSpacerItem *horizontalSpacer_2;
    QWidget *dilution;
    QCheckBox *enableDilution;
    QLabel *dilutePostBoilLabel;
    QLabel *dilutePostBoilValue;
    QWidget *mash;
    QGridLayout *gridLayout_5;
    QLineEdit *mashNameEdit;
    QTableView *mashStepsTable;
    QPushButton *delMashStep;
    QPushButton *saveMashSteps;
    QPushButton *addMashStep;
    QToolButton *mashProfiles;
    QToolBox *mashTools;
    QWidget *mashSettings;
    QGridLayout *gridLayout_14;
    QLabel *grainTempUnit;
    QLabel *deadSpaceLabel;
    QComboBox *mashVolCombo;
    QLabel *tempLossLabel;
    QComboBox *ratioUnits;
    QLabel *ratioLabel;
    QLabel *tempLossUnit;
    QLabel *boilTempUnit;
    QLabel *deadSpaceUnit;
    QLabel *grainTempLabel;
    QDoubleSpinBox *boilTempSpin;
    QDoubleSpinBox *deadSpaceSpin;
    QDoubleSpinBox *tempLossSpin;
    QDoubleSpinBox *ratioSpin;
    QLabel *mashVolLabel;
    QDoubleSpinBox *grainTempSpin;
    QSpacerItem *horizontalSpacer_4;
    QLabel *boilTempLabel;
    QRadioButton *mashTempC;
    QRadioButton *mashTempF;
    QWidget *mashTotals;
    QGridLayout *gridLayout_12;
    QLabel *totalTimeLabel;
    QLabel *totalTimeValue;
    QLabel *totalWeightLabel;
    QLabel *totalWeightValue;
    QLabel *totalWeightUnit;
    QLabel *totaVolLabel;
    QLabel *totalVolValue;
    QLabel *totalVolUnit;
    QWidget *ferment;
    QGridLayout *gridLayout_6;
    QTableView *fermTable;
    QHBoxLayout *horizontalLayout;
    QPushButton *addFermStep;
    QPushButton *delFermStep;
    QWidget *carbonation;
    QGridLayout *gridLayout_17;
    QGroupBox *carbBatch;
    QGridLayout *gridLayout_16;
    QLabel *batchSizeLabel;
    QLabel *batchSizeValue;
    QLabel *batchSizeUnit;
    QLabel *botTempLabel;
    QDoubleSpinBox *botTempSpin;
    QLabel *botTempUnit;
    QLabel *servTempLabel;
    QDoubleSpinBox *servTempSpin;
    QLabel *servTempUnit;
    QLabel *targetCO2Label;
    QDoubleSpinBox *targetCO2Spin;
    QLabel *styleCO2Label;
    QLabel *dissCO2Label;
    QSpacerItem *horizontalSpacer_8;
    QLabel *styleCO2Text;
    QLabel *dissCO2Text;
    QFrame *primeFrame;
    QFormLayout *formLayout;
    QLabel *primeLabel;
    QComboBox *primeSugarCombo;
    QLCDNumber *primeValue;
    QLabel *primeUnit;
    QSpacerItem *verticalSpacer;
    QFrame *forceCarbFrame;
    QGridLayout *gridLayout_7;
    QLabel *faucHeightLabel;
    QLabel *lineVolUnit;
    QComboBox *tubingIDCombo;
    QLabel *tubingLenUnit;
    QLabel *kegPressureLabel;
    QLabel *tubingLenLabel;
    QLabel *kegPressureUnit;
    QLabel *faucHeightUnit;
    QDoubleSpinBox *faucHeightSpin;
    QLabel *tubingIDLabel;
    QLabel *lineVolLabel;
    QLCDNumber *keyPressureValue;
    QCheckBox *forceCarbCheck;
    QLCDNumber *tubeLengthNumber;
    QLCDNumber *lineVolNumber;
    QWidget *water;
    QGridLayout *gridLayout_19;
    QGroupBox *waterUseBox;
    QLabel *waterTotalLabel;
    QLCDNumber *waterTotalLCD;
    QLabel *waterTotalUnits;
    QLabel *waterMashLabel;
    QLabel *waterMashUnits;
    QLCDNumber *waterMashLCD;
    QLCDNumber *waterAbsorbedLCD;
    QLabel *waterAbsorbedUnits;
    QLabel *waterAbsorbedLabel;
    QLCDNumber *waterSpargeLCD;
    QLabel *waterSpargeUnits;
    QLabel *waterSpargeLabel;
    QLabel *waterColLabel;
    QDoubleSpinBox *waterColSpin;
    QLabel *waterColUnit;
    QDoubleSpinBox *waterPostSpin;
    QLabel *waterPostUnit;
    QLabel *waterPostLabel;
    QDoubleSpinBox *waterFinalSpin;
    QLabel *waterFinalUnit;
    QLabel *waterFinalLabel;
    QGroupBox *waterLossesBox;
    QGridLayout *gridLayout_18;
    QLabel *waterChillLabel;
    QLabel *waterChillValue;
    QLabel *waterChillUnit;
    QLabel *waterKetLabel;
    QDoubleSpinBox *waterKetSpin;
    QLabel *waterKetUnit;
    QLabel *waterTrubLabel;
    QDoubleSpinBox *waterTrubSpin;
    QLabel *waterTrubUnit;
    QLabel *waterMiscLabel;
    QDoubleSpinBox *waterMiscSpin;
    QLabel *waterMiscUnit;
    QWidget *cost;
    QGroupBox *recipeCostBox;
    QGridLayout *gridLayout_8;
    QLabel *costGrainLabel;
    QLabel *costGrainValue;
    QLabel *costHopsLabel;
    QLabel *costHopsValue;
    QLabel *costYeastLabel;
    QDoubleSpinBox *costYeastSpin;
    QLabel *costMiscLabel;
    QLabel *costMiscValue;
    QLabel *costOtherLabel;
    QDoubleSpinBox *costOtherSpin;
    QFrame *line;
    QLabel *costTotalLabel;
    QLabel *costTotalValue;
    QGroupBox *bottleCostBox;
    QGridLayout *gridLayout_9;
    QLabel *bottleSizeLabel;
    QLabel *finalVolLabel;
    QLabel *finalVolValue;
    QLabel *bottleCountLabel;
    QLabel *bottleCountValue;
    QLabel *bottleCostLabel;
    QLabel *bottleCostValue;
    QLabel *finalVolUnit;
    QComboBox *bottleSizeUnit;
    QSpinBox *bottleSizeSpin;
    QWidget *settings;
    QGridLayout *gridLayout_13;
    QGroupBox *mashSettingsBox;
    QGridLayout *gridLayout_10;
    QLabel *thinDecoctLabel;
    QDoubleSpinBox *thinDecoctSpin;
    QLabel *thinDecoctRatio;
    QLabel *thickDecoctLabel;
    QDoubleSpinBox *thickDecoctSpin;
    QLabel *thickDecoctRatio;
    QLabel *mashoutTempLabel;
    QSpinBox *mashoutTempValue;
    QLabel *mashoutTempUnit;
    QLabel *spargeTempLabel;
    QSpinBox *spargeTempValue;
    QLabel *spargeTempUnit;
    QGroupBox *otherSettingsBox;
    QGridLayout *gridLayout_11;
    QLabel *addIBULabel;
    QLabel *addIBUUnit;
    QDoubleSpinBox *addIBUValue;
    QFrame *frame;
    QGridLayout *gridLayout_25;
    QPushButton *deleteMalt;
    QPushButton *addMalt;
    QSpacerItem *horizontalSpacer;
    QTableView *fermentablesList;
    QFrame *frame_2;
    QGridLayout *gridLayout_26;
    QTableView *hopsList;
    QPushButton *addHop;
    QPushButton *deleteHop;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menuBar;
    QMenu *menuStrangeBrew;
    QMenu *menuCloud_Recipes;
    QMenu *menuEdit;
    QMenu *menuTools;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *StrangeBrew)
    {
        if (StrangeBrew->objectName().isEmpty())
            StrangeBrew->setObjectName(QStringLiteral("StrangeBrew"));
        StrangeBrew->resize(759, 847);
        QIcon icon;
        icon.addFile(QStringLiteral(":/menu/brew_png"), QSize(), QIcon::Normal, QIcon::Off);
        StrangeBrew->setWindowIcon(icon);
        actionOpen = new QAction(StrangeBrew);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/menu/open"), QSize(), QIcon::Normal, QIcon::On);
        actionOpen->setIcon(icon1);
        actionNew = new QAction(StrangeBrew);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/menu/new"), QSize(), QIcon::Normal, QIcon::On);
        actionNew->setIcon(icon2);
        actionSave = new QAction(StrangeBrew);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/menu/save"), QSize(), QIcon::Normal, QIcon::On);
        actionSave->setIcon(icon3);
        actionSave_As = new QAction(StrangeBrew);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/menu/saveas"), QSize(), QIcon::Normal, QIcon::On);
        actionSave_As->setIcon(icon4);
        actionExport = new QAction(StrangeBrew);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/menu/export"), QSize(), QIcon::Normal, QIcon::On);
        actionExport->setIcon(icon5);
        actionPrint = new QAction(StrangeBrew);
        actionPrint->setObjectName(QStringLiteral("actionPrint"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/menu/print"), QSize(), QIcon::Normal, QIcon::On);
        actionPrint->setIcon(icon6);
        actionExit = new QAction(StrangeBrew);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionPreferences = new QAction(StrangeBrew);
        actionPreferences->setObjectName(QStringLiteral("actionPreferences"));
        actionCopy_to_Clipboard = new QAction(StrangeBrew);
        actionCopy_to_Clipboard->setObjectName(QStringLiteral("actionCopy_to_Clipboard"));
        actionNew_Fermentable = new QAction(StrangeBrew);
        actionNew_Fermentable->setObjectName(QStringLiteral("actionNew_Fermentable"));
        actionNew_Hop = new QAction(StrangeBrew);
        actionNew_Hop->setObjectName(QStringLiteral("actionNew_Hop"));
        actionNew_Yeast = new QAction(StrangeBrew);
        actionNew_Yeast->setObjectName(QStringLiteral("actionNew_Yeast"));
        actionNew_Misc = new QAction(StrangeBrew);
        actionNew_Misc->setObjectName(QStringLiteral("actionNew_Misc"));
        actionNew_Prime_Sugar = new QAction(StrangeBrew);
        actionNew_Prime_Sugar->setObjectName(QStringLiteral("actionNew_Prime_Sugar"));
        actionPantry = new QAction(StrangeBrew);
        actionPantry->setObjectName(QStringLiteral("actionPantry"));
        actionResize_Convert = new QAction(StrangeBrew);
        actionResize_Convert->setObjectName(QStringLiteral("actionResize_Convert"));
        actionRefractometer = new QAction(StrangeBrew);
        actionRefractometer->setObjectName(QStringLiteral("actionRefractometer"));
        actionMalt_Percent = new QAction(StrangeBrew);
        actionMalt_Percent->setObjectName(QStringLiteral("actionMalt_Percent"));
        actionExtract_Tool = new QAction(StrangeBrew);
        actionExtract_Tool->setObjectName(QStringLiteral("actionExtract_Tool"));
        actionHydrometer = new QAction(StrangeBrew);
        actionHydrometer->setObjectName(QStringLiteral("actionHydrometer"));
        actionConversion = new QAction(StrangeBrew);
        actionConversion->setObjectName(QStringLiteral("actionConversion"));
        actionBrowse = new QAction(StrangeBrew);
        actionBrowse->setObjectName(QStringLiteral("actionBrowse"));
        actionUpload = new QAction(StrangeBrew);
        actionUpload->setObjectName(QStringLiteral("actionUpload"));
        centralWidget = new QWidget(StrangeBrew);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_15 = new QGridLayout(centralWidget);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        nameEdit = new QLineEdit(centralWidget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        gridLayout_15->addWidget(nameEdit, 0, 0, 1, 1);

        splitter_3 = new QSplitter(centralWidget);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter_3->sizePolicy().hasHeightForWidth());
        splitter_3->setSizePolicy(sizePolicy);
        splitter_3->setOrientation(Qt::Vertical);
        recipeTabs = new QTabWidget(splitter_3);
        recipeTabs->setObjectName(QStringLiteral("recipeTabs"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(recipeTabs->sizePolicy().hasHeightForWidth());
        recipeTabs->setSizePolicy(sizePolicy1);
        recipeTabs->setMinimumSize(QSize(0, 300));
        recipeTabs->setMaximumSize(QSize(16777215, 400));
        recipeTabs->setFocusPolicy(Qt::NoFocus);
        details = new QWidget();
        details->setObjectName(QStringLiteral("details"));
        sizePolicy.setHeightForWidth(details->sizePolicy().hasHeightForWidth());
        details->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(details);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        brewerLabel = new QLabel(details);
        brewerLabel->setObjectName(QStringLiteral("brewerLabel"));

        gridLayout->addWidget(brewerLabel, 0, 0, 1, 1);

        brewerEdit = new QLineEdit(details);
        brewerEdit->setObjectName(QStringLiteral("brewerEdit"));

        gridLayout->addWidget(brewerEdit, 0, 1, 1, 4);

        efficiencyLabel = new QLabel(details);
        efficiencyLabel->setObjectName(QStringLiteral("efficiencyLabel"));

        gridLayout->addWidget(efficiencyLabel, 0, 5, 1, 1);

        efficiencySpin = new QSpinBox(details);
        efficiencySpin->setObjectName(QStringLiteral("efficiencySpin"));
        efficiencySpin->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        efficiencySpin->setMaximum(100);
        efficiencySpin->setValue(75);

        gridLayout->addWidget(efficiencySpin, 0, 6, 1, 2);

        ogLabel = new QLabel(details);
        ogLabel->setObjectName(QStringLiteral("ogLabel"));

        gridLayout->addWidget(ogLabel, 0, 8, 1, 1);

        ogSpin = new QDoubleSpinBox(details);
        ogSpin->setObjectName(QStringLiteral("ogSpin"));
        ogSpin->setDecimals(3);
        ogSpin->setMinimum(0.9);
        ogSpin->setMaximum(2);
        ogSpin->setSingleStep(0.001);
        ogSpin->setValue(1);

        gridLayout->addWidget(ogSpin, 0, 9, 1, 3);

        alcoholLabel = new QLabel(details);
        alcoholLabel->setObjectName(QStringLiteral("alcoholLabel"));

        gridLayout->addWidget(alcoholLabel, 0, 12, 1, 1);

        alcoholNumber = new QLCDNumber(details);
        alcoholNumber->setObjectName(QStringLiteral("alcoholNumber"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        alcoholNumber->setFont(font);
        alcoholNumber->setSegmentStyle(QLCDNumber::Filled);

        gridLayout->addWidget(alcoholNumber, 0, 13, 1, 1);

        alcoholCombo = new QComboBox(details);
        alcoholCombo->setObjectName(QStringLiteral("alcoholCombo"));

        gridLayout->addWidget(alcoholCombo, 0, 14, 1, 1);

        dateLabel = new QLabel(details);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));

        gridLayout->addWidget(dateLabel, 1, 0, 1, 2);

        dateTimeEdit = new QDateTimeEdit(details);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setCalendarPopup(true);

        gridLayout->addWidget(dateTimeEdit, 1, 2, 1, 3);

        attenuationLabel = new QLabel(details);
        attenuationLabel->setObjectName(QStringLiteral("attenuationLabel"));

        gridLayout->addWidget(attenuationLabel, 1, 5, 1, 1);

        attenuationSpin = new QSpinBox(details);
        attenuationSpin->setObjectName(QStringLiteral("attenuationSpin"));
        attenuationSpin->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        attenuationSpin->setMaximum(100);
        attenuationSpin->setValue(75);

        gridLayout->addWidget(attenuationSpin, 1, 6, 1, 2);

        fgLabel = new QLabel(details);
        fgLabel->setObjectName(QStringLiteral("fgLabel"));

        gridLayout->addWidget(fgLabel, 1, 8, 1, 1);

        fgSpin = new QDoubleSpinBox(details);
        fgSpin->setObjectName(QStringLiteral("fgSpin"));
        fgSpin->setDecimals(3);
        fgSpin->setMinimum(0.9);
        fgSpin->setMaximum(2);
        fgSpin->setSingleStep(0.001);
        fgSpin->setValue(1);

        gridLayout->addWidget(fgSpin, 1, 9, 1, 3);

        ibuLabel = new QLabel(details);
        ibuLabel->setObjectName(QStringLiteral("ibuLabel"));

        gridLayout->addWidget(ibuLabel, 1, 12, 1, 1);

        ibuNumber = new QLCDNumber(details);
        ibuNumber->setObjectName(QStringLiteral("ibuNumber"));
        ibuNumber->setFont(font);

        gridLayout->addWidget(ibuNumber, 1, 13, 1, 1);

        ibuCombo = new QComboBox(details);
        ibuCombo->setObjectName(QStringLiteral("ibuCombo"));

        gridLayout->addWidget(ibuCombo, 1, 14, 1, 1);

        styleCombo = new QComboBox(details);
        styleCombo->setObjectName(QStringLiteral("styleCombo"));

        gridLayout->addWidget(styleCombo, 2, 1, 1, 11);

        colourLabel = new QLabel(details);
        colourLabel->setObjectName(QStringLiteral("colourLabel"));

        gridLayout->addWidget(colourLabel, 2, 12, 1, 1);

        colourNumber = new QLCDNumber(details);
        colourNumber->setObjectName(QStringLiteral("colourNumber"));
        colourNumber->setFont(font);

        gridLayout->addWidget(colourNumber, 2, 13, 1, 1);

        colourCombo = new QComboBox(details);
        colourCombo->setObjectName(QStringLiteral("colourCombo"));

        gridLayout->addWidget(colourCombo, 2, 14, 1, 1);

        yeastCombo = new QComboBox(details);
        yeastCombo->setObjectName(QStringLiteral("yeastCombo"));

        gridLayout->addWidget(yeastCombo, 3, 1, 1, 11);

        colourBox = new QFrame(details);
        colourBox->setObjectName(QStringLiteral("colourBox"));
        colourBox->setFrameShape(QFrame::StyledPanel);
        colourBox->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(colourBox, 3, 12, 2, 3);

        preBoilLabel = new QLabel(details);
        preBoilLabel->setObjectName(QStringLiteral("preBoilLabel"));

        gridLayout->addWidget(preBoilLabel, 4, 0, 1, 3);

        preBoilSpin = new QDoubleSpinBox(details);
        preBoilSpin->setObjectName(QStringLiteral("preBoilSpin"));
        preBoilSpin->setMaximum(1000);

        gridLayout->addWidget(preBoilSpin, 4, 3, 1, 1);

        boilVolumeUnitsCombo = new QComboBox(details);
        boilVolumeUnitsCombo->setObjectName(QStringLiteral("boilVolumeUnitsCombo"));

        gridLayout->addWidget(boilVolumeUnitsCombo, 4, 4, 1, 3);

        boilTimeLabel = new QLabel(details);
        boilTimeLabel->setObjectName(QStringLiteral("boilTimeLabel"));

        gridLayout->addWidget(boilTimeLabel, 4, 8, 1, 3);

        boilTimeSpin = new QSpinBox(details);
        boilTimeSpin->setObjectName(QStringLiteral("boilTimeSpin"));
        boilTimeSpin->setMaximum(240);
        boilTimeSpin->setValue(60);

        gridLayout->addWidget(boilTimeSpin, 4, 11, 1, 1);

        postBoilLabel = new QLabel(details);
        postBoilLabel->setObjectName(QStringLiteral("postBoilLabel"));

        gridLayout->addWidget(postBoilLabel, 5, 0, 1, 1);

        postBoilSpin = new QDoubleSpinBox(details);
        postBoilSpin->setObjectName(QStringLiteral("postBoilSpin"));
        postBoilSpin->setMaximum(1000);

        gridLayout->addWidget(postBoilSpin, 5, 3, 1, 1);

        evapLabel = new QLabel(details);
        evapLabel->setObjectName(QStringLiteral("evapLabel"));

        gridLayout->addWidget(evapLabel, 5, 7, 1, 3);

        evapSpin = new QDoubleSpinBox(details);
        evapSpin->setObjectName(QStringLiteral("evapSpin"));
        evapSpin->setSingleStep(0.01);
        evapSpin->setValue(1.5);

        gridLayout->addWidget(evapSpin, 5, 10, 1, 2);

        evapType = new QComboBox(details);
        evapType->setObjectName(QStringLiteral("evapType"));

        gridLayout->addWidget(evapType, 5, 12, 1, 2);

        recipeTabs->addTab(details, QString());
        style = new QWidget();
        style->setObjectName(QStringLiteral("style"));
        gridLayout_3 = new QGridLayout(style);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        stylesList = new QListView(style);
        stylesList->setObjectName(QStringLiteral("stylesList"));

        gridLayout_3->addWidget(stylesList, 1, 0, 11, 1);

        abvStyleLabel = new QLabel(style);
        abvStyleLabel->setObjectName(QStringLiteral("abvStyleLabel"));

        gridLayout_3->addWidget(abvStyleLabel, 8, 1, 1, 1);

        ogRecipe = new QLabel(style);
        ogRecipe->setObjectName(QStringLiteral("ogRecipe"));
        ogRecipe->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(ogRecipe, 9, 4, 1, 1);

        abvStyleHigh = new QLabel(style);
        abvStyleHigh->setObjectName(QStringLiteral("abvStyleHigh"));

        gridLayout_3->addWidget(abvStyleHigh, 8, 5, 1, 1);

        ibuStyleLabel = new QLabel(style);
        ibuStyleLabel->setObjectName(QStringLiteral("ibuStyleLabel"));

        gridLayout_3->addWidget(ibuStyleLabel, 1, 1, 1, 1);

        abvRecipe = new QLabel(style);
        abvRecipe->setObjectName(QStringLiteral("abvRecipe"));
        abvRecipe->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(abvRecipe, 6, 4, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        ogbuLabel = new QLabel(style);
        ogbuLabel->setObjectName(QStringLiteral("ogbuLabel"));

        gridLayout_2->addWidget(ogbuLabel, 0, 0, 1, 1);

        ogbuValue = new QLabel(style);
        ogbuValue->setObjectName(QStringLiteral("ogbuValue"));

        gridLayout_2->addWidget(ogbuValue, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 11, 4, 1, 1);

        ogStyleLabel = new QLabel(style);
        ogStyleLabel->setObjectName(QStringLiteral("ogStyleLabel"));

        gridLayout_3->addWidget(ogStyleLabel, 10, 1, 1, 1);

        colourStyleLabel = new QLabel(style);
        colourStyleLabel->setObjectName(QStringLiteral("colourStyleLabel"));

        gridLayout_3->addWidget(colourStyleLabel, 5, 1, 1, 1);

        colourProgress = new QProgressBar(style);
        colourProgress->setObjectName(QStringLiteral("colourProgress"));
        colourProgress->setValue(24);

        gridLayout_3->addWidget(colourProgress, 5, 4, 1, 1);

        colourRecipe = new QLabel(style);
        colourRecipe->setObjectName(QStringLiteral("colourRecipe"));
        colourRecipe->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(colourRecipe, 3, 4, 1, 1);

        ogStyleHigh = new QLabel(style);
        ogStyleHigh->setObjectName(QStringLiteral("ogStyleHigh"));

        gridLayout_3->addWidget(ogStyleHigh, 10, 5, 1, 1);

        abvStyleLow = new QLabel(style);
        abvStyleLow->setObjectName(QStringLiteral("abvStyleLow"));

        gridLayout_3->addWidget(abvStyleLow, 8, 2, 1, 1);

        matchedLabel = new QLabel(style);
        matchedLabel->setObjectName(QStringLiteral("matchedLabel"));

        gridLayout_3->addWidget(matchedLabel, 0, 0, 1, 1);

        ogStyleLow = new QLabel(style);
        ogStyleLow->setObjectName(QStringLiteral("ogStyleLow"));

        gridLayout_3->addWidget(ogStyleLow, 10, 2, 1, 1);

        ibuStyleHigh = new QLabel(style);
        ibuStyleHigh->setObjectName(QStringLiteral("ibuStyleHigh"));

        gridLayout_3->addWidget(ibuStyleHigh, 1, 5, 1, 1);

        colourStyleLow = new QLabel(style);
        colourStyleLow->setObjectName(QStringLiteral("colourStyleLow"));

        gridLayout_3->addWidget(colourStyleLow, 5, 2, 1, 1);

        ibuRecipe = new QLabel(style);
        ibuRecipe->setObjectName(QStringLiteral("ibuRecipe"));
        ibuRecipe->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(ibuRecipe, 0, 4, 1, 1);

        colourStyleHigh = new QLabel(style);
        colourStyleHigh->setObjectName(QStringLiteral("colourStyleHigh"));

        gridLayout_3->addWidget(colourStyleHigh, 5, 5, 1, 1);

        ibuStyleLow = new QLabel(style);
        ibuStyleLow->setObjectName(QStringLiteral("ibuStyleLow"));

        gridLayout_3->addWidget(ibuStyleLow, 1, 2, 1, 1);

        ibuProgress = new QProgressBar(style);
        ibuProgress->setObjectName(QStringLiteral("ibuProgress"));
        ibuProgress->setValue(24);

        gridLayout_3->addWidget(ibuProgress, 1, 4, 1, 1);

        abvProgress = new QProgressBar(style);
        abvProgress->setObjectName(QStringLiteral("abvProgress"));
        abvProgress->setValue(24);

        gridLayout_3->addWidget(abvProgress, 8, 4, 1, 1);

        ogProgress = new QProgressBar(style);
        ogProgress->setObjectName(QStringLiteral("ogProgress"));
        ogProgress->setValue(24);

        gridLayout_3->addWidget(ogProgress, 10, 4, 1, 1);

        recipeTabs->addTab(style, QString());
        misc = new QWidget();
        misc->setObjectName(QStringLiteral("misc"));
        gridLayout_27 = new QGridLayout(misc);
        gridLayout_27->setSpacing(6);
        gridLayout_27->setContentsMargins(11, 11, 11, 11);
        gridLayout_27->setObjectName(QStringLiteral("gridLayout_27"));
        commentsLabel = new QLabel(misc);
        commentsLabel->setObjectName(QStringLiteral("commentsLabel"));

        gridLayout_27->addWidget(commentsLabel, 0, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(278, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_27->addItem(horizontalSpacer_6, 0, 3, 1, 1);

        commentsText = new QTextEdit(misc);
        commentsText->setObjectName(QStringLiteral("commentsText"));

        gridLayout_27->addWidget(commentsText, 1, 2, 1, 2);

        splitter = new QSplitter(misc);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        addMisc = new QPushButton(splitter);
        addMisc->setObjectName(QStringLiteral("addMisc"));
        addMisc->setMaximumSize(QSize(88, 16777215));
        splitter->addWidget(addMisc);
        delMisc = new QPushButton(splitter);
        delMisc->setObjectName(QStringLiteral("delMisc"));
        delMisc->setMaximumSize(QSize(87, 16777215));
        splitter->addWidget(delMisc);

        gridLayout_27->addWidget(splitter, 2, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(174, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_27->addItem(horizontalSpacer_7, 2, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(349, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_27->addItem(horizontalSpacer_5, 2, 2, 1, 2);

        miscIngredientsList = new QTableView(misc);
        miscIngredientsList->setObjectName(QStringLiteral("miscIngredientsList"));
        miscIngredientsList->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        miscIngredientsList->setAlternatingRowColors(true);

        gridLayout_27->addWidget(miscIngredientsList, 0, 0, 2, 2);

        recipeTabs->addTab(misc, QString());
        commentsText->raise();
        miscIngredientsList->raise();
        commentsLabel->raise();
        splitter->raise();
        notes = new QWidget();
        notes->setObjectName(QStringLiteral("notes"));
        gridLayout_4 = new QGridLayout(notes);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        notesList = new QListView(notes);
        notesList->setObjectName(QStringLiteral("notesList"));

        gridLayout_4->addWidget(notesList, 0, 0, 2, 2);

        noteCombo = new QComboBox(notes);
        noteCombo->setObjectName(QStringLiteral("noteCombo"));

        gridLayout_4->addWidget(noteCombo, 0, 2, 1, 1);

        noteDate = new QDateEdit(notes);
        noteDate->setObjectName(QStringLiteral("noteDate"));

        gridLayout_4->addWidget(noteDate, 0, 3, 1, 1);

        notesEdit = new QTextEdit(notes);
        notesEdit->setObjectName(QStringLiteral("notesEdit"));

        gridLayout_4->addWidget(notesEdit, 1, 2, 1, 2);

        addNote = new QPushButton(notes);
        addNote->setObjectName(QStringLiteral("addNote"));

        gridLayout_4->addWidget(addNote, 2, 0, 1, 1);

        delNote = new QPushButton(notes);
        delNote->setObjectName(QStringLiteral("delNote"));

        gridLayout_4->addWidget(delNote, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(454, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 2, 2, 1, 2);

        recipeTabs->addTab(notes, QString());
        dilution = new QWidget();
        dilution->setObjectName(QStringLiteral("dilution"));
        enableDilution = new QCheckBox(dilution);
        enableDilution->setObjectName(QStringLiteral("enableDilution"));
        enableDilution->setGeometry(QRect(50, 10, 131, 21));
        dilutePostBoilLabel = new QLabel(dilution);
        dilutePostBoilLabel->setObjectName(QStringLiteral("dilutePostBoilLabel"));
        dilutePostBoilLabel->setGeometry(QRect(30, 40, 61, 16));
        dilutePostBoilValue = new QLabel(dilution);
        dilutePostBoilValue->setObjectName(QStringLiteral("dilutePostBoilValue"));
        dilutePostBoilValue->setGeometry(QRect(100, 40, 57, 15));
        recipeTabs->addTab(dilution, QString());
        mash = new QWidget();
        mash->setObjectName(QStringLiteral("mash"));
        gridLayout_5 = new QGridLayout(mash);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        mashNameEdit = new QLineEdit(mash);
        mashNameEdit->setObjectName(QStringLiteral("mashNameEdit"));

        gridLayout_5->addWidget(mashNameEdit, 0, 2, 1, 1);

        mashStepsTable = new QTableView(mash);
        mashStepsTable->setObjectName(QStringLiteral("mashStepsTable"));

        gridLayout_5->addWidget(mashStepsTable, 1, 0, 1, 6);

        delMashStep = new QPushButton(mash);
        delMashStep->setObjectName(QStringLiteral("delMashStep"));
        delMashStep->setMaximumSize(QSize(30, 16777215));

        gridLayout_5->addWidget(delMashStep, 0, 1, 1, 1);

        saveMashSteps = new QPushButton(mash);
        saveMashSteps->setObjectName(QStringLiteral("saveMashSteps"));

        gridLayout_5->addWidget(saveMashSteps, 0, 3, 1, 1);

        addMashStep = new QPushButton(mash);
        addMashStep->setObjectName(QStringLiteral("addMashStep"));
        addMashStep->setMaximumSize(QSize(30, 16777215));

        gridLayout_5->addWidget(addMashStep, 0, 0, 1, 1);

        mashProfiles = new QToolButton(mash);
        mashProfiles->setObjectName(QStringLiteral("mashProfiles"));

        gridLayout_5->addWidget(mashProfiles, 0, 4, 1, 1);

        mashTools = new QToolBox(mash);
        mashTools->setObjectName(QStringLiteral("mashTools"));
        mashSettings = new QWidget();
        mashSettings->setObjectName(QStringLiteral("mashSettings"));
        mashSettings->setGeometry(QRect(0, 0, 268, 218));
        gridLayout_14 = new QGridLayout(mashSettings);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        grainTempUnit = new QLabel(mashSettings);
        grainTempUnit->setObjectName(QStringLiteral("grainTempUnit"));

        gridLayout_14->addWidget(grainTempUnit, 3, 4, 1, 1);

        deadSpaceLabel = new QLabel(mashSettings);
        deadSpaceLabel->setObjectName(QStringLiteral("deadSpaceLabel"));

        gridLayout_14->addWidget(deadSpaceLabel, 7, 0, 1, 2);

        mashVolCombo = new QComboBox(mashSettings);
        mashVolCombo->setObjectName(QStringLiteral("mashVolCombo"));

        gridLayout_14->addWidget(mashVolCombo, 1, 1, 1, 3);

        tempLossLabel = new QLabel(mashSettings);
        tempLossLabel->setObjectName(QStringLiteral("tempLossLabel"));

        gridLayout_14->addWidget(tempLossLabel, 6, 0, 1, 1);

        ratioUnits = new QComboBox(mashSettings);
        ratioUnits->setObjectName(QStringLiteral("ratioUnits"));

        gridLayout_14->addWidget(ratioUnits, 0, 3, 1, 2);

        ratioLabel = new QLabel(mashSettings);
        ratioLabel->setObjectName(QStringLiteral("ratioLabel"));

        gridLayout_14->addWidget(ratioLabel, 0, 0, 1, 1);

        tempLossUnit = new QLabel(mashSettings);
        tempLossUnit->setObjectName(QStringLiteral("tempLossUnit"));

        gridLayout_14->addWidget(tempLossUnit, 6, 4, 1, 1);

        boilTempUnit = new QLabel(mashSettings);
        boilTempUnit->setObjectName(QStringLiteral("boilTempUnit"));

        gridLayout_14->addWidget(boilTempUnit, 5, 4, 1, 1);

        deadSpaceUnit = new QLabel(mashSettings);
        deadSpaceUnit->setObjectName(QStringLiteral("deadSpaceUnit"));

        gridLayout_14->addWidget(deadSpaceUnit, 7, 4, 1, 1);

        grainTempLabel = new QLabel(mashSettings);
        grainTempLabel->setObjectName(QStringLiteral("grainTempLabel"));

        gridLayout_14->addWidget(grainTempLabel, 3, 0, 1, 1);

        boilTempSpin = new QDoubleSpinBox(mashSettings);
        boilTempSpin->setObjectName(QStringLiteral("boilTempSpin"));
        boilTempSpin->setMaximum(250);

        gridLayout_14->addWidget(boilTempSpin, 5, 2, 1, 1);

        deadSpaceSpin = new QDoubleSpinBox(mashSettings);
        deadSpaceSpin->setObjectName(QStringLiteral("deadSpaceSpin"));

        gridLayout_14->addWidget(deadSpaceSpin, 7, 2, 1, 1);

        tempLossSpin = new QDoubleSpinBox(mashSettings);
        tempLossSpin->setObjectName(QStringLiteral("tempLossSpin"));
        tempLossSpin->setMaximum(250);

        gridLayout_14->addWidget(tempLossSpin, 6, 2, 1, 1);

        ratioSpin = new QDoubleSpinBox(mashSettings);
        ratioSpin->setObjectName(QStringLiteral("ratioSpin"));

        gridLayout_14->addWidget(ratioSpin, 0, 1, 1, 2);

        mashVolLabel = new QLabel(mashSettings);
        mashVolLabel->setObjectName(QStringLiteral("mashVolLabel"));

        gridLayout_14->addWidget(mashVolLabel, 1, 0, 1, 1);

        grainTempSpin = new QDoubleSpinBox(mashSettings);
        grainTempSpin->setObjectName(QStringLiteral("grainTempSpin"));
        grainTempSpin->setMaximum(250);

        gridLayout_14->addWidget(grainTempSpin, 3, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_4, 1, 4, 1, 1);

        boilTempLabel = new QLabel(mashSettings);
        boilTempLabel->setObjectName(QStringLiteral("boilTempLabel"));

        gridLayout_14->addWidget(boilTempLabel, 5, 0, 1, 1);

        mashTempC = new QRadioButton(mashSettings);
        mashTempC->setObjectName(QStringLiteral("mashTempC"));

        gridLayout_14->addWidget(mashTempC, 8, 0, 1, 1);

        mashTempF = new QRadioButton(mashSettings);
        mashTempF->setObjectName(QStringLiteral("mashTempF"));

        gridLayout_14->addWidget(mashTempF, 8, 2, 1, 1);

        mashTools->addItem(mashSettings, QStringLiteral("Settings"));
        mashTotals = new QWidget();
        mashTotals->setObjectName(QStringLiteral("mashTotals"));
        mashTotals->setGeometry(QRect(0, 0, 154, 75));
        gridLayout_12 = new QGridLayout(mashTotals);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        totalTimeLabel = new QLabel(mashTotals);
        totalTimeLabel->setObjectName(QStringLiteral("totalTimeLabel"));

        gridLayout_12->addWidget(totalTimeLabel, 0, 0, 1, 1);

        totalTimeValue = new QLabel(mashTotals);
        totalTimeValue->setObjectName(QStringLiteral("totalTimeValue"));

        gridLayout_12->addWidget(totalTimeValue, 0, 1, 1, 1);

        totalWeightLabel = new QLabel(mashTotals);
        totalWeightLabel->setObjectName(QStringLiteral("totalWeightLabel"));

        gridLayout_12->addWidget(totalWeightLabel, 1, 0, 1, 1);

        totalWeightValue = new QLabel(mashTotals);
        totalWeightValue->setObjectName(QStringLiteral("totalWeightValue"));

        gridLayout_12->addWidget(totalWeightValue, 1, 1, 1, 1);

        totalWeightUnit = new QLabel(mashTotals);
        totalWeightUnit->setObjectName(QStringLiteral("totalWeightUnit"));

        gridLayout_12->addWidget(totalWeightUnit, 1, 2, 1, 1);

        totaVolLabel = new QLabel(mashTotals);
        totaVolLabel->setObjectName(QStringLiteral("totaVolLabel"));

        gridLayout_12->addWidget(totaVolLabel, 2, 0, 1, 1);

        totalVolValue = new QLabel(mashTotals);
        totalVolValue->setObjectName(QStringLiteral("totalVolValue"));

        gridLayout_12->addWidget(totalVolValue, 2, 1, 1, 1);

        totalVolUnit = new QLabel(mashTotals);
        totalVolUnit->setObjectName(QStringLiteral("totalVolUnit"));

        gridLayout_12->addWidget(totalVolUnit, 2, 2, 1, 1);

        mashTools->addItem(mashTotals, QStringLiteral("Totals"));

        gridLayout_5->addWidget(mashTools, 0, 6, 2, 1);

        recipeTabs->addTab(mash, QString());
        ferment = new QWidget();
        ferment->setObjectName(QStringLiteral("ferment"));
        gridLayout_6 = new QGridLayout(ferment);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        fermTable = new QTableView(ferment);
        fermTable->setObjectName(QStringLiteral("fermTable"));

        gridLayout_6->addWidget(fermTable, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addFermStep = new QPushButton(ferment);
        addFermStep->setObjectName(QStringLiteral("addFermStep"));

        horizontalLayout->addWidget(addFermStep);

        delFermStep = new QPushButton(ferment);
        delFermStep->setObjectName(QStringLiteral("delFermStep"));

        horizontalLayout->addWidget(delFermStep);


        gridLayout_6->addLayout(horizontalLayout, 1, 0, 1, 1);

        recipeTabs->addTab(ferment, QString());
        carbonation = new QWidget();
        carbonation->setObjectName(QStringLiteral("carbonation"));
        gridLayout_17 = new QGridLayout(carbonation);
        gridLayout_17->setSpacing(6);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        carbBatch = new QGroupBox(carbonation);
        carbBatch->setObjectName(QStringLiteral("carbBatch"));
        gridLayout_16 = new QGridLayout(carbBatch);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        batchSizeLabel = new QLabel(carbBatch);
        batchSizeLabel->setObjectName(QStringLiteral("batchSizeLabel"));

        gridLayout_16->addWidget(batchSizeLabel, 0, 0, 1, 1);

        batchSizeValue = new QLabel(carbBatch);
        batchSizeValue->setObjectName(QStringLiteral("batchSizeValue"));

        gridLayout_16->addWidget(batchSizeValue, 0, 1, 1, 1);

        batchSizeUnit = new QLabel(carbBatch);
        batchSizeUnit->setObjectName(QStringLiteral("batchSizeUnit"));

        gridLayout_16->addWidget(batchSizeUnit, 0, 2, 1, 1);

        botTempLabel = new QLabel(carbBatch);
        botTempLabel->setObjectName(QStringLiteral("botTempLabel"));

        gridLayout_16->addWidget(botTempLabel, 1, 0, 1, 1);

        botTempSpin = new QDoubleSpinBox(carbBatch);
        botTempSpin->setObjectName(QStringLiteral("botTempSpin"));

        gridLayout_16->addWidget(botTempSpin, 1, 1, 1, 1);

        botTempUnit = new QLabel(carbBatch);
        botTempUnit->setObjectName(QStringLiteral("botTempUnit"));

        gridLayout_16->addWidget(botTempUnit, 1, 2, 1, 1);

        servTempLabel = new QLabel(carbBatch);
        servTempLabel->setObjectName(QStringLiteral("servTempLabel"));

        gridLayout_16->addWidget(servTempLabel, 2, 0, 1, 1);

        servTempSpin = new QDoubleSpinBox(carbBatch);
        servTempSpin->setObjectName(QStringLiteral("servTempSpin"));

        gridLayout_16->addWidget(servTempSpin, 2, 1, 1, 1);

        servTempUnit = new QLabel(carbBatch);
        servTempUnit->setObjectName(QStringLiteral("servTempUnit"));

        gridLayout_16->addWidget(servTempUnit, 2, 2, 1, 1);

        targetCO2Label = new QLabel(carbBatch);
        targetCO2Label->setObjectName(QStringLiteral("targetCO2Label"));

        gridLayout_16->addWidget(targetCO2Label, 3, 0, 1, 1);

        targetCO2Spin = new QDoubleSpinBox(carbBatch);
        targetCO2Spin->setObjectName(QStringLiteral("targetCO2Spin"));

        gridLayout_16->addWidget(targetCO2Spin, 3, 1, 1, 1);

        styleCO2Label = new QLabel(carbBatch);
        styleCO2Label->setObjectName(QStringLiteral("styleCO2Label"));

        gridLayout_16->addWidget(styleCO2Label, 4, 0, 1, 1);

        dissCO2Label = new QLabel(carbBatch);
        dissCO2Label->setObjectName(QStringLiteral("dissCO2Label"));

        gridLayout_16->addWidget(dissCO2Label, 5, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_16->addItem(horizontalSpacer_8, 3, 2, 1, 1);

        styleCO2Text = new QLabel(carbBatch);
        styleCO2Text->setObjectName(QStringLiteral("styleCO2Text"));

        gridLayout_16->addWidget(styleCO2Text, 4, 1, 1, 1);

        dissCO2Text = new QLabel(carbBatch);
        dissCO2Text->setObjectName(QStringLiteral("dissCO2Text"));

        gridLayout_16->addWidget(dissCO2Text, 5, 1, 1, 1);


        gridLayout_17->addWidget(carbBatch, 0, 0, 1, 1);

        primeFrame = new QFrame(carbonation);
        primeFrame->setObjectName(QStringLiteral("primeFrame"));
        primeFrame->setFrameShape(QFrame::StyledPanel);
        primeFrame->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(primeFrame);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        primeLabel = new QLabel(primeFrame);
        primeLabel->setObjectName(QStringLiteral("primeLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, primeLabel);

        primeSugarCombo = new QComboBox(primeFrame);
        primeSugarCombo->setObjectName(QStringLiteral("primeSugarCombo"));

        formLayout->setWidget(1, QFormLayout::SpanningRole, primeSugarCombo);

        primeValue = new QLCDNumber(primeFrame);
        primeValue->setObjectName(QStringLiteral("primeValue"));
        primeValue->setEnabled(true);
        primeValue->setSegmentStyle(QLCDNumber::Flat);

        formLayout->setWidget(2, QFormLayout::LabelRole, primeValue);

        primeUnit = new QLabel(primeFrame);
        primeUnit->setObjectName(QStringLiteral("primeUnit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, primeUnit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(3, QFormLayout::LabelRole, verticalSpacer);


        gridLayout_17->addWidget(primeFrame, 0, 1, 1, 1);

        forceCarbFrame = new QFrame(carbonation);
        forceCarbFrame->setObjectName(QStringLiteral("forceCarbFrame"));
        forceCarbFrame->setFrameShape(QFrame::StyledPanel);
        forceCarbFrame->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(forceCarbFrame);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        faucHeightLabel = new QLabel(forceCarbFrame);
        faucHeightLabel->setObjectName(QStringLiteral("faucHeightLabel"));

        gridLayout_7->addWidget(faucHeightLabel, 3, 0, 1, 1);

        lineVolUnit = new QLabel(forceCarbFrame);
        lineVolUnit->setObjectName(QStringLiteral("lineVolUnit"));

        gridLayout_7->addWidget(lineVolUnit, 6, 2, 1, 1);

        tubingIDCombo = new QComboBox(forceCarbFrame);
        tubingIDCombo->setObjectName(QStringLiteral("tubingIDCombo"));

        gridLayout_7->addWidget(tubingIDCombo, 2, 1, 1, 2);

        tubingLenUnit = new QLabel(forceCarbFrame);
        tubingLenUnit->setObjectName(QStringLiteral("tubingLenUnit"));

        gridLayout_7->addWidget(tubingLenUnit, 4, 2, 1, 1);

        kegPressureLabel = new QLabel(forceCarbFrame);
        kegPressureLabel->setObjectName(QStringLiteral("kegPressureLabel"));

        gridLayout_7->addWidget(kegPressureLabel, 1, 0, 1, 1);

        tubingLenLabel = new QLabel(forceCarbFrame);
        tubingLenLabel->setObjectName(QStringLiteral("tubingLenLabel"));

        gridLayout_7->addWidget(tubingLenLabel, 4, 0, 1, 1);

        kegPressureUnit = new QLabel(forceCarbFrame);
        kegPressureUnit->setObjectName(QStringLiteral("kegPressureUnit"));

        gridLayout_7->addWidget(kegPressureUnit, 1, 2, 1, 1);

        faucHeightUnit = new QLabel(forceCarbFrame);
        faucHeightUnit->setObjectName(QStringLiteral("faucHeightUnit"));

        gridLayout_7->addWidget(faucHeightUnit, 3, 2, 1, 1);

        faucHeightSpin = new QDoubleSpinBox(forceCarbFrame);
        faucHeightSpin->setObjectName(QStringLiteral("faucHeightSpin"));

        gridLayout_7->addWidget(faucHeightSpin, 3, 1, 1, 1);

        tubingIDLabel = new QLabel(forceCarbFrame);
        tubingIDLabel->setObjectName(QStringLiteral("tubingIDLabel"));

        gridLayout_7->addWidget(tubingIDLabel, 2, 0, 1, 1);

        lineVolLabel = new QLabel(forceCarbFrame);
        lineVolLabel->setObjectName(QStringLiteral("lineVolLabel"));

        gridLayout_7->addWidget(lineVolLabel, 6, 0, 1, 1);

        keyPressureValue = new QLCDNumber(forceCarbFrame);
        keyPressureValue->setObjectName(QStringLiteral("keyPressureValue"));
        keyPressureValue->setSegmentStyle(QLCDNumber::Filled);

        gridLayout_7->addWidget(keyPressureValue, 1, 1, 1, 1);

        forceCarbCheck = new QCheckBox(forceCarbFrame);
        forceCarbCheck->setObjectName(QStringLiteral("forceCarbCheck"));

        gridLayout_7->addWidget(forceCarbCheck, 0, 0, 1, 3);

        tubeLengthNumber = new QLCDNumber(forceCarbFrame);
        tubeLengthNumber->setObjectName(QStringLiteral("tubeLengthNumber"));

        gridLayout_7->addWidget(tubeLengthNumber, 4, 1, 1, 1);

        lineVolNumber = new QLCDNumber(forceCarbFrame);
        lineVolNumber->setObjectName(QStringLiteral("lineVolNumber"));
        lineVolNumber->setEnabled(true);
        lineVolNumber->setSmallDecimalPoint(false);
        lineVolNumber->setSegmentStyle(QLCDNumber::Filled);

        gridLayout_7->addWidget(lineVolNumber, 6, 1, 1, 1);


        gridLayout_17->addWidget(forceCarbFrame, 0, 2, 1, 1);

        recipeTabs->addTab(carbonation, QString());
        water = new QWidget();
        water->setObjectName(QStringLiteral("water"));
        gridLayout_19 = new QGridLayout(water);
        gridLayout_19->setSpacing(6);
        gridLayout_19->setContentsMargins(11, 11, 11, 11);
        gridLayout_19->setObjectName(QStringLiteral("gridLayout_19"));
        waterUseBox = new QGroupBox(water);
        waterUseBox->setObjectName(QStringLiteral("waterUseBox"));
        waterTotalLabel = new QLabel(waterUseBox);
        waterTotalLabel->setObjectName(QStringLiteral("waterTotalLabel"));
        waterTotalLabel->setGeometry(QRect(37, 33, 57, 15));
        waterTotalLCD = new QLCDNumber(waterUseBox);
        waterTotalLCD->setObjectName(QStringLiteral("waterTotalLCD"));
        waterTotalLCD->setGeometry(QRect(80, 30, 64, 23));
        waterTotalLCD->setSegmentStyle(QLCDNumber::Flat);
        waterTotalUnits = new QLabel(waterUseBox);
        waterTotalUnits->setObjectName(QStringLiteral("waterTotalUnits"));
        waterTotalUnits->setGeometry(QRect(157, 34, 57, 15));
        waterMashLabel = new QLabel(waterUseBox);
        waterMashLabel->setObjectName(QStringLiteral("waterMashLabel"));
        waterMashLabel->setGeometry(QRect(37, 63, 57, 15));
        waterMashUnits = new QLabel(waterUseBox);
        waterMashUnits->setObjectName(QStringLiteral("waterMashUnits"));
        waterMashUnits->setGeometry(QRect(157, 64, 57, 15));
        waterMashLCD = new QLCDNumber(waterUseBox);
        waterMashLCD->setObjectName(QStringLiteral("waterMashLCD"));
        waterMashLCD->setGeometry(QRect(80, 60, 64, 23));
        waterMashLCD->setSegmentStyle(QLCDNumber::Flat);
        waterAbsorbedLCD = new QLCDNumber(waterUseBox);
        waterAbsorbedLCD->setObjectName(QStringLiteral("waterAbsorbedLCD"));
        waterAbsorbedLCD->setGeometry(QRect(80, 87, 64, 23));
        waterAbsorbedLCD->setSegmentStyle(QLCDNumber::Flat);
        waterAbsorbedUnits = new QLabel(waterUseBox);
        waterAbsorbedUnits->setObjectName(QStringLiteral("waterAbsorbedUnits"));
        waterAbsorbedUnits->setGeometry(QRect(157, 91, 57, 15));
        waterAbsorbedLabel = new QLabel(waterUseBox);
        waterAbsorbedLabel->setObjectName(QStringLiteral("waterAbsorbedLabel"));
        waterAbsorbedLabel->setGeometry(QRect(10, 90, 57, 15));
        waterSpargeLCD = new QLCDNumber(waterUseBox);
        waterSpargeLCD->setObjectName(QStringLiteral("waterSpargeLCD"));
        waterSpargeLCD->setGeometry(QRect(80, 117, 64, 23));
        waterSpargeLCD->setSegmentStyle(QLCDNumber::Flat);
        waterSpargeUnits = new QLabel(waterUseBox);
        waterSpargeUnits->setObjectName(QStringLiteral("waterSpargeUnits"));
        waterSpargeUnits->setGeometry(QRect(157, 121, 57, 15));
        waterSpargeLabel = new QLabel(waterUseBox);
        waterSpargeLabel->setObjectName(QStringLiteral("waterSpargeLabel"));
        waterSpargeLabel->setGeometry(QRect(26, 120, 57, 15));
        waterColLabel = new QLabel(waterUseBox);
        waterColLabel->setObjectName(QStringLiteral("waterColLabel"));
        waterColLabel->setGeometry(QRect(10, 150, 61, 16));
        waterColSpin = new QDoubleSpinBox(waterUseBox);
        waterColSpin->setObjectName(QStringLiteral("waterColSpin"));
        waterColSpin->setGeometry(QRect(80, 145, 66, 24));
        waterColUnit = new QLabel(waterUseBox);
        waterColUnit->setObjectName(QStringLiteral("waterColUnit"));
        waterColUnit->setGeometry(QRect(157, 150, 57, 15));
        waterPostSpin = new QDoubleSpinBox(waterUseBox);
        waterPostSpin->setObjectName(QStringLiteral("waterPostSpin"));
        waterPostSpin->setGeometry(QRect(80, 175, 66, 24));
        waterPostUnit = new QLabel(waterUseBox);
        waterPostUnit->setObjectName(QStringLiteral("waterPostUnit"));
        waterPostUnit->setGeometry(QRect(157, 180, 57, 15));
        waterPostLabel = new QLabel(waterUseBox);
        waterPostLabel->setObjectName(QStringLiteral("waterPostLabel"));
        waterPostLabel->setGeometry(QRect(10, 180, 61, 16));
        waterFinalSpin = new QDoubleSpinBox(waterUseBox);
        waterFinalSpin->setObjectName(QStringLiteral("waterFinalSpin"));
        waterFinalSpin->setGeometry(QRect(80, 203, 66, 24));
        waterFinalUnit = new QLabel(waterUseBox);
        waterFinalUnit->setObjectName(QStringLiteral("waterFinalUnit"));
        waterFinalUnit->setGeometry(QRect(157, 208, 57, 15));
        waterFinalLabel = new QLabel(waterUseBox);
        waterFinalLabel->setObjectName(QStringLiteral("waterFinalLabel"));
        waterFinalLabel->setGeometry(QRect(11, 208, 61, 16));

        gridLayout_19->addWidget(waterUseBox, 0, 0, 1, 1);

        waterLossesBox = new QGroupBox(water);
        waterLossesBox->setObjectName(QStringLiteral("waterLossesBox"));
        gridLayout_18 = new QGridLayout(waterLossesBox);
        gridLayout_18->setSpacing(6);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        waterChillLabel = new QLabel(waterLossesBox);
        waterChillLabel->setObjectName(QStringLiteral("waterChillLabel"));

        gridLayout_18->addWidget(waterChillLabel, 0, 0, 1, 1);

        waterChillValue = new QLabel(waterLossesBox);
        waterChillValue->setObjectName(QStringLiteral("waterChillValue"));

        gridLayout_18->addWidget(waterChillValue, 0, 1, 1, 1);

        waterChillUnit = new QLabel(waterLossesBox);
        waterChillUnit->setObjectName(QStringLiteral("waterChillUnit"));

        gridLayout_18->addWidget(waterChillUnit, 0, 2, 1, 1);

        waterKetLabel = new QLabel(waterLossesBox);
        waterKetLabel->setObjectName(QStringLiteral("waterKetLabel"));

        gridLayout_18->addWidget(waterKetLabel, 1, 0, 1, 1);

        waterKetSpin = new QDoubleSpinBox(waterLossesBox);
        waterKetSpin->setObjectName(QStringLiteral("waterKetSpin"));

        gridLayout_18->addWidget(waterKetSpin, 1, 1, 1, 1);

        waterKetUnit = new QLabel(waterLossesBox);
        waterKetUnit->setObjectName(QStringLiteral("waterKetUnit"));

        gridLayout_18->addWidget(waterKetUnit, 1, 2, 1, 1);

        waterTrubLabel = new QLabel(waterLossesBox);
        waterTrubLabel->setObjectName(QStringLiteral("waterTrubLabel"));

        gridLayout_18->addWidget(waterTrubLabel, 2, 0, 1, 1);

        waterTrubSpin = new QDoubleSpinBox(waterLossesBox);
        waterTrubSpin->setObjectName(QStringLiteral("waterTrubSpin"));

        gridLayout_18->addWidget(waterTrubSpin, 2, 1, 1, 1);

        waterTrubUnit = new QLabel(waterLossesBox);
        waterTrubUnit->setObjectName(QStringLiteral("waterTrubUnit"));

        gridLayout_18->addWidget(waterTrubUnit, 2, 2, 1, 1);

        waterMiscLabel = new QLabel(waterLossesBox);
        waterMiscLabel->setObjectName(QStringLiteral("waterMiscLabel"));

        gridLayout_18->addWidget(waterMiscLabel, 3, 0, 1, 1);

        waterMiscSpin = new QDoubleSpinBox(waterLossesBox);
        waterMiscSpin->setObjectName(QStringLiteral("waterMiscSpin"));

        gridLayout_18->addWidget(waterMiscSpin, 3, 1, 1, 1);

        waterMiscUnit = new QLabel(waterLossesBox);
        waterMiscUnit->setObjectName(QStringLiteral("waterMiscUnit"));

        gridLayout_18->addWidget(waterMiscUnit, 3, 2, 1, 1);


        gridLayout_19->addWidget(waterLossesBox, 0, 1, 1, 1);

        recipeTabs->addTab(water, QString());
        cost = new QWidget();
        cost->setObjectName(QStringLiteral("cost"));
        recipeCostBox = new QGroupBox(cost);
        recipeCostBox->setObjectName(QStringLiteral("recipeCostBox"));
        recipeCostBox->setGeometry(QRect(30, 10, 149, 189));
        gridLayout_8 = new QGridLayout(recipeCostBox);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        costGrainLabel = new QLabel(recipeCostBox);
        costGrainLabel->setObjectName(QStringLiteral("costGrainLabel"));

        gridLayout_8->addWidget(costGrainLabel, 0, 0, 1, 1);

        costGrainValue = new QLabel(recipeCostBox);
        costGrainValue->setObjectName(QStringLiteral("costGrainValue"));

        gridLayout_8->addWidget(costGrainValue, 0, 1, 1, 1);

        costHopsLabel = new QLabel(recipeCostBox);
        costHopsLabel->setObjectName(QStringLiteral("costHopsLabel"));

        gridLayout_8->addWidget(costHopsLabel, 1, 0, 1, 1);

        costHopsValue = new QLabel(recipeCostBox);
        costHopsValue->setObjectName(QStringLiteral("costHopsValue"));

        gridLayout_8->addWidget(costHopsValue, 1, 1, 1, 1);

        costYeastLabel = new QLabel(recipeCostBox);
        costYeastLabel->setObjectName(QStringLiteral("costYeastLabel"));

        gridLayout_8->addWidget(costYeastLabel, 2, 0, 1, 1);

        costYeastSpin = new QDoubleSpinBox(recipeCostBox);
        costYeastSpin->setObjectName(QStringLiteral("costYeastSpin"));

        gridLayout_8->addWidget(costYeastSpin, 2, 1, 1, 1);

        costMiscLabel = new QLabel(recipeCostBox);
        costMiscLabel->setObjectName(QStringLiteral("costMiscLabel"));

        gridLayout_8->addWidget(costMiscLabel, 3, 0, 1, 1);

        costMiscValue = new QLabel(recipeCostBox);
        costMiscValue->setObjectName(QStringLiteral("costMiscValue"));

        gridLayout_8->addWidget(costMiscValue, 3, 1, 1, 1);

        costOtherLabel = new QLabel(recipeCostBox);
        costOtherLabel->setObjectName(QStringLiteral("costOtherLabel"));

        gridLayout_8->addWidget(costOtherLabel, 4, 0, 1, 1);

        costOtherSpin = new QDoubleSpinBox(recipeCostBox);
        costOtherSpin->setObjectName(QStringLiteral("costOtherSpin"));

        gridLayout_8->addWidget(costOtherSpin, 4, 1, 1, 1);

        line = new QFrame(recipeCostBox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_8->addWidget(line, 5, 0, 1, 2);

        costTotalLabel = new QLabel(recipeCostBox);
        costTotalLabel->setObjectName(QStringLiteral("costTotalLabel"));

        gridLayout_8->addWidget(costTotalLabel, 6, 0, 1, 1);

        costTotalValue = new QLabel(recipeCostBox);
        costTotalValue->setObjectName(QStringLiteral("costTotalValue"));

        gridLayout_8->addWidget(costTotalValue, 6, 1, 1, 1);

        bottleCostBox = new QGroupBox(cost);
        bottleCostBox->setObjectName(QStringLiteral("bottleCostBox"));
        bottleCostBox->setGeometry(QRect(230, 10, 316, 128));
        gridLayout_9 = new QGridLayout(bottleCostBox);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        bottleSizeLabel = new QLabel(bottleCostBox);
        bottleSizeLabel->setObjectName(QStringLiteral("bottleSizeLabel"));

        gridLayout_9->addWidget(bottleSizeLabel, 0, 0, 1, 1);

        finalVolLabel = new QLabel(bottleCostBox);
        finalVolLabel->setObjectName(QStringLiteral("finalVolLabel"));

        gridLayout_9->addWidget(finalVolLabel, 1, 0, 1, 1);

        finalVolValue = new QLabel(bottleCostBox);
        finalVolValue->setObjectName(QStringLiteral("finalVolValue"));

        gridLayout_9->addWidget(finalVolValue, 1, 1, 1, 1);

        bottleCountLabel = new QLabel(bottleCostBox);
        bottleCountLabel->setObjectName(QStringLiteral("bottleCountLabel"));

        gridLayout_9->addWidget(bottleCountLabel, 2, 0, 1, 1);

        bottleCountValue = new QLabel(bottleCostBox);
        bottleCountValue->setObjectName(QStringLiteral("bottleCountValue"));

        gridLayout_9->addWidget(bottleCountValue, 2, 1, 1, 1);

        bottleCostLabel = new QLabel(bottleCostBox);
        bottleCostLabel->setObjectName(QStringLiteral("bottleCostLabel"));

        gridLayout_9->addWidget(bottleCostLabel, 3, 0, 1, 1);

        bottleCostValue = new QLabel(bottleCostBox);
        bottleCostValue->setObjectName(QStringLiteral("bottleCostValue"));

        gridLayout_9->addWidget(bottleCostValue, 3, 1, 1, 1);

        finalVolUnit = new QLabel(bottleCostBox);
        finalVolUnit->setObjectName(QStringLiteral("finalVolUnit"));

        gridLayout_9->addWidget(finalVolUnit, 1, 2, 1, 1);

        bottleSizeUnit = new QComboBox(bottleCostBox);
        bottleSizeUnit->setObjectName(QStringLiteral("bottleSizeUnit"));

        gridLayout_9->addWidget(bottleSizeUnit, 0, 2, 1, 2);

        bottleSizeSpin = new QSpinBox(bottleCostBox);
        bottleSizeSpin->setObjectName(QStringLiteral("bottleSizeSpin"));

        gridLayout_9->addWidget(bottleSizeSpin, 0, 1, 1, 1);

        recipeTabs->addTab(cost, QString());
        settings = new QWidget();
        settings->setObjectName(QStringLiteral("settings"));
        gridLayout_13 = new QGridLayout(settings);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        mashSettingsBox = new QGroupBox(settings);
        mashSettingsBox->setObjectName(QStringLiteral("mashSettingsBox"));
        gridLayout_10 = new QGridLayout(mashSettingsBox);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        thinDecoctLabel = new QLabel(mashSettingsBox);
        thinDecoctLabel->setObjectName(QStringLiteral("thinDecoctLabel"));

        gridLayout_10->addWidget(thinDecoctLabel, 0, 0, 1, 1);

        thinDecoctSpin = new QDoubleSpinBox(mashSettingsBox);
        thinDecoctSpin->setObjectName(QStringLiteral("thinDecoctSpin"));

        gridLayout_10->addWidget(thinDecoctSpin, 0, 1, 1, 1);

        thinDecoctRatio = new QLabel(mashSettingsBox);
        thinDecoctRatio->setObjectName(QStringLiteral("thinDecoctRatio"));

        gridLayout_10->addWidget(thinDecoctRatio, 0, 2, 1, 1);

        thickDecoctLabel = new QLabel(mashSettingsBox);
        thickDecoctLabel->setObjectName(QStringLiteral("thickDecoctLabel"));

        gridLayout_10->addWidget(thickDecoctLabel, 1, 0, 1, 1);

        thickDecoctSpin = new QDoubleSpinBox(mashSettingsBox);
        thickDecoctSpin->setObjectName(QStringLiteral("thickDecoctSpin"));

        gridLayout_10->addWidget(thickDecoctSpin, 1, 1, 1, 1);

        thickDecoctRatio = new QLabel(mashSettingsBox);
        thickDecoctRatio->setObjectName(QStringLiteral("thickDecoctRatio"));

        gridLayout_10->addWidget(thickDecoctRatio, 1, 2, 1, 1);

        mashoutTempLabel = new QLabel(mashSettingsBox);
        mashoutTempLabel->setObjectName(QStringLiteral("mashoutTempLabel"));

        gridLayout_10->addWidget(mashoutTempLabel, 2, 0, 1, 1);

        mashoutTempValue = new QSpinBox(mashSettingsBox);
        mashoutTempValue->setObjectName(QStringLiteral("mashoutTempValue"));
        mashoutTempValue->setMaximum(232);

        gridLayout_10->addWidget(mashoutTempValue, 2, 1, 1, 1);

        mashoutTempUnit = new QLabel(mashSettingsBox);
        mashoutTempUnit->setObjectName(QStringLiteral("mashoutTempUnit"));

        gridLayout_10->addWidget(mashoutTempUnit, 2, 2, 1, 1);

        spargeTempLabel = new QLabel(mashSettingsBox);
        spargeTempLabel->setObjectName(QStringLiteral("spargeTempLabel"));

        gridLayout_10->addWidget(spargeTempLabel, 3, 0, 1, 1);

        spargeTempValue = new QSpinBox(mashSettingsBox);
        spargeTempValue->setObjectName(QStringLiteral("spargeTempValue"));
        spargeTempValue->setMaximum(232);

        gridLayout_10->addWidget(spargeTempValue, 3, 1, 1, 1);

        spargeTempUnit = new QLabel(mashSettingsBox);
        spargeTempUnit->setObjectName(QStringLiteral("spargeTempUnit"));

        gridLayout_10->addWidget(spargeTempUnit, 3, 2, 1, 1);


        gridLayout_13->addWidget(mashSettingsBox, 0, 0, 1, 1);

        otherSettingsBox = new QGroupBox(settings);
        otherSettingsBox->setObjectName(QStringLiteral("otherSettingsBox"));
        gridLayout_11 = new QGridLayout(otherSettingsBox);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        addIBULabel = new QLabel(otherSettingsBox);
        addIBULabel->setObjectName(QStringLiteral("addIBULabel"));

        gridLayout_11->addWidget(addIBULabel, 0, 0, 1, 1);

        addIBUUnit = new QLabel(otherSettingsBox);
        addIBUUnit->setObjectName(QStringLiteral("addIBUUnit"));

        gridLayout_11->addWidget(addIBUUnit, 0, 2, 1, 1);

        addIBUValue = new QDoubleSpinBox(otherSettingsBox);
        addIBUValue->setObjectName(QStringLiteral("addIBUValue"));

        gridLayout_11->addWidget(addIBUValue, 0, 1, 1, 1);


        gridLayout_13->addWidget(otherSettingsBox, 0, 1, 1, 1);

        recipeTabs->addTab(settings, QString());
        splitter_3->addWidget(recipeTabs);
        frame = new QFrame(splitter_3);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_25 = new QGridLayout(frame);
        gridLayout_25->setSpacing(6);
        gridLayout_25->setContentsMargins(11, 11, 11, 11);
        gridLayout_25->setObjectName(QStringLiteral("gridLayout_25"));
        deleteMalt = new QPushButton(frame);
        deleteMalt->setObjectName(QStringLiteral("deleteMalt"));

        gridLayout_25->addWidget(deleteMalt, 1, 1, 1, 1);

        addMalt = new QPushButton(frame);
        addMalt->setObjectName(QStringLiteral("addMalt"));

        gridLayout_25->addWidget(addMalt, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(546, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_25->addItem(horizontalSpacer, 1, 2, 1, 1);

        fermentablesList = new QTableView(frame);
        fermentablesList->setObjectName(QStringLiteral("fermentablesList"));
        fermentablesList->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        fermentablesList->setAlternatingRowColors(true);

        gridLayout_25->addWidget(fermentablesList, 0, 0, 1, 3);

        splitter_3->addWidget(frame);
        frame_2 = new QFrame(splitter_3);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_26 = new QGridLayout(frame_2);
        gridLayout_26->setSpacing(6);
        gridLayout_26->setContentsMargins(11, 11, 11, 11);
        gridLayout_26->setObjectName(QStringLiteral("gridLayout_26"));
        hopsList = new QTableView(frame_2);
        hopsList->setObjectName(QStringLiteral("hopsList"));
        hopsList->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        hopsList->setAlternatingRowColors(true);

        gridLayout_26->addWidget(hopsList, 0, 0, 1, 3);

        addHop = new QPushButton(frame_2);
        addHop->setObjectName(QStringLiteral("addHop"));

        gridLayout_26->addWidget(addHop, 1, 0, 1, 1);

        deleteHop = new QPushButton(frame_2);
        deleteHop->setObjectName(QStringLiteral("deleteHop"));

        gridLayout_26->addWidget(deleteHop, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(548, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_26->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        splitter_3->addWidget(frame_2);

        gridLayout_15->addWidget(splitter_3, 1, 0, 1, 1);

        StrangeBrew->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(StrangeBrew);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 759, 20));
        menuStrangeBrew = new QMenu(menuBar);
        menuStrangeBrew->setObjectName(QStringLiteral("menuStrangeBrew"));
        menuCloud_Recipes = new QMenu(menuStrangeBrew);
        menuCloud_Recipes->setObjectName(QStringLiteral("menuCloud_Recipes"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        StrangeBrew->setMenuBar(menuBar);
        mainToolBar = new QToolBar(StrangeBrew);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setIconSize(QSize(24, 24));
        StrangeBrew->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(StrangeBrew);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        StrangeBrew->setStatusBar(statusBar);

        menuBar->addAction(menuStrangeBrew->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuStrangeBrew->addAction(actionOpen);
        menuStrangeBrew->addAction(menuCloud_Recipes->menuAction());
        menuStrangeBrew->addAction(actionNew);
        menuStrangeBrew->addAction(actionSave);
        menuStrangeBrew->addAction(actionSave_As);
        menuStrangeBrew->addAction(actionExport);
        menuStrangeBrew->addAction(actionCopy_to_Clipboard);
        menuStrangeBrew->addAction(actionPrint);
        menuStrangeBrew->addSeparator();
        menuStrangeBrew->addAction(actionExit);
        menuCloud_Recipes->addAction(actionBrowse);
        menuCloud_Recipes->addAction(actionUpload);
        menuEdit->addAction(actionPreferences);
        menuEdit->addSeparator();
        menuEdit->addAction(actionNew_Fermentable);
        menuEdit->addAction(actionNew_Hop);
        menuEdit->addAction(actionNew_Yeast);
        menuEdit->addAction(actionNew_Misc);
        menuEdit->addAction(actionNew_Prime_Sugar);
        menuEdit->addSeparator();
        menuEdit->addAction(actionPantry);
        menuTools->addAction(actionResize_Convert);
        menuTools->addAction(actionMalt_Percent);
        menuTools->addAction(actionRefractometer);
        menuTools->addAction(actionExtract_Tool);
        menuTools->addAction(actionHydrometer);
        menuTools->addAction(actionConversion);
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionSave_As);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionExport);
        mainToolBar->addAction(actionPrint);
        mainToolBar->addSeparator();

        retranslateUi(StrangeBrew);

        recipeTabs->setCurrentIndex(2);
        mashTools->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StrangeBrew);
    } // setupUi

    void retranslateUi(QMainWindow *StrangeBrew)
    {
        StrangeBrew->setWindowTitle(QApplication::translate("StrangeBrew", "StrangeBrew", 0));
        actionOpen->setText(QApplication::translate("StrangeBrew", "Open", 0));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("StrangeBrew", "Open Recipe File", 0));
#endif // QT_NO_TOOLTIP
        actionOpen->setShortcut(QApplication::translate("StrangeBrew", "Ctrl+O", 0));
        actionNew->setText(QApplication::translate("StrangeBrew", "New", 0));
        actionNew->setShortcut(QApplication::translate("StrangeBrew", "Ctrl+N", 0));
        actionSave->setText(QApplication::translate("StrangeBrew", "Save", 0));
        actionSave->setShortcut(QApplication::translate("StrangeBrew", "Ctrl+S", 0));
        actionSave_As->setText(QApplication::translate("StrangeBrew", "Save As", 0));
        actionExport->setText(QApplication::translate("StrangeBrew", "Export", 0));
        actionPrint->setText(QApplication::translate("StrangeBrew", "Print", 0));
        actionPrint->setShortcut(QApplication::translate("StrangeBrew", "Ctrl+P", 0));
        actionExit->setText(QApplication::translate("StrangeBrew", "Exit", 0));
        actionExit->setShortcut(QApplication::translate("StrangeBrew", "Ctrl+Q", 0));
        actionPreferences->setText(QApplication::translate("StrangeBrew", "Preferences", 0));
        actionCopy_to_Clipboard->setText(QApplication::translate("StrangeBrew", "Copy to Clipboard", 0));
        actionNew_Fermentable->setText(QApplication::translate("StrangeBrew", "New Fermentable", 0));
        actionNew_Hop->setText(QApplication::translate("StrangeBrew", "New Hop", 0));
        actionNew_Yeast->setText(QApplication::translate("StrangeBrew", "New Yeast", 0));
        actionNew_Misc->setText(QApplication::translate("StrangeBrew", "New Misc", 0));
        actionNew_Prime_Sugar->setText(QApplication::translate("StrangeBrew", "New Prime Sugar", 0));
        actionPantry->setText(QApplication::translate("StrangeBrew", "Pantry", 0));
        actionResize_Convert->setText(QApplication::translate("StrangeBrew", "Resize/Convert", 0));
        actionResize_Convert->setShortcut(QApplication::translate("StrangeBrew", "Ctrl+R", 0));
        actionRefractometer->setText(QApplication::translate("StrangeBrew", "Refractometer", 0));
        actionMalt_Percent->setText(QApplication::translate("StrangeBrew", "Malt Percent", 0));
        actionMalt_Percent->setShortcut(QApplication::translate("StrangeBrew", "Ctrl+M", 0));
        actionExtract_Tool->setText(QApplication::translate("StrangeBrew", "Extract Potential", 0));
        actionHydrometer->setText(QApplication::translate("StrangeBrew", "Hydrometer ", 0));
        actionConversion->setText(QApplication::translate("StrangeBrew", "Conversion", 0));
        actionBrowse->setText(QApplication::translate("StrangeBrew", "Browse", 0));
        actionUpload->setText(QApplication::translate("StrangeBrew", "Upload", 0));
        nameEdit->setText(QApplication::translate("StrangeBrew", "Recipe Name", 0));
        brewerLabel->setText(QApplication::translate("StrangeBrew", "Brewer", 0));
        efficiencyLabel->setText(QApplication::translate("StrangeBrew", "Efficiency", 0));
        efficiencySpin->setSuffix(QApplication::translate("StrangeBrew", "%", 0));
        ogLabel->setText(QApplication::translate("StrangeBrew", "OG", 0));
        alcoholLabel->setText(QApplication::translate("StrangeBrew", "Alc", 0));
        alcoholCombo->clear();
        alcoholCombo->insertItems(0, QStringList()
         << QApplication::translate("StrangeBrew", "Volume", 0)
         << QApplication::translate("StrangeBrew", "Weight", 0)
        );
        alcoholCombo->setCurrentText(QApplication::translate("StrangeBrew", "Volume", 0));
        dateLabel->setText(QApplication::translate("StrangeBrew", "Date", 0));
        dateTimeEdit->setDisplayFormat(QApplication::translate("StrangeBrew", "dd/MM/yy", 0));
        attenuationLabel->setText(QApplication::translate("StrangeBrew", "Attenuation", 0));
        attenuationSpin->setSuffix(QApplication::translate("StrangeBrew", "%", 0));
        fgLabel->setText(QApplication::translate("StrangeBrew", "FG", 0));
        ibuLabel->setText(QApplication::translate("StrangeBrew", "IBU", 0));
        ibuCombo->clear();
        ibuCombo->insertItems(0, QStringList()
         << QApplication::translate("StrangeBrew", "Tinseth", 0)
         << QApplication::translate("StrangeBrew", "Ragez", 0)
         << QApplication::translate("StrangeBrew", "Garetz", 0)
        );
        styleCombo->clear();
        styleCombo->insertItems(0, QStringList()
         << QApplication::translate("StrangeBrew", "Style", 0)
        );
        colourLabel->setText(QApplication::translate("StrangeBrew", "Colour", 0));
        colourCombo->clear();
        colourCombo->insertItems(0, QStringList()
         << QApplication::translate("StrangeBrew", "EBC", 0)
         << QApplication::translate("StrangeBrew", "SRM", 0)
        );
        yeastCombo->clear();
        yeastCombo->insertItems(0, QStringList()
         << QApplication::translate("StrangeBrew", "Yeast", 0)
        );
        preBoilLabel->setText(QApplication::translate("StrangeBrew", "Pre-Boil", 0));
        boilTimeLabel->setText(QApplication::translate("StrangeBrew", "Boil Time", 0));
        postBoilLabel->setText(QApplication::translate("StrangeBrew", "Post-Boil", 0));
        evapLabel->setText(QApplication::translate("StrangeBrew", "Evaporation", 0));
        evapType->clear();
        evapType->insertItems(0, QStringList()
         << QApplication::translate("StrangeBrew", "Constant", 0)
         << QApplication::translate("StrangeBrew", "Percent", 0)
        );
        recipeTabs->setTabText(recipeTabs->indexOf(details), QApplication::translate("StrangeBrew", "Details", 0));
        abvStyleLabel->setText(QApplication::translate("StrangeBrew", "ABV", 0));
        ogRecipe->setText(QApplication::translate("StrangeBrew", "OG Recipe", 0));
        abvStyleHigh->setText(QString());
        ibuStyleLabel->setText(QApplication::translate("StrangeBrew", "IBU", 0));
        abvRecipe->setText(QApplication::translate("StrangeBrew", "ABV Recipe", 0));
        ogbuLabel->setText(QApplication::translate("StrangeBrew", "OG:BU Ratio", 0));
        ogbuValue->setText(QApplication::translate("StrangeBrew", "ogbuValue", 0));
        ogStyleLabel->setText(QApplication::translate("StrangeBrew", "OG", 0));
        colourStyleLabel->setText(QApplication::translate("StrangeBrew", "Colour", 0));
#ifndef QT_NO_TOOLTIP
        colourProgress->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        colourProgress->setFormat(QString());
        colourRecipe->setText(QApplication::translate("StrangeBrew", "Colour Recipe", 0));
        ogStyleHigh->setText(QString());
        abvStyleLow->setText(QString());
        matchedLabel->setText(QApplication::translate("StrangeBrew", "Matched Styles", 0));
        ogStyleLow->setText(QString());
        ibuStyleHigh->setText(QString());
        colourStyleLow->setText(QString());
        ibuRecipe->setText(QApplication::translate("StrangeBrew", "IBU Recipe", 0));
        colourStyleHigh->setText(QString());
        ibuStyleLow->setText(QString());
        ibuProgress->setFormat(QString());
        abvProgress->setFormat(QString());
        ogProgress->setFormat(QString());
        recipeTabs->setTabText(recipeTabs->indexOf(style), QApplication::translate("StrangeBrew", "Style", 0));
        commentsLabel->setText(QApplication::translate("StrangeBrew", "Comments", 0));
        addMisc->setText(QApplication::translate("StrangeBrew", "+", 0));
        delMisc->setText(QApplication::translate("StrangeBrew", "-", 0));
        recipeTabs->setTabText(recipeTabs->indexOf(misc), QApplication::translate("StrangeBrew", "Misc", 0));
        addNote->setText(QApplication::translate("StrangeBrew", "+", 0));
        delNote->setText(QApplication::translate("StrangeBrew", "-", 0));
        recipeTabs->setTabText(recipeTabs->indexOf(notes), QApplication::translate("StrangeBrew", "Notes", 0));
        enableDilution->setText(QApplication::translate("StrangeBrew", "Dilute Recipe", 0));
        dilutePostBoilLabel->setText(QApplication::translate("StrangeBrew", "Post Boil", 0));
        dilutePostBoilValue->setText(QApplication::translate("StrangeBrew", "volValue", 0));
        recipeTabs->setTabText(recipeTabs->indexOf(dilution), QApplication::translate("StrangeBrew", "Dilution", 0));
        delMashStep->setText(QApplication::translate("StrangeBrew", "-", 0));
        saveMashSteps->setText(QApplication::translate("StrangeBrew", "Save", 0));
        addMashStep->setText(QApplication::translate("StrangeBrew", "+", 0));
        mashProfiles->setText(QApplication::translate("StrangeBrew", "...", 0));
        grainTempUnit->setText(QApplication::translate("StrangeBrew", "F", 0));
        deadSpaceLabel->setText(QApplication::translate("StrangeBrew", "Dead Space", 0));
        tempLossLabel->setText(QApplication::translate("StrangeBrew", "Temp Loss", 0));
        ratioLabel->setText(QApplication::translate("StrangeBrew", "Ratio:", 0));
        tempLossUnit->setText(QApplication::translate("StrangeBrew", "F", 0));
        boilTempUnit->setText(QApplication::translate("StrangeBrew", "F", 0));
        deadSpaceUnit->setText(QApplication::translate("StrangeBrew", "G (US)", 0));
        grainTempLabel->setText(QApplication::translate("StrangeBrew", "Grain Temp", 0));
        mashVolLabel->setText(QApplication::translate("StrangeBrew", "Volume Units", 0));
        boilTempLabel->setText(QApplication::translate("StrangeBrew", "Boil Temp", 0));
        mashTempC->setText(QApplication::translate("StrangeBrew", "C", 0));
        mashTempF->setText(QApplication::translate("StrangeBrew", "F", 0));
        mashTools->setItemText(mashTools->indexOf(mashSettings), QApplication::translate("StrangeBrew", "Settings", 0));
        totalTimeLabel->setText(QApplication::translate("StrangeBrew", "Total Time", 0));
        totalTimeValue->setText(QApplication::translate("StrangeBrew", "0", 0));
        totalWeightLabel->setText(QApplication::translate("StrangeBrew", "Total Weight", 0));
        totalWeightValue->setText(QApplication::translate("StrangeBrew", "0", 0));
        totalWeightUnit->setText(QApplication::translate("StrangeBrew", "lbs", 0));
        totaVolLabel->setText(QApplication::translate("StrangeBrew", "Total Volume", 0));
        totalVolValue->setText(QApplication::translate("StrangeBrew", "0", 0));
        totalVolUnit->setText(QApplication::translate("StrangeBrew", "G (US)", 0));
        mashTools->setItemText(mashTools->indexOf(mashTotals), QApplication::translate("StrangeBrew", "Totals", 0));
        recipeTabs->setTabText(recipeTabs->indexOf(mash), QApplication::translate("StrangeBrew", "Mash", 0));
        addFermStep->setText(QApplication::translate("StrangeBrew", "+", 0));
        delFermStep->setText(QApplication::translate("StrangeBrew", "-", 0));
        recipeTabs->setTabText(recipeTabs->indexOf(ferment), QApplication::translate("StrangeBrew", "Ferment", 0));
        carbBatch->setTitle(QApplication::translate("StrangeBrew", "Batch Details", 0));
        batchSizeLabel->setText(QApplication::translate("StrangeBrew", "Batch Size", 0));
        batchSizeValue->setText(QApplication::translate("StrangeBrew", "bSize", 0));
        batchSizeUnit->setText(QApplication::translate("StrangeBrew", "F", 0));
        botTempLabel->setText(QApplication::translate("StrangeBrew", "Bottle Temp", 0));
        botTempUnit->setText(QApplication::translate("StrangeBrew", "F", 0));
        servTempLabel->setText(QApplication::translate("StrangeBrew", "Serving Temp", 0));
        servTempUnit->setText(QApplication::translate("StrangeBrew", "F", 0));
        targetCO2Label->setText(QApplication::translate("StrangeBrew", "Target CO2", 0));
        styleCO2Label->setText(QApplication::translate("StrangeBrew", "Style CO2", 0));
        dissCO2Label->setText(QApplication::translate("StrangeBrew", "Dissovled CO2", 0));
        styleCO2Text->setText(QApplication::translate("StrangeBrew", "TextLabel", 0));
        dissCO2Text->setText(QApplication::translate("StrangeBrew", "TextLabel", 0));
        primeLabel->setText(QApplication::translate("StrangeBrew", "Prime", 0));
        primeUnit->setText(QApplication::translate("StrangeBrew", "primeUnit", 0));
        faucHeightLabel->setText(QApplication::translate("StrangeBrew", "Faucet Height", 0));
        lineVolUnit->setText(QApplication::translate("StrangeBrew", "ml", 0));
        tubingLenUnit->setText(QApplication::translate("StrangeBrew", "ft", 0));
        kegPressureLabel->setText(QApplication::translate("StrangeBrew", "Keg Pressure", 0));
        tubingLenLabel->setText(QApplication::translate("StrangeBrew", "Tubing Length", 0));
        kegPressureUnit->setText(QApplication::translate("StrangeBrew", "PSI", 0));
        faucHeightUnit->setText(QApplication::translate("StrangeBrew", "ft", 0));
        tubingIDLabel->setText(QApplication::translate("StrangeBrew", "Tubing ID", 0));
        lineVolLabel->setText(QApplication::translate("StrangeBrew", "Line Volume", 0));
        forceCarbCheck->setText(QApplication::translate("StrangeBrew", "Force Carbonation", 0));
        recipeTabs->setTabText(recipeTabs->indexOf(carbonation), QApplication::translate("StrangeBrew", "Carbonation", 0));
        waterUseBox->setTitle(QApplication::translate("StrangeBrew", "Water Use", 0));
        waterTotalLabel->setText(QApplication::translate("StrangeBrew", "Total", 0));
        waterTotalUnits->setText(QApplication::translate("StrangeBrew", "totalUnit", 0));
        waterMashLabel->setText(QApplication::translate("StrangeBrew", "Mash", 0));
        waterMashUnits->setText(QApplication::translate("StrangeBrew", "mashUnit", 0));
        waterAbsorbedUnits->setText(QApplication::translate("StrangeBrew", "mashUnit", 0));
        waterAbsorbedLabel->setText(QApplication::translate("StrangeBrew", "Absorbed", 0));
        waterSpargeUnits->setText(QApplication::translate("StrangeBrew", "mashUnit", 0));
        waterSpargeLabel->setText(QApplication::translate("StrangeBrew", "Sparge", 0));
        waterColLabel->setText(QApplication::translate("StrangeBrew", "To Collect", 0));
        waterColUnit->setText(QApplication::translate("StrangeBrew", "mashUnit", 0));
        waterPostUnit->setText(QApplication::translate("StrangeBrew", "mashUnit", 0));
        waterPostLabel->setText(QApplication::translate("StrangeBrew", "Post Boil", 0));
        waterFinalUnit->setText(QApplication::translate("StrangeBrew", "mashUnit", 0));
        waterFinalLabel->setText(QApplication::translate("StrangeBrew", "Final Vol", 0));
        waterLossesBox->setTitle(QApplication::translate("StrangeBrew", "Losses", 0));
        waterChillLabel->setText(QApplication::translate("StrangeBrew", "Chill Shrinkage", 0));
        waterChillValue->setText(QApplication::translate("StrangeBrew", "TextLabel", 0));
        waterChillUnit->setText(QApplication::translate("StrangeBrew", "Chill Shrinkage", 0));
        waterKetLabel->setText(QApplication::translate("StrangeBrew", "Kettle Losses", 0));
        waterKetUnit->setText(QApplication::translate("StrangeBrew", "kShrink", 0));
        waterTrubLabel->setText(QApplication::translate("StrangeBrew", "Trub Losses", 0));
        waterTrubUnit->setText(QApplication::translate("StrangeBrew", "tShrink", 0));
        waterMiscLabel->setText(QApplication::translate("StrangeBrew", "Misc Losses", 0));
        waterMiscUnit->setText(QApplication::translate("StrangeBrew", "mShrink", 0));
        recipeTabs->setTabText(recipeTabs->indexOf(water), QApplication::translate("StrangeBrew", "Water", 0));
        recipeCostBox->setTitle(QApplication::translate("StrangeBrew", "Recipe Cost", 0));
        costGrainLabel->setText(QApplication::translate("StrangeBrew", "Grains", 0));
        costGrainValue->setText(QApplication::translate("StrangeBrew", "gCost", 0));
        costHopsLabel->setText(QApplication::translate("StrangeBrew", "Hops", 0));
        costHopsValue->setText(QApplication::translate("StrangeBrew", "hCost", 0));
        costYeastLabel->setText(QApplication::translate("StrangeBrew", "Yeast", 0));
        costMiscLabel->setText(QApplication::translate("StrangeBrew", "Misc Ing.", 0));
        costMiscValue->setText(QApplication::translate("StrangeBrew", "mCost", 0));
        costOtherLabel->setText(QApplication::translate("StrangeBrew", "Other", 0));
        costTotalLabel->setText(QApplication::translate("StrangeBrew", "Total", 0));
        costTotalValue->setText(QApplication::translate("StrangeBrew", "mCost", 0));
        bottleCostBox->setTitle(QApplication::translate("StrangeBrew", "Bottle Cost", 0));
        bottleSizeLabel->setText(QApplication::translate("StrangeBrew", "Bottle Size", 0));
        finalVolLabel->setText(QApplication::translate("StrangeBrew", "Final Volume", 0));
        finalVolValue->setText(QApplication::translate("StrangeBrew", "volValue", 0));
        bottleCountLabel->setText(QApplication::translate("StrangeBrew", "# of Bottles", 0));
        bottleCountValue->setText(QApplication::translate("StrangeBrew", "bottValue", 0));
        bottleCostLabel->setText(QApplication::translate("StrangeBrew", "Cost", 0));
        bottleCostValue->setText(QApplication::translate("StrangeBrew", "Cost", 0));
        finalVolUnit->setText(QApplication::translate("StrangeBrew", "volUnit", 0));
        recipeTabs->setTabText(recipeTabs->indexOf(cost), QApplication::translate("StrangeBrew", "Cost", 0));
        mashSettingsBox->setTitle(QApplication::translate("StrangeBrew", "Mash Settings", 0));
        thinDecoctLabel->setText(QApplication::translate("StrangeBrew", "Thin Decoction", 0));
        thinDecoctRatio->setText(QApplication::translate("StrangeBrew", "dRatio", 0));
        thickDecoctLabel->setText(QApplication::translate("StrangeBrew", "Thick Decoction", 0));
        thickDecoctRatio->setText(QApplication::translate("StrangeBrew", "dRatio", 0));
        mashoutTempLabel->setText(QApplication::translate("StrangeBrew", "Mashout Temp", 0));
        mashoutTempUnit->setText(QApplication::translate("StrangeBrew", "mTemp", 0));
        spargeTempLabel->setText(QApplication::translate("StrangeBrew", "Sparge Temp", 0));
        spargeTempUnit->setText(QApplication::translate("StrangeBrew", "mTemp", 0));
        otherSettingsBox->setTitle(QApplication::translate("StrangeBrew", "Other", 0));
        addIBULabel->setText(QApplication::translate("StrangeBrew", "Pellet Hops + IBU", 0));
        addIBUUnit->setText(QApplication::translate("StrangeBrew", "%", 0));
        recipeTabs->setTabText(recipeTabs->indexOf(settings), QApplication::translate("StrangeBrew", "Settings", 0));
        deleteMalt->setText(QApplication::translate("StrangeBrew", "-", 0));
        addMalt->setText(QApplication::translate("StrangeBrew", "+", 0));
        addHop->setText(QApplication::translate("StrangeBrew", "+", 0));
        deleteHop->setText(QApplication::translate("StrangeBrew", "-", 0));
        menuStrangeBrew->setTitle(QApplication::translate("StrangeBrew", "StrangeBrew", 0));
        menuCloud_Recipes->setTitle(QApplication::translate("StrangeBrew", "Cloud Recipes", 0));
        menuEdit->setTitle(QApplication::translate("StrangeBrew", "Edit", 0));
        menuTools->setTitle(QApplication::translate("StrangeBrew", "Tools", 0));
    } // retranslateUi

};

namespace Ui {
    class StrangeBrew: public Ui_StrangeBrew {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRANGEBREW_H
