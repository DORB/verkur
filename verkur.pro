#-------------------------------------------------
#
# Project created by QtCreator 2014-11-28T11:41:47
#
#-------------------------------------------------

QT       += core sql
QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT       -= gui

TARGET = verkur
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    person.cpp \
    consoleui.cpp \
    comparer.cpp \
    computer.cpp \
    database.cpp \
    service.cpp \
    repository.cpp \
    relation.cpp \
    utilities.cpp \
    mainwindow.cpp

HEADERS += \
    person.h \
    consoleui.h \
    comparer.h \
    computer.h \
    database.h \
    service.h \
    repository.h \
    relation.h \
    utilities.h \
    mainwindow.h

OTHER_FILES += \
    README.md \
    splash.txt \
    todo.md

FORMS += \
    mainwindow.ui
