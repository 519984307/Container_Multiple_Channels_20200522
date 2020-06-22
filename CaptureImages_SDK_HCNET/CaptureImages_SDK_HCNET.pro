#-------------------------------------------------
#
# Project created by QtCreator 2020-06-22T22:29:40
#
#-------------------------------------------------

QT       -= gui

CONFIG += plugin

TARGET = CaptureImages_SDK_HCNET
TEMPLATE = lib

DEFINES += CAPTUREIMAGES_SDK_HCNET_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        captureimages_sdk_hcnet.cpp

HEADERS += \
        captureimages_sdk_hcnet.h \
        captureimages_sdk_hcnet_global.h \ 
    HCNetSDK.h \
    captureimages_sdk_hcnet_interface.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DESTDIR +=../MainUI/Plugins
