/********************************************************************************
** Form generated from reading UI file 'hydrodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HYDRODIALOG_H
#define UI_HYDRODIALOG_H

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

QT_BEGIN_NAMESPACE

class Ui_HydroDialog
{
public:
    QGridLayout *gridLayout;
    QDoubleSpinBox *tempSpin;
    QDialogButtonBox *buttonBox;
    QLabel *gravLabel;
    QLabel *cTempLabel;
    QDoubleSpinBox *cTempSpin;
    QLabel *tempLabel;
    QDoubleSpinBox *gravSpin;
    QLabel *cGravLabel;
    QLabel *cGravValue;
    QLabel *mTempUnit;
    QLabel *cTempUnit;

    void setupUi(QDialog *HydroDialog)
    {
        if (HydroDialog->objectName().isEmpty())
            HydroDialog->setObjectName(QStringLiteral("HydroDialog"));
        HydroDialog->resize(242, 152);
        QIcon icon;
        icon.addFile(QStringLiteral(":/menu/sb2"), QSize(), QIcon::Normal, QIcon::Off);
        HydroDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(HydroDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tempSpin = new QDoubleSpinBox(HydroDialog);
        tempSpin->setObjectName(QStringLiteral("tempSpin"));
        tempSpin->setValue(15);

        gridLayout->addWidget(tempSpin, 1, 1, 1, 1);

        buttonBox = new QDialogButtonBox(HydroDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 4, 0, 1, 2);

        gravLabel = new QLabel(HydroDialog);
        gravLabel->setObjectName(QStringLiteral("gravLabel"));

        gridLayout->addWidget(gravLabel, 0, 0, 1, 1);

        cTempLabel = new QLabel(HydroDialog);
        cTempLabel->setObjectName(QStringLiteral("cTempLabel"));

        gridLayout->addWidget(cTempLabel, 3, 0, 1, 1);

        cTempSpin = new QDoubleSpinBox(HydroDialog);
        cTempSpin->setObjectName(QStringLiteral("cTempSpin"));
        cTempSpin->setValue(15);

        gridLayout->addWidget(cTempSpin, 3, 1, 1, 1);

        tempLabel = new QLabel(HydroDialog);
        tempLabel->setObjectName(QStringLiteral("tempLabel"));

        gridLayout->addWidget(tempLabel, 1, 0, 1, 1);

        gravSpin = new QDoubleSpinBox(HydroDialog);
        gravSpin->setObjectName(QStringLiteral("gravSpin"));
        gravSpin->setDecimals(3);
        gravSpin->setSingleStep(0.001);
        gravSpin->setValue(1.04);

        gridLayout->addWidget(gravSpin, 0, 1, 1, 1);

        cGravLabel = new QLabel(HydroDialog);
        cGravLabel->setObjectName(QStringLiteral("cGravLabel"));

        gridLayout->addWidget(cGravLabel, 2, 0, 1, 1);

        cGravValue = new QLabel(HydroDialog);
        cGravValue->setObjectName(QStringLiteral("cGravValue"));

        gridLayout->addWidget(cGravValue, 2, 1, 1, 1);

        mTempUnit = new QLabel(HydroDialog);
        mTempUnit->setObjectName(QStringLiteral("mTempUnit"));

        gridLayout->addWidget(mTempUnit, 1, 2, 1, 1);

        cTempUnit = new QLabel(HydroDialog);
        cTempUnit->setObjectName(QStringLiteral("cTempUnit"));

        gridLayout->addWidget(cTempUnit, 3, 2, 1, 1);


        retranslateUi(HydroDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), HydroDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), HydroDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(HydroDialog);
    } // setupUi

    void retranslateUi(QDialog *HydroDialog)
    {
        HydroDialog->setWindowTitle(QApplication::translate("HydroDialog", "Hydrometer Tool", 0));
        gravLabel->setText(QApplication::translate("HydroDialog", "Measured Gravity", 0));
        cTempLabel->setText(QApplication::translate("HydroDialog", "Calibrated Temp", 0));
        tempLabel->setText(QApplication::translate("HydroDialog", "Measured Temp", 0));
        cGravLabel->setText(QApplication::translate("HydroDialog", "Corrected Gravity", 0));
        cGravValue->setText(QApplication::translate("HydroDialog", "TextLabel", 0));
        mTempUnit->setText(QApplication::translate("HydroDialog", "C", 0));
        cTempUnit->setText(QApplication::translate("HydroDialog", "C", 0));
    } // retranslateUi

};

namespace Ui {
    class HydroDialog: public Ui_HydroDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HYDRODIALOG_H
