/********************************************************************************
** Form generated from reading UI file 'newyeast.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWYEAST_H
#define UI_NEWYEAST_H

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

class Ui_NewYeast
{
public:
    QGridLayout *gridLayout;
    QLabel *nameLabel;
    QComboBox *nameEditCombo;
    QLabel *costLabel;
    QDoubleSpinBox *costSpin;
    QPlainTextEdit *descrEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewYeast)
    {
        if (NewYeast->objectName().isEmpty())
            NewYeast->setObjectName(QStringLiteral("NewYeast"));
        NewYeast->resize(400, 300);
        QIcon icon;
        icon.addFile(QStringLiteral(":/menu/sb2"), QSize(), QIcon::Normal, QIcon::Off);
        NewYeast->setWindowIcon(icon);
        gridLayout = new QGridLayout(NewYeast);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        nameLabel = new QLabel(NewYeast);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        nameEditCombo = new QComboBox(NewYeast);
        nameEditCombo->setObjectName(QStringLiteral("nameEditCombo"));
        nameEditCombo->setEditable(true);

        gridLayout->addWidget(nameEditCombo, 0, 1, 1, 2);

        costLabel = new QLabel(NewYeast);
        costLabel->setObjectName(QStringLiteral("costLabel"));

        gridLayout->addWidget(costLabel, 1, 0, 1, 2);

        costSpin = new QDoubleSpinBox(NewYeast);
        costSpin->setObjectName(QStringLiteral("costSpin"));

        gridLayout->addWidget(costSpin, 1, 2, 1, 1);

        descrEdit = new QPlainTextEdit(NewYeast);
        descrEdit->setObjectName(QStringLiteral("descrEdit"));

        gridLayout->addWidget(descrEdit, 2, 0, 1, 3);

        buttonBox = new QDialogButtonBox(NewYeast);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 3);


        retranslateUi(NewYeast);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewYeast, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewYeast, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewYeast);
    } // setupUi

    void retranslateUi(QDialog *NewYeast)
    {
        NewYeast->setWindowTitle(QApplication::translate("NewYeast", "Add/Edit Yeast", 0));
        nameLabel->setText(QApplication::translate("NewYeast", "Name", 0));
        costLabel->setText(QApplication::translate("NewYeast", "Cost", 0));
    } // retranslateUi

};

namespace Ui {
    class NewYeast: public Ui_NewYeast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWYEAST_H
