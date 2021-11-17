#-------------------------------------------------
#
# Project created by QtCreator 2021-11-04T11:52:30
# 功能：大华相机SDK开发包集成，实现手动抓图，视频预览，过车录像。
# 作者：CC
#
#-------------------------------------------------

QT -= gui

TEMPLATE = lib
DEFINES += MIDDLEWARECLINET_LIBRARY

CONFIG += plugin

TARGET = plug-the_LICNET
CONFIG += skip_target_version_ext
VERSION = 0.0.0.1
QMAKE_TARGET_COPYRIGHT = "Copyright 2021 Shen zhen zhong bai yuan"


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    middlewareclinet.cpp

HEADERS += \
    MiddlewareCLINET_global.h \
    include/avglobal.h \
    include/dhconfigsdk.h \
    include/dhnetsdk.h \
    middlewareclinet.h

TRANSLATIONS += \
    MiddlewareCLINET_zh_SG.ts

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

unix:!macx|win32: LIBS += -L$$PWD/lib/ -ldhnetsdk

INCLUDEPATH += $$PWD/lib
DEPENDPATH += $$PWD/lib

unix:!macx|win32: LIBS += -L$$PWD/lib/ -ldhnetsdk

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

DESTDIR += ../MainUI/Plugins

