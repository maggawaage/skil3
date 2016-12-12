#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T10:46:11
#
#-------------------------------------------------

//QT       += core gui
QT       += sql

QT += core
QT -= gui

QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Skil3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dataaccess.cpp \
    personservice.cpp \
    computerservice.cpp \
    database.cpp \
    person.cpp \
    computer.cpp

HEADERS  += mainwindow.h \
    dataaccess.h \
    personservice.h \
    computerservice.h \
    database.h \
    person.h \
    computer.h

FORMS    += mainwindow.ui