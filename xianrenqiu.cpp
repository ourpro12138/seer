#include "xianrenqiu.h"
#include "map.h"
Xianrenqiu::Xianrenqiu(int i,int j)
{
this->i = i;this->j=j;
    width=90;height=130;

    this->hp = 300;this->atk=30;

    prepareTime = 210; atkcounter=210;
    standTime=80; standcounter=80;
    coolTime = 200;coolcounter=0;

    name="Xianrenqou";
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
                    enemy->hp-=this->atk;
                    standcounter=80;
                    coolcounter=0;
                    return;
                }
            }
            if(atkcounter==prepareTime)
            {
                atkcounter=0;
                atkmovie = new QMovie(":/partner/resource/partner/attack_2.gif");
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
