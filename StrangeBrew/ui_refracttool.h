/********************************************************************************
** Form generated from reading UI file 'refracttool.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REFRACTTOOL_H
#define UI_REFRACTTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_RefractTool
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *brixFGBox;
    QGridLayout *gridLayout;
    QLabel *brixLabel;
    QDoubleSpinBox *brixSpin;
    QLabel *fgLabel;
    QLabel *fgValue;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *abvFinalValue;
    QDoubleSpinBox *fgABVSpin;
    QLabel *abvFGLabel;
    QLabel *abvLabel_3;
    QDoubleSpinBox *finalBrixSpin;
    QLabel *finalBrixLabel;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *originalLabel;
    QDoubleSpinBox *originalSpin;
    QLabel *finalLabel;
    QDoubleSpinBox *finalSpin;
    QLabel *fgLabel_2;
    QLabel *fgBrixValue;
    QLabel *abvLabel;
    QLabel *abvBrixLabel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *RefractTool)
    {
        if (RefractTool->objectName().isEmpty())
            RefractTool->setObjectName(QStringLiteral("RefractTool"));
        RefractTool->resize(287, 345);
        QIcon icon;
        icon.addFile(QStringLiteral(":/menu/sb2"), QSize(), QIcon::Normal, QIcon::Off);
        RefractTool->setWindowIcon(icon);
        gridLayout_4 = new QGridLayout(RefractTool);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        brixFGBox = new QGroupBox(RefractTool);
        brixFGBox->setObjectName(QStringLiteral("brixFGBox"));
        gridLayout = new QGridLayout(brixFGBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        brixLabel = new QLabel(brixFGBox);
        brixLabel->setObjectName(QStringLiteral("brixLabel"));

        gridLayout->addWidget(brixLabel, 0, 0, 1, 1);

        brixSpin = new QDoubleSpinBox(brixFGBox);
        brixSpin->setObjectName(QStringLiteral("brixSpin"));

        gridLayout->addWidget(brixSpin, 0, 1, 1, 2);

        fgLabel = new QLabel(brixFGBox);
        fgLabel->setObjectName(QStringLiteral("fgLabel"));

        gridLayout->addWidget(fgLabel, 1, 0, 1, 2);

        fgValue = new QLabel(brixFGBox);
        fgValue->setObjectName(QStringLiteral("fgValue"));

        gridLayout->addWidget(fgValue, 1, 2, 1, 1);


        gridLayout_4->addWidget(brixFGBox, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(RefractTool);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        abvFinalValue = new QLabel(groupBox_3);
        abvFinalValue->setObjectName(QStringLiteral("abvFinalValue"));

        gridLayout_3->addWidget(abvFinalValue, 2, 1, 1, 1);

        fgABVSpin = new QDoubleSpinBox(groupBox_3);
        fgABVSpin->setObjectName(QStringLiteral("fgABVSpin"));
        fgABVSpin->setDecimals(3);

        gridLayout_3->addWidget(fgABVSpin, 1, 1, 1, 1);

        abvFGLabel = new QLabel(groupBox_3);
        abvFGLabel->setObjectName(QStringLiteral("abvFGLabel"));

        gridLayout_3->addWidget(abvFGLabel, 1, 0, 1, 1);

        abvLabel_3 = new QLabel(groupBox_3);
        abvLabel_3->setObjectName(QStringLiteral("abvLabel_3"));

        gridLayout_3->addWidget(abvLabel_3, 2, 0, 1, 1);

        finalBrixSpin = new QDoubleSpinBox(groupBox_3);
        finalBrixSpin->setObjectName(QStringLiteral("finalBrixSpin"));

        gridLayout_3->addWidget(finalBrixSpin, 0, 1, 1, 1);

        finalBrixLabel = new QLabel(groupBox_3);
        finalBrixLabel->setObjectName(QStringLiteral("finalBrixLabel"));

        gridLayout_3->addWidget(finalBrixLabel, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 1, 0, 1, 2);

        groupBox_2 = new QGroupBox(RefractTool);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        originalLabel = new QLabel(groupBox_2);
        originalLabel->setObjectName(QStringLiteral("originalLabel"));

        gridLayout_2->addWidget(originalLabel, 0, 0, 1, 1);

        originalSpin = new QDoubleSpinBox(groupBox_2);
        originalSpin->setObjectName(QStringLiteral("originalSpin"));

        gridLayout_2->addWidget(originalSpin, 0, 1, 1, 1);

        finalLabel = new QLabel(groupBox_2);
        finalLabel->setObjectName(QStringLiteral("finalLabel"));

        gridLayout_2->addWidget(finalLabel, 1, 0, 1, 1);

        finalSpin = new QDoubleSpinBox(groupBox_2);
        finalSpin->setObjectName(QStringLiteral("finalSpin"));

        gridLayout_2->addWidget(finalSpin, 1, 1, 1, 1);

        fgLabel_2 = new QLabel(groupBox_2);
        fgLabel_2->setObjectName(QStringLiteral("fgLabel_2"));

        gridLayout_2->addWidget(fgLabel_2, 2, 0, 1, 1);

        fgBrixValue = new QLabel(groupBox_2);
        fgBrixValue->setObjectName(QStringLiteral("fgBrixValue"));

        gridLayout_2->addWidget(fgBrixValue, 2, 1, 1, 1);

        abvLabel = new QLabel(groupBox_2);
        abvLabel->setObjectName(QStringLiteral("abvLabel"));

        gridLayout_2->addWidget(abvLabel, 3, 0, 1, 1);

        abvBrixLabel = new QLabel(groupBox_2);
        abvBrixLabel->setObjectName(QStringLiteral("abvBrixLabel"));

        gridLayout_2->addWidget(abvBrixLabel, 3, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(RefractTool);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        buttonBox->setCenterButtons(true);

        gridLayout_4->addWidget(buttonBox, 2, 0, 1, 2);


        retranslateUi(RefractTool);
        QObject::connect(buttonBox, SIGNAL(accepted()), RefractTool, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RefractTool, SLOT(reject()));

        QMetaObject::connectSlotsByName(RefractTool);
    } // setupUi

    void retranslateUi(QDialog *RefractTool)
    {
        RefractTool->setWindowTitle(QApplication::translate("RefractTool", "Refractometer", 0));
        brixFGBox->setTitle(QApplication::translate("RefractTool", "Brix to FG", 0));
        brixLabel->setText(QApplication::translate("RefractTool", "Brix", 0));
        fgLabel->setText(QApplication::translate("RefractTool", "FG", 0));
        fgValue->setText(QApplication::translate("RefractTool", "1.00", 0));
        groupBox_3->setTitle(QApplication::translate("RefractTool", "ABV from FG and Brix", 0));
        abvFinalValue->setText(QApplication::translate("RefractTool", "TextLabel", 0));
        abvFGLabel->setText(QApplication::translate("RefractTool", "FG", 0));
        abvLabel_3->setText(QApplication::translate("RefractTool", "ABV", 0));
        finalBrixLabel->setText(QApplication::translate("RefractTool", "Final Brix", 0));
        groupBox_2->setTitle(QApplication::translate("RefractTool", "FG from Brix", 0));
        originalLabel->setText(QApplication::translate("RefractTool", "Original", 0));
        finalLabel->setText(QApplication::translate("RefractTool", "Final", 0));
        fgLabel_2->setText(QApplication::translate("RefractTool", "FG", 0));
        fgBrixValue->setText(QApplication::translate("RefractTool", "TextLabel", 0));
        abvLabel->setText(QApplication::translate("RefractTool", "ABV", 0));
        abvBrixLabel->setText(QApplication::translate("RefractTool", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class RefractTool: public Ui_RefractTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REFRACTTOOL_H
