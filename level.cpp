#include "level.h"
#include "ui_level.h"
#include "moguguai.h"
#include "gangyasha.h"
#include "zuoluo.h"
#include "taqiduoke.h"
#include "maokai.h"
#include "heertuoke.h"
#include "phoenix.h"
#include "jianxishuiling.h"
#include "nisike.h"
#include "xikela.h"
#include "xingjila.h"
#include "sailatu.h"
#include "boge.h"
#include "dululu.h"
#include "xianrenqiu.h"
#include "beier.h"

Level::Level(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Level)
{
    this->setStyleSheet("QPushButton{background-color:transparent}");
    gametime = new QTimer(this);
    wavetime = new QTimer(this);
    diamondtimer = new QTimer(this);
    levelMode=0;//选卡阶段
    ui->setupUi(this);
    isLocked =0;
    this->setFixedSize(1566,911);
    this->hide();
    initlevel();
}

Level::~Level()
{
    Cards::diamondTotal=50;
    delete ui;
    delete this->cb;
    delete this->cm;
    delete this->Back;
    delete this->map;
    delete this->view;
    delete this->scene;
//    delete Partner::skillButton;
//    delete Partner::evolutionButton;
//    delete Partner::capsuleButton;
}

void Level::paintEvent(QPaintEvent *)
{
//   QPainter painter(this);
//   QPixmap map;
//   map.load(":/map/resource/map/"+levelName+".png");
//   painter.drawPixmap(0,0,map);
//   painter.end();
    view->setBackgroundBrush(QPixmap(":/map/resource/map/"+levelName+".png"));
}

void Level::GameStart()
{

    QTimer *timer = new QTimer(this);
    timer->start(3);
    cm->hide();
    delete Back;
    connect(timer,&QTimer::timeout,this,[=](){
        qDebug()<<"moving"<<x;
        x++;
        this->move(x,0);
        this->cb->move(-x,0);
        if(x==0)
        {
            qDebug()<<"time stop";
            Back = new pdbackPushButton(1366);
            Back->setParent(this);
            Back->show();
            connect(Back,&pdbackPushButton::backpress,this,&Level::back);
            levelMode=1;//游戏正式开始
            diamondtimer->start(1000);
            wavetime->start(10000);
            emit gamestart();
            delete timer;
        }
    });

}
kls::kls()
{
    levelName = "kls";
        Wave = 1;
        totalWave=2;
        Enemy *gang,*gang2,*gang3,*gang4,*gang5,*mo,*mo2,*mo3,*zl,*zl1,*zl2,*zl3,*mk,*taqi2,*bm,*bm2;

        creattimer = new QTimer(this);
        gang = new GangYaSha(2);
        gang2 = new GangYaSha(3);
        gang3 = new GangYaSha(1);
        gang4 = new GangYaSha(2);
        gang5 = new GangYaSha(0);

        mo = new MoGuGuai(2);
        mo2 = new MoGuGuai(3);
        mo3 = new MoGuGuai(1);

        zl2 = new ZuoLuo(3);
        zl3 = new ZuoLuo(4);

        taqi2 = new Taqiduoke(3);

        bm = new Beilami(3);
        bm2 = new Beilami(2);


        mk = new Maokai(3);



        connect(wavetime,&QTimer::timeout,[=](){

            if(Wave==1)
            {
                levelMode =2;
                creattimer->start(2000);
                wavetime->stop();
            }
            else if(Wave==2)
            {
                levelMode=3;
                creattimer->start(2000);
                delete wavetime;
            }

        });
        static int enemy_count=0;
           connect(creattimer,&QTimer::timeout,[=]()
           {
               if(levelMode==2)
               {
                   switch(enemy_count)
               {
               case 0:
                  {scene->addItem(mo2);break;}
               case 1:
                  {scene->addItem(mo);break;}
               case 2:
                 { scene->addItem(gang2);break;}
               case 3:
                 { scene->addItem(gang5);break;}
               case 4:
                 { scene->addItem(mo3);break;}
               case 5:
                 { scene->addItem(mo);break;}
               case 6:
                 { scene->addItem(gang4);break;}
                case 7:
                 { scene->addItem(mo);break;}
                case 8:
                 { scene->addItem(mk);break;}
                   default:
                 {
                   if(mo2->nowStatus==0&&mo->nowStatus==0&&gang2->nowStatus==0&&gang4->nowStatus==0&mo3->nowStatus==0&&mo->nowStatus==0&&gang4->nowStatus==0&&mo->nowStatus==0&&mk->nowStatus==0)
                   {
                       qDebug("two");
                       Wave=2;
                       enemy_count=0;
                       wavetime->start(10000);
                       creattimer->stop();
                       enemy_count=-1;
                       break;
                   }
               }
               }
                     enemy_count++;
               }
               else if(levelMode==3)
               {
                    qDebug()<<"第二波来咯";
                   {
                       switch(enemy_count)
                   {
                   case 0:
                      {scene->addItem(bm);break;}
                   case 1:
                      {scene->addItem(gang2);break;}
                   case 2:
                     { scene->addItem(zl2);break;}
                   case 3:
                     { scene->addItem(bm2);break;}
                   case 4:
                     { scene->addItem(zl3);break;}
                   case 5:
                     { scene->addItem(mo);break;}
                   case 6:
                     { scene->addItem(gang3);break;}
                   case 7:
                     { scene->addItem(taqi2);break;}
                   default:
                   {
                       if(bm->nowStatus==0&&gang2->nowStatus==0&&zl2->nowStatus==0&&bm2->nowStatus==0&&zl3->nowStatus==0&&mo->nowStatus==0&&gang3->nowStatus==0&&taqi2->nowStatus==0)
                       {
                           //Mission completion



                           break;
                       }
                   }
                   }
                         enemy_count++;
                   }
               }
           });
}

