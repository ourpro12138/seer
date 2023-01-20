#include "jier.h"
#include<QPointF>

Jier::Jier(int i,int j)
{

  attribute = FIRE;
  this->i = i; this->j=j;
  width = 108;height=130;health=300;
  hp=300;atkcounter=0;prepareTime=300;
  this->atk = 50;
  name="Jier";
  atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
  atkmovie->start();
    Skill = new QMovie(":/partner/resource/partner/skill/"+name.toLower()+".gif");
  setPos(145+234*j-47,300-133+154*i);

}
Jier::~Jier()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        atkmovie =NULL;
        delete atkmovie;
    }
    if(Skill)
        delete Skill;

}
void Jier::advance(int phase)
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
        bullet->attribute = this->attribute;
        bullet->name = this->name.toLower();
        scene()->addItem(bullet);
    }
    }
    if(hp<=0)
        delete this;
}
//bool Jier::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
//{
//     Q_UNUSED(mode);
//    qDebug()<<other->y()<<y();

//    return other->type() == Enemy::Type && qAbs(other->y()-y())>-50&&qAbs(other->y()-y())<100&&qAbs(other->x()-x())>50;
//}
void Jier::skill()
{

}
void Jier::evolution()
{
    Linuo *bbh = new Linuo(i,j);
    Map::myptn[i][j] = bbh;
    scene()->addItem(Map::myptn[i][j]);
    delete this;
    Map::myptn[i][j] = bbh;
    Cards::diamondTotal-=price_ev;
}
Linuo::Linuo(int i,int j):Jier(i,j)
{
    this->i = i; this->j=j;
    width = 134;height=138;health=500;
    hp=500;atkcounter=0;prepareTime=200;
    this->atk = 50;
    name="Linuo";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
      Skill = new QMovie(":/partner/resource/partner/skill/"+name.toLower()+".gif");
    setPos(140+234*j-47,300-133+154*i);
}
void Linuo::evolution()
{
    Luojilasi *bbh = new Luojilasi(i,j);
    Map::myptn[i][j] = bbh;
    scene()->addItem(Map::myptn[i][j]);
    delete this;
    Map::myptn[i][j] = bbh;
    this->skillButton->setEnabled(false);
    Cards::diamondTotal-=price_ev;
}
void Linuo::skill()
{

}
Linuo::~Linuo()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        atkmovie =NULL;
        delete atkmovie;
    }
}
void Luojilasi::skill()
{

}
Luojilasi::Luojilasi(int i,int j):Jier(i,j)
{
    this->i = i; this->j=j;health=500;
    width = 114;height=140;
    hp=500;atkcounter=0;prepareTime=100;
    this->atk = 50;
    name="Luojilasi";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
      Skill = new QMovie(":/partner/resource/partner/skill/"+name.toLower()+".gif");
    setPos(140+234*j-47,300-133+154*i);
}

Luojilasi::~Luojilasi()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        atkmovie =NULL;
        delete atkmovie;
    }
}

