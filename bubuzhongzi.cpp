#include "bubuzhongzi.h"
Bubuzhongzi::Bubuzhongzi(int i,int j)
{
    this->i = i; this->j = j;
    hp=500,atk=50;
    this->width = 95;this->height=146;
    standTime = 64; standcounter=64;
    prepareTime = 150; atkcounter=150;
    coolTime = 600; coolcounter=0;
    name="bubuzhongzi";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
      setPos(154+234*j-47,290-133+154*i);
}
Bubuzhongzi::~Bubuzhongzi()
{
    Map::myptn[i][j]=nullptr;
    if(atkmovie)
    {
        atkmovie=NULL;
        delete  atkmovie;
    }
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
                    Map::myptn[i][j+1]->hp+=atk;
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
                atkmovie = new QMovie(":/partner/resource/partner/attack_1.gif");
                atkmovie->start();
            }
        }
    }
    if(hp<=0)
    delete this;
}

void Bubuzhongzi::skill()
{

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
    hp=700,atk=55;
    this->width = 95;this->height=146;
    standTime = 64; standcounter=64;
    prepareTime = 150; atkcounter=150;
    //coolTime = 600; coolcounter=0;
    name="BuBuCao";
    atkmovie=new QMovie(":/partner/resource/partner/stand_bubucao.gif");
    atkmovie->start();
      setPos(154+234*j-47,290-133+154*i);
}

void BuBuCao::evolution()
{

    BuBuHua *bbh = new BuBuHua(i,j);
    Map::myptn[i][j] = bbh;
    scene()->addItem(Map::myptn[i][j]);
    delete this;
    Map::myptn[i][j] = bbh;

    this->skillButton->setEnabled(false);

}
void BuBuCao::skill()
{

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
    hp=800,atk=65;
    this->width = 95;this->height=146;
    standTime = 64; standcounter=64;
    prepareTime = 150; atkcounter=150;
    //coolTime = 600; coolcounter=0;
    name="BuBuHua";
    atkmovie=new QMovie(":/partner/resource/partner/stand_bubuhua.gif");
    atkmovie->start();
    setPos(154+234*j-47,290-133+154*i);
}
void BuBuHua::skill()
{

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

