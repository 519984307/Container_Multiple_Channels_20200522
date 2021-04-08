QT -= gui

TEMPLATE = lib
DEFINES += DATAINTERRABBITMQ_LIBRARY

CONFIG += plugin
TARGET = DataInterMQ

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
    datainterrabbitmq.cpp

HEADERS += \
    DataInterRabbitMQ_global.h \
    datainterchangeinterface.h \
    datainterrabbitmq.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Qamqp/ -lQamqp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Qamqp/ -lQamqpd

INCLUDEPATH += $$PWD/../Qamqp
DEPENDPATH += $$PWD/../Qamqp

DESTDIR+=../MainUI/Plugins