#include "zuoluo.h"
#include<QGraphicsItem>
ZuoLuo::ZuoLuo(int i)
{
    attribute = WATER;
    this->width = 126;this->height=130;
    hp=300;atk=40;speed=0.40;
    atkcounter=80;prepareTime=80;
    standTime=64;standcounter=0;
    name="ZuoLuo";
    atkmovie=new  QMovie(":/enemy/resource/enemy/zuoluo.gif");
    atkmovie->start();
    posX=1300;
    this->i=i;
    this->setPos(1300,i*160+10);
}
ZuoLuo::~ZuoLuo()
{
    if(atkmovie)
    {
        atkmovie =NULL;
        delete  atkmovie;
    }
}
bool ZuoLuo::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
//    if(other->type()==Partner::Type)
//          {
//               qDebug()<<other->x()-x();
//          }
    return other->type()==Partner::Type && posX-other->x()<150 && posX-other->x()>120
            && other->y()-y()>-50 && other->y()-y()<50;

}
void ZuoLuo::advance(int phase)
{
    if(!phase)
        return;
    update();

     QList <QGraphicsItem *> items = collidingItems();

     if(hp<=0)
     {
         delete this;
         nowStatus=0;  //死亡
         return;
     }

     if(hp>0)
     {
         if(!items.isEmpty())
         {

//             qDebug()<<"advance调用";



             qDebug()<<"advance调用";

             Partner *partner=qgraphicsitem_cast <Partner *> (items[0]);
             qDebug()<<partner->hp;
             qDebug()<<atkcounter;
          if(atkcounter<prepareTime)
          {
           atkcounter++;
           if(atkcounter==prepareTime)
               partner->hp-=Damage(this,partner);
          }
          if(atkcounter==prepareTime)
          {
             atkcounter=0;
             atkmovie = new QMovie(":/enemy/resource/enemy/zuoluo_attack.gif");
             atkmovie->start();
          }
         }
         else
         {
             if(standcounter<standTime)
             {
              standcounter++;
             }
             if(standcounter==standTime)
             {
                standcounter=0;
                atkmovie = new QMovie(":/enemy/resource/enemy/zuoluo.gif");
                atkmovie->start();
             }
             else
             {
                 setX(posX-speed*speedFactor);
                     posX--;
             }
}
     }
}
