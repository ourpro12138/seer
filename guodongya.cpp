#include "guodongya.h"
#include "level.h"
Guodongya::Guodongya(int i,int j)
{
    this->attribute = WATER;
    this->i = i; this->j = j;
    hp=500,atk=4;
    this->width = 108;this->height=120;
    hp=300,atk=4;
    this->No=7;skillname="水之波动";
    this->width = 118;this->height=130;health=500;
    standTime =80; standcounter=standTime;
    prepareTime = 240; atkcounter=prepareTime;
    coolTime = 600; coolcounter=coolTime;
    name="Guodongya";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
      setPos(154+234*j-60,290-125+154*i);
    Skill = new QMovie(":/partner/resource/partner/skill/"+name.toLower()+".gif");
    Skillplayer->setMovie(Skill);
      setPos(154+234*j-47,290-133+154*i);
      this->price=50;
      this->price_ev=80;
      this->price_skill=80;
}
Guodongya::~Guodongya()
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
//QRectF Bubuzhongzi::boundingRect() const
//{
//     return QRectF(180, 0, 100, 70);
//}


void Guodongya::advance(int phase)
{
    if(!phase)
        return;
    update();
    if(hp>health)
        hp=health;
    if(Map::myptn[i][j+1])
    {
        if(coolcounter<coolTime)
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
            coolcounter++;
        }
        if(coolcounter==coolTime)
        {
            if(atkcounter<prepareTime)
            {
                atkcounter++;
                if(atkcounter==prepareTime)
                {
                    if(Map::myptn[i][j+1]->prepareTime-Damage(this,Map::myptn[i][j+1])>0)
                    {
                        Map::myptn[i][j+1]->prepareTime-=atk;
                        Map::myptn[i][j+1]->atkcounter=Map::myptn[i][j+1]->prepareTime;
                    }

                    qDebug()<<atkcounter;
                    standcounter=standTime;
                    coolcounter=0;
                    return;
                }
            }
            if(atkcounter==prepareTime)
            {
                qDebug()<<"atkcounter"<<atkcounter<<" coolcounter"<<coolcounter<<" standcounter"<<standcounter;
                atkcounter=0;
                atkmovie = new QMovie(":/partner/resource/partner/attack_"+name.toLower()+".gif");
                atkmovie->start();
            }
        }
    }
    if(hp<=0)
    delete this;
}

void Guodongya::skill()
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
            if(Map::myptn[i][j+1])
            {
                 if(Map::myptn[i+1][j]->prepareTime-this->atk*5>0)
             Map::myptn[i][j+1]->prepareTime-=this->atk*5;
             Map::myptn[i][j+1]->atkcounter=Map::myptn[i][j+1]->prepareTime;
            }
            count=0;
        }
    });
}
void BoLangYa::skill()
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
            if(Map::myptn[i][j+1])
            {
                 if(Map::myptn[i+1][j]->prepareTime-this->atk*5>0)
             Map::myptn[i][j+1]->prepareTime-=this->atk*5;
             Map::myptn[i][j+1]->atkcounter=Map::myptn[i][j+1]->prepareTime;
            }
            if(Map::myptn[i+1][j])
            {
                 if(Map::myptn[i+1][j]->prepareTime-this->atk*5>0)
             Map::myptn[i+1][j]->prepareTime-=this->atk*5;
             Map::myptn[i+1][j]->atkcounter=Map::myptn[i+1][j]->prepareTime;
            }
            count=0;
        }
    });
}
void ShuiJingYa::skill()
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
            if(Map::myptn[i][j+1])
            {
                 if(Map::myptn[i][j+1]->prepareTime-this->atk*5>0)
             Map::myptn[i][j+1]->prepareTime-=this->atk*5;
             Map::myptn[i][j+1]->atkcounter=Map::myptn[i][j+1]->prepareTime;
            }
            if(Map::myptn[i+1][j])
            {
                if(Map::myptn[i+1][j]->prepareTime-this->atk*5>0)
             Map::myptn[i+1][j]->prepareTime-=this->atk*5;
             Map::myptn[i+1][j]->atkcounter=Map::myptn[i+1][j]->prepareTime;
            }
            {if(Map::myptn[i][j-1])
            {
                 if(Map::myptn[i][j-1]->prepareTime-this->atk*5>0)
             Map::myptn[i][j-1]->prepareTime-=this->atk*5;
             Map::myptn[i][j-1]->atkcounter=Map::myptn[i+1][j]->prepareTime;
            }}
            {if(Map::myptn[i-1][j])
            {
                 if(Map::myptn[i-1][j]->prepareTime-this->atk*5>0)
             Map::myptn[i-1][j]->prepareTime-=this->atk*5;
             Map::myptn[i-1][j]->atkcounter=Map::myptn[i+1][j]->prepareTime;
            }}
            count=0;
        }
    });
}
void Guodongya::evolution()
{
    BoLangYa *yla = new BoLangYa(i,j);
    Map::myptn[i][j] = yla;
    scene()->addItem(Map::myptn[i][j]);
    delete this;
    Map::myptn[i][j] = yla;
}
 ShuiJingYa::ShuiJingYa(int i,int j): Guodongya(i,j)
{
     this->i = i; this->j = j;
     hp=600,atk=8;name="shuijingya";
     health=600;this->No=39;skillname="水神护体";
     this->width = 120;this->height=139;
     standTime =80; standcounter=80;
     prepareTime = 300; atkcounter=300;
     coolTime = 400; coolcounter=0;
     atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
     atkmovie->start();
     Skill = new QMovie(":/partner/resource/partner/skill/"+name.toLower()+".gif");
     Skillplayer->setMovie(Skill);
       setPos(154+234*j-47,290-133+154*i);
       this->price_skill=150;
}


 BoLangYa::BoLangYa(int i,int j):Guodongya(i,j)
 {
     this->i = i; this->j = j;
     hp=500,atk=50;
     this->width = 108;this->height=120;
     standTime =80; standcounter=80;
     prepareTime = 260; atkcounter=prepareTime;
     coolTime = 600; coolcounter=0;
     name="BoLangYa";
     atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
     atkmovie->start();
       setPos(154+234*j-50,290-120+154*i);
     this->No=23;skillname="海啸";
     name = "bolangya";
     health=400,atk=6;hp=health;
     this->width = 110;this->height=157;
     standTime =80; standcounter=standcounter;
     prepareTime = 300; atkcounter=prepareTime;
     coolTime = 600; coolcounter=0;
     atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
     atkmovie->start();
     Skill = new QMovie(":/partner/resource/partner/skill/"+name.toLower()+".gif");
     Skillplayer->setMovie(Skill);
       setPos(154+234*j-47,290-133+154*i);
       this->price_ev=100;
       this->price_skill=90;

 }
 BoLangYa::~BoLangYa()
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
 ShuiJingYa::~ShuiJingYa()
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
void BoLangYa::evolution()
{
    ShuiJingYa *yla = new ShuiJingYa(i,j);
    Map::myptn[i][j] = yla;
    scene()->addItem(Map::myptn[i][j]);
    delete this;
    Map::myptn[i][j] = yla;
    Map::myptn[i][j]->evolutionButton->setEnabled(false);
}

