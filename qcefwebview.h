#ifndef _QCEFWEBVIEW_H_
#define _QCEFWEBVIEW_H_

#include <QWidget>

class QCefWebView: public QWidget
{
public:
    QCefWebView();
    
protected:
    void showEvent(QShowEvent *event);
    void resizeEvent(QResizeEvent *event);
    
private:
    enum BrowserState
    {
        NoneBrowserState,
        CreatingBrowserState,
        CreatedBrowserState
    };

    void createBrowser(const QRect &rect);

    BrowserState _state;
};

#endif /* _QCEFWEBVIEW_H_ */
