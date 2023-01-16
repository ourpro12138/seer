#include "xiaohuohou.h"
#include "enemy.h"
#include <QDebug>
#include <QMovie>
#include <QLabel>


Xiaohuohou::Xiaohuohou(int i,int j)
{
    this->i = i; this->j = j;
    this->width = 130;this->height=160;

    hp=100,atk=100,prepareTime=50,counter=0;
    name="XiaoHuoHou";

    hp=1000,atk=0,prepareTime=50,counter=0;
    name="xiaohuohou";

    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(154+234*j-47-10,290-133+154*i-30);
}

Xiaohuohou::~Xiaohuohou()
{
    Map::myptn[i][j]=nullptr;
    if(atkmovie)
        delete atkmovie;
}

//QRectF Xiaohuohou::boundingRect() const
//{
////     return QRectF(180, 0, 100, 70);
//}

bool Xiaohuohou::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
    if(other->type()==Enemy::Type)
    {
        qDebug()<<other->x()-x()<<"  "<<other->y()-y();
    }
    return other->type()==Enemy::Type && other->x()-x()>145 && other->x()-x()<180
            && other->y()-y()>-20 && other->y()-y()<0;
}

void Xiaohuohou::advance(int phase)
{
    if(!phase)
        return;
    update();

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
            qDebug()<<"xxx";
            Enemy *enemy=qgraphicsitem_cast <Enemy *> (items[qrand()%items.size()]);
            enemy->hp -= atk;
            atkmovie = new QMovie(":/partner/resource/partner/attack_9.gif");
            atkmovie->start();
        }


    }
}


void Xiaohuohou::skill()
{

}
void Xiaohuohou::evolution()
{

}
