#include "yiyou.h"
#include<QPointF>
Yiyou::Yiyou(int i,int j)
{

  this->i = i; this->j=j;
  width = 95;height=133;
  hp=300;atkcounter=100;prepareTime=100;
  this->atk = 20;
  name="Yiyou";
  this->skillname = "高压水枪";
  this->price_ev=100;
  this->price_skill=100;
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
    QList <QGraphicsItem *> items = collidingItems();
    if(!items.isEmpty())
    {
    if(atkcounter<prepareTime)
        ++atkcounter;
    if(atkcounter==prepareTime)
    {
        atkcounter=0;
        bullet=new Bullet(i,j,43,43);
        bullet->ATK=this->atk;
        bullet->name = this->name.toLower();
        scene()->addItem(bullet);
    }
    }
    if(hp<=0)
        delete this;
}
//bool Yiyou::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
//{
//     Q_UNUSED(mode);
//    qDebug()<<other->y()<<y();

//    return other->type() == Enemy::Type && qAbs(other->y()-y())>-50&&qAbs(other->y()-y())<100&&qAbs(other->x()-x())>50;
//}
void Yiyou::skill()
{

}
void Yiyou::evolution()
{


}
YouLiAn::YouLiAn(int i,int j):Yiyou(i,j)
{
    this->i = i; this->j=j;
    width = 95;height=133;
    hp=350;atkcounter=100;prepareTime=100;
    this->atk = 65;
    name="YouLiAn";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(154+234*j-50,290-133+154*i);

}
YouLiAn::~YouLiAn()
{
    Map::myptn[i][j]=nullptr;
    if(atkmovie)
        delete  atkmovie;
}




BaLuSi::BaLuSi(int i,int j):Yiyou(i,j)
{
    this->i = i; this->j=j;
    width = 95;height=133;
    hp=350;atkcounter=100;prepareTime=100;
    this->atk = 80;
    name="BaLuSi";
    atkmovie=new QMovie(":/partner/resource/partner/stand_balusi.gif");
    atkmovie->start();
    setPos(154+234*j-47,290-133+154*i);

}
BaLuSi::~BaLuSi()
{
    Map::myptn[i][j]=nullptr;
    if(atkmovie)
        delete  atkmovie;
}
