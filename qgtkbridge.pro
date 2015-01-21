#-------------------------------------------------
#
# Project created by QtCreator 2014-05-01T14:34:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qgtkbridge
TEMPLATE = app

CONFIG += link_pkgconfig

SOURCES += main.cpp\
        mainwindow.cpp\
        QtCefWidget.cpp\

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

PKGCONFIG += gdk-2.0 glib-2.0 gtk+-2.0

QMAKE_CXXFLAGS += -std=c++0x -pthread  -g -DQT_NO_KEYWORDS
