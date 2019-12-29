#-------------------------------------------------
#
# Project created by QtCreator 2019-12-29T15:50:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qte2048
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamelogic.cpp

HEADERS  += mainwindow.h \
    gamelogic.h

FORMS    += mainwindow.ui
