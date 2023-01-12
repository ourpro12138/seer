#include "level.h"
#include "ui_level.h"


Level::Level(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Level)
{
    this->setStyleSheet("QPushButton{background-color:transparent}");

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
}

void Level::paintEvent(QPaintEvent *)
{

   QPainter painter(this);
   QPixmap map;
   map.load(":/map/resource/map/"+levelName+".png");
   painter.drawPixmap(0,0,map);
   painter.end();
}

void Level::GameStart()
{

    QTimer *timer = new QTimer(this);
    timer->start(3);
    cm->hide();

    connect(timer,&QTimer::timeout,this,[=](){
        qDebug()<<"moving"<<x;
        x++;
        this->move(x,0);
        this->cb->move(-x,0);
        if(x==0)
        {
            qDebug()<<"time stop";
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

    connect(Countinue,&QPushButton::clicked,this,[=](){
        GameStart();
        delete  Countinue;
    });

    Back = new pdbackPushButton();
    Back->setParent(this);
    connect(Back,&pdbackPushButton::backpress,this,[=](){
        emit this->back();
    });

    connect(cm,&cardsmenu::bbzz,this,[=](){
        if(cm->count<5)
        {
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
        }
    });
    connect(cm,&cardsmenu::xrq,this,[=](){
        if(cm->count<5)
        {
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new xianrenqou();
              cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
            cm->count++;
            break;
                }
            }
        }
    });
    connect(cm,&cardsmenu::xdy,this,[=](){
        if(cm->count<5)
        {
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new xiaodouya();
           cb->cardsPaint(i);
            cm->count++;
                        break;
                }}
        }
    });
    connect(cm,&cardsmenu::yy,this,[=](){
        if(cm->count<5)
        {
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new yiyi();

            cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
            cm->count++;
                        break;
                }}
        }
    });
    connect(cm,&cardsmenu::yiy,this,[=](){
        if(cm->count<5)
        {
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new yiyou();

            cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
            cm->count++;
                        break;
                }}
        }
    });
    connect(cm,&cardsmenu::be,this,[=](){
        if(cm->count<5)
        {
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new beier();

            cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
            cm->count++;
                        break;
                }}
        }
    });
    connect(cm,&cardsmenu::gdy,this,[=](){
        if(cm->count<5)
        {
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new guodongya();

            cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
            cm->count++;
                        break;
                }}
        }
    });
    connect(cm,&cardsmenu::bbl,this,[=](){
        if(cm->count<5)
        {
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new baobeili();

            cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
            cm->count++;
                        break;
                }}
        }
    });
    connect(cm,&cardsmenu::xhh,this,[=](){
        if(cm->count<5)
        {
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new xiaohuohou();

            cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
            cm->count++;
                        break;
                }}
        }
    });
    connect(cm,&cardsmenu::je,this,[=](){
        if(cm->count<5)
        {
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new jier();

            cb->cardsPaint(i);

//            scene->addItem(cb->cards[count]);
            cm->count++;
                        break;
                }}
        }
    });
    connect(cm,&cardsmenu::hly,this,[=](){
        if(cm->count<5)
        {
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new huliya();

            cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
           cm-> count++;
                       break;
                }}
        }
    });
    connect(cm,&cardsmenu::dd,this,[=](){
        if(cm->count<5)
        {
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
            }}
    });
    connect(cm,&cardsmenu::dgl,this,[=](){
        if(cm->count<5)
        {
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new dugulu();

            cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
            cm->count++;
                        break;
                }}
        }
    });
    connect(cm,&cardsmenu::xk,this,[=](){
        if(cm->count<5)
        {
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new xinke();

            cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
            cm->count++;
                        break;
                }}
        }
    });
    connect(cm,&cardsmenu::ag,this,[=](){
        if(cm->count<5)
        {
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new agong();

            cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
            cm->count++;
                        break;
                }}
        }
    });
    connect(cm,&cardsmenu::td,this,[=](){
        if(cm->count<5)
        {
            for(int i=0;i<5;i++)
            {
                if(cb->cards[i]->name=="none")
                {
            cb->cards[i] = new taida();

            cb->cardsPaint(i);
//            scene->addItem(cb->cards[count]);
           cm-> count++;
                       break;
                }}
        }
    });

    for(int j=0;j<5;j++)
    {
        connect(cb->headButton[j],&QPushButton::clicked,[=](){
        for(int i=0;i<16;i++)
        {
            if(cb->cards[j]->No==i+1)
            {

                cm->p_PB[i]->setEnabled(true);
                cm->p_PB[i]->setStyleSheet("background-image:url(:/partner/resource/partner/cardshead/"+cb->cards[j]->name.toLower()+".png)");

                cb->headButton[j]->hide();
                cb->cards[j] = new none();
                cm->count--;
            }
        }

    });
    }

//view->show();

}
