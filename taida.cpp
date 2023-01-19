#include "taida.h"
#include "enemy.h"
#include <QDebug>
#include <QMovie>
#include <QLabel>


Taida::Taida(int i,int j)
{
    attribute=ORDINARY;
    this->attribute = ORDINARY;
    this->i = i; this->j = j;
    this->width = 105;this->height=130;

    hp=200,atk=20,prepareTime=220,atkcounter=220;

    hp=100,atk=20,prepareTime=220,atkcounter=prepareTime;

    standTime=64; standcounter=0; coolTime=0;coolcounter=0;
    name="Taida";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(160+234*j-47-10,320-133+154*i-30);
}

Taida::~Taida()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        atkmovie =NULL;
        delete atkmovie;
    }
}


bool Taida::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
//    if(other->type()==Enemy::Type)
//    {
//        qDebug()<<other->x()-x()<<"  "<<other->y()-y();
//    }
    return other->type()==Enemy::Type && other->x()-x()>120 && other->x()-x()<150;

}

void Taida::advance(int phase)
{
    if(!phase)
        return;
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


void Taida::skill()
{

}
void Taida::evolution()
{

}
TaiLeSi::TaiLeSi(int i,int j):Taida(i,j)
{
    attribute=ORDINARY;
    this->attribute = ORDINARY;
    this->i = i; this->j = j;
    this->width = 130;this->height=145;

    hp=100,atk=20,prepareTime=200,atkcounter=prepareTime;
    standTime=64; standcounter=0; coolTime=0;coolcounter=0;
    name="TaiLeSi";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(160+234*j-47-20,320-133+154*i-25);
}
TaiLeSi::~TaiLeSi()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        atkmovie =NULL;
        delete  atkmovie;
    }
}
void TaiLeSi::skill()
{

}
