#include "clientapp.h"
#include "clienthandler.h"

ClientApp::ClientApp()
{
}

     void ClientApp::OnContextInitialized() {

        printf("Context initialized\n");

        CefWindowInfo window_info;
        if( mWidget != 0) {
            CefRect r;
            r.width = 400;
            r.height = 400;
            r.x = 0;
            r.y = 0;

            window_info.SetAsChild(mWidget, r);

            printf("setting mWidget as child\n");
        }
        CefRefPtr<ClientHandler> handler(new ClientHandler());

        // Specify CEF browser settings here.
        CefBrowserSettings browser_settings;

        std::string url;

        CefRefPtr<CefCommandLine> command_line =
            CefCommandLine::GetGlobalCommandLine();
        url = command_line->GetSwitchValue("url");
        if (url.empty())
            url = "http://www.google.com";
        CefBrowserHost::CreateBrowser(window_info, handler.get(), url,
                                      browser_settings, NULL);
    }

