#include "taqiduoke.h"

Taqiduoke::Taqiduoke(int i)
{
    this->width = 190;this->height=140;
    prepareTime=80,atkcounter=80;
    standTime=60; standcounter=0;
    hp=700;atk=50;speed=0.40;
    name="taqiduoke";
    //if(qrand()%2)
    atkmovie=new  QMovie(":/enemy/resource/enemy/taqiduoke.gif");
    atkmovie->start();
    posX=1300;
    posY=i*200-100;
    this->i=i;
    this->setPos(1300,i*200-100);
}
Taqiduoke::~Taqiduoke()
{
    if(atkmovie)
        delete atkmovie;
}
void Taqiduoke::advance(int phase)
{
    if(!phase)
        return;
    update();

     QList <QGraphicsItem *> items = collidingItems();

     if(hp<=0)
     {

         nowStatus=0;  //死亡
         atkmovie->currentFrameNumber()==atkmovie->frameCount()-1;


         delete this;
         return;
     }
     if(hp>0)
     {
         if(!items.isEmpty())
         {

//

             Partner *partner=qgraphicsitem_cast <Partner *> (items[0]);

          if(atkcounter<prepareTime)
          {
           atkcounter++;
           if(atkcounter==prepareTime)
               partner->hp-=atk;
           qDebug()<<partner->hp;
          }
          if(atkcounter==prepareTime)
          {
             atkcounter=0;
             atkmovie = new QMovie(":/enemy/resource/enemy/taqiduoke_attack.gif");
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
                atkmovie = new QMovie(":/enemy/resource/enemy/taqiduoke.gif");
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
bool Taqiduoke::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
    return other->type()==Partner::Type && posX-other->x()<150&&posX-other->x()>80&&posY-other->y()>-100&&posY-other->y()<100;
}
