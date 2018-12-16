/********************************************************************************
** Form generated from reading UI file 'addwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDWINDOW_H
#define UI_ADDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addWindow
{
public:
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

    void setupUi(QWidget *addWindow)
    {
        if (addWindow->objectName().isEmpty())
            addWindow->setObjectName(QString::fromUtf8("addWindow"));
        addWindow->resize(245, 121);
        gridLayout = new QGridLayout(addWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(addWindow);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(addWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(addWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        nameEdit = new QLineEdit(addWindow);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        verticalLayout_2->addWidget(nameEdit);

        betEdit = new QLineEdit(addWindow);
        betEdit->setObjectName(QString::fromUtf8("betEdit"));

        verticalLayout_2->addWidget(betEdit);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        addButton = new QPushButton(addWindow);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout_3->addWidget(addButton);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(addWindow);

        QMetaObject::connectSlotsByName(addWindow);
    } // setupUi

    void retranslateUi(QWidget *addWindow)
    {
        addWindow->setWindowTitle(QApplication::translate("addWindow", "Form", nullptr));
        label->setText(QApplication::translate("addWindow", "Add new bet", nullptr));
        label_2->setText(QApplication::translate("addWindow", "Student's name", nullptr));
        label_3->setText(QApplication::translate("addWindow", "Bet", nullptr));
        addButton->setText(QApplication::translate("addWindow", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addWindow: public Ui_addWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWINDOW_H
