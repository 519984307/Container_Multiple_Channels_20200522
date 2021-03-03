/********************************************************************************
** Form generated from reading UI file 'errcodeform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRCODEFORM_H
#define UI_ERRCODEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ErrCodeForm
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget;

    void setupUi(QWidget *ErrCodeForm)
    {
        if (ErrCodeForm->objectName().isEmpty())
            ErrCodeForm->setObjectName(QString::fromUtf8("ErrCodeForm"));
        ErrCodeForm->resize(768, 576);
        gridLayout = new QGridLayout(ErrCodeForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(ErrCodeForm);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 744, 552));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(scrollAreaWidgetContents);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->verticalHeader()->setVisible(false);

        gridLayout_2->addWidget(tableWidget, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(ErrCodeForm);

        QMetaObject::connectSlotsByName(ErrCodeForm);
    } // setupUi

    void retranslateUi(QWidget *ErrCodeForm)
    {
        ErrCodeForm->setWindowTitle(QApplication::translate("ErrCodeForm", "ErrCode", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ErrCodeForm", "\351\224\231\350\257\257\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ErrCodeForm", "\351\224\231\350\257\257\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ErrCodeForm", "\351\224\231\350\257\257\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ErrCodeForm: public Ui_ErrCodeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRCODEFORM_H
