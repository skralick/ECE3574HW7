#-------------------------------------------------
#
# Project created by QtCreator 2015-04-14T22:42:42
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chatServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    server.cpp

LIBS += -lrt

HEADERS  += mainwindow.h \
    ../include/common.h \
    server.h

FORMS    += mainwindow.ui
