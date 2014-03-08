/********************************************************************************
** Form generated from reading UI file 'newmisc.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWMISC_H
#define UI_NEWMISC_H

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

class Ui_NewMisc
{
public:
    QGridLayout *gridLayout;
    QLabel *nameLabel;
    QLabel *stockLabel;
    QDoubleSpinBox *stockSpin;
    QComboBox *stockUnitsCombo;
    QLabel *costLabel;
    QDoubleSpinBox *costSpin;
    QPlainTextEdit *commentsEdit;
    QDialogButtonBox *buttonBox;
    QComboBox *nameEditCombo;

    void setupUi(QDialog *NewMisc)
    {
        if (NewMisc->objectName().isEmpty())
            NewMisc->setObjectName(QStringLiteral("NewMisc"));
        NewMisc->resize(514, 278);
        gridLayout = new QGridLayout(NewMisc);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        nameLabel = new QLabel(NewMisc);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        stockLabel = new QLabel(NewMisc);
        stockLabel->setObjectName(QStringLiteral("stockLabel"));

        gridLayout->addWidget(stockLabel, 1, 1, 1, 1);

        stockSpin = new QDoubleSpinBox(NewMisc);
        stockSpin->setObjectName(QStringLiteral("stockSpin"));

        gridLayout->addWidget(stockSpin, 1, 2, 1, 1);

        stockUnitsCombo = new QComboBox(NewMisc);
        stockUnitsCombo->setObjectName(QStringLiteral("stockUnitsCombo"));

        gridLayout->addWidget(stockUnitsCombo, 1, 3, 1, 1);

        costLabel = new QLabel(NewMisc);
        costLabel->setObjectName(QStringLiteral("costLabel"));

        gridLayout->addWidget(costLabel, 1, 4, 1, 1);

        costSpin = new QDoubleSpinBox(NewMisc);
        costSpin->setObjectName(QStringLiteral("costSpin"));

        gridLayout->addWidget(costSpin, 1, 5, 1, 1);

        commentsEdit = new QPlainTextEdit(NewMisc);
        commentsEdit->setObjectName(QStringLiteral("commentsEdit"));

        gridLayout->addWidget(commentsEdit, 2, 0, 1, 6);

        buttonBox = new QDialogButtonBox(NewMisc);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 2, 1, 3);

        nameEditCombo = new QComboBox(NewMisc);
        nameEditCombo->setObjectName(QStringLiteral("nameEditCombo"));
        nameEditCombo->setEditable(true);

        gridLayout->addWidget(nameEditCombo, 0, 1, 1, 5);


        retranslateUi(NewMisc);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewMisc, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewMisc, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewMisc);
    } // setupUi

    void retranslateUi(QDialog *NewMisc)
    {
        NewMisc->setWindowTitle(QApplication::translate("NewMisc", "Dialog", 0));
        nameLabel->setText(QApplication::translate("NewMisc", "Name", 0));
        stockLabel->setText(QApplication::translate("NewMisc", "Stock", 0));
        costLabel->setText(QApplication::translate("NewMisc", "Cost", 0));
    } // retranslateUi

};

namespace Ui {
    class NewMisc: public Ui_NewMisc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWMISC_H
