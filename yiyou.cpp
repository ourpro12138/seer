#include "yiyou.h"
#include<QPointF>
Yiyou::Yiyou(int i,int j)
{

    this->i = i; this->j=j;
  width = 95;height=133;
  hp=300;bulletCounter=0;bulletCreateTime=40;
  name="Yiyou";
  atkmovie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_yiyou.gif");
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
        bulletCounter=0;

            qDebug()<<"水单";
        bullet=new Bullet(i,j);
        scene()->addItem(bullet);

    }
    if(hp<=0)
        delete this;
}
//bool Yiyou::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
//{
//     Q_UNUSED(mode);
//    return other->type() == Enemy::Type && qFuzzyCompare(other->y(), y())&&qAbs(other->x()-x())<800;
//}
void Yiyou::skill()
{

}
void Yiyou::evolution()
{

}

