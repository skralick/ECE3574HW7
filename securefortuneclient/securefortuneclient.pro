######################################################################

TEMPLATE = app
TARGET = securefortuneclient
DEPENDPATH += .
INCLUDEPATH += .
QT           += widgets
QT           += network

# Input
HEADERS += client.h
SOURCES += client.cpp main.cpp
