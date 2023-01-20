#include "xiaohuohou.h"
#include "enemy.h"
#include <QDebug>
#include <QMovie>
#include <QLabel>
#include "level.h"

Xiaohuohou::Xiaohuohou(int i,int j)
{
    this->i = i; this->j = j;
    this->No=9;
    this->width = 130;this->height=160;health=500;
    hp=500,atk=20,prepareTime=150,atkcounter=prepareTime;
    standTime=64; standcounter=0; coolTime=0;coolcounter=0;
    name="XiaoHuoHou"; skillname="音速拳";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    Skill = new QMovie(":/partner/resource/partner/skill/"+name.toLower()+".gif");
    Skillplayer->setMovie(Skill);
    atkmovie->start();
    setPos(154+234*j-47-10,290-133+154*i-30);
}

Xiaohuohou::~Xiaohuohou()
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


bool Xiaohuohou::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
//    if(other->type()==Enemy::Type)
//    {
//        qDebug()<<other->x()-x()<<"  "<<other->y()-y();
//    }

    return other->type()==Enemy::Type && other->x()-x()>100 && other->x()-x()<140
            && other->y()-y()>-60 && other->y()-y()<60;



}

void Xiaohuohou::advance(int phase)
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
    parent->gametime->stop();
    skillButton->hide();
    evolutionButton->hide();
    capsuleButton->hide();

    Skillplayer->show();
    Skill->start();

    QTimer *time = new QTimer(parent);
    time->start(10);
    static  int count = 0;
    connect(time,&QTimer::timeout,[=](){
        count++;
        if(count ==200)
        {   QList <QGraphicsItem *> items = collidingItems();
            if(!items.isEmpty())
            {Enemy *enemy=qgraphicsitem_cast <Enemy *> (items[qrand()%items.size()]);
            int temp = this->atk;
            this->atk=300;
            enemy->hp-=Damage(this,enemy);
            this->atk=temp;}
            delete time;
            parent->gametime->start(10);
            Skill->stop();
            Skillplayer->hide();
            count=0;
        }
    });
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
    this->width = 101;this->height=140;health=650;
    hp=650,atk=50,prepareTime=150,atkcounter=prepareTime;
    standTime=28; standcounter=0; coolTime=0;coolcounter=0;
    name="LieHuoHou";this->skillname="火焰车";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    Skill = new QMovie(":/partner/resource/partner/skill/"+name.toLower()+".gif");
    Skillplayer->setMovie(Skill);
    setPos(154+234*j-47,290-133+154*i);
}
void LieHuoHou::skill()
{
    parent->gametime->stop();
    skillButton->hide();
    evolutionButton->hide();
    capsuleButton->hide();

    Skillplayer->show();
    Skill->start();

    QTimer *time = new QTimer(parent);
    time->start(10);
    static  int count = 0;
    connect(time,&QTimer::timeout,[=](){
        count++;
        if(count ==208)
        {   QList <QGraphicsItem *> items = collidingItems();
            if(!items.isEmpty())
            {Enemy *enemy=qgraphicsitem_cast <Enemy *> (items[qrand()%items.size()]);
            int temp = this->atk;
            this->atk=500;
            enemy->hp-=Damage(this,enemy);
            this->atk=temp;}
            delete time;
            parent->gametime->start(10);
            Skill->stop();
            Skillplayer->hide();
            count=0;
        }
    });
}
void LieHuoHou::evolution()
{
    Lieyanxingxing *yla = new Lieyanxingxing(i,j);
    Map::myptn[i][j] = yla;
    scene()->addItem(Map::myptn[i][j]);
    delete this;
    Map::myptn[i][j] = yla;
    Map::myptn[i][j]->evolutionButton->setEnabled(false);
}
LieHuoHou::~LieHuoHou()
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

Lieyanxingxing::Lieyanxingxing(int i,int j):Xiaohuohou(i,j)
{

    this->i = i; this->j = j;
    this->width = 128;this->height=150;health=800;
    hp=800,atk=65,prepareTime=150,atkcounter=prepareTime;
    standTime=32; standcounter=0; coolTime=0;coolcounter=0;
    No=41;
    name="Lieyanxingxing";skillname="烈焰冲撞";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    Skill = new QMovie(":/partner/resource/partner/skill/"+name.toLower()+".gif");
    Skillplayer->setMovie(Skill);
    setPos(154+234*j-40,290-130+154*i);
}
void Lieyanxingxing::skill()
{
    parent->gametime->stop();
    skillButton->hide();
    evolutionButton->hide();
    capsuleButton->hide();

    Skillplayer->show();
    Skill->start();

    QTimer *time = new QTimer(parent);
    time->start(10);
    static  int count = 0;
    connect(time,&QTimer::timeout,[=](){
        count++;
        if(count ==288)
        {   QList <QGraphicsItem *> items = collidingItems();
            if(!items.isEmpty())
            {Enemy *enemy=qgraphicsitem_cast <Enemy *> (items[qrand()%items.size()]);
            int temp = this->atk;
            this->atk=600;
            enemy->hp-=Damage(this,enemy);
            this->atk=temp;}
            delete time;
            parent->gametime->start(10);
            Skill->stop();
            Skillplayer->hide();
            count=0;
        }
    });
}
Lieyanxingxing::~Lieyanxingxing()
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
