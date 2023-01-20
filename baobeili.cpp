#include "baobeili.h"
#include<QPointF>
Baobeili::Baobeili(int i,int j)
{
    attribute=WATER;

   this->attribute = WATER;
  this->i = i; this->j=j;
  width = 108;height=87;health=300;
  hp=300;atkcounter=0;prepareTime=100;
  this->atk = 50;
  No=8;
  name="Baobeili";
  atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
  atkmovie->start();
  setPos(154+234*j-47,320-133+154*i);

}
Baobeili::~Baobeili()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        delete atkmovie;
        atkmovie=NULL;
    }
    if(Skill)
    {
        delete Skill;
    Skill=NULL;
    }

}
void Baobeili::advance(int phase)
{

    if(!phase)
        return;
    if(hp>health)
        hp=health;
    update();
    QList <QGraphicsItem *> items = collidingItems();
    if(!items.isEmpty())
    {
    if(atkcounter<prepareTime)
        ++atkcounter;
    if(atkcounter==prepareTime)
    {
        atkcounter=0;
        bullet=new Bullet(i,j,80,80);
        bullet->ATK=this->atk;
        bullet->attribute=WATER;
        bullet->name = this->name.toLower();
        scene()->addItem(bullet);
    }
    }
    if(hp<=0)
        delete this;
}
//bool Baobeili::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
//{
//     Q_UNUSED(mode);
//    qDebug()<<other->y()<<y();

//    return other->type() == Enemy::Type && qAbs(other->y()-y())>-50&&qAbs(other->y()-y())<100&&qAbs(other->x()-x())>50;
//}
void Baobeili::skill()
{

}
void Baobeili::evolution()
{

}
YuanGuYuLong::YuanGuYuLong(int i,int j):Baobeili(i,j)
{
    attribute=WATER;
    this->i = i; this->j=j;
    width = 185;height=170;
    hp=300;atkcounter=0;prepareTime=90;
    this->atk = 60;
    No=24;
    name="YuanGuYuLong";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(154+234*j-60-10-10-15,320-133-30-5+154*i);
}
YuanGuYuLong::~YuanGuYuLong()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        delete atkmovie;
        atkmovie=NULL;
    }
    if(Skill)
    {
        delete Skill;
    Skill=NULL;
    }
}
void YuanGuYuLong::skill()
{

}
void YuanGuYuLong::evolution()
{

}

