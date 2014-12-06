#-------------------------------------------------
#
# Project created by QtCreator 2014-11-28T11:41:47
#
#-------------------------------------------------

QT       += core sql

QT       -= gui

TARGET = verkur
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    person.cpp \
    consoleui.cpp \
    comparer.cpp \
    computer.cpp \
    database.cpp \
    service.cpp \
    repository.cpp

HEADERS += \
    person.h \
    consoleui.h \
    comparer.h \
    computer.h \
    database.h \
    service.h \
    repository.h

OTHER_FILES += \
    README.md \
    splash.txt \
    todo.md
