#ifndef _CLIENTAPP_H
#define _CLIENTAPP_H

#include <QWidget>

#include <include/cef_app.h>
#include "include/cef_client.h"

class ClientApp: public CefApp, public CefBrowserProcessHandler
{
public:
    ClientApp();

    virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() OVERRIDE { return this; }

private:
    IMPLEMENT_REFCOUNTING(ClientApp);
};

#endif /* _CLIENTAPP_H */

