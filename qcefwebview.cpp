#include "qcefwebview.h"
#include "clienthandler.h"
#include "clientapp.h"

#include <include/cef_client.h>
#include <include/cef_app.h>

QCefWebView::QCefWebView()
{
    _state = NoneBrowserState;

    setAttribute(Qt::WA_NativeWindow);
    setAttribute(Qt::WA_DontCreateNativeAncestors);
    
    CefRefPtr<ClientApp> app(new ClientApp());
}

void QCefWebView::showEvent(QShowEvent *event)
{
    createBrowser(rect());
}

void QCefWebView::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
}
    
void QCefWebView::createBrowser(const QRect &rect)
{
    CefRect r;
    r.x = 0;
    r.y = 0;
    r.width = rect.width();
    r.height = rect.height();
    
    
        printf("Context initialized\n");

        CefWindowInfo window_info;



            window_info.SetAsChild(this->winId(), r);

            printf("setting mWidget as child\n");

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

