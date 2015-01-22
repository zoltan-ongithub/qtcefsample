#ifndef _QCEFWEBVIEW_H_
#define _QCEFWEBVIEW_H_

#include <QWidget>

class QCefWebView: public QWidget
{
public:
    QCefWebView();
    
protected:
    void resizeEvent(QResizeEvent *event);    
};

#endif /* _QCEFWEBVIEW_H_ */
