#include "bubucao.h"

//BuBuCao::BuBuCao(int i,int j):Bubuzhongzi(i,j)
//{
//    hp=600,atk=50;
//    this->width = 95;this->height=146;
//    standTime = 64; standcounter=64;
//    prepareTime = 150; atkcounter=150;
//    //coolTime = 600; coolcounter=0;
//    name="BuBuCao";
//    atkmovie=new QMovie(":/partner/resource/partner/stand_bubucao.gif");
//    atkmovie->start();
//      setPos(154+234*j-47,290-133+154*i);
//}
//BuBuCao::~BuBuCao()
//{
//    Map::myptn[i][j]=nullptr;
//    if(atkmovie)
//        delete atkmovie;
//}
//QRectF Bubuzhongzi::boundingRect() const
//{
//     return QRectF(180, 0, 100, 70);
//}


//void BuBuCao::advance(int phase)
//{
//    if(!phase)
//        return;
//    update();
//    if(Map::myptn[i][j+1])
//    {
//        //if(coolcounter<coolTime)
//        //{
//            if(standcounter<standTime)
//            {
//                standcounter++;
//            }
//            if(standcounter==standTime)
//            {
//            standcounter=0;
////            qDebug()<<"战力开始";
//            atkmovie = new QMovie(":/partner/resource/partner/stand_"+name.toLower()+".gif");
//            atkmovie->start();
//            //}
//            coolcounter++;
//        }
//        if(coolcounter==coolTime)
//        {
//            if(atkcounter<prepareTime)
//            {
//                atkcounter++;
//                if(atkcounter==prepareTime)
//                {
//                    Map::myptn[i][j+1]->hp+=atk;
//                    qDebug()<<"治疗"<<Map::myptn[i][j+1]->name;
//                    qDebug()<<atkcounter;
//                    standcounter=64;
//                    coolcounter=0;
//                    return;
//                }
//            }
//            if(atkcounter==prepareTime)
//            {
//                qDebug()<<"治疗开始";
//                qDebug()<<"atkcounter"<<atkcounter<<" coolcounter"<<coolcounter<<" standcounter"<<standcounter;
//                atkcounter=0;
//                atkmovie = new QMovie(":/partner/resource/partner/attack_1.gif");
//                atkmovie->start();
//            }
//        }
//    }
//    if(hp<=0)
//    delete this;
//}

//void BuBuCao::skill()
//{

//}
//void BuBuCao::evolution()
//{

//}
