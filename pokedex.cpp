#include "pokedex.h"
#include "ui_pokedex.h"
#include <QBitmap>
#include <QtGui>
#include <QHBoxLayout>
#include <QLabel>
#include <QMovie>
#include <QButtonGroup>
pokedex::pokedex(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pokedex)
{
    ui->setupUi(this);
    setFixedSize(1366,911);

    //按钮隐藏
    ui->pushButtonfireh->hide();
    ui->pushButtonfirej->hide();
    ui->pushButtonfirel->hide();
    ui->pushButtonfireljls->hide();
    ui->pushButtonfirem->hide();
    ui->pushButtonfirex->hide();
    ui->pushButtonwateryy->hide();

    QPixmap pix;
    //火属性选择按钮
    pix.load(":/background/resource/background/shuxing_fire.png");
    ui->pushButtonfire->setFixedSize(pix.size());
    ui->pushButtonfire->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/shuxing_fire.png);}"
                                   "QPushButton:pressed{background-image : url(:/background/resource/background/xvanzhong_fire.png);}");
    ui->pushButtonfire->setMask(pix.mask());

    //水属性选择按钮
    pix.load(":/background/resource/background/shuxing_water.png");
    ui->pushButtonwater->setFixedSize(pix.size());
    ui->pushButtonwater->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/shuxing_water.png);}"
                                   "QPushButton:pressed{background-image : url(:/background/resource/background/xvanzhong_water.png);}");
    ui->pushButtonwater->setMask(pix.mask());

    //草属性选择按钮
    pix.load(":/background/resource/background/shuxing_grass.png");
    ui->pushButtongrass->setFixedSize(pix.size());
    ui->pushButtongrass->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/shuxing_grass.png);}"
                                   "QPushButton:pressed{background-image : url(:/background/resource/background/xvanzhong_grass.png);}");
    ui->pushButtongrass->setMask(pix.mask());

    //普通属性选择按钮
    pix.load(":/background/resource/background/shuxing_normal.png");
    ui->pushButtonnormal->setFixedSize(pix.size());
    ui->pushButtonnormal->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/shuxing_normal.png);}"
                                   "QPushButton:pressed{background-image : url(:/background/resource/background/xvanzhong_normal.png);}");
    ui->pushButtonnormal->setMask(pix.mask());

    //小火猴查看按钮
    pix.load(":/partner/resource/partner/head_firem.png");
    ui->pushButtonfirem->setFixedSize(pix.size());
    ui->pushButtonfirem->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/head_firem.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/head_firem2.png);}");
    ui->pushButtonfirem->setMask(pix.mask());

    //烈火猴查看按钮
    pix.load(":/partner/resource/partner/head_fireh.png");
    ui->pushButtonfireh->setFixedSize(pix.size());
    ui->pushButtonfireh->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/head_fireh.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/head_fireh2.png);}");
    ui->pushButtonfireh->setMask(pix.mask());

    //烈焰猩猩查看按钮
    pix.load(":/partner/resource/partner/head_firex.png");
    ui->pushButtonfirex->setFixedSize(pix.size());
    ui->pushButtonfirex->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/head_firex.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/head_firex2.png);}");
    ui->pushButtonfirex->setMask(pix.mask());

    //吉尔查看按钮
    pix.load(":/partner/resource/partner/head_firej.png");
    ui->pushButtonfirej->setFixedSize(pix.size());
    ui->pushButtonfirej->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/head_firej.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/head_firej2.png);}");
    ui->pushButtonfirej->setMask(pix.mask());

    //里诺查看按钮
    pix.load(":/partner/resource/partner/head_firel.png");
    ui->pushButtonfirel->setFixedSize(pix.size());
    ui->pushButtonfirel->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/head_firel.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/head_firel2.png);}");
    ui->pushButtonfirel->setMask(pix.mask());

    //洛吉拉斯查看按钮
    pix.load(":/partner/resource/partner/head_fireljls.png");
    ui->pushButtonfireljls->setFixedSize(pix.size());
    ui->pushButtonfireljls->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/head_fireljls.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/head_fireljls2.png);}");
    ui->pushButtonfireljls->setMask(pix.mask());

    //伊优查看按钮
    pix.load(":/partner/resource/partner/head_wateryy.png");
    ui->pushButtonwateryy->setFixedSize(pix.size());
    ui->pushButtonwateryy->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/head_wateryy.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/head_wateryy2.png);}");
    ui->pushButtonwateryy->setMask(pix.mask());


