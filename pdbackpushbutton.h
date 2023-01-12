#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H
#include <QPushButton>
#include <QPixmap>
#include <QBitmap>
#include <QDebug>
#include <QMouseEvent>
class pdbackPushButton : public QPushButton
{
    Q_OBJECT
public:
    pdbackPushButton(int width);

    ~pdbackPushButton();
    int window_width;

    void enterEvent(QEvent *);

    void leaveEvent(QEvent *);

    virtual void mousePressEvent(QMouseEvent *ev);

    virtual  void mouseReleaseEvent(QMouseEvent *ev);
 signals :
    void backpress();


};

#endif // MYPUSHBUTTON_H
