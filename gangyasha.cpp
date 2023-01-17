#include "gangyasha.h"
#include"partner.h"
#include<QGraphicsItem>
#include<QDebug>
GangYaSha::GangYaSha(int i)
{
    this->width =180;this->height=152;
    hp=250;atk=30;speed=0.40;
    name="MoGuGuai";
    //if(qrand()%2)
    atkmovie=new  QMovie(":/enemy/resource/enemy/gangyasha.gif");
    atkmovie->start();
    posX=1300;
    this->i=i;
    this->setPos(1300,i*220);
    atkcounter=96;prepareTime=96;
    standcounter=232; standTime=0;

}
GangYaSha::~GangYaSha()
{
    if(atkmovie)
        delete atkmovie;
}

bool GangYaSha::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
//    if(other->type()==Partner::Type)
//       {
//           qDebug()<<other->x()-x();
//      }
    return other->type()==Partner::Type && posX-other->x()<140 && posX-other->x()>139
            && other->y()-y()>-60 && other->y()-y()<60;


}

void GangYaSha::advance(int phase)
{

    if(!phase)
        return;
    update();

     QList <QGraphicsItem *> items = collidingItems();

     if(hp<=0)
     {
         delete this;
         return;
     }
     if(hp>0)
     {
         if(!items.isEmpty())
         {
//             qDebug()<<"advance调用";
             Partner *partner=qgraphicsitem_cast <Partner *> (items[0]);
          if(atkcounter<prepareTime)
          {
           atkcounter++;
           if(atkcounter==prepareTime)
               partner->hp-=atk;
          }
          if(atkcounter==prepareTime)
          {
             atkcounter=0;
             atkmovie = new QMovie(":/enemy/resource/enemy/gangyasha_attack.gif");
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
                atkmovie = new QMovie(":/enemy/resource/enemy/gangyasha.gif");
                atkmovie->start();

             }
             else
             {
                 setX(posX-speed*speedFactor/100);
                     posX--;
             }
         }
     }
}