//    QButtonGroup * box = new QButtonGroup;
//    // 设置是否互斥
//    box->setExclusive(true);
//    // 将需要互斥的按钮全部添加到 QButtonGroup 中
//    box->addButton(ui->pushButtonfire);
//    box->addButton(ui->pushButtongrass);
//    box->addButton(ui->pushButtonwater);
//    box->addButton(ui->pushButtonnormal);
//	box->addButton(ui.pushButton_5);
//	box->addButton(ui.pushButton_6);
//	box->addButton(ui.pushButton_7);
//	box->addButton(ui.pushButton_8);
//	box->addButton(ui.pushButton_9);
//	box->addButton(ui.pushButton_10);

//    box->setExclusive(false);
//    // 将需要互斥的按钮全部添加到 QButtonGroup 中
//    box->addButton(ui->pushButtonfireh);
//    box->addButton(ui->pushButtonfirej);
//    box->addButton(ui->pushButtonfirel);
//    box->addButton(ui->pushButtonfirem);
//    box->addButton(ui->pushButtonfirex);
//    box->addButton(ui->pushButtonfireljls);
//    box->addButton(ui->pushButtonwateryy);
//	box->addButton(ui.pushButton_8);
//	box->addButton(ui.pushButton_9);
//	box->addButton(ui.pushButton_10);

    pdbackPushButton *Close = new pdbackPushButton();

    Close->setParent(this);

//    Close->setFixedSize(pix.size());
//    Close->setMask(pix.mask()); Close->move(1280,30); Close->setStyleSheet("border-image: url(:/background/resource/background/backmoto.png)");


    Close->setCursor(QCursor(Qt::PointingHandCursor));

    connect(Close,&pdbackPushButton::backpress,[=](){emit this->back();qDebug()<<"?";});

    this->setStyleSheet("QPushButton{background-color:transparent}");

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
    ui->pushButtonfireh->show();
    ui->pushButtonfirej->show();
    ui->pushButtonfirel->show();
    ui->pushButtonfireljls->show();
    ui->pushButtonfirem->show();
    ui->pushButtonfirex->show();
    ui->pushButtonwateryy->hide();
    ui->pushButtonfire->setDown(true);//写到最后
}

void pokedex::on_pushButtonwater_clicked()
{
    ui->pushButtonfireh->hide();
    ui->pushButtonfirej->hide();
    ui->pushButtonfirel->hide();
    ui->pushButtonfireljls->hide();
    ui->pushButtonfirem->hide();
    ui->pushButtonfirex->hide();
    ui->pushButtonwateryy->show();
    ui->pushButtonwater->setDown(true);//写到最后
}

void pokedex::on_pushButtongrass_clicked()
{
    ui->pushButtonfireh->hide();
    ui->pushButtonfirej->hide();
    ui->pushButtonfirel->hide();
    ui->pushButtonfireljls->hide();
    ui->pushButtonfirem->hide();
    ui->pushButtonfirex->hide();
     ui->pushButtongrass->setDown(true);
}

void pokedex::on_pushButtonnormal_clicked()
{
    ui->pushButtonfireh->hide();
    ui->pushButtonfirej->hide();
    ui->pushButtonfirel->hide();
    ui->pushButtonfireljls->hide();
    ui->pushButtonfirem->hide();
    ui->pushButtonfirex->hide();
    ui->pushButtonnormal->setDown(true);
}


void pokedex::on_pushButtonfirem_clicked()
{

       QMovie * movie=new QMovie(":/partner/resource/partner/stand_firem.gif");
       ui->label->setAlignment(Qt::AlignRight);
       ui->label->setMovie(movie);
       movie->start();
       ui->label->move(700,550);
        ui->pushButtonfirem->setDown(true);
}

void pokedex::on_pushButtonfireh_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/stand_fireh.gif");
   ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(760,450);
    ui->pushButtonfireh->setDown(true);
}

void pokedex::on_pushButtonfirex_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/stand_firex.gif");
   ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(810,450);
    ui->pushButtonfirex->setDown(true);
}

void pokedex::on_pushButtonfirej_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/stand_fierj.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(700,650);
    ui->pushButtonfirej->setDown(true);
}

void pokedex::on_pushButtonfirel_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/stand_firel.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(690,630);
    ui->pushButtonfirel->setDown(true);
}


void pokedex::on_pushButtonfireljls_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/stand_fireljls.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(990,580);
    ui->pushButtonfireljls->setDown(true);
}

void pokedex::on_pushButtonwateryy_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/stand_wateryy.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(650,650);
    ui->pushButtonwateryy->setDown(true);
}
