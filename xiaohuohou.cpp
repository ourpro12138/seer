#include "xiaohuohou.h"
#include "enemy.h"
#include <QDebug>
#include <QMovie>
#include <QLabel>


Xiaohuohou::Xiaohuohou(int i,int j)
{
    this->i = i; this->j = j;
    this->No=9;
    this->width = 130;this->height=160;
    hp=100,atk=20,prepareTime=150,atkcounter=150;
    standTime=64; standcounter=0; coolTime=0;coolcounter=0;
    name="XiaoHuoHou";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(154+234*j-47-10,290-133+154*i-30);
}

Xiaohuohou::~Xiaohuohou()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        atkmovie =NULL;
        delete atkmovie;
    }
}


bool Xiaohuohou::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
//    if(other->type()==Enemy::Type)
//    {
//        qDebug()<<other->x()-x()<<"  "<<other->y()-y();
//    }

    return other->type()==Enemy::Type && other->x()-x()>100 && other->x()-x()<140
            && other->y()-y()>-60 && other->y()-y()<60;

    return other->type()==Enemy::Type && other->x()-x()>120 && other->x()-x()<150;


}

void Xiaohuohou::advance(int phase)
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
          if(atkcounter==150)
              enemy->hp-=atk;
         }
         if(atkcounter==prepareTime)
         {
            atkcounter=0;
            atkmovie = new QMovie(":/partner/resource/partner/attack_"+QString::number(this->No)+".gif");
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


void Xiaohuohou::skill()
{

}
void Xiaohuohou::evolution()
{
    LieHuoHou *yla = new LieHuoHou(i,j);
    Map::myptn[i][j] = yla;
    scene()->addItem(Map::myptn[i][j]);
    delete this;
    Map::myptn[i][j] = yla;
}
LieHuoHou::LieHuoHou(int i,int j):Xiaohuohou(i,j)
{
    this->i = i; this->j = j;
    this->No=25;
    this->width = 130;this->height=160;
    hp=350,atk=50,prepareTime=150,atkcounter=150;
    standTime=64; standcounter=0; coolTime=0;coolcounter=0;
    name="LieHuoHou";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(154+234*j-47-10,290-133+154*i-30);
}
void LieHuoHou::skill()
{

}
void LieHuoHou::evolution()
{
    Lieyanxingxing *yla = new Lieyanxingxing(i,j);
    Map::myptn[i][j] = yla;
    scene()->addItem(Map::myptn[i][j]);
    delete this;
    Map::myptn[i][j] = yla;
}
LieHuoHou::~LieHuoHou()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        atkmovie =NULL;
        delete atkmovie;
    }
}

Lieyanxingxing::Lieyanxingxing(int i,int j):Xiaohuohou(i,j)
{
    this->i = i; this->j = j;
    this->width = 128;this->height=150;
    hp=550,atk=65,prepareTime=150,atkcounter=150;
    standTime=64; standcounter=0; coolTime=0;coolcounter=0;
    name="Lieyanxingxing";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(154+234*j-47-10,290-133+154*i-30);
}
void Lieyanxingxing::skill()
{

}
Lieyanxingxing::~Lieyanxingxing()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        atkmovie =NULL;
        delete atkmovie;
    }
}
