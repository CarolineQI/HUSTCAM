#-------------------------------------------------
#
# Project created by QtCreator 2019-05-19T16:16:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CAM
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    cmtwidget.cpp \
    jlitem.cpp \
        mainwindow.cpp \
    diagramscene.cpp \
    diagramitem.cpp \
    mdichildwindow.cpp \
    datadeal.cpp \
    planecamitem.cpp \
    planecdjitem.cpp \
    planeitem.cpp \
    planemainitem.cpp

HEADERS  += mainwindow.h \
    cmtwidget.h \
    diagramscene.h \
    diagramitem.h \
    jlitem.h \
    mdichildwindow.h \
    datadeal.h \
    planecamitem.h \
    planecdjitem.h \
    planeitem.h

FORMS    += mainwindow.ui \
    cmtwidget.ui

RESOURCES += \
    resource.qrc
CONFIG += C++ 11


