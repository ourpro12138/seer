#include "partner.h"



Partner::Partner()
{

}
Partner::~Partner()
{

}
//void partner::skill()
//{}

//void partner::evolution()
//{}
void Partner::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawImage(boundingRect(),atkmovie->currentImage());
}
QRectF Partner::boundingRect() const
{
    return QRectF(0,0,width,height);
}
void Partner::advance(int phase)
{
    if(!phase)
        return;
    update();

}
int Partner::type() const
{
return Type;
}
