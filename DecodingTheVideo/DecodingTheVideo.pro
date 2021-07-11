QT -= gui

TEMPLATE = lib
DEFINES += DECODINGTHEVIDEO_LIBRARY

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    decodingthevideo.cpp

HEADERS += \
    DecodingTheVideo_global.h \
    decodingthevideo.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target


unix|win32{
LIBS += -L$$PWD/lib/ -lavcodec -lavfilter -lavformat -lswscale -lavutil -lswresample -lavdevice
}

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
