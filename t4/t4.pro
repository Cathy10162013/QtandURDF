#-------------------------------------------------
#
# Project created by QtCreator 2019-01-06T19:28:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = t4
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    urdfparser/console_bridge/console.cpp \
    urdfparser/src/check_urdf.cpp \
    urdfparser/src/joint.cpp \
    urdfparser/src/link.cpp \
    urdfparser/src/model.cpp \
    urdfparser/src/pose.cpp \
    urdfparser/src/twist.cpp \
    urdfparser/src/urdf_model_state.cpp \
    urdfparser/src/urdf_sensor.cpp \
    urdfparser/src/urdf_to_graphiz.cpp \
    urdfparser/src/world.cpp \
    tinyxml/tinystr.cpp \
    tinyxml/tinyxml.cpp \
    tinyxml/tinyxmlerror.cpp \
    tinyxml/tinyxmlparser.cpp

HEADERS += \
        mainwindow.h \
    urdfparser/console_bridge/console.h \
    urdfparser/include/urdf_exception/exception.h \
    urdfparser/include/urdf_model/color.h \
    urdfparser/include/urdf_model/joint.h \
    urdfparser/include/urdf_model/link.h \
    urdfparser/include/urdf_model/model.h \
    urdfparser/include/urdf_model/pose.h \
    urdfparser/include/urdf_model/twist.h \
    urdfparser/include/urdf_model/types.h \
    urdfparser/include/urdf_model/utils.h \
    urdfparser/include/urdf_model_state/model_state.h \
    urdfparser/include/urdf_model_state/twist.h \
    urdfparser/include/urdf_model_state/types.h \
    urdfparser/include/urdf_sensor/sensor.h \
    urdfparser/include/urdf_sensor/types.h \
    urdfparser/include/urdf_world/types.h \
    urdfparser/include/urdf_world/world.h \
    urdfparser/include/check_urdf.h \
    urdfparser/include/exportdecl.h \
    urdfparser/include/urdf_parser.h \
    urdfparser/include/urdf_to_graphiz.h \
    tinyxml/tinystr.h \
    tinyxml/tinyxml.h

FORMS += \
        mainwindow.ui
