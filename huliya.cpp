#include "huliya.h"
#include<QPointF>

Huliya::Huliya(int i,int j)
{

   attribute = FIRE;
  this->i = i; this->j=j;
  width = 121;height=135;health=300;
  hp=300;atkcounter=0;prepareTime=200;
  this->atk = 75;
  name="Huliya";
  atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
  atkmovie->start();
  setPos(154+234*j-47,290-133+154*i);
  this->price=100;
  this->price_ev=300;
  this->price_skill=0;
}
Huliya::~Huliya()
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
    }

}
void Huliya::advance(int phase)
{
    if(!phase)
        return;
    update();
    QList <QGraphicsItem *> items = collidingItems();
    if(hp>health)
        hp=health;
    if(!items.isEmpty())
    {
    if(atkcounter<prepareTime)
        ++atkcounter;
    if(atkcounter==prepareTime)
    {
        atkcounter=0;
        bullet=new Bullet(i,j,80,50);
        bullet->ATK=this->atk;
        bullet->attribute = this->attribute;
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
    Liaosi *bbh = new Liaosi(i,j);
    Map::myptn[i][j] = bbh;
    scene()->addItem(Map::myptn[i][j]);
    delete this;
    Map::myptn[i][j] = bbh;
    Map::myptn[i][j]->evolutionButton->setEnabled(false);
    Cards::diamondTotal-=price_ev;
}
void Liaosi::skill()
{

}
Liaosi::Liaosi(int i,int j):Huliya(i,j)
{
    this->i = i; this->j=j;
    width = 116;height=140;health=500;
    hp=500;atkcounter=0;prepareTime=150;
    this->atk = 200;
    name="Liaosi";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(140+234*j-47,300-133+154*i);
    this->price_skill=0;
}

Liaosi::~Liaosi()
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

    }
}

