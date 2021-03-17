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
VERSION = 1.1.1.7_2103120132
QMAKE_TARGET_COPYRIGHT = "Copyright 2020 Shen zhen zhong bai yuan"

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
        main.cpp \

HEADERS += \

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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../LogController/release/ -lLogging
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../LogController/debug/ -lLogging
else:unix: LIBS += -L$$OUT_PWD/../LogController/ -lLogging

INCLUDEPATH += $$PWD/../LogController
DEPENDPATH += $$PWD/../LogController
