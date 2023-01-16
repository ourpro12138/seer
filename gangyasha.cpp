#include "gangyasha.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include"partner.h"
#include<QDebug>
GangYaSha::GangYaSha(int i)
{
    this->width = 100;this->height=86;
    hp=250;atk=10;speed=0.40;
    name="MoGuGuai";
    //if(qrand()%2)
    movie=new  QMovie(":/enemy/resource/enemy/gangyasha.gif");
    movie->start();
    posX=1300;
    this->i=i;
    this->setPos(1300,i*200);
}
GangYaSha::~GangYaSha()
{
    if(movie)
        delete movie;
}

void GangYaSha::advance(int phase)
{

    if(!phase)
        return;
    update();

     QList <QGraphicsItem *> items = collidingItems();

     if(hp<=0)
     {
         nowStatus=0;  //死亡
         movie->currentFrameNumber()==movie->frameCount()-1;
         delete this;
         return;
     }

     if(hp>0)
     {
         nowStatus=1;
         moveMovie(":/enemy/resource/enemy/gangyasha.gif");
         if(!items.isEmpty())
         {
             Partner *partner=qgraphicsitem_cast<Partner *>(items[0]);
             partner->hp-=atk;
             nowStatus=2;
             moveMovie(":/enemy/resource/enemy/enemy_attack.gif");
         }
         else
         {
             setX(posX-speed*speedFactor/100);
                 posX--;
         }

     }
}

