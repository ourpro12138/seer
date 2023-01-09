#include "pdbackpushbutton.h"

pdbackPushButton::pdbackPushButton()
{

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
    this->move(1270,20);
}
void pdbackPushButton::leaveEvent(QEvent *)
{
    this->move(1280,30);
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
        qDebug()<<"??";
    this->move(1280,30);
    QPixmap pix;
    pix.load(":/background/resource/background/backmoto.png");
    this->setFixedSize(pix.size());
    this->setMask(pix.mask());
    this->setStyleSheet("border-image: url(:background/resource/background/backmoto2.png)");
    }
}
void pdbackPushButton::mouseReleaseEvent(QMouseEvent *ev)
{
    qDebug()<<ev->x(); qDebug()<<ev->y();
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
        this->move(1270,20);
        QPixmap pix;
        pix.load(":/background/resource/background/backmoto3.png");
        this->setFixedSize(pix.size());
        this->setMask(pix.mask());
        this->setStyleSheet("border-image: url(:/background/resource/background/backmoto3.png)");
        emit this->backpress();
    }
}
