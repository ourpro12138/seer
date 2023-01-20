#include "boge.h"

Boge::Boge(int i)
{
    this->attribute = ORDINARY;
    this->width=200; this->height=196;
    hp=200;atk=100;speed=0.40;
    atkcounter=200;prepareTime=200;
    standTime=84;standcounter=0;
    name="Boge";
    atkmovie=new  QMovie(":/enemy/resource/enemy/enemy_384.gif");
    atkmovie->start();
    posX=1300;
    this->i=i;
    this->setPos(1300,360-133+154*i-65);

}
bool Boge::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return other->type()==Partner::Type && posX-other->x()<131 && posX-other->x()>129
            && other->y()-y()>-60 && other->y()-y()<60;


}

Boge::~Boge()
{
    if(atkmovie)
    {
        atkmovie =NULL;
        delete  atkmovie;
    }
}

void Boge::advance(int phase)
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
             atkmovie = new QMovie(":/enemy/resource/enemy/attack_enemy384.gif");
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
                atkmovie = new QMovie(":/enemy/resource/enemy/enemy_384.gif");
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




