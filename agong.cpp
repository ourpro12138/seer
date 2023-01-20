#include "agong.h"
#include "enemy.h"
#include <QDebug>
#include <QMovie>
#include <QLabel>


Agong::Agong(int i,int j)
{
    this->attribute = ORDINARY;
    this->i = i; this->j = j;
    this->width = 101;this->height=135;
    health =100;
    hp=100,atk=20,prepareTime=16,atkcounter=16;
    standTime=40; standcounter=0; coolTime=0;coolcounter=0;
    No=15;
    name="Agone";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(156+234*j-47,350-133+154*i-40);
    this->price=50;
    this->price_ev=100;
    this->price_skill=0;
}

Agong::~Agong()
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
    if(hp>health)
        hp=health;
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


void Agong::skill()
{

}
void Agong::evolution()
{
    BoBoGong *bbh = new BoBoGong(i,j);
    Map::myptn[i][j] = bbh;
    scene()->addItem(Map::myptn[i][j]);
    delete this;
    Map::myptn[i][j] = bbh;
    Cards::diamondTotal-=price_ev;
}

BoBoGong::BoBoGong(int i,int j):Agong(i,j)
{
    this->attribute = ORDINARY;
    this->i = i; this->j = j;
    this->width = 120;this->height=135;

    hp=100,atk=20,prepareTime=16,atkcounter=16;
    standTime=40; standcounter=0; coolTime=0;coolcounter=0;
    No=31;
    name="BoBoGong";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(156+234*j-47-20,350-133+154*i-55);
    this->price_ev=200;
    this->price_skill=0;
}
BoBoGong::~BoBoGong()
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
void BoBoGong::skill()
{

}
void BoBoGong::evolution()
{
    AoLiGong *bbh = new AoLiGong(i,j);
    Map::myptn[i][j] = bbh;
    scene()->addItem(Map::myptn[i][j]);
    delete this;
    Map::myptn[i][j] = bbh;
    Map::myptn[i][j]->evolutionButton->setEnabled(false);
    Cards::diamondTotal-=price_ev;
}

AoLiGong::AoLiGong(int i,int j):Agong(i,j)
{
    this->attribute = ORDINARY;
    this->i = i; this->j = j;
    this->width = 125;this->height=145;

    hp=100,atk=20,prepareTime=16,atkcounter=16;
    standTime=40; standcounter=0; coolTime=0;coolcounter=0;
    No=47;
    name="AoLiGong";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(156+234*j-47-20,350-133+154*i-60);
}
AoLiGong::~AoLiGong()
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
void AoLiGong::skill()
{

}
