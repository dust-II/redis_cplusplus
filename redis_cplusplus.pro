TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += = -I.

HEADERS += ./base_strc/object.h

SOURCES += main.cpp \
           ./base_strc/object.cpp
