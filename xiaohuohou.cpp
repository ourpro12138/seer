#include "xiaohuohou.h"
#include "enemy.h"


Xiaohuohou::Xiaohuohou(int i,int j)
{
    this->i = i; this->j = j;
    this->width = 97;this->height=110;
    hp=1000,atk=0,prepareTime=50,counter=0;
    name="xiaohuohou";
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


void Xiaohuohou::advance(int phase)
{
    if(!phase)
        return;
    update();
    QList <QGraphicsItem *> items = collidingItems();

    if(hp<=0)
    {
        nowStatus=0;  //死亡
        atkmovie->currentFrameNumber()==atkmovie->frameCount()-1;
        delete this;
        return;
    }

    if(hp>0)
    {
        nowStatus=1;
        QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
        if(!items.isEmpty())
        {
            Enemy *enemy=qgraphicsitem_cast<Enemy *>(items[0]);
            enemy->hp-=atk;
            nowStatus=2;
            QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
        }

    }
}


void Xiaohuohou::skill()
{

}
void Xiaohuohou::evolution()
{

}
