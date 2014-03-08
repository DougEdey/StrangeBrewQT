/********************************************************************************
** Form generated from reading UI file 'conversiontool.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERSIONTOOL_H
#define UI_CONVERSIONTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConversionTool
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;
    QWidget *gravity;
    QGridLayout *gridLayout_3;
    QLabel *platoLabel;
    QDoubleSpinBox *platoSpin;
    QLabel *brixLabel;
    QDoubleSpinBox *brixSpin;
    QLabel *gravLabel;
    QDoubleSpinBox *gravSpin;
    QWidget *volume;
    QGridLayout *gridLayout_5;
    QDoubleSpinBox *gallonUSSpin;
    QLabel *litresLabel;
    QLabel *quartUSLabel;
    QDoubleSpinBox *quartSpin;
    QLabel *pintLabel;
    QDoubleSpinBox *pintUSSpin;
    QDoubleSpinBox *barrelUSSpin;
    QDoubleSpinBox *gallonImpSpin;
    QLabel *gallonsUSLabel;
    QLabel *gallonUSLabel;
    QLabel *barrelUSLabel;
    QDoubleSpinBox *barrelImpSpin;
    QDoubleSpinBox *litersSpin;
    QLabel *barrelImpLabel;
    QWidget *weight;
    QGridLayout *gridLayout_2;
    QLabel *tonneLabel;
    QDoubleSpinBox *tonneSpin;
    QLabel *poundLabel;
    QDoubleSpinBox *kiloSpin;
    QLabel *kiloLabel;
    QDoubleSpinBox *poundSpin;
    QDoubleSpinBox *ounceSpin;
    QLabel *ounceLabel;
    QDoubleSpinBox *gramSpin;
    QLabel *gramLabel;
    QDoubleSpinBox *tonSpin;
    QLabel *tonLabel;
    QWidget *pressure;
    QGridLayout *gridLayout_4;
    QLabel *atmoLabel;
    QDoubleSpinBox *atmoSpin;
    QLabel *psiLabel;
    QLabel *kpLabel;
    QDoubleSpinBox *psiSpin;
    QLabel *barLabel;
    QDoubleSpinBox *barSpin;
    QDoubleSpinBox *kpSpin;
    QWidget *temperature;
    QLabel *cLabel;
    QLabel *fLabel;
    QDoubleSpinBox *celsiusSpin;
    QDoubleSpinBox *fahrenheitSpin;

    void setupUi(QDialog *ConversionTool)
    {
        if (ConversionTool->objectName().isEmpty())
            ConversionTool->setObjectName(QStringLiteral("ConversionTool"));
        ConversionTool->resize(400, 385);
        gridLayout = new QGridLayout(ConversionTool);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonBox = new QDialogButtonBox(ConversionTool);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);

        tabWidget = new QTabWidget(ConversionTool);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        gravity = new QWidget();
        gravity->setObjectName(QStringLiteral("gravity"));
        gridLayout_3 = new QGridLayout(gravity);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        platoLabel = new QLabel(gravity);
        platoLabel->setObjectName(QStringLiteral("platoLabel"));

        gridLayout_3->addWidget(platoLabel, 2, 0, 1, 1);

        platoSpin = new QDoubleSpinBox(gravity);
        platoSpin->setObjectName(QStringLiteral("platoSpin"));

        gridLayout_3->addWidget(platoSpin, 2, 1, 1, 1);

        brixLabel = new QLabel(gravity);
        brixLabel->setObjectName(QStringLiteral("brixLabel"));

        gridLayout_3->addWidget(brixLabel, 3, 0, 1, 1);

        brixSpin = new QDoubleSpinBox(gravity);
        brixSpin->setObjectName(QStringLiteral("brixSpin"));

        gridLayout_3->addWidget(brixSpin, 3, 1, 1, 1);

        gravLabel = new QLabel(gravity);
        gravLabel->setObjectName(QStringLiteral("gravLabel"));

        gridLayout_3->addWidget(gravLabel, 1, 0, 1, 1);

        gravSpin = new QDoubleSpinBox(gravity);
        gravSpin->setObjectName(QStringLiteral("gravSpin"));
        gravSpin->setDecimals(3);
        gravSpin->setSingleStep(0.001);

        gridLayout_3->addWidget(gravSpin, 1, 1, 1, 1);

        tabWidget->addTab(gravity, QString());
        volume = new QWidget();
        volume->setObjectName(QStringLiteral("volume"));
        gridLayout_5 = new QGridLayout(volume);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gallonUSSpin = new QDoubleSpinBox(volume);
        gallonUSSpin->setObjectName(QStringLiteral("gallonUSSpin"));
        gallonUSSpin->setMaximum(1000);

        gridLayout_5->addWidget(gallonUSSpin, 3, 1, 1, 1);

        litresLabel = new QLabel(volume);
        litresLabel->setObjectName(QStringLiteral("litresLabel"));

        gridLayout_5->addWidget(litresLabel, 4, 0, 1, 1);

        quartUSLabel = new QLabel(volume);
        quartUSLabel->setObjectName(QStringLiteral("quartUSLabel"));

        gridLayout_5->addWidget(quartUSLabel, 5, 0, 1, 1);

        quartSpin = new QDoubleSpinBox(volume);
        quartSpin->setObjectName(QStringLiteral("quartSpin"));
        quartSpin->setSingleStep(1000);

        gridLayout_5->addWidget(quartSpin, 5, 1, 1, 1);

        pintLabel = new QLabel(volume);
        pintLabel->setObjectName(QStringLiteral("pintLabel"));

        gridLayout_5->addWidget(pintLabel, 6, 0, 1, 1);

        pintUSSpin = new QDoubleSpinBox(volume);
        pintUSSpin->setObjectName(QStringLiteral("pintUSSpin"));
        pintUSSpin->setSingleStep(1000);

        gridLayout_5->addWidget(pintUSSpin, 6, 1, 1, 1);

        barrelUSSpin = new QDoubleSpinBox(volume);
        barrelUSSpin->setObjectName(QStringLiteral("barrelUSSpin"));

        gridLayout_5->addWidget(barrelUSSpin, 1, 1, 1, 1);

        gallonImpSpin = new QDoubleSpinBox(volume);
        gallonImpSpin->setObjectName(QStringLiteral("gallonImpSpin"));
        gallonImpSpin->setMaximum(1000);

        gridLayout_5->addWidget(gallonImpSpin, 2, 1, 1, 1);

        gallonsUSLabel = new QLabel(volume);
        gallonsUSLabel->setObjectName(QStringLiteral("gallonsUSLabel"));

        gridLayout_5->addWidget(gallonsUSLabel, 3, 0, 1, 1);

        gallonUSLabel = new QLabel(volume);
        gallonUSLabel->setObjectName(QStringLiteral("gallonUSLabel"));

        gridLayout_5->addWidget(gallonUSLabel, 2, 0, 1, 1);

        barrelUSLabel = new QLabel(volume);
        barrelUSLabel->setObjectName(QStringLiteral("barrelUSLabel"));

        gridLayout_5->addWidget(barrelUSLabel, 1, 0, 1, 1);

        barrelImpSpin = new QDoubleSpinBox(volume);
        barrelImpSpin->setObjectName(QStringLiteral("barrelImpSpin"));

        gridLayout_5->addWidget(barrelImpSpin, 0, 1, 1, 1);

        litersSpin = new QDoubleSpinBox(volume);
        litersSpin->setObjectName(QStringLiteral("litersSpin"));
        litersSpin->setMaximum(1000);

        gridLayout_5->addWidget(litersSpin, 4, 1, 1, 1);

        barrelImpLabel = new QLabel(volume);
        barrelImpLabel->setObjectName(QStringLiteral("barrelImpLabel"));

        gridLayout_5->addWidget(barrelImpLabel, 0, 0, 1, 1);

        tabWidget->addTab(volume, QString());
        weight = new QWidget();
        weight->setObjectName(QStringLiteral("weight"));
        gridLayout_2 = new QGridLayout(weight);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tonneLabel = new QLabel(weight);
        tonneLabel->setObjectName(QStringLiteral("tonneLabel"));

        gridLayout_2->addWidget(tonneLabel, 0, 0, 1, 1);

        tonneSpin = new QDoubleSpinBox(weight);
        tonneSpin->setObjectName(QStringLiteral("tonneSpin"));

        gridLayout_2->addWidget(tonneSpin, 0, 1, 1, 1);

        poundLabel = new QLabel(weight);
        poundLabel->setObjectName(QStringLiteral("poundLabel"));

        gridLayout_2->addWidget(poundLabel, 7, 0, 1, 1);

        kiloSpin = new QDoubleSpinBox(weight);
        kiloSpin->setObjectName(QStringLiteral("kiloSpin"));

        gridLayout_2->addWidget(kiloSpin, 5, 1, 1, 1);

        kiloLabel = new QLabel(weight);
        kiloLabel->setObjectName(QStringLiteral("kiloLabel"));

        gridLayout_2->addWidget(kiloLabel, 5, 0, 1, 1);

        poundSpin = new QDoubleSpinBox(weight);
        poundSpin->setObjectName(QStringLiteral("poundSpin"));
        poundSpin->setMaximum(1e+08);

        gridLayout_2->addWidget(poundSpin, 7, 1, 1, 1);

        ounceSpin = new QDoubleSpinBox(weight);
        ounceSpin->setObjectName(QStringLiteral("ounceSpin"));
        ounceSpin->setMaximum(1e+08);

        gridLayout_2->addWidget(ounceSpin, 8, 1, 1, 1);

        ounceLabel = new QLabel(weight);
        ounceLabel->setObjectName(QStringLiteral("ounceLabel"));

        gridLayout_2->addWidget(ounceLabel, 8, 0, 1, 1);

        gramSpin = new QDoubleSpinBox(weight);
        gramSpin->setObjectName(QStringLiteral("gramSpin"));
        gramSpin->setMaximum(1e+08);

        gridLayout_2->addWidget(gramSpin, 9, 1, 1, 1);

        gramLabel = new QLabel(weight);
        gramLabel->setObjectName(QStringLiteral("gramLabel"));

        gridLayout_2->addWidget(gramLabel, 9, 0, 1, 1);

        tonSpin = new QDoubleSpinBox(weight);
        tonSpin->setObjectName(QStringLiteral("tonSpin"));

        gridLayout_2->addWidget(tonSpin, 4, 1, 1, 1);

        tonLabel = new QLabel(weight);
        tonLabel->setObjectName(QStringLiteral("tonLabel"));

        gridLayout_2->addWidget(tonLabel, 4, 0, 1, 1);

        tabWidget->addTab(weight, QString());
        pressure = new QWidget();
        pressure->setObjectName(QStringLiteral("pressure"));
        gridLayout_4 = new QGridLayout(pressure);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        atmoLabel = new QLabel(pressure);
        atmoLabel->setObjectName(QStringLiteral("atmoLabel"));

        gridLayout_4->addWidget(atmoLabel, 8, 0, 1, 1);

        atmoSpin = new QDoubleSpinBox(pressure);
        atmoSpin->setObjectName(QStringLiteral("atmoSpin"));

        gridLayout_4->addWidget(atmoSpin, 8, 1, 1, 1);

        psiLabel = new QLabel(pressure);
        psiLabel->setObjectName(QStringLiteral("psiLabel"));

        gridLayout_4->addWidget(psiLabel, 0, 0, 1, 1);

        kpLabel = new QLabel(pressure);
        kpLabel->setObjectName(QStringLiteral("kpLabel"));

        gridLayout_4->addWidget(kpLabel, 2, 0, 1, 1);

        psiSpin = new QDoubleSpinBox(pressure);
        psiSpin->setObjectName(QStringLiteral("psiSpin"));

        gridLayout_4->addWidget(psiSpin, 0, 1, 1, 1);

        barLabel = new QLabel(pressure);
        barLabel->setObjectName(QStringLiteral("barLabel"));

        gridLayout_4->addWidget(barLabel, 5, 0, 1, 1);

        barSpin = new QDoubleSpinBox(pressure);
        barSpin->setObjectName(QStringLiteral("barSpin"));

        gridLayout_4->addWidget(barSpin, 5, 1, 1, 1);

        kpSpin = new QDoubleSpinBox(pressure);
        kpSpin->setObjectName(QStringLiteral("kpSpin"));

        gridLayout_4->addWidget(kpSpin, 2, 1, 1, 1);

        tabWidget->addTab(pressure, QString());
        temperature = new QWidget();
        temperature->setObjectName(QStringLiteral("temperature"));
        cLabel = new QLabel(temperature);
        cLabel->setObjectName(QStringLiteral("cLabel"));
        cLabel->setGeometry(QRect(60, 70, 57, 15));
        fLabel = new QLabel(temperature);
        fLabel->setObjectName(QStringLiteral("fLabel"));
        fLabel->setGeometry(QRect(60, 100, 57, 15));
        celsiusSpin = new QDoubleSpinBox(temperature);
        celsiusSpin->setObjectName(QStringLiteral("celsiusSpin"));
        celsiusSpin->setGeometry(QRect(150, 60, 66, 24));
        fahrenheitSpin = new QDoubleSpinBox(temperature);
        fahrenheitSpin->setObjectName(QStringLiteral("fahrenheitSpin"));
        fahrenheitSpin->setGeometry(QRect(150, 90, 66, 24));
        tabWidget->addTab(temperature, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);


        retranslateUi(ConversionTool);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConversionTool, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConversionTool, SLOT(reject()));

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(ConversionTool);
    } // setupUi

    void retranslateUi(QDialog *ConversionTool)
    {
        ConversionTool->setWindowTitle(QApplication::translate("ConversionTool", "Dialog", 0));
        platoLabel->setText(QApplication::translate("ConversionTool", "Plato", 0));
        brixLabel->setText(QApplication::translate("ConversionTool", "Brix", 0));
        gravLabel->setText(QApplication::translate("ConversionTool", "Specific Gravity", 0));
        tabWidget->setTabText(tabWidget->indexOf(gravity), QApplication::translate("ConversionTool", "Gravity", 0));
        litresLabel->setText(QApplication::translate("ConversionTool", "Litres", 0));
        quartUSLabel->setText(QApplication::translate("ConversionTool", "Quart US", 0));
        pintLabel->setText(QApplication::translate("ConversionTool", "Pint US", 0));
        gallonsUSLabel->setText(QApplication::translate("ConversionTool", "Gallons US", 0));
        gallonUSLabel->setText(QApplication::translate("ConversionTool", "Gallons IMP", 0));
        barrelUSLabel->setText(QApplication::translate("ConversionTool", "Barrel US", 0));
        barrelImpLabel->setText(QApplication::translate("ConversionTool", "Barrel IMP", 0));
        tabWidget->setTabText(tabWidget->indexOf(volume), QApplication::translate("ConversionTool", "Volume", 0));
        tonneLabel->setText(QApplication::translate("ConversionTool", "Tonne SI", 0));
        poundLabel->setText(QApplication::translate("ConversionTool", "Pounds", 0));
        kiloLabel->setText(QApplication::translate("ConversionTool", "Kilograms", 0));
        ounceLabel->setText(QApplication::translate("ConversionTool", "Ounces", 0));
        gramLabel->setText(QApplication::translate("ConversionTool", "Grams", 0));
        tonLabel->setText(QApplication::translate("ConversionTool", "Ton S", 0));
        tabWidget->setTabText(tabWidget->indexOf(weight), QApplication::translate("ConversionTool", "Weight", 0));
        atmoLabel->setText(QApplication::translate("ConversionTool", "Atmospheres", 0));
        psiLabel->setText(QApplication::translate("ConversionTool", "Pounds Per Square Inch", 0));
        kpLabel->setText(QApplication::translate("ConversionTool", "KiloPascals", 0));
        barLabel->setText(QApplication::translate("ConversionTool", "Bar", 0));
        tabWidget->setTabText(tabWidget->indexOf(pressure), QApplication::translate("ConversionTool", "Pressure", 0));
        cLabel->setText(QApplication::translate("ConversionTool", "Celsius", 0));
        fLabel->setText(QApplication::translate("ConversionTool", "Fahrenheit", 0));
        tabWidget->setTabText(tabWidget->indexOf(temperature), QApplication::translate("ConversionTool", "Temperature", 0));
    } // retranslateUi

};

namespace Ui {
    class ConversionTool: public Ui_ConversionTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERSIONTOOL_H
