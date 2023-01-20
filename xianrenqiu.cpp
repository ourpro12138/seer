#include "xianrenqiu.h"
#include "map.h"
Xianrenqiu::Xianrenqiu(int i,int j)
{

    this->attribute = GRASS;
    this->i = i;this->j=j;
    width=90;height=130;
    No=2;
    this->hp = 300;this->atk=30;

    prepareTime = 210; atkcounter=prepareTime;
    standTime=80; standcounter=standTime;
    coolTime = 200;coolcounter=0;

    name="Xianrenqiu";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(154+234*j-47,290-133+154*i);
}

Xianrenqiu::~Xianrenqiu()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        atkmovie =NULL;
        delete atkmovie;
    }
}
bool Xianrenqiu::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
    if(other->type()==Enemy::Type)
    {
        qDebug()<<other->x()-x();
    }
    return other->type()==Enemy::Type && other->x()-x()>145 && other->x()-x()<250
            && other->y()-y()>-20 && other->y()-y()<20;
}
void Xianrenqiu::advance(int phase)
{
    if(!phase)
        return;
    update();
    QList <QGraphicsItem *> items = collidingItems();
    if(!items.isEmpty())
    {
        Enemy *enemy=qgraphicsitem_cast <Enemy *> (items[qrand()%items.size()]);
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
                    if(this->hp+this->atk<=300)
                        this->hp+=this->atk;
                    else if(this->hp<=300&&this->hp+this->atk>=300)
                        this->hp=300;
                    qDebug()<<"仙人球治疗自己"<<this->atk;
                    enemy->hp-=Damage(this,enemy);
                    standcounter=prepareTime;
                    coolcounter=0;
                    return;
                }
            }
            if(atkcounter==prepareTime)
            {
                atkcounter=0;
                atkmovie = new QMovie(":/partner/resource/partner/attack_"+name.toLower()+".gif");
                atkmovie->start();
            }
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
    if(hp<=0)
    delete this;
}
void Xianrenqiu::skill()
{

}
void Xianrenqiu::evolution()
{

}

XianRenZhang::XianRenZhang(int i,int j):Xianrenqiu(i,j)
{
    this->attribute = GRASS;
    this->i = i;this->j=j;
    width=140;height=130;

    this->hp = 350;this->atk=40;

    prepareTime = 320; atkcounter=prepareTime;
    standTime=76; standcounter=standTime;
    coolTime = 200;coolcounter=0;
    No=18;
    name="Xianrenzhang";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(154+234*j-47-20,290-133+154*i);
}
XianRenZhang::~XianRenZhang()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        atkmovie =NULL;
        delete atkmovie;
    }
}
void XianRenZhang::skill()
{

}
void XianRenZhang::evolution()
{

}
JuXingXianRenZhang::JuXingXianRenZhang(int i,int j):Xianrenqiu(i,j)
{
    this->attribute = GRASS;
    this->i = i;this->j=j;
    width=150;height=130;

    this->hp = 350;this->atk=40;

    prepareTime = 210; atkcounter=prepareTime;
    standTime=80; standcounter=standTime;
    coolTime = 200;coolcounter=0;
    No=18;
    name="JuXingXianrenzhang";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(154+234*j-55-10,290-100+154*i);
}
JuXingXianRenZhang::~JuXingXianRenZhang()
{
    if(Map::myptn[i][j])
    Map::myptn[i][j]=NULL;
    if(atkmovie)
    {
        atkmovie =NULL;
        delete atkmovie;
    }
}
void JuXingXianRenZhang::skill()
{

}
