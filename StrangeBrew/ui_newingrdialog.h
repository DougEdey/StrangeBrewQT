/********************************************************************************
** Form generated from reading UI file 'newingrdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWINGRDIALOG_H
#define UI_NEWINGRDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_NewIngrDialog
{
public:
    QGridLayout *gridLayout;
    QTableView *ingredientsView;
    QDialogButtonBox *miscIngrButtons;

    void setupUi(QDialog *NewIngrDialog)
    {
        if (NewIngrDialog->objectName().isEmpty())
            NewIngrDialog->setObjectName(QStringLiteral("NewIngrDialog"));
        NewIngrDialog->resize(400, 300);
        gridLayout = new QGridLayout(NewIngrDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        ingredientsView = new QTableView(NewIngrDialog);
        ingredientsView->setObjectName(QStringLiteral("ingredientsView"));

        gridLayout->addWidget(ingredientsView, 0, 0, 1, 1);

        miscIngrButtons = new QDialogButtonBox(NewIngrDialog);
        miscIngrButtons->setObjectName(QStringLiteral("miscIngrButtons"));
        miscIngrButtons->setOrientation(Qt::Horizontal);
        miscIngrButtons->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(miscIngrButtons, 1, 0, 1, 1);


        retranslateUi(NewIngrDialog);
        QObject::connect(miscIngrButtons, SIGNAL(accepted()), NewIngrDialog, SLOT(accept()));
        QObject::connect(miscIngrButtons, SIGNAL(rejected()), NewIngrDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewIngrDialog);
    } // setupUi

    void retranslateUi(QDialog *NewIngrDialog)
    {
        NewIngrDialog->setWindowTitle(QApplication::translate("NewIngrDialog", "New Ingredients Detected", 0));
    } // retranslateUi

};

namespace Ui {
    class NewIngrDialog: public Ui_NewIngrDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWINGRDIALOG_H
