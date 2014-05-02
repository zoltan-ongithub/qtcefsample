/*
 * QtCefWidget.h
 *
 *  Created on: May 2, 2014
 *      Author: kuscsik
 */

#ifndef QTCEFWIDGET_H_
#define QTCEFWIDGET_H_

#include <QWidget>
#include <QWindow>
#include <gtk/gtk.h>

namespace cef {
class QtCefWidget : public QWidget{
	GtkWidget *mGtkWdgt;
	QWidget* mQWidget;
	QWindow* mQwindow;
public:
	static QtCefWidget* newGtkBasedWidget();
	void show();
	QWidget* getQWidget() { return mQWidget;}
	GtkWidget* getGtkWidget() { return mGtkWdgt; }
	~QtCefWidget();
private:
	QtCefWidget();
};
}

#endif /* QTCEFWIDGET_H_ */
