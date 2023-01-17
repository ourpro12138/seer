#include "jier.h"
#include<QPointF>

Jier::Jier(int i,int j)
{

  this->i = i; this->j=j;
  width = 108;height=130;
  hp=300;atkcounter=0;prepareTime=100;
  this->atk = 50;
  name="Jier";
  atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
  atkmovie->start();
  setPos(145+234*j-47,300-133+154*i);

}
Jier::~Jier()
{
    Map::myptn[i][j]=NULL;
    if(atkmovie)
        delete atkmovie;

}
void Jier::advance(int phase)
{

    if(!phase)
        return;
    update();
    QList <QGraphicsItem *> items = collidingItems();
    if(!items.isEmpty())
    {
    if(atkcounter<prepareTime)
        ++atkcounter;
    if(atkcounter==prepareTime)
    {
        atkcounter=0;
        bullet=new Bullet(i,j,100,100);
        bullet->ATK=this->atk;
        bullet->name = this->name.toLower();
        scene()->addItem(bullet);
    }
    }
    if(hp<=0)
        delete this;
}
//bool Jier::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
//{
//     Q_UNUSED(mode);
//    qDebug()<<other->y()<<y();

//    return other->type() == Enemy::Type && qAbs(other->y()-y())>-50&&qAbs(other->y()-y())<100&&qAbs(other->x()-x())>50;
//}
void Jier::skill()
{

}
void Jier::evolution()
{

}

