#include "yiyou.h"
#include<QPointF>
Yiyou::Yiyou(int i,int j)
{
  hp=300;bulletCounter=0;bulletCreateTime=40;
  name="Yiyou";
  atkmovie=new QMovie(":/partner/resource/partner/stand_yiyou.gif");
  atkmovie->start();
  setPos(i*230+170,j*152+121);
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
    update();
    if(bulletCounter<bulletCreateTime)
        ++bulletCounter;
    if(bulletCounter==bulletCreateTime)
    {
        bullet=new Bullet(i*230+170,j*152+121);
        scene()->addItem(bullet);
        bulletCounter=0;
    }
    if(hp<=0)
        delete this;
}
