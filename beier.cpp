#include "beier.h"

#include "enemy.h"
#include <QDebug>
#include <QMovie>
#include <QLabel>


Beier::Beier(int i,int j)
{
    attribute=WATER;

    this->attribute = WATER;
    this->i = i; this->j = j;
    this->width = 142;this->height=110;
    health = 700;
    hp=700,prepareTime=428,atkcounter=prepareTime;
    standTime=104; standcounter=0; coolTime=0;coolcounter=0;
    No=6;
    name="Beier";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(148+234*j-47-10,360-133+154*i-30);
}

Beier::~Beier()
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


bool Beier::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
//    if(other->type()==Enemy::Type)
//    {
//        qDebug()<<other->x()-x()<<"  "<<other->y()-y();
//    }
    return other->type()==Enemy::Type && other->x()-x()>120 && other->x()-x()<150;

}

void Beier::advance(int phase)
{
    if(!phase)
        return;
    if(hp>health)
        hp=health;
    update();
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
          if(atkcounter==428)
              enemy->hp-=atk;
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


void Beier::skill()
{

}
void Beier::evolution()
{

}
ABu::ABu(int i,int j):Beier(i,j)
{
    this->i = i; this->j = j;
    this->width = 105;this->height=92;
    health=1000;
    hp=1000,prepareTime=300,atkcounter=prepareTime;
    standTime=42; standcounter=0; coolTime=0;coolcounter=0;
    No=22;
    name="ABu";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(148+234*j-35,360-133+154*i-30);

}
ABu::~ABu()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        atkmovie =NULL;
        delete  atkmovie;
    }
}
void ABu::skill()
{

}
void ABu::evolution()
{

}

BaLaGui::BaLaGui(int i,int j):Beier(i,j)
{
    this->i = i; this->j = j;
    this->width = 120;this->height=101;
    health=1500;
    hp=1500,prepareTime=300,atkcounter=prepareTime;
    standTime=68; standcounter=0; coolTime=0;coolcounter=0;
    No=38;
    name="BaLaGui";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(148+234*j-35,360-140+154*i);
}
BaLaGui::~BaLaGui()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        atkmovie =NULL;
        delete  atkmovie;
    }
}
void BaLaGui::skill()
{

}
