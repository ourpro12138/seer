#include "yiyou.h"
#include<QPointF>
#include "level.h"
Yiyou::Yiyou(int i,int j)
{

   attribute = WATER;
  qDebug()<<"伊优构造函数调用";
  this->i = i; this->j=j;
  width = 95;height=133;health=200;
  hp=200;atkcounter=prepareTime;prepareTime=300;
  No=5;
  this->atk = 20;
  name="Yiyou";
  this->skillname = "玩水";
  this->price_ev=100;
  this->price_skill=100;
  atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
  Skill = new QMovie(":/partner/resource/partner/skill/"+name.toLower()+".gif");
  Skillplayer->setMovie(Skill);
  atkmovie->start();
  setPos(154+234*j-47,290-133+154*i);


}
Yiyou::~Yiyou()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        atkmovie =NULL;
        delete atkmovie;
    }
    if(Skill)
        delete Skill;

}
void Yiyou::advance(int phase)
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
        bullet->attribute = this->attribute;
        bullet->name = this->name.toLower();
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
void Yiyou::skill()
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
        if(count ==300)
        {
            delete time;
            qDebug()<<"技能释放完毕";
            parent->gametime->start(10);
            Skill->stop();
            Skillplayer->hide();
            this->prepareTime*=0.8;
            this->atkcounter = prepareTime;
            count=0;
        }
    });
}
void Yiyou::evolution()
{
    YouLiAn *yla = new YouLiAn(i,j);
    Map::myptn[i][j] = yla;
    scene()->addItem(Map::myptn[i][j]);
    delete this;
    Map::myptn[i][j] = yla;
}

YouLiAn::YouLiAn(int i,int j):Yiyou(i,j)
{
    this->i = i; this->j=j;
    width = 95;height=133;health=350;
    hp=350;prepareTime=300;atkcounter=prepareTime;
    this->atk = 65;
    No=21;
    name="YouLiAn";
    skillname = "潮汐";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    Skill = new QMovie(":/partner/resource/partner/skill/"+name.toLower()+".gif");
    Skillplayer->setMovie(Skill);
    atkmovie->start();
    setPos(154+234*j-50,290-133+154*i);
    qDebug()<<"尤里安构造函数调用";


}
YouLiAn::~YouLiAn()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        atkmovie =NULL;
        delete atkmovie;
    }
    qDebug()<<"尤里安析造函数调用";
}

void YouLiAn::evolution()
{
    BaLuSi *yla = new BaLuSi(i,j);
    Map::myptn[i][j] = yla;
    scene()->addItem(Map::myptn[i][j]);
    delete this;
    Map::myptn[i][j] = yla;
    Map::myptn[i][j]->evolutionButton->setEnabled(false);
}

void YouLiAn::skill()
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
            this->prepareTime*=0.75;
            this->atkcounter = prepareTime;
            count=0;
        }
    });
}
BaLuSi::BaLuSi(int i,int j):Yiyou(i,j)
{
    this->i = i; this->j=j;
    health=500;
    skillname = "剑舞";
    width = 150;height=156;
    hp=500;prepareTime=200;atkcounter=prepareTime;
    this->atk = 80;
    No=37;
    name="BaLuSi";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    Skill = new QMovie(":/partner/resource/partner/skill/"+name.toLower()+".gif");
    Skillplayer->setMovie(Skill);
    setPos(154+234*j-70,290-133+5+154*i);

}
void BaLuSi::skill()
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
            this->prepareTime*=0.7;
            this->atkcounter = prepareTime;
            count=0;
        }
    });
}
BaLuSi::~BaLuSi()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        atkmovie =NULL;
        delete atkmovie;
    }
}
