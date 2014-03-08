/********************************************************************************
** Form generated from reading UI file 'remoterecipes.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOTERECIPES_H
#define UI_REMOTERECIPES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_RemoteRecipes
{
public:
    QGridLayout *gridLayout;
    QComboBox *styleCombo;
    QComboBox *brewerCombo;
    QLabel *errorLabel;
    QPushButton *cancelButton;
    QTableView *recipeTable;
    QPushButton *downloadButton;

    void setupUi(QDialog *RemoteRecipes)
    {
        if (RemoteRecipes->objectName().isEmpty())
            RemoteRecipes->setObjectName(QStringLiteral("RemoteRecipes"));
        RemoteRecipes->resize(623, 517);
        gridLayout = new QGridLayout(RemoteRecipes);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        styleCombo = new QComboBox(RemoteRecipes);
        styleCombo->setObjectName(QStringLiteral("styleCombo"));

        gridLayout->addWidget(styleCombo, 0, 3, 1, 1);

        brewerCombo = new QComboBox(RemoteRecipes);
        brewerCombo->setObjectName(QStringLiteral("brewerCombo"));
        brewerCombo->setEditable(true);

        gridLayout->addWidget(brewerCombo, 0, 1, 1, 1);

        errorLabel = new QLabel(RemoteRecipes);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));

        gridLayout->addWidget(errorLabel, 2, 1, 1, 1);

        cancelButton = new QPushButton(RemoteRecipes);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        gridLayout->addWidget(cancelButton, 2, 3, 1, 1);

        recipeTable = new QTableView(RemoteRecipes);
        recipeTable->setObjectName(QStringLiteral("recipeTable"));
        recipeTable->setSelectionMode(QAbstractItemView::SingleSelection);
        recipeTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        recipeTable->horizontalHeader()->setCascadingSectionResizes(true);
        recipeTable->horizontalHeader()->setStretchLastSection(true);
        recipeTable->verticalHeader()->setCascadingSectionResizes(false);
        recipeTable->verticalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(recipeTable, 1, 1, 1, 3);

        downloadButton = new QPushButton(RemoteRecipes);
        downloadButton->setObjectName(QStringLiteral("downloadButton"));

        gridLayout->addWidget(downloadButton, 2, 2, 1, 1);


        retranslateUi(RemoteRecipes);

        QMetaObject::connectSlotsByName(RemoteRecipes);
    } // setupUi

    void retranslateUi(QDialog *RemoteRecipes)
    {
        RemoteRecipes->setWindowTitle(QApplication::translate("RemoteRecipes", "Dialog", 0));
        errorLabel->setText(QString());
        cancelButton->setText(QApplication::translate("RemoteRecipes", "Cancel", 0));
        downloadButton->setText(QApplication::translate("RemoteRecipes", "Download", 0));
    } // retranslateUi

};

namespace Ui {
    class RemoteRecipes: public Ui_RemoteRecipes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOTERECIPES_H
