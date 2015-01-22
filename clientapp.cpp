#include "clientapp.h"
#include "clienthandler.h"

#include <QCoreApplication>
#include <QDebug>

ClientApp::ClientApp()
{
    char **args = new char*[qApp->arguments().size() + 1];
    for (int i = 0; i < qApp->arguments().size(); i++)
    {
        args[i] = new char[qApp->arguments()[i].size() + 1];
        strcpy(args[i], qApp->arguments()[i].toLocal8Bit().constData());
        args[i][qApp->arguments()[i].size()] = '\0';
    }
    
    CefSettings settings;
    
    CefString(&settings.locales_dir_path)="/home/gustavo/cef/Resources/locales";
    CefString(&settings.resources_dir_path) ="/home/gustavo/cef/Resources/";
    
    CefMainArgs main_args(qApp->arguments().size(), args);

    CefRefPtr<ClientApp> app = this;

    CefInitialize(main_args, settings, app.get(), NULL);   
}


