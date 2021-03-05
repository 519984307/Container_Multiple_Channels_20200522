/********************************************************************************
** Form generated from reading UI file 'equipment_state_from.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQUIPMENT_STATE_FROM_H
#define UI_EQUIPMENT_STATE_FROM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Equipment_State_From
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Equipment_State_From)
    {
        if (Equipment_State_From->objectName().isEmpty())
            Equipment_State_From->setObjectName(QString::fromUtf8("Equipment_State_From"));
        Equipment_State_From->resize(986, 433);
        gridLayout = new QGridLayout(Equipment_State_From);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(Equipment_State_From);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 984, 431));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(scrollAreaWidgetContents);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setAlternatingRowColors(false);
        tableWidget->setSortingEnabled(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(50);

        gridLayout_2->addWidget(tableWidget, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(Equipment_State_From);

        QMetaObject::connectSlotsByName(Equipment_State_From);
    } // setupUi

    void retranslateUi(QWidget *Equipment_State_From)
    {
        Equipment_State_From->setWindowTitle(QApplication::translate("Equipment_State_From", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Equipment_State_From: public Ui_Equipment_State_From {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQUIPMENT_STATE_FROM_H
