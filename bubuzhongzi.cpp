#include "bubuzhongzi.h"
#include "level.h"
Bubuzhongzi::Bubuzhongzi(int i,int j)
{
    this->attribute = GRASS;
    this->i = i; this->j = j;
    hp=500,atk=50;health=300;
    this->width = 95;this->height=146;
    standTime = 64; standcounter=standTime;
    prepareTime = 150; atkcounter=atkcounter;
    coolTime = 600; coolcounter=0;
    No=1;
    name="bubuzhongzi";skillname ="光合作用";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    Skill = new QMovie(":/partner/resource/partner/skill/"+name.toLower()+".gif");
    Skillplayer->setMovie(Skill);
    atkmovie->start();
      setPos(154+234*j-47,290-133+154*i);
      this->price=50;
      this->price_ev=150;
      this->price_skill=50;
}
Bubuzhongzi::~Bubuzhongzi()
{
    Map::myptn[i][j]=nullptr;
    if(atkmovie)
    {
        atkmovie=NULL;
        delete  atkmovie;
    }
    if(Skill)
        delete Skill;
}
//QRectF Bubuzhongzi::boundingRect() const
//{
//     return QRectF(180, 0, 100, 70);
//}


void Bubuzhongzi::advance(int phase)
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
//            qDebug()<<"战力开始";
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
                    Map::myptn[i][j+1]->hp+=Damage(this,Map::myptn[i][j]);
                    qDebug()<<"治疗"<<Map::myptn[i][j+1]->name;
                    qDebug()<<atkcounter;
                    standcounter=64;
                    coolcounter=0;
                    return;
                }
            }
            if(atkcounter==prepareTime)
            {
                qDebug()<<"治疗开始";
                qDebug()<<"atkcounter"<<atkcounter<<" coolcounter"<<coolcounter<<" standcounter"<<standcounter;
                atkcounter=0;
                atkmovie = new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
                atkmovie->start();
            }
        }
    }
    if(hp<=0)
    delete this;
}

void Bubuzhongzi::skill()
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
            this->hp+=atk*2;
            int temp= atk;
            atk=200;
            if(Map::myptn[i][j+1])
            Map::myptn[i][j+1]->hp+=Damage(this,Map::myptn[i][j]);
            atk=temp;
            parent->gametime->start(10);
            Skill->stop();
            Skillplayer->hide();
            count=0;
        }
    });
}
void Bubuzhongzi::evolution()
{
    BuBuCao *bbc = new BuBuCao(i,j);
    Map::myptn[i][j] = bbc;
    scene()->addItem(Map::myptn[i][j]);
    delete this;
    Map::myptn[i][j] = bbc;
}
BuBuCao::BuBuCao(int i,int j):Bubuzhongzi(i,j)
{
    health=500;
    hp=500,atk=55;
    this->width = 95;this->height=146;
    standTime = 64; standcounter=standcounter;
    prepareTime = 150; atkcounter=atkcounter;
    //coolTime = 600; coolcounter=0;
    No=17;
    name="BuBuCao";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    Skill = new QMovie(":/partner/resource/partner/skill/"+name.toLower()+".gif");
    Skillplayer->setMovie(Skill);
    atkmovie->start();
      setPos(154+234*j-47,290-133+154*i);
      this->price=100;
      this->price_ev=200;
      this->price_skill=100;
}

void BuBuCao::evolution()
{

    BuBuHua *bbh = new BuBuHua(i,j);
    Map::myptn[i][j] = bbh;
    scene()->addItem(Map::myptn[i][j]);
    delete this;
    Map::myptn[i][j] = bbh;
    Map::myptn[i][j]->evolutionButton->setEnabled(false);

}
void BuBuCao::skill()
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
        if(count ==208)
        {
            delete time;
            qDebug()<<"技能释放完毕";
            this->hp+=atk*2;
            int temp= atk;
            atk=300;
            if(Map::myptn[i][j+1])
            Map::myptn[i][j+1]->hp+=Damage(this,Map::myptn[i][j]);
            atk=temp;
            parent->gametime->start(10);
            Skill->stop();
            Skillplayer->hide();
            count=0;
        }
    });
}
BuBuCao::~BuBuCao()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        atkmovie =NULL;
        delete atkmovie;
    }
}
BuBuHua::BuBuHua(int i,int j):Bubuzhongzi(i,j)
{
    health=700;
    hp=700,atk=65;
    this->width = 95;this->height=146;
    standTime = 64; standcounter=standTime;
    prepareTime = 150; atkcounter=prepareTime;
    //coolTime = 600; coolcounter=0;
    No=33;
    name="BuBuHua";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    Skill = new QMovie(":/partner/resource/partner/skill/"+name.toLower()+".gif");
    Skillplayer->setMovie(Skill);
    atkmovie->start();
    setPos(154+234*j-47,290-133+154*i);
    this->price_skill=150;
}
void BuBuHua::skill()
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
        if(count ==196)
        {
            delete time;
            qDebug()<<"技能释放完毕";
            this->hp+=atk*2;
            int temp= atk;
            atk=400;
            if(Map::myptn[i][j+1])
            Map::myptn[i][j+1]->hp+=Damage(this,Map::myptn[i][j]);
            atk=temp;
            parent->gametime->start(10);
            Skill->stop();
            Skillplayer->hide();
            count=0;
        }
    });
}
BuBuHua::~BuBuHua()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        atkmovie =NULL;
        delete atkmovie;
    }
}

