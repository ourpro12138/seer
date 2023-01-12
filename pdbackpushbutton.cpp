#include "pdbackpushbutton.h"

pdbackPushButton::pdbackPushButton(int width)
{
    this->window_width = width;
    QPixmap pix;
    pix.load(":/background/resource/background/backmoto.png");
    this->setFixedSize(pix.size());
    this->setMask(pix.mask()); this->move(window_width-86,30); this->setStyleSheet("border-image: url(:/background/resource/background/backmoto.png)");
        this->setCursor(QCursor(Qt::PointingHandCursor));
}
pdbackPushButton::~pdbackPushButton()
{

}
void pdbackPushButton::enterEvent(QEvent *)
{
    QPixmap pix;
    pix.load(":/background/resource/background/backmoto3.png");
    this->setFixedSize(pix.size());
    this->setMask(pix.mask());
    this->setStyleSheet("border-image: url(:background/resource/background/backmoto3.png)");
    this->move(window_width-96,20);
}
void pdbackPushButton::leaveEvent(QEvent *)
{
    this->move(window_width-86,30);
    QPixmap pix;
    pix.load(":background/resource/background/backmoto.png");
    this->setFixedSize(pix.size());
    this->setMask(pix.mask());
    this->setStyleSheet("border-image: url(:/background/resource/background/backmoto.png)");
}
void pdbackPushButton::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button()==Qt::LeftButton)
    {
    this->move(window_width-86,30);
    QPixmap pix;
    pix.load(":/background/resource/background/backmoto.png");
    this->setFixedSize(pix.size());
    this->setMask(pix.mask());
    this->setStyleSheet("border-image: url(:background/resource/background/backmoto2.png)");
    }
}
void pdbackPushButton::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button()==Qt::LeftButton&&(ev->x()<0||ev->x()>30||ev->y()<0||ev->y()>30))
   {
    QPixmap pix;
    pix.load(":/background/resource/background/backmoto.png");
    this->setFixedSize(pix.size());
    this->setMask(pix.mask());
    this->setStyleSheet("border-image: url(:/background/resource/background/backmoto.png)");
    }
    else
    {
        this->move(window_width-96,20);
        QPixmap pix;
        pix.load(":/background/resource/background/backmoto3.png");
        this->setFixedSize(pix.size());
        this->setMask(pix.mask());
        this->setStyleSheet("border-image: url(:/background/resource/background/backmoto3.png)");
        emit this->backpress();
    }
}
