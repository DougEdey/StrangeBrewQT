/********************************************************************************
** Form generated from reading UI file 'resizerecipe.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESIZERECIPE_H
#define UI_RESIZERECIPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ResizeRecipe
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *resizeGroup;
    QGridLayout *gridLayout_2;
    QLabel *volLabel;
    QDoubleSpinBox *volSizeSpin;
    QComboBox *volUnitsCombo;
    QGroupBox *convertGroup;
    QGridLayout *gridLayout;
    QCheckBox *maltCheck;
    QComboBox *maltUnitCombo;
    QCheckBox *hopCheck;
    QComboBox *hopUnitCombo;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ResizeRecipe)
    {
        if (ResizeRecipe->objectName().isEmpty())
            ResizeRecipe->setObjectName(QStringLiteral("ResizeRecipe"));
        ResizeRecipe->resize(400, 233);
        QIcon icon;
        icon.addFile(QStringLiteral(":/menu/sb2"), QSize(), QIcon::Normal, QIcon::Off);
        ResizeRecipe->setWindowIcon(icon);
        gridLayout_3 = new QGridLayout(ResizeRecipe);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        resizeGroup = new QGroupBox(ResizeRecipe);
        resizeGroup->setObjectName(QStringLiteral("resizeGroup"));
        gridLayout_2 = new QGridLayout(resizeGroup);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        volLabel = new QLabel(resizeGroup);
        volLabel->setObjectName(QStringLiteral("volLabel"));

        gridLayout_2->addWidget(volLabel, 0, 0, 1, 1);

        volSizeSpin = new QDoubleSpinBox(resizeGroup);
        volSizeSpin->setObjectName(QStringLiteral("volSizeSpin"));

        gridLayout_2->addWidget(volSizeSpin, 0, 1, 1, 1);

        volUnitsCombo = new QComboBox(resizeGroup);
        volUnitsCombo->setObjectName(QStringLiteral("volUnitsCombo"));

        gridLayout_2->addWidget(volUnitsCombo, 0, 2, 1, 1);


        gridLayout_3->addWidget(resizeGroup, 0, 0, 1, 1);

        convertGroup = new QGroupBox(ResizeRecipe);
        convertGroup->setObjectName(QStringLiteral("convertGroup"));
        gridLayout = new QGridLayout(convertGroup);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        maltCheck = new QCheckBox(convertGroup);
        maltCheck->setObjectName(QStringLiteral("maltCheck"));

        gridLayout->addWidget(maltCheck, 0, 0, 1, 1);

        maltUnitCombo = new QComboBox(convertGroup);
        maltUnitCombo->setObjectName(QStringLiteral("maltUnitCombo"));

        gridLayout->addWidget(maltUnitCombo, 0, 1, 1, 1);

        hopCheck = new QCheckBox(convertGroup);
        hopCheck->setObjectName(QStringLiteral("hopCheck"));

        gridLayout->addWidget(hopCheck, 1, 0, 1, 1);

        hopUnitCombo = new QComboBox(convertGroup);
        hopUnitCombo->setObjectName(QStringLiteral("hopUnitCombo"));

        gridLayout->addWidget(hopUnitCombo, 1, 1, 1, 1);


        gridLayout_3->addWidget(convertGroup, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(ResizeRecipe);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_3->addWidget(buttonBox, 2, 0, 1, 1);

        resizeGroup->raise();
        buttonBox->raise();
        convertGroup->raise();

        retranslateUi(ResizeRecipe);
        QObject::connect(buttonBox, SIGNAL(accepted()), ResizeRecipe, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ResizeRecipe, SLOT(reject()));

        QMetaObject::connectSlotsByName(ResizeRecipe);
    } // setupUi

    void retranslateUi(QDialog *ResizeRecipe)
    {
        ResizeRecipe->setWindowTitle(QApplication::translate("ResizeRecipe", "Resize/Convert Recipe", 0));
        resizeGroup->setTitle(QApplication::translate("ResizeRecipe", "Resize Recipe", 0));
        volLabel->setText(QApplication::translate("ResizeRecipe", "New Size", 0));
        convertGroup->setTitle(QApplication::translate("ResizeRecipe", "Convert Units", 0));
        maltCheck->setText(QApplication::translate("ResizeRecipe", "Convert Malt", 0));
        hopCheck->setText(QApplication::translate("ResizeRecipe", "Convert Hops", 0));
    } // retranslateUi

};

namespace Ui {
    class ResizeRecipe: public Ui_ResizeRecipe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESIZERECIPE_H
