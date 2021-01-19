TEMPLATE = app
CONFIG += console
QMAKE_CXXFLAGS += -std=c++11
CONFIG -= app_bundle
CONFIG -= qt
QT     -= core gui

CONFIG(debug, debug|release){
    TARGET = ./Targets/Debug/redis_cppd
    OBJECTS_DIR = ./build-Debug/
    QMAKE_CXXFLAGS -= -O2
    QMAKE_CXXFLAGS += -O0
    #QMAKE_LFLAGS += -Wl,-rpath,../../Targets/Debug:./modules/$$PLATFORM/lib/$$BUILD_TYPE
    #BUILD_TYPE = debug
}else{
    TARGET = ./Targets/Release/redis_cpp
    OBJECTS_DIR = ./build-Release/
    QMAKE_CXXFLAGS += -O3
    QMAKE_CXXFLAGS -= -O2
    #QMAKE_LFLAGS += -Wl,-rpath,../../Targets/Release:./modules/$$PLATFORM/lib/$$BUILD_TYPE
    #BUILD_TYPE = release
}


INCLUDEPATH += ./


HEADERS += ./base_strc/*.h \
           ./db/*.h \
           ./server/*.h \
           ./util/*.h

SOURCES += main.cpp \
           ./base_strc/*.cpp \
           ./db/*.cpp \
           ./server/*.cpp \
           ./util/*.cpp
