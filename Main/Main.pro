#-------------------------------------------------
#
# Project created by QtCreator 2020-05-22T13:43:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Main
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    Channel_Data/channel_data_form.cpp \
    Channel_Data/equipment_state_from.cpp \
    Setting/setting_form.cpp \
    Setting/channel_setting_form.cpp \
    Setting/system_setting_form.cpp \
    #mainwindow_original.cpp
    Setting/main_setting_form.cpp

HEADERS += \
        mainwindow.h \
    Channel_Data/channel_data_form.h \
    Channel_Data/equipment_state_from.h \
    Setting/setting_form.h \
    Setting/channel_setting_form.h \
    Setting/system_setting_form.h \
    #mainwindow_original.h
    Setting/main_setting_form.h

FORMS += \
        mainwindow.ui \
    Channel_Data/channel_data_form.ui \
    Channel_Data/equipment_state_from.ui \
    Setting/setting_form.ui \
    Setting/channel_setting_form.ui \
    Setting/system_setting_form.ui \
    Setting/main_setting_form.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ico.qrc
