#include "moguguai.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include"partner.h"
#include<QDebug>

MoGuGuai::MoGuGuai(int i)
{
    this->width = 184;this->height=200;
    hp=350;atk=30;speed=0.40;
    name="MoGuGuai";
    //if(qrand()%2)
    movie=new  QMovie(":/enemy/resource/enemy/moguguai.gif");
    movie->start();
    x=1300;
    this->i=i;
    this->setPos(1300,i*200);
}

MoGuGuai::~MoGuGuai()
{
    if(movie)
        delete movie;
}
//蘑菇怪状态变化
void MoGuGuai::advance(int phase)
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
         moveMovie(":/enemy/resource/enemy/moguguai.gif");
         if(!items.isEmpty())
         {
             Partner *partner=qgraphicsitem_cast<Partner *>(items[0]);
             partner->hp-=atk;
             nowStatus=2;
             moveMovie(":/enemy/resource/enemy/enemy_6attack.gif");
         }

     }

    setX(x-speed*speedFactor/100);
    qDebug()<<"moving"<<x;
        x--;


}