hek::hek()
{
levelName = "hek";
Wave = 1;
totalWave=2;
Enemy *bm,*bm1,*bm2,*mo,*mo1,*gang,*gang2,*ph,*hr,*xk,*xk1;

bm = new Beilami(3);
bm1 = new Beilami(0);
bm2 = new Beilami(2);

mo = new MoGuGuai(4);
mo1 = new MoGuGuai(2);

gang = new GangYaSha(1);
gang2 = new GangYaSha(3);

xk = new Xikela(2);
xk1 = new Xikela(1);

hr = new Heertoke(4);



creattimer = new QTimer(this);




connect(wavetime,&QTimer::timeout,[=](){

    if(Wave==1)
    {
        levelMode =2;
        creattimer->start(2000);
        wavetime->stop();
    }
    else if(Wave==2)
    {
        levelMode=3;
        creattimer->start(2000);
        delete wavetime;
    }

});
static int enemy_count=0;
   connect(creattimer,&QTimer::timeout,[=]()
   {
       if(levelMode==2)
       {
           switch(enemy_count)
       {
       case 0:
          {scene->addItem(bm);break;}
       case 1:
          {scene->addItem(bm2);break;}
       case 2:
         { scene->addItem(xk1);break;}
       case 3:
         { scene->addItem(gang);break;}
       case 4:
         { scene->addItem(mo);break;}
       case 5:
         { scene->addItem(mo1);break;}
       case 6:
         { scene->addItem(gang2);break;}
        case 7:
         { scene->addItem(xk);break;}
        case 8:
         { scene->addItem(hr);break;}
           default:
         {
           if(bm->nowStatus==0&&bm2->nowStatus==0&&bm1->nowStatus==0&&gang->nowStatus==0&&mo->nowStatus==0&&mo1->nowStatus==0&&gang2->nowStatus==0&&bm2->nowStatus==0&&hr->nowStatus==0)
           {
               qDebug("two");
               Wave=2;
               enemy_count=0;
               wavetime->start(10000);
               creattimer->stop();
               enemy_count=-1;
               break;
           }
       }
       }
             enemy_count++;
       }
       else if(levelMode==3)
       {
            qDebug()<<"第二波来咯";
           {
               switch(enemy_count)
           {
           case 0:
              {scene->addItem(bm2);break;}
           case 1:
              {scene->addItem(mo);break;}
           case 2:
             { scene->addItem(xk);break;}
           case 3:
             { scene->addItem(gang);break;}
           case 4:
             { scene->addItem(mo1);break;}
           case 5:
             { scene->addItem(bm);break;}
           case 6:
             { scene->addItem(xk1);break;}
           case 7:
             { scene->addItem(hr);break;}
           case 8:
             { scene->addItem(hr);break;}
           default:
           {
               if(bm2->nowStatus==0&&mo->nowStatus==0&&bm1->nowStatus==0&&gang->nowStatus==0&&mo1->nowStatus==0&&bm->nowStatus==0&&gang2->nowStatus==0&&hr->nowStatus==0&&hr->nowStatus==0)
               {
                   //Mission completion



                   break;
               }
           }
           }
                 enemy_count++;
           }
       }
   });


}
hs::hs()
{
levelName = "hs";
Wave = 1;
totalWave=2;
Enemy *bm,*bm1,*nis,*slt,*mk,*taqi,*xk,*hr,*hr1,*ph;

bm = new Beilami(3);
bm1 = new Beilami(0);

ph = new Phoenix(2);

hr = new Heertoke(4);
hr1 = new Heertoke(1);

nis = new Nisike(2);

slt = new Sailatu(1);

mk = new Maokai(2);

xk = new Xikela(4);



creattimer = new QTimer(this);




connect(wavetime,&QTimer::timeout,[=](){

    if(Wave==1)
    {
        levelMode =2;
        creattimer->start(2000);
        wavetime->stop();
    }
    else if(Wave==2)
    {
        levelMode=3;
        creattimer->start(2000);
        delete wavetime;
    }

});
static int enemy_count=0;
   connect(creattimer,&QTimer::timeout,[=]()
   {
       if(levelMode==2)
       {
           switch(enemy_count)
       {
       case 0:
          {scene->addItem(bm);break;}
       case 1:
          {scene->addItem(slt);break;}
       case 2:
         { scene->addItem(xk);break;}
       case 3:
         { scene->addItem(bm1);break;}
       case 4:
         { scene->addItem(nis);break;}
       case 5:
         { scene->addItem(bm1);break;}
       case 6:
         { scene->addItem(slt);break;}
        case 7:
         { scene->addItem(hr);break;}
        case 8:
         { scene->addItem(hr1);break;}
           default:
         {
           if(bm->nowStatus==0&&slt->nowStatus==0&&xk->nowStatus==0&&bm1->nowStatus==0&&nis->nowStatus==0&&bm1->nowStatus==0&&hr->nowStatus==0&&hr1->nowStatus==0)
           {
               qDebug("two");
               Wave=2;
               enemy_count=0;
               wavetime->start(10000);
               creattimer->stop();
               enemy_count=-1;
               break;
           }
       }
       }
             enemy_count++;
       }
       else if(levelMode==3)
       {
            qDebug()<<"第二波来咯";
           {
               switch(enemy_count)
           {
           case 0:
              {scene->addItem(bm);break;}
           case 1:
              {scene->addItem(xk);break;}
           case 2:
             { scene->addItem(xk);break;}
           case 3:
             { scene->addItem(slt);break;}
           case 4:
             { scene->addItem(bm1);break;}
           case 5:
             { scene->addItem(nis);break;}
           case 6:
             { scene->addItem(hr);break;}
           case 7:
             { scene->addItem(ph);break;}
           case 8:
             { scene->addItem(ph);break;}
           default:
           {
               if(bm->nowStatus==0&&xk->nowStatus==0&&xk->nowStatus==0&&slt->nowStatus==0&&bm1->nowStatus==0&&nis->nowStatus==0&&hr->nowStatus==0&&ph->nowStatus==0&&ph->nowStatus==0)
               {
                   //Mission completion



                   break;
               }
           }
           }
                 enemy_count++;
           }
       }
   });



}
alpha::alpha()
{
levelName = "alpha";
Wave = 1;
totalWave=2;
Enemy *nis,*slt,*xjl,*dll,*mk,*xk,*bm,*bg,*hr;

nis = new Nisike(2);

slt = new Sailatu(3);

xjl = new Xingjila(3);

dll = new Dululu(2);

mk = new Maokai(1);

xk = new Xikela(2);

bm = new Beilami(4);

bg = new Boge(3);

hr = new Heertoke(2);





creattimer = new QTimer(this);




connect(wavetime,&QTimer::timeout,[=](){

    if(Wave==1)
    {
        levelMode =2;
        creattimer->start(2000);
        wavetime->stop();
    }
    else if(Wave==2)
    {
        levelMode=3;
        creattimer->start(2000);
        delete wavetime;
    }

});
static int enemy_count=0;
   connect(creattimer,&QTimer::timeout,[=]()
   {
       if(levelMode==2)
       {
           switch(enemy_count)
       {
       case 0:
          {scene->addItem(bm);break;}
       case 1:
          {scene->addItem(xjl);break;}
       case 2:
         { scene->addItem(dll);break;}
       case 3:
         { scene->addItem(mk);break;}
       case 4:
         { scene->addItem(slt);break;}
       case 5:
         { scene->addItem(xk);break;}
       case 6:
         { scene->addItem(dll);break;}
        case 7:
         { scene->addItem(hr);break;}
        case 8:
         { scene->addItem(bg);break;}
           default:
         {
           if(bm->nowStatus==0&&xjl->nowStatus==0&&dll->nowStatus==0&&mk->nowStatus==0&&hr->nowStatus==0&&xk->nowStatus==0&&dll->nowStatus==0&&hr->nowStatus==0&&bg->nowStatus==0)
           {
               qDebug("two");
               Wave=2;
               enemy_count=0;
               wavetime->start(10000);
               creattimer->stop();
               enemy_count=-1;
               break;
           }
       }
       }
             enemy_count++;
       }
       else if(levelMode==3)
       {
            qDebug()<<"第二波来咯";
           {
               switch(enemy_count)
           {
           case 0:
              {scene->addItem(xjl);break;}
           case 1:
              {scene->addItem(mk);break;}
           case 2:
             { scene->addItem(xk);break;}
           case 3:
             { scene->addItem(dll);break;}
           case 4:
             { scene->addItem(xjl);break;}
           case 5:
             { scene->addItem(nis);break;}
           case 6:
             { scene->addItem(slt);break;}
           case 7:
             { scene->addItem(bg);break;}
           case 8:
             { scene->addItem(bg);break;}
           default:
           {
               if(xjl->nowStatus==0&&mk->nowStatus==0&&xk->nowStatus==0&&dll->nowStatus==0&&xjl->nowStatus==0&&slt->nowStatus==0&&bg->nowStatus==0&&bg->nowStatus==0)
               {
                   //Mission completion



                   break;
               }
           }
           }
                 enemy_count++;
           }
       }
   });


}
hm::hm()
{
levelName = "hm";
Wave = 1;
totalWave=2;
Enemy *ph,*hr,*xjl,*js,*bg,*xk,*slt;

xjl = new Xingjila(3);

js = new Jianxishuiling(0);

bg = new Boge(1);

xk = new Xikela(3);

slt = new Sailatu(0);

ph = new Phoenix(2);

hr = new Heertoke(4);



creattimer = new QTimer(this);




connect(wavetime,&QTimer::timeout,[=](){

    if(Wave==1)
    {
        levelMode =2;
        creattimer->start(2000);
        wavetime->stop();
    }
    else if(Wave==2)
    {
        levelMode=3;
        creattimer->start(2000);
        delete wavetime;
    }

});
static int enemy_count=0;
   connect(creattimer,&QTimer::timeout,[=]()
   {
       if(levelMode==2)
       {
           switch(enemy_count)
       {
       case 0:
          {scene->addItem(slt);break;}
       case 1:
          {scene->addItem(xk);break;}
       case 2:
         { scene->addItem(slt);break;}
       case 3:
         { scene->addItem(xjl);break;}
       case 4:
         { scene->addItem(hr);break;}
       case 5:
         { scene->addItem(ph);break;}
       case 6:
         { scene->addItem(bg);break;}
        case 7:
         { scene->addItem(ph);break;}
        case 8:
         { scene->addItem(js);break;}
           default:
         {
           if(slt->nowStatus==0&&xk->nowStatus==0&&slt->nowStatus==0&&xjl->nowStatus==0&&hr->nowStatus==0&&ph->nowStatus==0&&bg->nowStatus==0&&ph->nowStatus==0&&js->nowStatus==0)
           {
               qDebug("two");
               Wave=2;
               enemy_count=0;
               wavetime->start(10000);
               creattimer->stop();
               enemy_count=-1;
               break;
           }
       }
       }
             enemy_count++;
       }
       else if(levelMode==3)
       {
            qDebug()<<"第二波来咯";
           {
               switch(enemy_count)
           {
           case 0:
              {scene->addItem(xk);break;}
           case 1:
              {scene->addItem(slt);break;}
           case 2:
             { scene->addItem(bg);break;}
           case 3:
             { scene->addItem(xjl);break;}
           case 4:
             { scene->addItem(bg);break;}
           case 5:
             { scene->addItem(ph);break;}
           case 6:
             { scene->addItem(hr);break;}
           case 7:
             { scene->addItem(js);break;}
           case 8:
             { scene->addItem(js);break;}
           default:
           {
               if(xk->nowStatus==0&&slt->nowStatus==0&&bg->nowStatus==0&&xjl->nowStatus==0&&bg->nowStatus==0&&ph->nowStatus==0&&hr->nowStatus==0&&js->nowStatus==0&&js->nowStatus==0)
               {
                   //Mission completion



                   break;
               }
           }
           }
                 enemy_count++;
           }
       }
   });


}
final::final()
{
levelName = "final";
Wave = 1;
totalWave=2;
Enemy *ph,*hr,*js,*bg,*dll;

js = new Jianxishuiling(3);

ph = new Phoenix(2);

hr = new Heertoke(4);

bg = new Boge(0);

dll = new Dululu(1);


creattimer = new QTimer(this);




connect(wavetime,&QTimer::timeout,[=](){

    if(Wave==1)
    {
        levelMode =2;
        creattimer->start(2000);
        wavetime->stop();
    }
    else if(Wave==2)
    {
        levelMode=3;
        creattimer->start(2000);
        delete wavetime;
    }

});
static int enemy_count=0;
   connect(creattimer,&QTimer::timeout,[=]()
   {
       if(levelMode==2)
       {
           switch(enemy_count)
       {
       case 0:
          {scene->addItem(dll);break;}
       case 1:
          {scene->addItem(hr);break;}
       case 2:
         { scene->addItem(ph);break;}
       case 3:
         { scene->addItem(js);break;}
       case 4:
         { scene->addItem(bg);break;}
       case 5:
         { scene->addItem(ph);break;}
       case 6:
         { scene->addItem(hr);break;}
        case 7:
         { scene->addItem(js);break;}
        case 8:
         { scene->addItem(dll);break;}
           default:
         {
           if(dll->nowStatus==0&&hr->nowStatus==0&&hr->nowStatus==0&&ph->nowStatus==0&&js->nowStatus==0&&bg->nowStatus==0&&bg->nowStatus==0&&hr->nowStatus==0&&js->nowStatus==0)
           {
               qDebug("two");
               Wave=2;
               enemy_count=0;
               wavetime->start(10000);
               creattimer->stop();
               enemy_count=-1;
               break;
           }
       }
       }
             enemy_count++;
       }
       else if(levelMode==3)
       {
            qDebug()<<"第二波来咯";
           {
               switch(enemy_count)
           {
           case 0:
              {scene->addItem(bg);break;}
           case 1:
              {scene->addItem(ph);break;}
           case 2:
             { scene->addItem(hr);break;}
           case 3:
             { scene->addItem(js);break;}
           case 4:
             { scene->addItem(bg);break;}
           case 5:
             { scene->addItem(dll);break;}
           case 6:
             { scene->addItem(hr);break;}
           case 7:
             { scene->addItem(js);break;}
            case 8:
             { scene->addItem(js);break;}
           default:
           {
               if(bg->nowStatus==0&&ph->nowStatus==0&&hr->nowStatus==0&&js->nowStatus==0&&bg->nowStatus==0&&dll->nowStatus==0&&hr->nowStatus==0&&js->nowStatus==0&&js->nowStatus==0)
               {
                   //Mission completion



                   break;
               }
           }
           }
                 enemy_count++;
           }
       }
   });


}
void Level::initlevel()
{

//    scene = new QGraphicsScene(this);
//    scene->setSceneRect(0,0,1566,911);
//    view = new QGraphicsView(scene,this);
//    view->setBackgroundBrush(QPixmap(":/map/resource/map/"+levelName+".png"));

//    this->setStyleSheet("background-image:url(:/map/resource/map/"+levelName+".png)");

    this->move(-200,0);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(9,9,1566,911);
     map = new Map();

    view = new QGraphicsView(scene,this);
    view->setFixedSize(1586,931);

    scene->addItem(map);


    cm = new cardsmenu(this);
    cb = new cardsblank(this);


    for(int i=0;i<5;i++)
    {
        cb->headButton[i] = new QPushButton(this->cb);
    }

    cm->move(200,0);
    cb->move(200,0);


    QPushButton *Countinue = new QPushButton(this);
    Countinue->setFixedSize(200,200);
    Countinue->move(1366,800);
    QPixmap pix;
    pix.load(":/background/resource/background/countinue.png");
    Countinue->setMask(pix.mask());
    Countinue->setStyleSheet("background-image:url(:/background/resource/background/countinue.png)");
//    Countinue->hide();

    //点击游戏开始按钮 则游戏正式开始 屏幕滑动结束时，令startMode=1;
    connect(Countinue,&QPushButton::clicked,this,[=](){
        GameStart();
        delete  Countinue;
    });

    Back = new pdbackPushButton(this->width());
    Back->setParent(this);
    connect(Back,&pdbackPushButton::backpress,this,[=](){
        emit this->back();
    });
    //当卡片目录发出信号时，接受，并且分析信号，让卡片栏新增对应按钮
    connect(cm,&cardsmenu::bbzz,this,[=](){
            for(int i=0;i<5;i++)
            {
            if(cb->cards[i]->name=="none")
            {
            cb->cards[i] = new bubuzhongzi();
            cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
            cm->count++;
            break;
            }
        }
    });
    connect(cm,&cardsmenu::xrq,this,[=](){
    for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new xianrenqiu();
              cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
            cm->count++;
            break;
                }      }
    });
    connect(cm,&cardsmenu::xdy,this,[=](){
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new xiaodouya();
           cb->cardsPaint(i);
            cm->count++;
                        break;
                }
        }
    });
    connect(cm,&cardsmenu::yy,this,[=](){
 for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new yiyi();

            cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
            cm->count++;
                        break;
                }
        }
    });
    connect(cm,&cardsmenu::yiy,this,[=](){

            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new yiyou();

            cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
            cm->count++;
                        break;
                }
        }
    });
    connect(cm,&cardsmenu::be,this,[=](){
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new beier();

            cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
            cm->count++;
                        break;
                }
        }
    });
    connect(cm,&cardsmenu::gdy,this,[=](){
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new guodongya();

            cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
            cm->count++;
                        break;
                }
        }
    });
    connect(cm,&cardsmenu::bbl,this,[=](){
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new baobeili();

            cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
            cm->count++;
                        break;
                }
        }
    });
    connect(cm,&cardsmenu::xhh,this,[=](){
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new xiaohuohou();

            cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
            cm->count++;
                        break;
                }
        }
    });
    connect(cm,&cardsmenu::je,this,[=](){
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new jier();

            cb->cardsPaint(i);

//            scene->addItem(cb->cards[count]);
            cm->count++;
                        break;
                }
        }
    });
    connect(cm,&cardsmenu::hly,this,[=](){
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new huliya();

            cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
           cm-> count++;
                       break;
                }
        }
    });
    connect(cm,&cardsmenu::dd,this,[=](){
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new dida();

            cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
            cm->count++;
                        break;
        }
            }
    });
    connect(cm,&cardsmenu::dgl,this,[=](){
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new dugulu();

            cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
            cm->count++;
                        break;
                }
        }
    });
    connect(cm,&cardsmenu::xk,this,[=](){
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new xinke();

            cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
            cm->count++;
                        break;
                }
        }
    });
    connect(cm,&cardsmenu::ag,this,[=](){
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new agong();

            cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
            cm->count++;
                        break;
                }
        }
    });
    connect(cm,&cardsmenu::td,this,[=](){
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new taida();

            cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
           cm-> count++;
                       break;
                }
        }
    });
