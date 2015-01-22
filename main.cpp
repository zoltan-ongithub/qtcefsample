#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QLayout>
#include <QDebug>
#include <QWidget>
#include <stdio.h>
#include "qcefwebview.h"
#include "clienthandler.h"
#include "clientapp.h"
#include <thread>

#include <include/cef_app.h>
#include "include/cef_client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    QCefWebView *webView = new QCefWebView();

    MainWindow w;

    QWidget *browserWidget = w.findChild<QWidget *>("browserWidget");
    QVBoxLayout *browserLayout = new QVBoxLayout(browserWidget);
    browserLayout->addWidget( webView);
    w.show();
    
    std::thread bthread([&] { a.exec(); });
    CefRunMessageLoop();
    return 0;
}
