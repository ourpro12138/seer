#include "bullet.h"

Bullet::Bullet(QPointF point)
{
    ATK=20;
    posX=point.x();
    posY=point.y();
    setPos(posX-180,posY);
    setZValue((posY-100)/90);
}
Bullet::~Bullet()
{

}
QRectF Bullet::boundingRect()const
{
    return QRectF(180,0,30,30);
}
void Bullet::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    //painter->drawImage(boundingRect());
}
void Bullet::advance(int phase)
{
//    if(!phase)
//        return;
//    updata();
}
bool Bullet::collideWithItem(const QGraphicsItem *other,Qt::ItemSelectionMode mode)const
{

}
int  Bullet::type()const
{
    return Type;
}
