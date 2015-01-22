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

using namespace cef;

int g_argc;
char **g_argv;

int main(int argc, char *argv[])
{
    g_argc = argc;
    g_argv = argv;



    CefSettings settings;
    CefMainArgs main_args(g_argc, g_argv);

    CefRefPtr<ClientApp> app(new ClientApp());

    // CEF applications have multiple sub-processes (render, plugin, GPU, etc)
    // that share the same executable. This function checks the command-line and,
    // if this is a sub-process, executes the appropriate logic.
    int exit_code = CefExecuteProcess(main_args, app.get(), NULL);
    if (exit_code >= 0) {
        // The sub-process has completed so return here.
        printf("Failed to run CefExecuteProcess\n");
        return exit_code;
    }

    QApplication a(argc, argv);

    QCefWebView *webView = new QCefWebView();
    app->setGtkWidget(webView->winId());

    CefString(&settings.locales_dir_path)="/home/gustavo/cef/Resources/locales";
    CefString(&settings.resources_dir_path) ="/home/gustavo/cef/Resources/";
    printf("Initialize CEF\n");
    // Initialize CEF for the browser process.
    CefInitialize(main_args, settings, app.get(), NULL);

    // Shut down CEF.


    MainWindow w;


    QWidget *browserWidget = w.findChild<QWidget *>("browserWidget");
    QVBoxLayout *browserLayout = new QVBoxLayout(browserWidget);
    browserLayout->addWidget( webView);
    //printf("Browser widget 0x%x\n", (long int) browserWidget->logicalDpiX());
    //browserWidget->layout()->addWidget(button1);
    // w.layout()->addWidget(qw);
    //w.layout()->addWidget(button1);
    w.show();
    std::thread bthread([&] { a.exec(); });
    CefRunMessageLoop();
    return 0;
}
