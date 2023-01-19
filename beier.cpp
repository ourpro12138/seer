#include "beier.h"

#include "enemy.h"
#include <QDebug>
#include <QMovie>
#include <QLabel>


Beier::Beier(int i,int j)
{
    this->attribute = WATER;
    this->i = i; this->j = j;
    this->width = 142;this->height=110;

    hp=100,prepareTime=428,atkcounter=428;
    standTime=104; standcounter=0; coolTime=0;coolcounter=0;
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
    update();
    QList <QGraphicsItem *> items = collidingItems();
    if(hp<=0)
    {
        delete this;
        return;
    }
//    if(hp>0)
//    {
//        if(!items.isEmpty())
//        {
//            Enemy *enemy=qgraphicsitem_cast <Enemy *> (items[qrand()%items.size()]);
//         if(atkcounter<prepareTime)
//         {
//          atkcounter++;
//          if(atkcounter==428)
//              enemy->hp-=atk;
//         }
//         if(atkcounter==prepareTime)
//         {
//            atkcounter=0;
//            atkmovie = new QMovie(":/partner/resource/partner/attack_beier.gif");
//            atkmovie->start();
//         }
//        }
//        else
//        {
//            if(standcounter<standTime)
//            {
//             standcounter++;
//            }
//            if(standcounter==standTime)
//            {
//               standcounter=0;
//               atkmovie = new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
//               atkmovie->start();
//            }
//        }
//    }
}


void Beier::skill()
{

}
void Beier::evolution()
{

}

