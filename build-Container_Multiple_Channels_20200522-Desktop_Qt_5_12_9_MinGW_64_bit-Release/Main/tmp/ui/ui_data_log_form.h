/********************************************************************************
** Form generated from reading UI file 'data_log_form.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATA_LOG_FORM_H
#define UI_DATA_LOG_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Data_Log_Form
{
public:
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget;
    QWidget *Log;
    QGridLayout *gridLayout_2;
    QTableWidget *logTableWidget;
    QWidget *Service;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;
    QWidget *Upload;
    QGridLayout *gridLayout_4;
    QTableWidget *upLoadTableWidget;

    void setupUi(QWidget *Data_Log_Form)
    {
        if (Data_Log_Form->objectName().isEmpty())
            Data_Log_Form->setObjectName(QString::fromUtf8("Data_Log_Form"));
        Data_Log_Form->resize(971, 524);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/UI_ICO/ICO/ICO.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Data_Log_Form->setWindowIcon(icon);
        gridLayout_3 = new QGridLayout(Data_Log_Form);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(Data_Log_Form);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        Log = new QWidget();
        Log->setObjectName(QString::fromUtf8("Log"));
        gridLayout_2 = new QGridLayout(Log);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        logTableWidget = new QTableWidget(Log);
        if (logTableWidget->columnCount() < 3)
            logTableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        logTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        logTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        logTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        logTableWidget->setObjectName(QString::fromUtf8("logTableWidget"));
        logTableWidget->setRowCount(0);
        logTableWidget->horizontalHeader()->setDefaultSectionSize(200);
        logTableWidget->horizontalHeader()->setStretchLastSection(true);
        logTableWidget->verticalHeader()->setVisible(false);
        logTableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        logTableWidget->verticalHeader()->setStretchLastSection(false);

        gridLayout_2->addWidget(logTableWidget, 0, 0, 1, 1);

        tabWidget->addTab(Log, QString());
        Service = new QWidget();
        Service->setObjectName(QString::fromUtf8("Service"));
        gridLayout = new QGridLayout(Service);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(Service);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        tableWidget = new QTableWidget(splitter);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMinimumSize(QSize(0, 0));
        tableWidget->setRowCount(0);
        splitter->addWidget(tableWidget);
        tableWidget->horizontalHeader()->setDefaultSectionSize(115);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget_2 = new QTableWidget(splitter);
        if (tableWidget_2->columnCount() < 5)
            tableWidget_2->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setAlternatingRowColors(false);
        tableWidget_2->setRowCount(0);
        splitter->addWidget(tableWidget_2);
        tableWidget_2->horizontalHeader()->setStretchLastSection(true);
        tableWidget_2->verticalHeader()->setVisible(false);
        tableWidget_2->verticalHeader()->setStretchLastSection(true);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        tabWidget->addTab(Service, QString());
        Upload = new QWidget();
        Upload->setObjectName(QString::fromUtf8("Upload"));
        gridLayout_4 = new QGridLayout(Upload);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        upLoadTableWidget = new QTableWidget(Upload);
        if (upLoadTableWidget->columnCount() < 2)
            upLoadTableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        upLoadTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        upLoadTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        upLoadTableWidget->setObjectName(QString::fromUtf8("upLoadTableWidget"));
        upLoadTableWidget->setRowCount(0);
        upLoadTableWidget->horizontalHeader()->setDefaultSectionSize(200);
        upLoadTableWidget->horizontalHeader()->setStretchLastSection(true);
        upLoadTableWidget->verticalHeader()->setVisible(false);
        upLoadTableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        upLoadTableWidget->verticalHeader()->setStretchLastSection(false);

        gridLayout_4->addWidget(upLoadTableWidget, 0, 0, 1, 1);

        tabWidget->addTab(Upload, QString());

        gridLayout_3->addWidget(tabWidget, 0, 0, 1, 1);

        tabWidget->raise();
        splitter->raise();

        retranslateUi(Data_Log_Form);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Data_Log_Form);
    } // setupUi

    void retranslateUi(QWidget *Data_Log_Form)
    {
        Data_Log_Form->setWindowTitle(QApplication::translate("Data_Log_Form", "Log", nullptr));
        QTableWidgetItem *___qtablewidgetitem = logTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Data_Log_Form", "Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = logTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Data_Log_Form", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = logTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Data_Log_Form", "Msg", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Log), QApplication::translate("Data_Log_Form", "Log", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("Data_Log_Form", "Address", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("Data_Log_Form", "Port", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("Data_Log_Form", "Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("Data_Log_Form", "Flow", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("Data_Log_Form", "Address", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("Data_Log_Form", "Port", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QApplication::translate("Data_Log_Form", "Msg", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Service), QApplication::translate("Data_Log_Form", "Service", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = upLoadTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QApplication::translate("Data_Log_Form", "Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = upLoadTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QApplication::translate("Data_Log_Form", "Msg", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Upload), QApplication::translate("Data_Log_Form", "Upload", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Data_Log_Form: public Ui_Data_Log_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATA_LOG_FORM_H
