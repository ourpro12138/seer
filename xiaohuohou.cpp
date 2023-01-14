#include "xiaohuohou.h"


Xiaohuohou::Xiaohuohou(int i,int j)
{
    this->i = i; this->j = j;
    this->width = 97;this->height=110;
    hp=500,atk=0,prepareTime=50,counter=0;
    name="xiaohuohou";
    atkStatus=0;
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
    if(hp<=0)
    delete this;
}

bool Xiaohuohou::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode);
    return other->type()==partner::Type && other->x()-x()<80 && other->x()-x()>15
            && other->y()-y()>0 && other->y()-y()<100;
}
void Xiaohuohou::skill()
{

}
void Xiaohuohou::evolution()
{

}
