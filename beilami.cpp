#include "beilami.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include"partner.h"
#include<QDebug>

Beilami::Beilami(int i)
{
    this->width = 96;this->height=140;
    prepareTime=300,atkcounter=300;
    standTime=84; standcounter=0;
    hp=700;atk=50;speed=0.40;
    name="beilami";
    //if(qrand()%2)
    atkmovie=new  QMovie(":/enemy/resource/enemy/beilami.gif");
    atkmovie->start();
    posX=1300;
    this->i=i;
    this->setPos(1300,i*200-50);
}

Beilami::~Beilami()
{
    if(atkmovie)
        delete atkmovie;
}
//蘑菇怪状态变化
void Beilami::advance(int phase)
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

         nowStatus=1;
         atkMovie(":/enemy/resource/enemy/beilami.gif");
         if(!items.isEmpty())
         {

             Partner *partner=qgraphicsitem_cast<Partner *>(items[0]);
             partner->hp-=atk;
             nowStatus=2;
             atkMovie(":/enemy/resource/enemy/beilami_attack.gif");

         if(!items.isEmpty())
         {
             //qDebug()<<"advance调用";
             Partner *partner=qgraphicsitem_cast <Partner *> (items[0]);
          if(atkcounter<prepareTime)
          {
           atkcounter++;
           if(atkcounter==300)
               partner->hp-=atk;
          }
          if(atkcounter==prepareTime)
          {
             atkcounter=0;
             atkmovie = new QMovie(":/enemy/resource/enemy/beilami_attack.gif");
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
                atkmovie = new QMovie(":/enemy/resource/enemy/beilami.gif");
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

bool Beilami::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
    return other->type()==Partner::Type && posX-other->x()<200&&posX-other->x()>100;
}
