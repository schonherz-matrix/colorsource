######################################################################
# Automatically generated by qmake (3.0) Sun Sep 20 15:14:39 2015
######################################################################

TEMPLATE = app
TARGET = ColorSource
QT += core gui widgets
INCLUDEPATH += . ./sw-common
QMAKE_CXXFLAGS += -std=c++11 -Wall -pedantic
QMAKE_LFLAGS += -lm

# Input
HEADERS += colorsender.h mainwindow.h timer.h
SOURCES += main.cpp colorsender.cpp mainwindow.cpp timer.cpp
OBJECTS += sw-common/build/lib/libmatrix_sw-common.a
