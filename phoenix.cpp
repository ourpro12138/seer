#include "phoenix.h"
#include<QGraphicsItem>
#include"partner.h"
#include<QDebug>

Phoenix::Phoenix(int i)
{
    this->attribute=FIRE;
    this->width = 200;this->height=196;
    hp=2000;atk=500;speed=0.40;
    atkcounter=100;prepareTime=100;
    standTime=50;standcounter=0;
    name="Phoenix";
    atkmovie=new  QMovie(":/enemy/resource/enemy/enemy_2634.gif");
    atkmovie->start();
    posX=1300;
    this->i=i;
    this->setPos(1300,360-133+154*i-65);}
bool Phoenix::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return other->type()==Partner::Type && posX-other->x()<131 && posX-other->x()>129
            && other->y()-y()>-60 && other->y()-y()<60;


}

Phoenix::~Phoenix()
{
    if(atkmovie)
        delete atkmovie;
}

void Phoenix::advance(int phase)
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
             atkmovie = new QMovie(":/enemy/resource/enemy/attack_enemy2634.gif");
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
                atkmovie = new QMovie(":/enemy/resource/enemy/enemy_2634.gif");
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

