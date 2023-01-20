#include "xiaodouya.h"

#include "enemy.h"
#include <QDebug>
#include <QMovie>
#include <QLabel>


Xiaodouya::Xiaodouya(int i,int j)
{
    this->attribute = GRASS;
    this->i = i; this->j = j;
    this->width = 111;this->height=130;
    this->width = 121;this->height=140;
    health=100;
    hp=100,atk=20,prepareTime=96,atkcounter=prepareTime;
    standTime=40; standcounter=0; coolTime=0;coolcounter=0;
    name="Xiaodouya";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(140+234*j-47-10,320-133+154*i-30);
}

Xiaodouya::~Xiaodouya()
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


bool Xiaodouya::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
//    if(other->type()==Enemy::Type)
//    {
//        qDebug()<<other->x()-x()<<"  "<<other->y()-y();
//    }
    return other->type()==Enemy::Type && other->x()-x()>120 && other->x()-x()<150;

}

void Xiaodouya::advance(int phase)
{
    if(!phase)
        return;
    update();
    if(hp>health)
        hp=health;
    QList <QGraphicsItem *> items = collidingItems();
    if(hp<=0)
    {
        delete this;
        return;
    }
    if(hp>0)
    {
        if(!items.isEmpty())
        {
            Enemy *enemy=qgraphicsitem_cast <Enemy *> (items[qrand()%items.size()]);
         if(atkcounter<prepareTime)
         {
          atkcounter++;
          if(atkcounter==prepareTime)
              enemy->hp-=Damage(this,enemy);
         }
         if(atkcounter==prepareTime)
         {
            atkcounter=0;
            atkmovie = new QMovie(":/partner/resource/partner/attack_"+name.toLower()+".gif");
            atkmovie->start();
         }
        }
        else
        {
            if(standcounter<standTime)
            {
             standcounter++;
            }
            if(standcounter==standTime)
            {
               standcounter=0;
               atkmovie = new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
               atkmovie->start();
            }
        }
    }
}


void Xiaodouya::skill()
{

}
void Xiaodouya::evolution()
{

}

DingDing::DingDing(int i,int j):Xiaodouya(i,j)
{
    this->attribute = GRASS;
    this->i = i; this->j = j;
    this->width = 85;this->height=140;

    hp=100,atk=20,prepareTime=220,atkcounter=prepareTime;
    standTime=42; standcounter=0; coolTime=0;coolcounter=0;
    name="DingDing";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(140+234*j-25,320-133+154*i-40);
}
DingDing::~DingDing()
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
void DingDing::skill()
{

}
void DingDing::evolution()
{

}
MoHuaXianZi::MoHuaXianZi(int i,int j):Xiaodouya(i,j)
{
    this->attribute = GRASS;
    this->i = i; this->j = j;
    this->width = 110;this->height=115;

    hp=100,atk=20,prepareTime=220,atkcounter=prepareTime;
    standTime=42; standcounter=0; coolTime=0;coolcounter=0;
    name="MoHuaXianZi";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(140+234*j-30,320-133+154*i-10);
}
MoHuaXianZi::~MoHuaXianZi()
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
void MoHuaXianZi::skill()
{

}
