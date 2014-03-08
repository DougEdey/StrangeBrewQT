/********************************************************************************
** Form generated from reading UI file 'extractdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXTRACTDIALOG_H
#define UI_EXTRACTDIALOG_H

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

class Ui_ExtractDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *extractLabel;
    QDoubleSpinBox *extractSpin;
    QLabel *moistureLabel;
    QDoubleSpinBox *moistureSpin;
    QLabel *ppppgLabel;
    QLabel *ppppgValue;
    QLabel *platoLabel;
    QLabel *platoValue;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ExtractDialog)
    {
        if (ExtractDialog->objectName().isEmpty())
            ExtractDialog->setObjectName(QStringLiteral("ExtractDialog"));
        ExtractDialog->resize(246, 171);
        QIcon icon;
        icon.addFile(QStringLiteral(":/menu/sb2"), QSize(), QIcon::Normal, QIcon::Off);
        ExtractDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(ExtractDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        extractLabel = new QLabel(ExtractDialog);
        extractLabel->setObjectName(QStringLiteral("extractLabel"));

        gridLayout->addWidget(extractLabel, 0, 0, 1, 1);

        extractSpin = new QDoubleSpinBox(ExtractDialog);
        extractSpin->setObjectName(QStringLiteral("extractSpin"));

        gridLayout->addWidget(extractSpin, 0, 1, 1, 1);

        moistureLabel = new QLabel(ExtractDialog);
        moistureLabel->setObjectName(QStringLiteral("moistureLabel"));

        gridLayout->addWidget(moistureLabel, 1, 0, 1, 1);

        moistureSpin = new QDoubleSpinBox(ExtractDialog);
        moistureSpin->setObjectName(QStringLiteral("moistureSpin"));

        gridLayout->addWidget(moistureSpin, 1, 1, 1, 1);

        ppppgLabel = new QLabel(ExtractDialog);
        ppppgLabel->setObjectName(QStringLiteral("ppppgLabel"));

        gridLayout->addWidget(ppppgLabel, 2, 0, 1, 1);

        ppppgValue = new QLabel(ExtractDialog);
        ppppgValue->setObjectName(QStringLiteral("ppppgValue"));

        gridLayout->addWidget(ppppgValue, 2, 1, 1, 1);

        platoLabel = new QLabel(ExtractDialog);
        platoLabel->setObjectName(QStringLiteral("platoLabel"));

        gridLayout->addWidget(platoLabel, 3, 0, 1, 1);

        platoValue = new QLabel(ExtractDialog);
        platoValue->setObjectName(QStringLiteral("platoValue"));

        gridLayout->addWidget(platoValue, 3, 1, 1, 1);

        buttonBox = new QDialogButtonBox(ExtractDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        gridLayout->addWidget(buttonBox, 4, 0, 1, 2);


        retranslateUi(ExtractDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ExtractDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ExtractDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ExtractDialog);
    } // setupUi

    void retranslateUi(QDialog *ExtractDialog)
    {
        ExtractDialog->setWindowTitle(QApplication::translate("ExtractDialog", "Extract Potential", 0));
        extractLabel->setText(QApplication::translate("ExtractDialog", "Extract (DBCG)", 0));
        moistureLabel->setText(QApplication::translate("ExtractDialog", "Moisture (%)", 0));
        ppppgLabel->setText(QApplication::translate("ExtractDialog", "PPPPG", 0));
        ppppgValue->setText(QApplication::translate("ExtractDialog", "TextLabel", 0));
        platoLabel->setText(QApplication::translate("ExtractDialog", "Plato", 0));
        platoValue->setText(QApplication::translate("ExtractDialog", "pValue", 0));
    } // retranslateUi

};

namespace Ui {
    class ExtractDialog: public Ui_ExtractDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTRACTDIALOG_H
