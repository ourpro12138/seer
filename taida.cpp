#include "taida.h"
#include "enemy.h"
#include <QDebug>
#include <QMovie>
#include <QLabel>


Taida::Taida(int i,int j)
{
    this->i = i; this->j = j;
    this->width = 105;this->height=130;

    hp=100,atk=20,prepareTime=220,atkcounter=220;
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
          if(atkcounter==220)
              enemy->hp-=atk;
         }
         if(atkcounter==prepareTime)
         {
            atkcounter=0;
            atkmovie = new QMovie(":/partner/resource/partner/attack_taida.gif");
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