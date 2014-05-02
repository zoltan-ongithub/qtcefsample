#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QLayout>
#include <QWidget>
#include <gtk/gtk.h>
#include <gdk/gdkx.h>
#include <stdio.h>
#include "QtCefWidget.h"
#include <thread>

#include <include/cef_app.h>
#include "include/cef_client.h"

using namespace cef;

int g_argc;
char **g_argv;

class SimpleHandler : public CefClient,
                      public CefDisplayHandler,
                      public CefLifeSpanHandler,
                      public CefLoadHandler {
 public:
    SimpleHandler() {

    }
    ~SimpleHandler(){}
    IMPLEMENT_REFCOUNTING(SimpleHandler);
};

class SimpleApp : public CefApp,
                  public CefBrowserProcessHandler {
 public:
  SimpleApp() : mWidget(nullptr) {};
  // CefApp methods:
  virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler()
      OVERRIDE { return this; }
  // CefBrowserProcessHandler methods:
  virtual void OnContextInitialized() {

    printf("Context initialized\n");

    CefWindowInfo window_info;
    if( mWidget != nullptr) {
    	window_info.SetAsChild(mWidget);
    	printf("setting mWidget as child\n");
    }
    CefRefPtr<SimpleHandler> handler(new SimpleHandler());

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
 void setGtkWidget(GtkWidget* w) { mWidget = w;}

 private:
  GtkWidget* mWidget;
  // Include the default reference counting implementation.
  IMPLEMENT_REFCOUNTING(SimpleApp);
};


void browser_thread() {

}

int main(int argc, char *argv[])
{
    g_argc = argc;
    g_argv = argv;



	  CefSettings settings;
	  CefMainArgs main_args(g_argc, g_argv);
	  //GtkWidget* gWidget = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	  //gtk_widget_show(gWidget);
	  CefRefPtr<SimpleApp> app(new SimpleApp());

	  // CEF applications have multiple sub-processes (render, plugin, GPU, etc)
	  // that share the same executable. This function checks the command-line and,
	  // if this is a sub-process, executes the appropriate logic.
	  int exit_code = CefExecuteProcess(main_args, app.get(), NULL);
	  if (exit_code >= 0) {
	    // The sub-process has completed so return here.
		  printf("Failed to run CefExecuteProcess\n");
	  }
	  printf("Initializing gtk\n");

      gtk_init(&argc, &argv);
      QApplication a(argc, argv);

  	  QtCefWidget *cefWidget = QtCefWidget::newGtkBasedWidget();
  	  app->setGtkWidget(cefWidget->getGtkWidget());

	  CefString(&settings.locales_dir_path)="/home/kuscsik/cef/chromium/src/out/Debug/locales";
	  CefString(&settings.resources_dir_path) ="/home/kuscsik/cef/chromium/src/out/Debug/";
	  printf("Initialize CEF\n");
	  // Initialize CEF for the browser process.
	  CefInitialize(main_args, settings, app.get(), NULL);

	  // Shut down CEF.


  	 MainWindow w;


    QWidget *browserWidget = w.findChild<QWidget*>("browserWidget");
    QVBoxLayout *browserLayout = new QVBoxLayout(browserWidget);
    browserLayout->addWidget( cefWidget->getQWidget());
    //printf("Browser widget 0x%x\n", (long int) browserWidget->logicalDpiX());
    //browserWidget->layout()->addWidget(button1);
   // w.layout()->addWidget(qw);
    //w.layout()->addWidget(button1);
    w.show();
    std::thread bthread([&]{ a.exec(); });
 	CefRunMessageLoop();
 	return 0;
}
