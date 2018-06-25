#-------------------------------------------------
#
# Project created by QtCreator 2017-06-01T18:06:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Battelship_v2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cobject.cpp \
    cfield.cpp \
    cmap.cpp \
    cbattelship.cpp \
    cgracz.cpp

HEADERS  += mainwindow.h \
    cobject.h \
    cfield.h \
    cmap.h \
    cbattelship.h \
    cgracz.h

FORMS    += mainwindow.ui

RESOURCES += \
    Grafika/magazyn.qrc

DISTFILES +=
