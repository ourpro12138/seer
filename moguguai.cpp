#include "moguguai.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include"partner.h"
MoGuGuai::MoGuGuai(int i)
{
    hp=350;atk=5;speed=0.40;
    name="MoGuGuai";
    if(qrand()%2)
        movie=new  QMovie(":/enemy/resource/enemy/enemy_attack.gif");
    else
        movie=new  QMovie(":/enemy/resource/enemy/enemy.gif");
    movie->start();
    x=1566;
    this->i=i=2;

    QGraphicsScene scene;
    QGraphicsRectItem *rect = scene.addRect(QRectF(0, 0, 100, 100));
    QTransform transform;;
    QGraphicsItem *item = scene.itemAt(50, 50, transform);
    QGraphicsScene scene2;

    QGraphicsView view(&scene2);
    view.show();
}

MoGuGuai::~MoGuGuai()
{
    if(movie)
        delete movie;
}

void MoGuGuai::advance(int phase)
{
    if(!phase)
        return;
    update();
     QList <QGraphicsItem *> items = collidingItems();
    if(hp!=0)
    {
      setStatus=1;         //没碰到精灵且存活
      if(!items.isEmpty())
      {
          setStatus=2; //碰到精灵且存活

      }
    }
    else
        setStatus=0;  //死亡


    switch(setStatus)
    {
    case 0:
        speedFactor=100;
        if(setStatus!=nowStatus)
            delete this;
            break;
    case 1:
        if(setStatus!=nowStatus)
            moveMovie(":/enemy/resource/enemy/enemy.gif");
        break;
    case 2:
        if(setStatus!=nowStatus)
            moveMovie(":/enemy/resource/enemy/enemy_attack.gif");
    default:break;


    }

    nowStatus=setStatus;
    if(nowStatus==0)
        delete  this;

    if(!items.empty())
        items.clear();
}

