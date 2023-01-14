#include "firemonkey.h"

Firemonkey::Firemonkey(int i,int j)
{
    hp=500;
    name="hou";
    atkmovie=new QMovie(":/partner/resource/partner/stand_xiaohuohou.gif");
    atkmovie->start();
    setPos(i*230+170,j*152+121);
}

Firemonkey::~Firemonkey()
{
    Map::myptn[i][j]=nullptr;
    if(atkmovie)
        delete atkmovie;
}


void Firemonkey::advance(int phase)
{
    if(!phase)
        return;
    update();
    if(hp<=0)
    delete this;
}

