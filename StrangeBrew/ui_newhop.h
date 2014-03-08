/********************************************************************************
** Form generated from reading UI file 'newhop.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWHOP_H
#define UI_NEWHOP_H

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
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_NewHop
{
public:
    QGridLayout *gridLayout;
    QComboBox *stockUnitsCombo;
    QDialogButtonBox *buttonBox;
    QTextEdit *descriptionText;
    QDoubleSpinBox *stockSpin;
    QLabel *nameLabel;
    QDoubleSpinBox *alphaSpin;
    QDoubleSpinBox *costSpin;
    QLabel *costLabel;
    QLabel *stockLabel;
    QLabel *alphaLabel;
    QComboBox *nameCombo;

    void setupUi(QDialog *NewHop)
    {
        if (NewHop->objectName().isEmpty())
            NewHop->setObjectName(QStringLiteral("NewHop"));
        NewHop->resize(400, 300);
        QIcon icon;
        icon.addFile(QStringLiteral(":/menu/sb2"), QSize(), QIcon::Normal, QIcon::Off);
        NewHop->setWindowIcon(icon);
        gridLayout = new QGridLayout(NewHop);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stockUnitsCombo = new QComboBox(NewHop);
        stockUnitsCombo->setObjectName(QStringLiteral("stockUnitsCombo"));

        gridLayout->addWidget(stockUnitsCombo, 1, 7, 1, 1);

        buttonBox = new QDialogButtonBox(NewHop);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 8);

        descriptionText = new QTextEdit(NewHop);
        descriptionText->setObjectName(QStringLiteral("descriptionText"));

        gridLayout->addWidget(descriptionText, 2, 0, 1, 8);

        stockSpin = new QDoubleSpinBox(NewHop);
        stockSpin->setObjectName(QStringLiteral("stockSpin"));

        gridLayout->addWidget(stockSpin, 1, 5, 1, 2);

        nameLabel = new QLabel(NewHop);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        alphaSpin = new QDoubleSpinBox(NewHop);
        alphaSpin->setObjectName(QStringLiteral("alphaSpin"));

        gridLayout->addWidget(alphaSpin, 0, 6, 1, 2);

        costSpin = new QDoubleSpinBox(NewHop);
        costSpin->setObjectName(QStringLiteral("costSpin"));

        gridLayout->addWidget(costSpin, 1, 1, 1, 1);

        costLabel = new QLabel(NewHop);
        costLabel->setObjectName(QStringLiteral("costLabel"));

        gridLayout->addWidget(costLabel, 1, 0, 1, 1);

        stockLabel = new QLabel(NewHop);
        stockLabel->setObjectName(QStringLiteral("stockLabel"));

        gridLayout->addWidget(stockLabel, 1, 4, 1, 1);

        alphaLabel = new QLabel(NewHop);
        alphaLabel->setObjectName(QStringLiteral("alphaLabel"));

        gridLayout->addWidget(alphaLabel, 0, 5, 1, 1);

        nameCombo = new QComboBox(NewHop);
        nameCombo->setObjectName(QStringLiteral("nameCombo"));
        nameCombo->setEditable(true);

        gridLayout->addWidget(nameCombo, 0, 1, 1, 3);


        retranslateUi(NewHop);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewHop, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewHop, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewHop);
    } // setupUi

    void retranslateUi(QDialog *NewHop)
    {
        NewHop->setWindowTitle(QApplication::translate("NewHop", "Add/Edit Hop", 0));
        nameLabel->setText(QApplication::translate("NewHop", "Name", 0));
        costLabel->setText(QApplication::translate("NewHop", "Cost", 0));
        stockLabel->setText(QApplication::translate("NewHop", "Stock", 0));
        alphaLabel->setText(QApplication::translate("NewHop", "Alpha", 0));
    } // retranslateUi

};

namespace Ui {
    class NewHop: public Ui_NewHop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWHOP_H
