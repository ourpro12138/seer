#include "heertuoke.h"
#include<QGraphicsItem>
#include"partner.h"
#include<QDebug>


Heertoke::Heertoke(int i)
{
    this->width = 200;this->height=194;
    hp=200;atk=100;speed=0.40;
    atkcounter=180;prepareTime=180;
    standTime=100;standcounter=0;
    this->attribute = FIRE;
    name="HeErTuoKe";
    atkmovie=new  QMovie(":/enemy/resource/enemy/enemy_527.gif");
    atkmovie->start();
    posX=1300;
    this->i=i;
    this->setPos(1300,360-133+154*i-85);}
bool Heertoke::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return other->type()==Partner::Type && posX-other->x()<131 && posX-other->x()>129
            && other->y()-y()>-60 && other->y()-y()<60;


}

Heertoke::~Heertoke()
{
    if(atkmovie)
        delete atkmovie;

}

void Heertoke::advance(int phase)
{
    if(!phase)
        return;
    update();

     QList <QGraphicsItem *> items = collidingItems();

     if(hp<=0)
     {
         this->nowStatus=0;
         delete this;
         return;
     }

     if(hp>0)
     {
         if(!items.isEmpty())
         {
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
             atkmovie = new QMovie(":/enemy/resource/enemy/attack_enemy527.gif");
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
                atkmovie = new QMovie(":/enemy/resource/enemy/enemy_527.gif");
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

