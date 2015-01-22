#include "qcefwebview.h"

QCefWebView::QCefWebView()
{
    setAttribute(Qt::WA_NativeWindow);
    setAttribute(Qt::WA_DontCreateNativeAncestors);
}


void QCefWebView::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
}
    
