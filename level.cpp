#include "level.h"
#include "ui_level.h"
#include "moguguai.h"

Level::Level(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Level)
{
    this->setStyleSheet("QPushButton{background-color:transparent}");

    gametime = new QTimer(this);
    levelMode=0;//选卡阶段
    ui->setupUi(this);
    isLocked =0;
    this->setFixedSize(1566,911);
    this->hide();
    initlevel();
}

Level::~Level()
{
    delete ui;
    delete this->cb;
    delete this->cm;
    delete this->Back;
//    delete this->scene;
//    delete this->view;
//    delete this->map;
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
            emit gamestart();
            delete timer;
        }
    });

}
kls::kls()
{
    levelName = "kls";
}

hek::hek()
{
levelName = "hek";
}
hs::hs()
{
levelName = "hs";
}
alpha::alpha()
{
levelName = "alpha";
}
hm::hm()
{
levelName = "hm";
}
final::final()
{
levelName = "final";
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
            cb->cards[i] = new xianrenqou();
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
         else if(this->levelMode==1)
            {
                 //设置光标效果
                 QApplication::restoreOverrideCursor();
                 QCursor ptn(QPixmap(":/partner/resource/partner/stand_"+cb->cards[j]->name.toLower()+".gif"));
                 QApplication::setOverrideCursor(ptn);
                 map->preparedPtn = cb->cards[j];
         }
    });
    }



    connect(this,&Level::gamestart,[=](){
        view->show();
        gametime->start(10);
        connect(gametime,&QTimer::timeout,scene,&QGraphicsScene::advance);

    });


}
