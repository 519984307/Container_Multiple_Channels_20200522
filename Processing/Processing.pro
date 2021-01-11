QT -= gui
QT += core sql

TEMPLATE = lib
DEFINES += PROCESSING_LIBRARY

CONFIG += c++11

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
    loadinglibaray.cpp

HEADERS += \
    Processing_global.h \
    INTERFACE/ICaptureImages.h \
    interface/IMiddleware.h \
    interface/databaseinsertinterface.h \
    interface/databasereadinterface.h \
    interface/datainterchangeinterface.h \
    interface/infraredlogicinterface.h \
    interface/recognizerinterface.h \
    interface/resultsanalysisinterface.h \
    loadinglibaray.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Parameter/release/ -lParameter
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Parameter/debug/ -lParameter
else:unix: LIBS += -L$$OUT_PWD/../Parameter/ -lParameter

INCLUDEPATH += $$PWD/../Parameter
DEPENDPATH += $$PWD/../Parameter

DESTDIR += ../MainUI/DLL
