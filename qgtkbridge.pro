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
        QtCefWidget.cpp\

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++0x -pthread  -g -DQT_NO_KEYWORDS
LIBS +=  -L/home/kuscsik/cef/chromium/src/out/Debug/lib\
         -lcef /home/kuscsik/cef/chromium/src/out/Debug/obj/cef/libcef_dll_wrapper.a\
         -lgtk-x11-2.0 -lgdk-x11-2.0 -latk-1.0 -lgio-2.0 -lpangoft2-1.0 -lpangocairo-1.0 -lgdk_pixbuf-2.0 -lcairo -lpango-1.0 -lfontconfig -lgobject-2.0 -lglib-2.0 -lfreetype

INCLUDEPATH += /home/kuscsik/cef/chromium/src/cef\
    /usr/include/gtk-2.0\
    /usr/include/glib-2.0/\
    /usr/lib/x86_64-linux-gnu/glib-2.0/include\
    /usr/include/cairo/\
    /usr/include/pango-1.0/\
    /usr/lib/x86_64-linux-gnu/gtk-2.0/include/\
    /usr/include/gdk-pixbuf-2.0\
    /usr/include/atk-1.0/\
