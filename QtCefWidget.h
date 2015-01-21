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

namespace cef {
class QtCefWidget : public QWidget{

	QWidget* mQWidget;
	QWindow* mQwindow;
public:
	static QtCefWidget* newGtkBasedWidget();

	~QtCefWidget();
private:
	QtCefWidget();
};
}

#endif /* QTCEFWIDGET_H_ */
