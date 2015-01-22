#ifndef _CLIENTAPP_H
#define _CLIENTAPP_H

#include <QWidget>

#include <include/cef_app.h>
#include "include/cef_client.h"

class ClientApp : public CefApp,
    public CefBrowserProcessHandler
{
public:
    ClientApp();
    
    // CefApp methods:
    virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler()
    OVERRIDE { return this; }
    // CefBrowserProcessHandler methods:
    virtual void OnContextInitialized();
    
    inline void setGtkWidget(WId w) {
        mWidget = w;
    }

private:
    WId mWidget;
    // Include the default reference counting implementation.
    IMPLEMENT_REFCOUNTING(ClientApp);
};

#endif /* _CLIENTAPP_H */

