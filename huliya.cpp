#include "huliya.h"
#include<QPointF>

Huliya::Huliya(int i,int j)
{

  this->i = i; this->j=j;
  width = 121;height=135;
  hp=300;atkcounter=0;prepareTime=100;
  this->atk = 50;
  name="Huliya";
  atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
  atkmovie->start();
  setPos(154+234*j-47,290-133+154*i);

}
Huliya::~Huliya()
{
    Map::myptn[i][j]=NULL;
    if(atkmovie)
        delete atkmovie;

}
void Huliya::advance(int phase)
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
        bullet=new Bullet(i,j,80,50);
        bullet->ATK=this->atk;
        bullet->name = this->name.toLower();
        scene()->addItem(bullet);
    }
    }
    if(hp<=0)
        delete this;
}
//bool Huliya::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
//{
//     Q_UNUSED(mode);
//    qDebug()<<other->y()<<y();

//    return other->type() == Enemy::Type && qAbs(other->y()-y())>-50&&qAbs(other->y()-y())<100&&qAbs(other->x()-x())>50;
//}
void Huliya::skill()
{

}
void Huliya::evolution()
{

}
Liaosi::Liaosi(int i,int j):Huliya(i,j)
{
    this->i = i; this->j=j;
    width = 116;height=140;
    hp=500;atkcounter=0;prepareTime=100;
    this->atk = 50;
    name="Liaosi";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(140+234*j-47,300-133+154*i);
}

Liaosi::~Liaosi()
{
    Map::myptn[i][j]=NULL;
    if(atkmovie)
        delete atkmovie;
}

