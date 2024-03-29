QT += gui
QT += concurrent

TEMPLATE = lib
DEFINES += DECODINGVIDEOHCNET_LIBRARY

CONFIG += plugin

TARGET = DecofingVideoHCNET

CONFIG += skip_target_version_ext
VERSION = 1.0.1.1
QMAKE_TARGET_COPYRIGHT = "Copyright 2020 Shen zhen zhong bai yuan"

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
    decodingvideohcnet.cpp

HEADERS += \
    DecodingVideoHCNET_global.h \
    HCNetSDK.h \
    IDecodingVideo.h \
    decodingvideohcnet.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

unix:!macx|win32: LIBS += -L$$PWD/../MiddlewareHCNET/HCNetSDK_WIN/ -lPlayCtrl

INCLUDEPATH += $$PWD/../MiddlewareHCNET/HCNetSDK_WIN
DEPENDPATH += $$PWD/../MiddlewareHCNET/HCNetSDK_WIN

CONFIG(debug, debug|release): {
unix:TARGET=$$join(TARGET,,,_debug)
win32:TARGET=$$join(TARGET,,Cc1_,d)
}
else:CONFIG(release, debug|release): {
unix:TARGET=$$join(TARGET,,,_release)
win32:TARGET=$$join(TARGET,,Cc1_,)
}

DESTDIR += ../MainUI/Plugins
