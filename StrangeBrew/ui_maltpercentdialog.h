/********************************************************************************
** Form generated from reading UI file 'maltpercentdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MALTPERCENTDIALOG_H
#define UI_MALTPERCENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_MaltPercentDialog
{
public:
    QGridLayout *gridLayout_2;
    QTableView *maltTable;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *weightCheck;
    QDoubleSpinBox *weightSpin;
    QComboBox *weightUnitsCombo;
    QRadioButton *ogCheck;
    QDoubleSpinBox *ogSpin;
    QDialogButtonBox *buttonBox;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *MaltPercentDialog)
    {
        if (MaltPercentDialog->objectName().isEmpty())
            MaltPercentDialog->setObjectName(QStringLiteral("MaltPercentDialog"));
        MaltPercentDialog->resize(400, 373);
        gridLayout_2 = new QGridLayout(MaltPercentDialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        maltTable = new QTableView(MaltPercentDialog);
        maltTable->setObjectName(QStringLiteral("maltTable"));

        gridLayout_2->addWidget(maltTable, 0, 0, 1, 2);

        groupBox = new QGroupBox(MaltPercentDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        weightCheck = new QRadioButton(groupBox);
        buttonGroup = new QButtonGroup(MaltPercentDialog);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(weightCheck);
        weightCheck->setObjectName(QStringLiteral("weightCheck"));

        gridLayout->addWidget(weightCheck, 0, 0, 1, 1);

        weightSpin = new QDoubleSpinBox(groupBox);
        weightSpin->setObjectName(QStringLiteral("weightSpin"));

        gridLayout->addWidget(weightSpin, 0, 1, 1, 1);

        weightUnitsCombo = new QComboBox(groupBox);
        weightUnitsCombo->setObjectName(QStringLiteral("weightUnitsCombo"));

        gridLayout->addWidget(weightUnitsCombo, 0, 2, 1, 1);

        ogCheck = new QRadioButton(groupBox);
        buttonGroup->addButton(ogCheck);
        ogCheck->setObjectName(QStringLiteral("ogCheck"));

        gridLayout->addWidget(ogCheck, 1, 0, 1, 1);

        ogSpin = new QDoubleSpinBox(groupBox);
        ogSpin->setObjectName(QStringLiteral("ogSpin"));
        ogSpin->setDecimals(3);
        ogSpin->setMaximum(2);
        ogSpin->setSingleStep(0.001);

        gridLayout->addWidget(ogSpin, 1, 1, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 2, 2);

        buttonBox = new QDialogButtonBox(MaltPercentDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 3, 0, 1, 1);


        retranslateUi(MaltPercentDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MaltPercentDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MaltPercentDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MaltPercentDialog);
    } // setupUi

    void retranslateUi(QDialog *MaltPercentDialog)
    {
        MaltPercentDialog->setWindowTitle(QApplication::translate("MaltPercentDialog", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("MaltPercentDialog", "Target", 0));
        weightCheck->setText(QApplication::translate("MaltPercentDialog", "Weight", 0));
        ogCheck->setText(QApplication::translate("MaltPercentDialog", "OG", 0));
    } // retranslateUi

};

namespace Ui {
    class MaltPercentDialog: public Ui_MaltPercentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MALTPERCENTDIALOG_H
