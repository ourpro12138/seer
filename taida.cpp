#include "taida.h"
#include "enemy.h"
#include <QDebug>
#include <QMovie>
#include <QLabel>
#include "level.h"

Taida::Taida(int i,int j)
{
    attribute=ORDINARY;
    this->i = i; this->j = j;
    this->width = 105;this->height=130;
    health=300;skillname="精准计算";
    hp=300,atk=70,prepareTime=220,atkcounter=prepareTime;
    standTime=64; standcounter=0; coolTime=0;coolcounter=0;
    No=16;
    name="Taida";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    Skill = new QMovie(":/partner/resource/partner/skill/"+name.toLower()+".gif");
    Skillplayer->setMovie(Skill);
    setPos(160+234*j-47-10,320-133+154*i-30);
}

Taida::~Taida()
{if(Map::myptn[i][j])
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


void Taida::skill()
{
    parent->gametime->stop();
    qDebug()<<"时间暂停！";
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
        {
            delete time;
            qDebug()<<"技能释放完毕";
            parent->gametime->start(10);
            Skill->stop();
            Skillplayer->hide();
            this->atk*=1.2;
            count=0;
        }
    });
}
void Taida::evolution()
{
    TaiLeSi *yla = new TaiLeSi(i,j);
    Map::myptn[i][j] = yla;
    scene()->addItem(Map::myptn[i][j]);
    delete this;
    Map::myptn[i][j] = yla;
    Map::myptn[i][j]->evolutionButton->setEnabled(false);
}
TaiLeSi::TaiLeSi(int i,int j):Taida(i,j)
{
    this->attribute = ORDINARY;
    this->i = i; this->j = j;
    this->width = 130;this->height=145;
    health=600;skillname="泰勒斯猜想";
    hp=health,atk=200,prepareTime=200,atkcounter=prepareTime;
    standTime=64; standcounter=0; coolTime=0;coolcounter=0;
    No=32;
    name="TaiLeSi";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    Skill = new QMovie(":/partner/resource/partner/skill/"+name.toLower()+".gif");
    Skillplayer->setMovie(Skill);
    setPos(160+234*j-47-20,320-133+154*i-25);
}
TaiLeSi::~TaiLeSi()
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
void TaiLeSi::skill()
{
    parent->gametime->stop();
    qDebug()<<"时间暂停！";
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
        {
            delete time;
            qDebug()<<"技能释放完毕";
            parent->gametime->start(10);
            Skill->stop();
            Skillplayer->hide();
            this->atk*=1.4;
            this->prepareTime-=40;
            this->atkcounter=prepareTime;
            count=0;
        }
    });
}
