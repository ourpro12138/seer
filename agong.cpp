#include "agong.h"
#include "enemy.h"
#include <QDebug>
#include <QMovie>
#include <QLabel>


Agong::Agong(int i,int j)
{
    this->i = i; this->j = j;
    this->width = 101;this->height=135;

    hp=100,atk=20,prepareTime=16,atkcounter=16;
    standTime=40; standcounter=0; coolTime=0;coolcounter=0;
    name="Agone";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(156+234*j-47-10,350-133+154*i-30);
}

Agong::~Agong()
{
    Map::myptn[i][j]=nullptr;
    if(atkmovie)
        delete atkmovie;
}


bool Agong::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
//    if(other->type()==Enemy::Type)
//    {
//        qDebug()<<other->x()-x()<<"  "<<other->y()-y();
//    }
    return other->type()==Enemy::Type && other->x()-x()>120 && other->x()-x()<150;

}

void Agong::advance(int phase)
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
          if(atkcounter==16)
              enemy->hp-=atk;
         }
         if(atkcounter==prepareTime)
         {
            atkcounter=0;
            atkmovie = new QMovie(":/partner/resource/partner/attack_agone.gif");
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


void Agong::skill()
{

}
void Agong::evolution()
{

}
