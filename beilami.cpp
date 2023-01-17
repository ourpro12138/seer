#include "beilami.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include"partner.h"
#include<QDebug>

Beilami::Beilami(int i)
{
    this->width = 96;this->height=140;
    hp=700;atk=0;speed=0.40;
    name="beilami";
    //if(qrand()%2)
    atkmovie=new  QMovie(":/enemy/resource/enemy/beilami.gif");
    atkmovie->start();
    posX=1300;
    this->i=i;
    this->setPos(1300,i*160-30);
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
         }
         else
         {
             setX(posX-speed*speedFactor/100);
                 posX--;
         }

     }


}
