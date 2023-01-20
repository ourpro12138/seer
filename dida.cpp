#include "dida.h"
#include<QPointF>
#include "level.h"
Dida::Dida(int i,int j)
{

  this->attribute = FIRE;
  this->i = i; this->j=j;
  width = 154;height=114;health=300;
  hp=health;atkcounter=0;prepareTime=200;
  this->atk = 50;
  name="Dida";skillname="冒火";
  atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
  atkmovie->start();
  Skill = new QMovie(":/partner/resource/partner/skill/"+name.toLower()+".gif");
  Skillplayer->setMovie(Skill);
  setPos(154+234*j-47,320-133+154*i);

}
Dida::~Dida()
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
void Dida::advance(int phase)
{
    if(!phase)
        return;
    if(hp>health)
        hp=health;
    update();
    QList <QGraphicsItem *> items = collidingItems();
    if(!items.isEmpty())
    {
    if(atkcounter<prepareTime)
        ++atkcounter;
    if(atkcounter==prepareTime)
    {
        atkcounter=0;
        bullet=new Bullet(i,j,80,80);
        bullet->ATK=this->atk;
        bullet->attribute = this->attribute;
        bullet->name = this->name.toLower();
        scene()->addItem(bullet);
    }
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
void Dida::skill()
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
        if(count ==240)
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
void Dida::evolution()
{
    Dierke *bbh = new Dierke(i,j);
    Map::myptn[i][j] = bbh;
    scene()->addItem(Map::myptn[i][j]);
    delete this;
    Map::myptn[i][j] = bbh;
    Map::myptn[i][j]->evolutionButton->setEnabled(false);
}

Dierke::Dierke(int i,int j):Dida(i,j)
{
    health=500;
    this->i = i; this->j=j;
    width = 135;height=138;
    hp=500;atkcounter=0;prepareTime=100;
    skillname="凌厉";
    this->atk = 150;
    name="Dierke";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    Skill = new QMovie(":/partner/resource/partner/skill/"+name.toLower()+".gif");
    Skillplayer->setMovie(Skill);
    setPos(140+234*j-47,300-133+154*i);
}
void Dierke::skill()
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
        if(count ==240)
        {
            delete time;
            qDebug()<<"技能释放完毕";
            parent->gametime->start(10);
            Skill->stop();
            Skillplayer->hide();
            this->atk*=1.3;
            this->prepareTime*=0.8;
            this->atkcounter=prepareTime;
            count=0;
        }
    });
}
Dierke::~Dierke()
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

