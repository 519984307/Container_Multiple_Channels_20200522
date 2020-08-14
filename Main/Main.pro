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
    Channel_Data/channel_data_form.cpp \
    Channel_Data/equipment_state_from.cpp \
    Setting/setting_form.cpp \
    Setting/channel_setting_form.cpp \
    Setting/system_setting_form.cpp \
    #mainwindow_original.cpp
    Setting/main_dialog.cpp \
    #Setting/setting_form_original.cpp
    Camera_Test/camera_test_form.cpp \
    MainWindow/mainwindow.cpp \
    Camera_Test/camera_list_form.cpp \
    DataBase/database_form.cpp \
    DataBase/image_dialog.cpp \
    Log/operational_log_form.cpp \
    Log/communication_logs_form.cpp \
    Log/identify_the_log_form.cpp

HEADERS += \
    Channel_Data/channel_data_form.h \
    Channel_Data/equipment_state_from.h \
    MainWindow/Processing/parameter.h \
    Setting/setting_form.h \
    Setting/channel_setting_form.h \
    Setting/system_setting_form.h \
    #mainwindow_original.h
    Setting/main_dialog.h \
    #Setting/setting_form_original.h
    Camera_Test/camera_test_form.h \
    MainWindow/mainwindow.h \
    Camera_Test/camera_list_form.h \
    DataBase/database_form.h \
    DataBase/image_dialog.h \
    Log/operational_log_form.h \
    Log/communication_logs_form.h \
    Log/identify_the_log_form.h

FORMS += \
    Channel_Data/channel_data_form.ui \
    Channel_Data/equipment_state_from.ui \
    Setting/setting_form.ui \
    Setting/channel_setting_form.ui \
    Setting/system_setting_form.ui \
    Setting/main_dialog.ui \
    Camera_Test/camera_test_form.ui \
    MainWindow/mainwindow.ui \
    Camera_Test/camera_list_form.ui \
    DataBase/database_form.ui \
    DataBase/image_dialog.ui \
    Log/operational_log_form.ui \
    Log/communication_logs_form.ui \
    Log/identify_the_log_form.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ico.qrc

MOC_DIR=tmp/moc
RCC_DIR=tmp/rcc
UI_DIR=tmp/ui
OBJECTS_DIR=tmp/obj
