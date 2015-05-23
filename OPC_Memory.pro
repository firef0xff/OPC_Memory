TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    memory.cpp

HEADERS += \
    cache.h \
    memory.h \
    def.h \
    opc_field.h

QMAKE_CXXFLAGS += -std=c++11
