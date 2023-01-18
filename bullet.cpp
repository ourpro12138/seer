#include "bullet.h"
#include <QTimer>

Bullet::Bullet(int i,int j,int wei,int hei)
{
    posX=80+234*j-47;
    posY=350-133+154*i;
    weight=wei;
    height=hei;
    setPos(posX,posY);
    setZValue((posY-100)/90);
}
Bullet::~Bullet()
{

}
QRectF Bullet::boundingRect()const
{
    return QRectF(180,0,weight,height);
}
void Bullet::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawImage(boundingRect(),QImage(":/partner/resource/partner/"+name+"_bullet.png"));
}

bool Bullet::collidesWithItem(const QGraphicsItem *other,Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);

    return other->type() ==Enemy::Type&&other->x()-posX<260&&other->x()-posX>180&&posY-other->y()>-50&&posY-other->y()<50;
}

void Bullet::advance(int phase)
{
    if(!phase)
        return;

    update();
    QList <QGraphicsItem *> items=collidingItems();

    if(!items.isEmpty())
    {
        Enemy *enemy=qgraphicsitem_cast <Enemy *> (items[qrand()%items.size()]);
        enemy->hp -= ATK;
        //qDebug()<<enemy->hp;
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
