#include "qcefwebview.h"

QCefWebView::QCefWebView()
{
    setAttribute(Qt::WA_NativeWindow);
    setAttribute(Qt::WA_DontCreateNativeAncestors);
}

