#include "dida.h"
#include<QPointF>

Dida::Dida(int i,int j)
{

  this->i = i; this->j=j;
  width = 154;height=114;
  hp=300;atkcounter=0;prepareTime=200;
  this->atk = 50;
  name="Dida";
  atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
  atkmovie->start();
  setPos(154+234*j-47,320-133+154*i);

}
Dida::~Dida()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        atkmovie =NULL;
        delete atkmovie;
    }
}
void Dida::advance(int phase)
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
        bullet=new Bullet(i,j,80,80);
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
void Dida::skill()
{

}
void Dida::evolution()
{
    Dierke *bbh = new Dierke(i,j);
    Map::myptn[i][j] = bbh;
    scene()->addItem(Map::myptn[i][j]);
    delete this;
    Map::myptn[i][j] = bbh;

    this->skillButton->setEnabled(false);
}

Dierke::Dierke(int i,int j):Dida(i,j)
{
    this->i = i; this->j=j;
    width = 135;height=138;
    hp=500;atkcounter=0;prepareTime=100;
    this->atk = 50;
    name="Dierke";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(140+234*j-47,300-133+154*i);
}
void Dierke::skill()
{

}
Dierke::~Dierke()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        atkmovie =NULL;
        delete atkmovie;
    }
}

