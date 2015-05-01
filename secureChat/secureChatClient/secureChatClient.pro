#-------------------------------------------------
#
# Project created by QtCreator 2015-04-30T14:11:49
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = secureChatClient
TEMPLATE = app


SOURCES += main.cpp\
        initwindow.cpp \
    client.cpp \
    selectionwindow.cpp \
    chatwindow.cpp

HEADERS  += initwindow.h \
    client.h \
    selectionwindow.h \
    chatwindow.h

FORMS    += initwindow.ui \
    selectionwindow.ui \
    chatwindow.ui
