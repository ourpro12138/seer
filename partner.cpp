#include "partner.h"



partner::partner()
{

}
partner::~partner()
{

}
//void partner::skill()
//{}

//void partner::evolution()
//{}
void partner::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawImage(boundingRect(),atkmovie->currentImage());
}
QRectF partner::boundingRect() const
{
    return QRectF(0,0,width,height);
}
void partner::advance(int phase)
{
    if(!phase)
        return;
    update();

}
int partner::type() const
{
return Type;
}
