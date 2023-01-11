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

//    this->setStyleSheet("background-image:url(:/map/resource/map/"+levelName+".png)");
    this->move(-200,0);


    cm = new cardsmenu(this);
    cb = new cardsblank(this);

    cb->move(200,0);
    cm->move(200,0);

    pdbackPushButton *back = new pdbackPushButton();
    back->setParent(this);

    QPushButton *Countinue = new QPushButton(this);
    Countinue->setFixedSize(200,200);
    Countinue->move(1366,800);
    QPixmap pix;
    pix.load(":/background/resource/background/countinue.png");
    Countinue->setMask(pix.mask());
    Countinue->setStyleSheet("background-image:url(:/background/resource/background/countinue.png)");
//    Countinue->hide();

    connect(Countinue,&QPushButton::clicked,this,&Level::GameStart);


    connect(back,&pdbackPushButton::backpress,this,[=](){
        emit this->back();
//        delete this;
    });

}

Level::~Level()
{
    delete ui;
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
    static int x=-200;

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
            timer->stop();
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
