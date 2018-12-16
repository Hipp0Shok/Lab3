/********************************************************************************
** Form generated from reading UI file 'betwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BETWINDOW_H
#define UI_BETWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BetWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *nameEdit;
    QLineEdit *betEdit;
    QPushButton *addButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BetWindow)
    {
        if (BetWindow->objectName().isEmpty())
            BetWindow->setObjectName(QString::fromUtf8("BetWindow"));
        BetWindow->resize(220, 162);
        centralwidget = new QWidget(BetWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        nameEdit = new QLineEdit(centralwidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        verticalLayout_2->addWidget(nameEdit);

        betEdit = new QLineEdit(centralwidget);
        betEdit->setObjectName(QString::fromUtf8("betEdit"));

        verticalLayout_2->addWidget(betEdit);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout_3->addWidget(addButton);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        BetWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BetWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 220, 20));
        BetWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(BetWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BetWindow->setStatusBar(statusbar);

        retranslateUi(BetWindow);

        QMetaObject::connectSlotsByName(BetWindow);
    } // setupUi

    void retranslateUi(QMainWindow *BetWindow)
    {
        BetWindow->setWindowTitle(QApplication::translate("BetWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("BetWindow", "Add Bet", nullptr));
        label_2->setText(QApplication::translate("BetWindow", "Student's name", nullptr));
        label_3->setText(QApplication::translate("BetWindow", "Bet", nullptr));
        addButton->setText(QApplication::translate("BetWindow", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BetWindow: public Ui_BetWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BETWINDOW_H
