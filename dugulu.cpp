#include "dugulu.h"
#include "enemy.h"
#include <QDebug>
#include <QMovie>
#include <QLabel>


DuGuLu::DuGuLu(int i,int j)
{
    this->attribute = ORDINARY;
    this->i = i; this->j = j;
    this->width = 136;this->height=111;health=100;
    hp=100,atk=1000,prepareTime=150,atkcounter=prepareTime;
    standTime=64; standcounter=0; coolTime=0;coolcounter=0;
    name="dugulu";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(154+234*j-47-10,290-133+154*i+30);
}

DuGuLu::~DuGuLu()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        atkmovie =NULL;
        delete atkmovie;
    }
}

bool DuGuLu::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
     Q_UNUSED(mode);
//    if(other->type()==Enemy::Type)
//    {
//        qDebug()<<other->x()-x()<<"  "<<other->y()-y();
//    }
    return other->type()==Enemy::Type && other->x()-x()>95 && other->x()-x()<200
            && other->y()-y()>-60 && other->y()-y()<60;
}

void DuGuLu::advance(int phase)
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
          if(atkcounter==150)
              enemy->hp-=Damage(this,enemy);
         }
         if(atkcounter==prepareTime)
         {

            atkcounter=0;
            atkmovie = new QMovie(":/partner/resource/partner/attack_dugulu.gif");
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


void DuGuLu::skill()
{

}
void DuGuLu::evolution()
{

}
