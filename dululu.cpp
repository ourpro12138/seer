#include "dululu.h"

Dululu::Dululu(int i)
{
    this->attribute = ORDINARY;
    this->width=200; this->height=175;
    hp=200;atk=100;speed=0.40;
    atkcounter=100;prepareTime=100;
    standTime=84;standcounter=0;
    name="DuLuLu";
    atkmovie=new  QMovie(":/enemy/resource/enemy/enemy_253.gif");
    atkmovie->start();
    posX=1300;
    this->i=i;
    this->setPos(1300,360-133+154*i-65);

}
bool Dululu::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return other->type()==Partner::Type && posX-other->x()<131 && posX-other->x()>129
            && other->y()-y()>-60 && other->y()-y()<60;


}

Dululu::~Dululu()
{
    if(atkmovie)
    {
        atkmovie =NULL;
        delete  atkmovie;
    }
}

void Dululu::advance(int phase)
{
    if(!phase)
        return;
    update();

     QList <QGraphicsItem *> items = collidingItems();

     if(hp<=0)
     {
         this->nowStatus=0;
         delete this;
         nowStatus=0;  //死亡
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
               partner->hp-=Damage(this,partner);
          }
          if(atkcounter==prepareTime)
          {
             atkcounter=0;
             atkmovie = new QMovie(":/enemy/resource/enemy/attack_enemy253.gif");
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
                atkmovie = new QMovie(":/enemy/resource/enemy/enemy_253.gif");
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




