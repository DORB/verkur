#-------------------------------------------------
#
# Project created by QtCreator 2014-11-28T11:41:47
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = verkur
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    person.cpp \
    consoleui.cpp \
    personservice.cpp \
    personrepo.cpp

HEADERS += \
    person.h \
    consoleui.h \
    personservice.h \
    personrepo.h

OTHER_FILES += \
    README.md \
    splash.txt
