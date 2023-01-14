#include "moguguai.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include"partner.h"
MoGuGuai::MoGuGuai(int i)
{
    hp=350;atk=25;speed=0.40;
    name="MoGuGuai";
//    if(qrand()%2)
    movie=new  QMovie(":/enemy/resource/enemy/moguguai.gif");
    movie->start();
    x=1566;
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
         delete this;
         return;
     }

    if(hp!=0)
    {
      nowStatus=1;         //存活没碰到精灵
      if(!items.isEmpty())
      {
          nowStatus=2;   //存活碰到精灵
          partner->hp-=atk;
          moveMovie(":/enemy/resource/enemy/enemy_6attack.gif");
         //partner *partner=qgraphicsitem_cast<partner *>(items[0]);

      }
    }
}

