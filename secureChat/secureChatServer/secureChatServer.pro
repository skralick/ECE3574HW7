#-------------------------------------------------
#
# Project created by QtCreator 2015-04-30T14:28:52
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = secureChatServer
TEMPLATE = app


SOURCES += main.cpp\
        serverwindow.cpp \
    SSLServer.cpp \
    server.cpp

HEADERS  += serverwindow.h \
    SSLServer.h \
    server.h

FORMS    += serverwindow.ui
