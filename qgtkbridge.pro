#-------------------------------------------------
#
# Project created by QtCreator 2014-05-01T14:34:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qgtkbridge
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp\
        qcefwebview.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++0x -pthread  -g -DQT_NO_KEYWORDS
LIBS +=  -L/home/gustavo/cef/Release\
         -lcef /home/gustavo/cef/out/Release/obj.target/libcef_dll_wrapper.a -ludev

INCLUDEPATH += /home/gustavo/cef/
