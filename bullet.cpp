#include "bullet.h"

Bullet::Bullet(int i,int j)
{
    ATK=20;
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

bool Bullet::collideWithItem(const QGraphicsItem *other,Qt::ItemSelectionMode mode)const
{
    Q_UNUSED(mode);

    return other->type() ==Enemy::Type && x()-other->x()>50&&x()-other->x()<90
            &&y()-other->y()>0&&y()-other->y()<100;
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

        enemy=new Enemy;
        enemy->hp -= ATK;

        if(enemy->hp>0)
            delete this;
    }
    setX(x()+5);
    if(x()>=1300)
        delete this;
}

int  Bullet::type()const
{
    return Type;
}
