QT       += core gui
QT       += sql widgets
QT       += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    cmtwidget.cpp \
    diagramitem.cpp \
    diagramscene.cpp \
    fmlwidget.cpp \
    followmotionlaw.cpp \
    jlitem.cpp \
    main.cpp \
    mainwindow.cpp \
    mdichildwindow.cpp \
    planecamitem.cpp \
    planecdjitem.cpp \
    planeitem.cpp \
    rcurve.cpp

HEADERS += \
    cmtwidget.h \
    database.h \
    diagramitem.h \
    diagramscene.h \
    fmlwidget.h \
    followmotionlaw.h \
    jlitem.h \
    mainwindow.h \
    mdichildwindow.h \
    planecamitem.h \
    planecdjitem.h \
    planeitem.h \
    rcurve.h

FORMS += \
    cmtwidget.ui \
    fmlwidget.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

#出了问题就重构main函数
INCLUDEPATH +=\
    eigen3

