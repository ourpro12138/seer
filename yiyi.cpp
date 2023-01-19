#include "yiyi.h"

#include<QPointF>
Yiyi::Yiyi(int i,int j)
{
    attribute = GRASS;
  this->i = i; this->j=j;
  width = 83;height=145;health=300;
  hp=300;atkcounter=0;prepareTime=200;
  this->atk = 50;
  No=4;
  name="Yiyi";
  atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
  atkmovie->start();
  setPos(154+234*j-47,290-133+154*i);

}
Yiyi::~Yiyi()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        atkmovie =NULL;
        delete atkmovie;
    }

}
void Yiyi::advance(int phase)
{
    if(!phase)
        return;
    update();
    if(hp>health)
        hp=health;
    QList <QGraphicsItem *> items = collidingItems();
    if(!items.isEmpty())
    {
    if(atkcounter<prepareTime)
        ++atkcounter;
    if(atkcounter==prepareTime)
    {
        atkcounter=0;
        bullet=new Bullet(i,j,100,100);
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
void Yiyi::skill()
{

}
void Yiyi::evolution()
{
    YiDingSi *yla = new YiDingSi(i,j);
    Map::myptn[i][j] = yla;
    scene()->addItem(Map::myptn[i][j]);
    delete this;
    Map::myptn[i][j] = yla;
    Map::myptn[i][j] = nullptr;
}


YiDingSi::YiDingSi(int i,int j): Yiyi(i,j)
{
    this->i = i; this->j=j;
    width = 83;height=145;health=350;
    hp=350;atkcounter=0;prepareTime=200;
    this->atk = 60;
    No=20;
    name="YiDingSi";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(154+234*j-47,290-125+154*i);
}
void YiDingSi::skill()
{

}
void YiDingSi::evolution()
{
    YiKaLaiEn *yla = new YiKaLaiEn(i,j);
    Map::myptn[i][j] = yla;
    scene()->addItem(Map::myptn[i][j]);
    delete this;
    Map::myptn[i][j] = yla;
    Map::myptn[i][j] = nullptr;
    Map::myptn[i][j]->skillButton->setEnabled(false);
}
YiDingSi::~YiDingSi()
{
    Map::myptn[i][j]=NULL;
    if(atkmovie)
        delete atkmovie;
}

YiKaLaiEn::YiKaLaiEn(int i,int j):Yiyi(i,j)
{
    this->i = i; this->j=j;
    width = 83;height=145;health=400;
    hp=400;atkcounter=0;prepareTime=200;
    this->atk = 70;
    No=36;
    name="YiKaLaiEn";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(154+234*j-47,290-133+154*i);
}
void YiKaLaiEn::skill()
{

}
YiKaLaiEn::~YiKaLaiEn()
{
    if(atkmovie)
        delete  atkmovie;
}
