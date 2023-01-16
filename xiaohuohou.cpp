#include "xiaohuohou.h"
#include "enemy.h"
#include <QDebug>
#include <QMovie>
#include <QLabel>


Xiaohuohou::Xiaohuohou(int i,int j)
{
    this->i = i; this->j = j;
    this->width = 97;this->height=110;
    hp=100,atk=100,prepareTime=50,counter=0;
    name="XiaoHuoHou";
    atkmovie=new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
    atkmovie->start();
    setPos(154+234*j-47,290-133+154*i);
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
    return other->type()==Enemy::Type && other->x()-x()>-75 && other->x()-x()<-14
            && other->y()-y()>-95 && other->y()-y()<0;
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
