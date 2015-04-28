#-------------------------------------------------
#
# Project created by QtCreator 2015-04-20T21:49:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chatClient
TEMPLATE = app

QMAKE_CXXFLAGS_WARN_OFF -= -Wunused-parameter

SOURCES += main.cpp\
        clientwindow.cpp \
    client.cpp \
    clientinit.cpp

LIBS += -lrt

HEADERS  += clientwindow.h \
    client.h \
    ../include/common.h \
    clientinit.h

FORMS    += clientwindow.ui \
    clientinit.ui
