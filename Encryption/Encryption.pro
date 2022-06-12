#-------------------------------------------------
#
# Project created by QtCreator 2020-05-03T11:40:15
#
#-------------------------------------------------

QT       -= gui

CONFIG += plugin

TARGET = Encryption
TEMPLATE = lib

CONFIG += skip_target_version_ext
VERSION =0.0.0.1
QMAKE_TARGET_COPYRIGHT = "Copyright 2020 Shen zhen zhong bai yuan"
QMAKE_TARGET_DESCRIPTION ="Standard-16452187ec9d9da939977d8b352f7c1e"

DEFINES += ENCRYPTION_LIBRARY

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
        encryption.cpp

HEADERS += \
        encryption.h \
        encryption_global.h \  
    encryptioninterface.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

CONFIG(debug, debug|release): {
unix:TARGET=$$join(TARGET,,,_debug)
win32:TARGET=$$join(TARGET,,Cc1_,d)
}
else:CONFIG(release, debug|release): {
unix:TARGET=$$join(TARGET,,,_release)
win32:TARGET=$$join(TARGET,,Cc1_,)
}

DESTDIR+=../MainUI/Plugins
#DESTDIR += ../MainUI/debug/Plugins
