#include "yiyou.h"
#include<QPointF>
Yiyou::Yiyou(QPointF point)
{
  hp=300;bulletCounter=0;bulletCreateTime=40;
  name="Yiyou";
  atkmovie=new QMovie("");
  atkmovie->start();
  posX=point.x();
  posY=point.y();
  i=(point.x()-107)/230;
  j=(point.y()-121)/152;
  //setPos(posX-180,posY);
}
Yiyou::~Yiyou()
{
    Map::myptn[i][j]=nullptr;
    if(atkmovie)
        delete atkmovie;

}
void Yiyou::advance(int phase)
{
    if(!phase)
        return;
    //updata();
    if(bulletCounter<bulletCreateTime)
        ++bulletCounter;
    if(bulletCounter==bulletCreateTime)
    {
        bullet=new Bullet(QPointF(posX,posY));
    }
}
