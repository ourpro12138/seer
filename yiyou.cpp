#include "yiyou.h"
#include<QPointF>
Yiyou::Yiyou(int i,int j)
{

  this->i = i; this->j=j;
  width = 95;height=133;
  hp=300;bulletCounter=0;bulletCreateTime=100;
  this->atk = 50;
  name="Yiyou";
  atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
  atkmovie->start();
  setPos(154+234*j-47,290-133+154*i);

}
Yiyou::~Yiyou()
{
    Map::myptn[i][j]=NULL;
    if(atkmovie)
        delete atkmovie;

}
void Yiyou::advance(int phase)
{
//    if(!phase)
//        return;
//    update();
//    if(bulletCounter<bulletCreateTime)
//        ++bulletCounter;
//    if(bulletCounter==bulletCreateTime)
//    {
//        bulletCounter=0;
//        bullet=new Bullet(i,j);
//        bullet->ATK=this->atk;
//        scene()->addItem(bullet);
//    }
//    if(hp<=0)
//        delete this;
    if(!phase)
        return;
    update();
    QList <QGraphicsItem *> items = collidingItems();
    if(!items.isEmpty())
    {
    if(bulletCounter<bulletCreateTime)
        ++bulletCounter;
    if(bulletCounter==bulletCreateTime)
    {
        bulletCounter=0;
        bullet=new Bullet(i,j);
        bullet->ATK=this->atk;
        scene()->addItem(bullet);
    }
    }
    if(hp<=0)
        delete this;
}
bool Yiyou::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
     Q_UNUSED(mode);
    qDebug()<<other->y()<<y();

    return other->type() == Enemy::Type && qAbs(other->y()-y())>-50&&qAbs(other->y()-y())<100&&qAbs(other->x()-x())>50;
}
void Yiyou::skill()
{

}
void Yiyou::evolution()
{

}

