#include "moguguai.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include"partner.h"
#include<QDebug>

MoGuGuai::MoGuGuai(int i)
{
    this->width = 184;this->height=200;
    hp=700;atk=80;speed=0.40;
    atkcounter=100;prepareTime=100;
    standTime=84;standcounter=0;
    name="MoGuGuai";
    //if(qrand()%2)
    atkmovie=new  QMovie(":/enemy/resource/enemy/moguguai.gif");
    atkmovie->start();
    posX=1300;
    this->i=i;
    this->setPos(1300,i*160-30);
}

MoGuGuai::~MoGuGuai()
{
    if(atkmovie)
        delete atkmovie;
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
         delete this;
         return;
     }

     if(hp>0)
     {
         if(!items.isEmpty())
         {

//             qDebug()<<"advance调用";



             qDebug()<<"advance调用";

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
             atkmovie = new QMovie(":/enemy/resource/enemy/moguguai_attack.gif");
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
                atkmovie = new QMovie(":/enemy/resource/enemy/moguguai.gif");
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

