#-------------------------------------------------
#
# Project created by QtCreator 2020-05-22T13:43:01
#
#-------------------------------------------------

QT += core gui sql serialport concurrent network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZBYCS
TEMPLATE = app

CONFIG += skip_target_version_ext

QMAKE_TARGET_COPYRIGHT = "Copyright 2021 Shen zhen zhong bai yuan"

VERSION = 1.1.1.14_2107200930_
DEFINES += APP_VERSION=\\\"$$VERSION\\\"
ID = f19d15dec81584b5ce4f9edb0aae1789
DEFINES += DOG_ID=\\\"$$ID\\\"
PROJECT += 烟台-贝奇
DEFINES += APP_PROJECT=\\\"$$PROJECT\\\"
CHANNEL = 2
DEFINES += APP_CHANNEL=\\\"$$CHANNEL\\\"
#If it is a multi-channel version, the software conditions need to be changed:
#1.EncryptionInterface plug-in version
#2.ID       EncryptionInterface.cpp
#3.PROJECT  Main.pro
#4.CHANNEL  LocalPar.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_MESSAGELOGCONTEXT

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    crashstack.cpp \
        main.cpp \

HEADERS += \ \
    crashstack.h

FORMS += \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ico.qrc

DISTFILES += \
    res.rc

RC_FILE = res.rc

MOC_DIR=tmp/moc
RCC_DIR=tmp/rcc
UI_DIR=tmp/ui
OBJECTS_DIR=tmp/obj

TRANSLATIONS = zh_hans.ts

QMAKE_LFLAGS+="-Wl,-rpath=./Library/"

include(CameraTest/CameraTest.pri)
include(ChannelData/ChannelData.pri)
include(DataBase/DataBase.pri)
include(ErrCode/ErrCode.pri)
include(Log/Log.pri)
include(MainWindow/MainWindow.pri)
include(Parameter/Parameter.pri)
include(Processing/Processing.pri)
include(Setting/Setting.pri)
include(About/About.pri)
include(DataProcessing/DataProcessing.pri)

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../LogController/ -lCc1_Logging
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../LogController/ -lCc1_Loggingd

INCLUDEPATH += $$PWD/../LogController
DEPENDPATH += $$PWD/../LogController
