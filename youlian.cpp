//#include "youlian.h"

//YouLiAn::YouLiAn(int i,int j):Yiyou(i,j)
//{
//    this->i = i; this->j=j;
//    width = 95;height=133;
//    hp=350;atkcounter=100;prepareTime=100;
//    this->atk = 65;
//    name="Yiyou";
//    atkmovie=new QMovie(":/partner/resource/partner/stand_youlian.gif");
//    atkmovie->start();
//    setPos(154+234*j-47,290-133+154*i);

//}
//YouLiAn::~YouLiAn()
//{
//    Map::myptn[i][j]=NULL;
//    if(atkmovie)
//        delete atkmovie;

//}
////void YouLiAn::advance(int phase)
////{

////    if(!phase)
////        return;
////    update();
////    QList <QGraphicsItem *> items = collidingItems();
////    if(!items.isEmpty())
////    {
////    if(atkcounter<prepareTime)
////        ++atkcounter;
////    if(atkcounter==prepareTime)
////    {
////        atkcounter=0;
////        bullet=new Bullet(i,j,43,43);
////        bullet->ATK=this->atk;
////        bullet->name = this->name.toLower();
////        scene()->addItem(bullet);
////    }
////    }
////    if(hp<=0)
////        delete this;
////}
//////bool Yiyou::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
//////{
//////     Q_UNUSED(mode);
//////    qDebug()<<other->y()<<y();

//////    return other->type() == Enemy::Type && qAbs(other->y()-y())>-50&&qAbs(other->y()-y())<100&&qAbs(other->x()-x())>50;
//////}
////void YouLiAn::skill()
////{

////}
////void YouLiAn::evolution()
////{

////}


