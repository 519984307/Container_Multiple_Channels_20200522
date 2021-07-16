/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionParameter_Settings;
    QAction *actionCamera_Test;
    QAction *actionHistory_Sqlite;
    QAction *actionData_log;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionVersion;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QMenuBar *menuBar;
    QMenu *menuChannel_To_View;
    QMenu *menuDatabase;
    QMenu *menuParameter_Setting;
    QMenu *menuLog;
    QMenu *menuHelp;
    QMenu *menuErrCode;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModal);
        MainWindow->resize(727, 459);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/UI_ICO/ICO/ICO.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(0, 0, 0);\n"
"selection-color: rgb(255, 255, 255);"));
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        actionParameter_Settings = new QAction(MainWindow);
        actionParameter_Settings->setObjectName(QString::fromUtf8("actionParameter_Settings"));
        actionCamera_Test = new QAction(MainWindow);
        actionCamera_Test->setObjectName(QString::fromUtf8("actionCamera_Test"));
        actionHistory_Sqlite = new QAction(MainWindow);
        actionHistory_Sqlite->setObjectName(QString::fromUtf8("actionHistory_Sqlite"));
        actionData_log = new QAction(MainWindow);
        actionData_log->setObjectName(QString::fromUtf8("actionData_log"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionVersion = new QAction(MainWindow);
        actionVersion->setObjectName(QString::fromUtf8("actionVersion"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));

        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 727, 26));
        menuBar->setAutoFillBackground(false);
        menuBar->setStyleSheet(QString::fromUtf8("background-color: rgb(206, 206, 206);\n"
"color: rgb(0, 0, 0);"));
        menuBar->setDefaultUp(false);
        menuChannel_To_View = new QMenu(menuBar);
        menuChannel_To_View->setObjectName(QString::fromUtf8("menuChannel_To_View"));
        menuDatabase = new QMenu(menuBar);
        menuDatabase->setObjectName(QString::fromUtf8("menuDatabase"));
        menuParameter_Setting = new QMenu(menuBar);
        menuParameter_Setting->setObjectName(QString::fromUtf8("menuParameter_Setting"));
        menuLog = new QMenu(menuBar);
        menuLog->setObjectName(QString::fromUtf8("menuLog"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuHelp->setTearOffEnabled(true);
        menuHelp->setSeparatorsCollapsible(false);
        menuErrCode = new QMenu(menuHelp);
        menuErrCode->setObjectName(QString::fromUtf8("menuErrCode"));
        menuErrCode->setTearOffEnabled(false);
        menuErrCode->setToolTipsVisible(false);
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setAutoFillBackground(false);
        mainToolBar->setStyleSheet(QString::fromUtf8("background-color: rgb(206, 206, 206);\n"
"color: rgb(0, 0, 0);"));
        mainToolBar->setMovable(true);
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setStyleSheet(QString::fromUtf8("background-color: rgb(64, 65, 66);\n"
"color: rgb(255, 255, 255);"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuChannel_To_View->menuAction());
        menuBar->addAction(menuDatabase->menuAction());
        menuBar->addAction(menuParameter_Setting->menuAction());
        menuBar->addAction(menuLog->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuDatabase->addAction(actionHistory_Sqlite);
        menuParameter_Setting->addAction(actionParameter_Settings);
        menuParameter_Setting->addAction(actionCamera_Test);
        menuLog->addAction(actionData_log);
        menuHelp->addAction(actionVersion);
        menuHelp->addAction(menuErrCode->menuAction());
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ZBYCS", nullptr));
        actionParameter_Settings->setText(QApplication::translate("MainWindow", "Parameter Settings", nullptr));
#ifndef QT_NO_TOOLTIP
        actionParameter_Settings->setToolTip(QApplication::translate("MainWindow", "System Settings", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionParameter_Settings->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionCamera_Test->setText(QApplication::translate("MainWindow", "Camera Test", nullptr));
#ifndef QT_NO_TOOLTIP
        actionCamera_Test->setToolTip(QApplication::translate("MainWindow", "Camera debugging", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionCamera_Test->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionHistory_Sqlite->setText(QApplication::translate("MainWindow", "History", nullptr));
#ifndef QT_NO_TOOLTIP
        actionHistory_Sqlite->setToolTip(QApplication::translate("MainWindow", "Search history", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionHistory_Sqlite->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_NO_SHORTCUT
        actionData_log->setText(QApplication::translate("MainWindow", "Data log", nullptr));
#ifndef QT_NO_TOOLTIP
        actionData_log->setToolTip(QApplication::translate("MainWindow", "Data exchange log", nullptr));
#endif // QT_NO_TOOLTIP
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "About", nullptr));
        actionVersion->setText(QApplication::translate("MainWindow", "Version", nullptr));
        menuChannel_To_View->setTitle(QApplication::translate("MainWindow", "Channel To View", nullptr));
        menuDatabase->setTitle(QApplication::translate("MainWindow", "&Data", nullptr));
        menuParameter_Setting->setTitle(QApplication::translate("MainWindow", "Setting", nullptr));
        menuLog->setTitle(QApplication::translate("MainWindow", "Log", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
        menuErrCode->setTitle(QApplication::translate("MainWindow", "ErrCode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
