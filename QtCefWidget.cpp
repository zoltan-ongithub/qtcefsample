/*
 * QtCefWidget.cpp
 *
 *  Created on: May 2, 2014
 *      Author: Zoltan Kuscsik
 *      E-mail: zoltan.kuscsik@linaro.org
 */

#include <QWidget>
#include <QWindow>
#include <gtk/gtk.h>
#include <gdk/gdkx.h>

#include "QtCefWidget.h"

namespace cef {

QtCefWidget::QtCefWidget() {
	mGtkWdgt = gtk_window_new (GTK_WINDOW_POPUP);
	GdkColor red = {0, 0xffff, 0x0000, 0x0000};
    gtk_widget_modify_bg(mGtkWdgt, GTK_STATE_NORMAL, &red);
	gtk_widget_show(mGtkWdgt);
	GdkWindow *gdkWin = gtk_widget_get_window(mGtkWdgt);
	QWindow *qWin = QWindow::fromWinId(GDK_DRAWABLE_XID(gdkWin));
    mQWidget = QWidget::createWindowContainer(qWin);
}

QtCefWidget* QtCefWidget::newGtkBasedWidget() {
	return new QtCefWidget();
}

void QtCefWidget::show() {
	gtk_widget_show(mGtkWdgt);
}


QtCefWidget::~QtCefWidget() {
	gtk_widget_destroy(mGtkWdgt);
	if (mQWidget != nullptr)
		delete mQWidget;
}

}//namespace cef
