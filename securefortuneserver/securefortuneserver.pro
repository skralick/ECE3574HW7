######################################################################

TEMPLATE = app
TARGET = securefortuneserver
DEPENDPATH += .
INCLUDEPATH += .
QT           += widgets
QT           += network

# Input
HEADERS += server.h SSLServer.h
SOURCES += main.cpp server.cpp SSLServer.cpp
