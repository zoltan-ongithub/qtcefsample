/*
 * QtCefWidget.cpp
 *
 *  Created on: May 2, 2014
 *      Author: Zoltan Kuscsik
 *      E-mail: zoltan.kuscsik@linaro.org
 */

#include <QWidget>
#include <QWindow>

#include "QtCefWidget.h"

namespace cef
{

QtCefWidget::QtCefWidget()
{
    setAttribute(Qt::WA_NativeWindow);
    setAttribute(Qt::WA_DontCreateNativeAncestors);
}

QtCefWidget *QtCefWidget::newGtkBasedWidget()
{
    return new QtCefWidget();
}


QtCefWidget::~QtCefWidget()
{
    if (mQWidget != nullptr)
        delete mQWidget;
}

}//namespace cef
