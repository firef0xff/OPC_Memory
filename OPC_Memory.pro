TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    memory.cpp \
    table.cpp

HEADERS += \
    cache.h \
    memory.h \
    def.h \
    opc_field.h \
    table.h \
    opc_types.h

QMAKE_CXXFLAGS += -std=c++11
