/********************************************************************************
** Form generated from reading UI file 'newprimesugar.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPRIMESUGAR_H
#define UI_NEWPRIMESUGAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_NewPrimeSugar
{
public:
    QGridLayout *gridLayout;
    QLabel *nameLabel;
    QPlainTextEdit *descrEdit;
    QDialogButtonBox *buttonBox;
    QDoubleSpinBox *yieldSpin;
    QLabel *yieldLabel;
    QLabel *costLabel;
    QDoubleSpinBox *costSpin;
    QComboBox *costUnitsCombo;
    QComboBox *nameEditCombo;

    void setupUi(QDialog *NewPrimeSugar)
    {
        if (NewPrimeSugar->objectName().isEmpty())
            NewPrimeSugar->setObjectName(QStringLiteral("NewPrimeSugar"));
        NewPrimeSugar->resize(400, 300);
        gridLayout = new QGridLayout(NewPrimeSugar);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        nameLabel = new QLabel(NewPrimeSugar);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        descrEdit = new QPlainTextEdit(NewPrimeSugar);
        descrEdit->setObjectName(QStringLiteral("descrEdit"));

        gridLayout->addWidget(descrEdit, 4, 0, 1, 6);

        buttonBox = new QDialogButtonBox(NewPrimeSugar);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 5, 0, 1, 6);

        yieldSpin = new QDoubleSpinBox(NewPrimeSugar);
        yieldSpin->setObjectName(QStringLiteral("yieldSpin"));

        gridLayout->addWidget(yieldSpin, 3, 1, 1, 1);

        yieldLabel = new QLabel(NewPrimeSugar);
        yieldLabel->setObjectName(QStringLiteral("yieldLabel"));

        gridLayout->addWidget(yieldLabel, 3, 0, 1, 1);

        costLabel = new QLabel(NewPrimeSugar);
        costLabel->setObjectName(QStringLiteral("costLabel"));

        gridLayout->addWidget(costLabel, 3, 2, 1, 1);

        costSpin = new QDoubleSpinBox(NewPrimeSugar);
        costSpin->setObjectName(QStringLiteral("costSpin"));

        gridLayout->addWidget(costSpin, 3, 3, 1, 1);

        costUnitsCombo = new QComboBox(NewPrimeSugar);
        costUnitsCombo->setObjectName(QStringLiteral("costUnitsCombo"));

        gridLayout->addWidget(costUnitsCombo, 3, 4, 1, 1);

        nameEditCombo = new QComboBox(NewPrimeSugar);
        nameEditCombo->setObjectName(QStringLiteral("nameEditCombo"));
        nameEditCombo->setEditable(true);

        gridLayout->addWidget(nameEditCombo, 0, 1, 1, 5);


        retranslateUi(NewPrimeSugar);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewPrimeSugar, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewPrimeSugar, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewPrimeSugar);
    } // setupUi

    void retranslateUi(QDialog *NewPrimeSugar)
    {
        NewPrimeSugar->setWindowTitle(QApplication::translate("NewPrimeSugar", "Dialog", 0));
        nameLabel->setText(QApplication::translate("NewPrimeSugar", "Name", 0));
        yieldLabel->setText(QApplication::translate("NewPrimeSugar", "Yield", 0));
        costLabel->setText(QApplication::translate("NewPrimeSugar", "Cost", 0));
    } // retranslateUi

};

namespace Ui {
    class NewPrimeSugar: public Ui_NewPrimeSugar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPRIMESUGAR_H
