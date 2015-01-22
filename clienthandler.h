#ifndef _CLIENTHANDLER_H
#define _CLIENTHANDLER_H

#include <include/cef_client.h>

class ClientHandler: public CefClient,
    public CefDisplayHandler,
    public CefLifeSpanHandler,
    public CefLoadHandler
{
public:
    ClientHandler();

    IMPLEMENT_REFCOUNTING(ClientHandler);
};

#endif /* _CLIENTHANDLER_H */

