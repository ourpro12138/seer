#include "moguguai.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include"partner.h"
#include<QDebug>

MoGuGuai::MoGuGuai(int i)
{
    this->width = 184;this->height=200;
    hp=700;atk=0;speed=0.40;
    name="MoGuGuai";
    //if(qrand()%2)
    movie=new  QMovie(":/enemy/resource/enemy/moguguai.gif");
    movie->start();
    posX=1300;
    this->i=i;
    this->setPos(1300,i*160-30);
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

             qDebug()<<"lll";

             qDebug()<<"碰撞";

             Partner *partner=qgraphicsitem_cast<Partner *>(items[0]);
             partner->hp-=atk;
             nowStatus=2;
             moveMovie(":/enemy/resource/enemy/moguguai_attack.gif");
         }
         else
         {
             setX(posX-speed*speedFactor/100);
                 posX--;
         }

     }


}

