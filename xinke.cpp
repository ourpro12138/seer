#include "xinke.h"
#include<QPointF>
Xinke::Xinke(int i,int j)
{

  attribute = ORDINARY;
  this->i = i; this->j=j;
  width = 149;height=135;
  hp=100;atkcounter=0;prepareTime=100;
  this->atk = 50;
  name="Xinke";
  atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
  atkmovie->start();
  setPos(135+234*j-47,290-133+154*i);

}
Xinke::~Xinke()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        atkmovie =NULL;
        delete atkmovie;
    }

}
void Xinke::advance(int phase)
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
        bullet=new Bullet(i,j,43,43);
        bullet->ATK=this->atk;
        bullet->attribute=this->attribute;
        bullet->name = this->name.toLower();
        scene()->addItem(bullet);
    }
    }
    if(hp<=0)
        delete this;
}
//bool Yiyou::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
//{
//     Q_UNUSED(mode);
//    qDebug()<<other->y()<<y();

//    return other->type() == Enemy::Type && qAbs(other->y()-y())>-50&&qAbs(other->y()-y())<100&&qAbs(other->x()-x())>50;
//}
void Xinke::skill()
{

}
void Xinke::evolution()
{

}

