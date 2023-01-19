#include "guodongya.h"

Guodongya::Guodongya(int i,int j)
{
    this->attribute = WATER;
    this->i = i; this->j = j;
    hp=500,atk=4;
    this->width = 118;this->height=130;health=500;
    standTime =80; standcounter=standTime;
    prepareTime = 300; atkcounter=prepareTime;
    coolTime = 600; coolcounter=coolTime;
    name="Guodongya";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
      setPos(154+234*j-47,290-133+154*i);
}
Guodongya::~Guodongya()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        atkmovie =NULL;
        delete atkmovie;
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
                    if(Map::myptn[i][j+1]->prepareTime-Damage(this,Map::myptn[i][j+1])>0)
                    {
                        Map::myptn[i][j+1]->prepareTime-=Damage(this,Map::myptn[i][j+1]);
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
                atkmovie = new QMovie(":/partner/resource/partner/attack_guodongya.gif");
                atkmovie->start();
            }
        }
    }
    if(hp<=0)
    delete this;
}

void Guodongya::skill()
{

}
void Guodongya::evolution()
{

}
 ShuiJingYa::ShuiJingYa(int i,int j): Guodongya(i,j)
{
     this->i = i; this->j = j;
     hp=500,atk=50;
     this->width = 118;this->height=130;
     standTime =80; standcounter=80;
     prepareTime = 300; atkcounter=300;
     coolTime = 600; coolcounter=0;
     name="Guodongya";
     atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
     atkmovie->start();
       setPos(154+234*j-47,290-133+154*i);

}
 ShuiJingYa::~ShuiJingYa()
 {
     if(Map::myptn[i][j])
     Map::myptn[i][j]=NULL;
     if(atkmovie)
     {
         atkmovie =NULL;
         delete atkmovie;
     }
 }

 BoLangYa::BoLangYa(int i,int j):Guodongya(i,j)
 {
     this->i = i; this->j = j;
     hp=500,atk=50;
     this->width = 118;this->height=130;
     standTime =80; standcounter=80;
     prepareTime = 300; atkcounter=300;
     coolTime = 600; coolcounter=0;
     name="Guodongya";
     atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
     atkmovie->start();
       setPos(154+234*j-47,290-133+154*i);

 }
 BoLangYa::~BoLangYa()
  {
     if(Map::myptn[i][j])
     Map::myptn[i][j]=NULL;
     if(atkmovie)
     {
         atkmovie =NULL;
         delete atkmovie;
     }
  }
