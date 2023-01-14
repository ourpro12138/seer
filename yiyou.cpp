#include "yiyou.h"
#include<QPointF>
Yiyou::Yiyou(int i,int j)
{

  this->i = i; this->j=j;
  width = 95;height=133;
  hp=300;bulletCounter=0;bulletCreateTime=40;
  name="Yiyou";
  atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
  atkmovie->start();
  setPos(154+234*j-47,290-133+154*i);

}
Yiyou::~Yiyou()
{
    Map::myptn[i][j]=NULL;
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
void Yiyou::skill()
{

}
void Yiyou::evolution()
{

}
