#include "pokedex.h"
#include "ui_pokedex.h"
#include <QBitmap>
#include <QtGui>

pokedex::pokedex(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pokedex)
{
    ui->setupUi(this);
    setFixedSize(1366,911);
//    QPalette pal =this->palette();
//    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/background/resource/background/backgd.png")));
//    setPalette(pal);


//    void setCursor(const QCursor &);

//    QPixmap pix;

//    pix.load(":/background/resource/background/backmoto.png");

    QPixmap pix;
    pix.load(":/background/resource/background/shuxing_fire.png");
    ui->pushButtonfire->setFixedSize(pix.size());
    ui->pushButtonfire->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/shuxing_fire.png);}"
                                   "QPushButton:pressed{background-image : url(:/background/resource/background/xvanzhong_fire.png);}");
    ui->pushButtonfire->setMask(pix.mask());


//    QPixmap pix;
    pix.load(":/background/resource/background/shuxing_water.png");
    ui->pushButtonwater->setFixedSize(pix.size());
    ui->pushButtonwater->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/shuxing_water.png);}"
                                   "QPushButton:pressed{background-image : url(:/background/resource/background/xvanzhong_water.png);}");
    ui->pushButtonwater->setMask(pix.mask());

    pix.load(":/background/resource/background/shuxing_grass.png");
    ui->pushButtongrass->setFixedSize(pix.size());
    ui->pushButtongrass->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/shuxing_grass.png);}"
                                   "QPushButton:pressed{background-image : url(:/background/resource/background/xvanzhong_grass.png);}");
    ui->pushButtongrass->setMask(pix.mask());

    pix.load(":/background/resource/background/shuxing_normal.png");
    ui->pushButtonnormal->setFixedSize(pix.size());
    ui->pushButtonnormal->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/shuxing_normal.png);}"
                                   "QPushButton:pressed{background-image : url(:/background/resource/background/xvanzhong_normal.png);}");
    ui->pushButtonnormal->setMask(pix.mask());

//    pix.load(":/background/resource/background/shuxing_grass.png");
//    ui->pushButtonzip->setFixedSize(pix.size());
//    ui->pushButtonzip->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/shuxing_grass.png);}"
//                                   "QPushButton:pressed{background-image : url(:/background/resource/background/xvanzhong_grass.png);}");
//    ui->pushButtonzip->setMask(pix.mask());

    pdbackPushButton *Close = new pdbackPushButton();
    Close->setParent(this);
//    Close->setFixedSize(pix.size());
//    Close->setMask(pix.mask()); Close->move(1280,30); Close->setStyleSheet("border-image: url(:/background/resource/background/backmoto.png)");


    Close->setCursor(QCursor(Qt::PointingHandCursor));

    connect(Close,&pdbackPushButton::backpress,[=](){emit this->back();qDebug()<<"?";});

}

pokedex::~pokedex()
{
    delete ui;
}

void pokedex::paintEvent(QPaintEvent *)
{
    QPainter *painter = new QPainter(this);
    QPixmap pix;
    pix.load(":/background/resource/background/backgd.png");
    painter->drawPixmap(0,0,pix);
    painter->end();
}

void pokedex::on_pushButtonfire_clicked()
{
    ui->pushButtonfire->setDown(true);//写到最后
}

void pokedex::on_pushButtonwater_clicked()
{
    ui->pushButtonwater->setDown(true);//写到最后
}

void pokedex::on_pushButtongrass_clicked()
{
     ui->pushButtongrass->setDown(true);
}

void pokedex::on_pushButtonnormal_clicked()
{
    ui->pushButtonnormal->setDown(true);
}

//void pokedex::on_pushButtonzip_clicked()
//{
//    ui->pushButtonzip->setDown(true);
//}
