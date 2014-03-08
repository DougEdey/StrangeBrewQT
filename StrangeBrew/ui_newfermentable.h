/********************************************************************************
** Form generated from reading UI file 'newfermentable.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWFERMENTABLE_H
#define UI_NEWFERMENTABLE_H

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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_NewFermentable
{
public:
    QGridLayout *gridLayout;
    QLabel *nameLabel;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *fermentsCheck;
    QCheckBox *mashedCheck;
    QLabel *lovLabel;
    QDialogButtonBox *buttonBox;
    QLabel *costLabel;
    QPlainTextEdit *descriptionText;
    QCheckBox *steepedCheck;
    QDoubleSpinBox *costSpin;
    QComboBox *stockUnits;
    QSpacerItem *horizontalSpacer;
    QLabel *stockLabel;
    QDoubleSpinBox *stockSpin;
    QSpinBox *lovSpin;
    QDoubleSpinBox *yieldSpin;
    QLabel *yieldLabel;
    QComboBox *nameEdit;

    void setupUi(QDialog *NewFermentable)
    {
        if (NewFermentable->objectName().isEmpty())
            NewFermentable->setObjectName(QStringLiteral("NewFermentable"));
        NewFermentable->resize(611, 300);
        QIcon icon;
        icon.addFile(QStringLiteral(":/menu/sb2"), QSize(), QIcon::Normal, QIcon::Off);
        NewFermentable->setWindowIcon(icon);
        gridLayout = new QGridLayout(NewFermentable);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        nameLabel = new QLabel(NewFermentable);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        fermentsCheck = new QCheckBox(NewFermentable);
        fermentsCheck->setObjectName(QStringLiteral("fermentsCheck"));

        gridLayout->addWidget(fermentsCheck, 4, 8, 1, 2);

        mashedCheck = new QCheckBox(NewFermentable);
        mashedCheck->setObjectName(QStringLiteral("mashedCheck"));

        gridLayout->addWidget(mashedCheck, 2, 8, 1, 2);

        lovLabel = new QLabel(NewFermentable);
        lovLabel->setObjectName(QStringLiteral("lovLabel"));

        gridLayout->addWidget(lovLabel, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(NewFermentable);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 5, 5, 1, 5);

        costLabel = new QLabel(NewFermentable);
        costLabel->setObjectName(QStringLiteral("costLabel"));

        gridLayout->addWidget(costLabel, 1, 3, 1, 1);

        descriptionText = new QPlainTextEdit(NewFermentable);
        descriptionText->setObjectName(QStringLiteral("descriptionText"));

        gridLayout->addWidget(descriptionText, 2, 0, 3, 8);

        steepedCheck = new QCheckBox(NewFermentable);
        steepedCheck->setObjectName(QStringLiteral("steepedCheck"));

        gridLayout->addWidget(steepedCheck, 3, 8, 1, 2);

        costSpin = new QDoubleSpinBox(NewFermentable);
        costSpin->setObjectName(QStringLiteral("costSpin"));

        gridLayout->addWidget(costSpin, 1, 4, 1, 1);

        stockUnits = new QComboBox(NewFermentable);
        stockUnits->setObjectName(QStringLiteral("stockUnits"));

        gridLayout->addWidget(stockUnits, 1, 9, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 5, 1, 1);

        stockLabel = new QLabel(NewFermentable);
        stockLabel->setObjectName(QStringLiteral("stockLabel"));

        gridLayout->addWidget(stockLabel, 1, 6, 1, 1);

        stockSpin = new QDoubleSpinBox(NewFermentable);
        stockSpin->setObjectName(QStringLiteral("stockSpin"));

        gridLayout->addWidget(stockSpin, 1, 7, 1, 2);

        lovSpin = new QSpinBox(NewFermentable);
        lovSpin->setObjectName(QStringLiteral("lovSpin"));

        gridLayout->addWidget(lovSpin, 1, 1, 1, 1);

        yieldSpin = new QDoubleSpinBox(NewFermentable);
        yieldSpin->setObjectName(QStringLiteral("yieldSpin"));
        yieldSpin->setDecimals(3);

        gridLayout->addWidget(yieldSpin, 0, 7, 1, 1);

        yieldLabel = new QLabel(NewFermentable);
        yieldLabel->setObjectName(QStringLiteral("yieldLabel"));

        gridLayout->addWidget(yieldLabel, 0, 6, 1, 1);

        nameEdit = new QComboBox(NewFermentable);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setEditable(true);

        gridLayout->addWidget(nameEdit, 0, 1, 1, 5);


        retranslateUi(NewFermentable);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewFermentable, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewFermentable, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewFermentable);
    } // setupUi

    void retranslateUi(QDialog *NewFermentable)
    {
        NewFermentable->setWindowTitle(QApplication::translate("NewFermentable", "Add/Edit Fermentable", 0));
        nameLabel->setText(QApplication::translate("NewFermentable", "Name", 0));
        fermentsCheck->setText(QApplication::translate("NewFermentable", "Ferments", 0));
        mashedCheck->setText(QApplication::translate("NewFermentable", "Mashed", 0));
        lovLabel->setText(QApplication::translate("NewFermentable", "Lovibond", 0));
        costLabel->setText(QApplication::translate("NewFermentable", "Cost", 0));
        steepedCheck->setText(QApplication::translate("NewFermentable", "Steeped", 0));
        stockLabel->setText(QApplication::translate("NewFermentable", "Stock", 0));
        yieldLabel->setText(QApplication::translate("NewFermentable", "PPPG", 0));
    } // retranslateUi

};

namespace Ui {
    class NewFermentable: public Ui_NewFermentable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWFERMENTABLE_H
