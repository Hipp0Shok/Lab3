/********************************************************************************
** Form generated from reading UI file 'profitwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFITWINDOW_H
#define UI_PROFITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProfitWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *profitLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ProfitWindow)
    {
        if (ProfitWindow->objectName().isEmpty())
            ProfitWindow->setObjectName(QString::fromUtf8("ProfitWindow"));
        ProfitWindow->resize(153, 111);
        centralwidget = new QWidget(ProfitWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        profitLabel = new QLabel(centralwidget);
        profitLabel->setObjectName(QString::fromUtf8("profitLabel"));
        profitLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(profitLabel);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        ProfitWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ProfitWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 153, 20));
        ProfitWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ProfitWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ProfitWindow->setStatusBar(statusbar);

        retranslateUi(ProfitWindow);

        QMetaObject::connectSlotsByName(ProfitWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ProfitWindow)
    {
        ProfitWindow->setWindowTitle(QApplication::translate("ProfitWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("ProfitWindow", "Bank Profit", nullptr));
        profitLabel->setText(QApplication::translate("ProfitWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProfitWindow: public Ui_ProfitWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFITWINDOW_H
