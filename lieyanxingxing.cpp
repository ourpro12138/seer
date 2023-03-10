#include "lieyanxingxing.h"

LieYanXingXing::LieYanXingXing(int i,int j)
{
    this->i = i; this->j = j;
    this->width = 130;this->height=160;

    hp=500,atk=75,prepareTime=150,atkcounter=150;
    standTime=64; standcounter=0; coolTime=0;coolcounter=0;
    name="LieHuoHou";
    atkmovie=new QMovie(":/partner/resource/partner/stand_lieyanxingxing.gif");
    atkmovie->start();
    setPos(154+234*j-47-10,290-133+154*i-30);
}
LieYanXingXing::~LieYanXingXing()
{
    Map::myptn[i][j]=nullptr;
    if(atkmovie)
        delete atkmovie;
}
bool LieYanXingXing::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
//    if(other->type()==Enemy::Type)
//    {
//        qDebug()<<other->x()-x()<<"  "<<other->y()-y();
//    }

    return other->type()==Enemy::Type && other->x()-x()>100 && other->x()-x()<140
            && other->y()-y()>-60 && other->y()-y()<60;

    return other->type()==Enemy::Type && other->x()-x()>120 && other->x()-x()<150;


}

void LieYanXingXing::advance(int phase)
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
            Enemy *enemy=qgraphicsitem_cast <Enemy *> (items[qrand()%items.size()]);
         if(atkcounter<prepareTime)
         {
          atkcounter++;
          if(atkcounter==150)
              enemy->hp-=atk;
         }
         if(atkcounter==prepareTime)
         {
            atkcounter=0;
            atkmovie = new QMovie(":/partner/resource/partner/attack_9.gif");
            atkmovie->start();
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
               atkmovie = new QMovie(":/partner/resource/partner/stand_lieyanxingxing.gif");
               atkmovie->start();
            }
        }
    }
}


void LieYanXingXing::skill()
{

}