//如果游戏尚在选卡阶段（levelMode==0） 点击卡片栏上的卡片则取消这张卡的选中
//如果游戏正式开始（levelMode==1） 点击卡片栏上的卡片则种植
    for(int j=0;j<5;j++)
    {
        connect(cb->headButton[j],&QPushButton::clicked,[=](){
         if(this->levelMode==0)
            {
             for(int i=0;i<16;i++)
        {
            if(cb->cards[j]->No==i+1)
            {

                cm->p_PB[i]->setEnabled(true);
                cm->p_PB[i]->setStyleSheet("background-image:url(:/partner/resource/partner/cardshead/"+cb->cards[j]->name.toLower()+".png)");

                cb->headButton[j]->hide();
                cb->cards[j] = new none();
                cm->count--;
                cb->cards_num--;
                break;
            }
         }
        }
         else if(this->levelMode!=0)
            {
                 if(Cards::diamondTotal>=cb->cards[j]->price)
                 {QApplication::restoreOverrideCursor();
                 QCursor ptn(QPixmap(":/partner/resource/partner/stand_"+cb->cards[j]->name.toLower()+".gif"));
                 QApplication::setOverrideCursor(ptn);
                 map->preparedPtn = cb->cards[j];}
         }
    });
    }


    connect(this,&Level::gamestart,[=](){


        view->show();
        gametime->start(10);
        connect(gametime,&QTimer::timeout,scene,&QGraphicsScene::advance);

        connect(gametime,&QTimer::timeout,[=](){  cb->diamond_view->setText(QString::number(Cards::diamondTotal));});

        connect(diamondtimer,&QTimer::timeout,[=](){
           Cards::diamondTotal+=2;
        });

    });

}
