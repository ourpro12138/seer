#include "bullet.h"
#include <QTimer>

Bullet::Bullet(int i,int j)
{
    posX=80+234*j-47;
    posY=350-133+154*i;
    setPos(posX,posY);
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
    painter->drawImage(boundingRect(),QImage(":/partner/resource/partner/yiyou_waterbullet.png"));
}

bool Bullet::collidesWithItem(const QGraphicsItem *other,Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
//    if(other->type()==Enemy::Type)
////    qDebug()<<other->x()-posX<<"  ";
    return other->type() ==Enemy::Type&&other->x()-posX<260&&other->x()-posX>180;
}

void Bullet::advance(int phase)
{
    if(!phase)
        return;

    update();
    QList <QGraphicsItem *> items=collidingItems();


    if(!items.isEmpty())
    {
//    qDebug()<<"ppp";
        Enemy *enemy=qgraphicsitem_cast <Enemy *> (items[qrand()%items.size()]);

        //enemy=new Enemy;
        enemy->hp -= ATK;
        if(enemy->hp>0)
       {
           delete this;
        }
    }
    setX(posX+2);
    posX+=2;
    if(posX>=1300)
        delete this;

}

int  Bullet::type()const
{
    return Type;
}
