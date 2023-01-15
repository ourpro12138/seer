#include "enemy.h"
#include "partner.h"




Partner::Partner()
{
    setStatus=1;nowStatus=1;
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
bool Partner::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
    return other->type()==Enemy::Type && other->x()-x()<80 && other->x()-x()>15
            && other->y()-y()>0 && other->y()-y()<100;
}
int Partner::type() const
{
return Type;
}
