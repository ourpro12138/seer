#include "xinke.h"
#include<QPointF>
#include "level.h"
Xinke::Xinke(int i,int j)
{

  attribute = ORDINARY;
  this->i = i; this->j=j;
  width = 149;height=135;health=300;
  hp=300;prepareTime=100;atkcounter=prepareTime;
  this->atk = 70;
  name="Xinke";skillname="星之光";
  this->price=50;
  this->price_ev=250;
  this->price_skill=10;
  atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
  Skill = new QMovie(":/partner/resource/partner/skill/"+name.toLower()+".gif");
  Skillplayer->setMovie(Skill);
  atkmovie->start();
  setPos(135+234*j-47,290-133+154*i);

}
Xinke::~Xinke()
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
void Xinke::advance(int phase)
{

    if(!phase)
        return;
    if(hp>health)
        hp=health;
    update();
    if(atkcounter<prepareTime)
        ++atkcounter;
    if(atkcounter==prepareTime)
    {
        atkcounter=0;
        bullet=new Bullet(i,j,43,43);
        bullet->ATK=this->atk;
        bullet->attribute=this->attribute;
        bullet->name = this->name.toLower();
        qDebug()<<bullet->name;
        scene()->addItem(bullet);
    }
    if(hp<=0)
        delete this;
}
//bool Yiyou::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
//{
//     Q_UNUSED(mode);
//    qDebug()<<other->y()<<y();

//    return other->type() == Enemy::Type && qAbs(other->y()-y())>-50&&qAbs(other->y()-y())<100&&qAbs(other->x()-x())>50;
//}
void Xinke::skill()
{
    parent->gametime->stop();
    qDebug()<<"时间暂停！";
    skillButton->hide();
    evolutionButton->hide();
    capsuleButton->hide();

    Skillplayer->show();
    Skill->start();
    this->price_skill=10;
    QTimer *time = new QTimer(parent);
    time->start(10);
    static  int count = 0;
    static int atb=0;
    connect(time,&QTimer::timeout,[=](){
        count++;
        if(count ==150)
        {
            delete time;
            qDebug()<<"技能释放完毕";
            parent->gametime->start(10);
            Skill->stop();
            Skillplayer->hide();
            switch(atb)
            {
            case 0:
                this->bullet->attribute=WATER;atb=1;this->name="xinkew";break;
            case 1:
                this->bullet->attribute=FIRE;atb=2;this->name="xinkef";break;
            case 2:
                this->bullet->attribute=GRASS;atb=3;this->name="xinkeg";break;
            case 3:
                this->bullet->attribute=ORDINARY;atb=0;this->name="xinke";break;
            }
            count=0;
        }
    });
}
void Xinke::evolution()
{
    Xinnasi *yla = new Xinnasi(i,j);
    Map::myptn[i][j] = yla;
    scene()->addItem(Map::myptn[i][j]);
    delete this;
    Map::myptn[i][j] = yla;
    Map::myptn[i][j]->evolutionButton->setEnabled(false);
}
Xinnasi::Xinnasi(int i,int j):Xinke(i,j)
{
    attribute = ORDINARY;
    this->i = i; this->j=j;
    width = 110;height=150;health=600;
    hp=600;prepareTime=100;atkcounter=prepareTime;
    this->atk = 150;
    name="Xinnasi";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    Skill = new QMovie(":/partner/resource/partner/skill/"+name.toLower()+".gif");
    Skillplayer->setMovie(Skill);
    atkmovie->start();
    setPos(135+234*j-47,290-133+154*i);
}
Xinnasi::~Xinnasi()
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
void Xinnasi::skill()
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
    static int atb=0;
    connect(time,&QTimer::timeout,[=](){
        count++;
        if(count ==150)
        {
            delete time;
            qDebug()<<"技能释放完毕";
            parent->gametime->start(10);
            Skill->stop();
            Skillplayer->hide();
            switch(atb)
            {
            case 0:
                this->bullet->attribute=WATER;atb=1;name="xinnasiw";break;
            case 1:
                this->bullet->attribute=FIRE;atb=2;name="xinnasif";break;
            case 2:
                this->bullet->attribute=GRASS;atb=3;name="xinnasig";break;
            case 3:
                this->bullet->attribute=ORDINARY;atb=0;name="xinnasi";break;
            }
            count=0;
        }
    });
}
