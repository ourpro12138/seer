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
    painter->drawImage(boundingRect(),atkmovie->currentImage());
}
QRectF partner::boundingRect() const
{
    return QRectF(0,0,95,133);
}
void partner::advance(int phase)
{

}
int partner::type() const
{

}
