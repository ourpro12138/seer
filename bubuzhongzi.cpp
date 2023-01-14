#include "bubuzhongzi.h"

Bubuzhongzi::Bubuzhongzi(int i,int j)
{
    hp=500,atk=0,prepareTime=50,counter=0;
    name="bubuzhongzi";
    atkStatus=0;
    atkmovie=new QMovie(":/partner/resource/partner/stand_bubuzhongzi.gif");
    atkmovie->start();
    setPos(i*230+170,j*152+121);
}
Bubuzhongzi::~Bubuzhongzi()
{
    Map::myptn[i][j]=nullptr;
    if(atkmovie)
        delete atkmovie;
}
QRectF Bubuzhongzi::boundingRect() const
{
     return QRectF(180, 0, 100, 70);
}


void Bubuzhongzi::advance(int phase)
{
    if(!phase)
        return;
    update();
    if(hp<=0)
    delete this;
}



