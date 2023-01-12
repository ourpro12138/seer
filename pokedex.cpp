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

    //火系
    ui->pushButtonfireh->hide();
    ui->pushButtonfirej->hide();
    ui->pushButtonfirel->hide();
    ui->pushButtonfireljls->hide();
    ui->pushButtonfirem->hide();
    ui->pushButtonfirex->hide();
    ui->pushButtonfirehly->hide();
    ui->pushButtonfirelos->hide();
    ui->pushButtondierk->hide();
    ui->pushButtonfiredierk->hide();

    //水系
    ui->pushButtonwateryy->hide();
    ui->pushButtonyourian->hide();
    ui->pushButtonbarus->hide();
    ui->pushButtonbara->hide();
    ui->pushButtonjieni->hide();
    ui->pushButtonbaragui->hide();
    ui->pushButtonyaya->hide();
    ui->pushButtonyayaa->hide();
    ui->pushButtonsyaya->hide();
    ui->pushButtonbbl->hide();
    ui->pushButtonfishdrgon->hide();
    ui->pushButtonking->hide();







    //草系
    ui->pushButtonbubu->hide();






    //普通系
    ui->pushButtonguru->hide();



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
    pix.load(":/partner/resource/partner/pokedex_head/fire/head_firem.png");
    ui->pushButtonfirem->setFixedSize(pix.size());
    ui->pushButtonfirem->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_firem.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_firem2.png);}");
    ui->pushButtonfirem->setMask(pix.mask());

    //烈火猴查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/fire/head_fireh.png");
    ui->pushButtonfireh->setFixedSize(pix.size());
    ui->pushButtonfireh->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_fireh.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_fireh2.png);}");
    ui->pushButtonfireh->setMask(pix.mask());

    //烈焰猩猩查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/fire/head_firex.png");
    ui->pushButtonfirex->setFixedSize(pix.size());
    ui->pushButtonfirex->setStyleSheet("QPushButton{background-image : url(://partner/resource/partner/pokedex_head/fire/head_firex.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_firex2.png);}");
    ui->pushButtonfirex->setMask(pix.mask());

    //吉尔查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/fire/head_firej.png");
    ui->pushButtonfirej->setFixedSize(pix.size());
    ui->pushButtonfirej->setStyleSheet("QPushButton{background-image : url(://partner/resource/partner/pokedex_head/fire/head_firej.png);}"
                                       "QPushButton:pressed{background-image : url(://partner/resource/partner/pokedex_head/fire/head_firej2.png);}");
    ui->pushButtonfirej->setMask(pix.mask());

    //里诺查看按钮
    pix.load("://partner/resource/partner/pokedex_head/fire/head_firel.png");
    ui->pushButtonfirel->setFixedSize(pix.size());
    ui->pushButtonfirel->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_firel.png);}"
                                       "QPushButton:pressed{background-image : url(://partner/resource/partner/pokedex_head/fire/head_firel2.png);}");
    ui->pushButtonfirel->setMask(pix.mask());

    //洛吉拉斯查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/fire/head_fireljls.png");
    ui->pushButtonfireljls->setFixedSize(pix.size());
    ui->pushButtonfireljls->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_fireljls.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_fireljls2.png);}");
    ui->pushButtonfireljls->setMask(pix.mask());

    //胡莉娅查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/fire/head_firehly.png");
    ui->pushButtonfirehly->setFixedSize(pix.size());
    ui->pushButtonfirehly->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_firehly.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_firehly2.png);}");
    ui->pushButtonfirehly->setMask(pix.mask());

    //里奥斯查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/fire/head_firelos.png");
    ui->pushButtonfirelos->setFixedSize(pix.size());
    ui->pushButtonfirelos->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_firelos.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_firelos2.png);}");
    ui->pushButtonfirelos->setMask(pix.mask());

    //迪克查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/fire/head_dierk.png");
    ui->pushButtondierk->setFixedSize(pix.size());
    ui->pushButtondierk->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_dierk.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_dierk2.png);}");
    ui->pushButtondierk->setMask(pix.mask());

    //迪尔克查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/fire/head_firedierk.png");
    ui->pushButtonfiredierk->setFixedSize(pix.size());
    ui->pushButtonfiredierk->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_firedierk.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_firedierk2.png);}");
    ui->pushButtonfiredierk->setMask(pix.mask());

//水系
    //伊优查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/water/head_wateryy.png");
    ui->pushButtonwateryy->setFixedSize(pix.size());
    ui->pushButtonwateryy->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/water/head_wateryy.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/water/head_wateryy2.png);}");
    ui->pushButtonwateryy->setMask(pix.mask());

    //尤利安
    pix.load(":/partner/resource/partner/pokedex_head/water/head_yourian.png");
    ui->pushButtonyourian->setFixedSize(pix.size());
    ui->pushButtonyourian->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/water/head_yourian.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/water/head_yourian2.png);}");
    ui->pushButtonyourian->setMask(pix.mask());

    //巴鲁斯
    pix.load(":/partner/resource/partner/pokedex_head/water/head_barus.png");
    ui->pushButtonbarus->setFixedSize(pix.size());
    ui->pushButtonbarus->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/water/head_barus.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/water/head_barus2.png);}");
    ui->pushButtonbarus->setMask(pix.mask());


    //小龟龟
    pix.load(":/partner/resource/partner/pokedex_head/water/head_bara.png");
    ui->pushButtonbara->setFixedSize(pix.size());
    ui->pushButtonbara->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/water/head_bara.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/water/head_bara2.png);}");
    ui->pushButtonbara->setMask(pix.mask());


    //小龟
    pix.load(":/partner/resource/partner/pokedex_head/water/head_jieni.png");
    ui->pushButtonjieni->setFixedSize(pix.size());
    ui->pushButtonjieni->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/water/head_jieni.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/water/head_jieni2.png);}");
    ui->pushButtonjieni->setMask(pix.mask());


    //巴拉龟
    pix.load(":/partner/resource/partner/pokedex_head/water/head_baragui.png");
    ui->pushButtonbaragui->setFixedSize(pix.size());
    ui->pushButtonbaragui->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/water/head_baragui.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/water/head_baragui2.png);}");
    ui->pushButtonbaragui->setMask(pix.mask());


    //鸭鸭
    pix.load(":/partner/resource/partner/pokedex_head/water/head_yaya.png");
    ui->pushButtonyaya->setFixedSize(pix.size());
    ui->pushButtonyaya->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/water/head_yaya.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/water/head_yaya2.png);}");
    ui->pushButtonyaya->setMask(pix.mask());


    //鸭鸭鸭
    pix.load(":/partner/resource/partner/pokedex_head/water/head_yayaa.png");
    ui->pushButtonyayaa->setFixedSize(pix.size());
    ui->pushButtonyayaa->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/water/head_yayaa.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/water/head_yayaa2.png);}");
    ui->pushButtonyayaa->setMask(pix.mask());


    //水晶鸭
    pix.load(":/partner/resource/partner/pokedex_head/water/head_syaya.png");
    ui->pushButtonsyaya->setFixedSize(pix.size());
    ui->pushButtonsyaya->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/water/head_syaya.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/water/head_syaya2.png);}");
    ui->pushButtonsyaya->setMask(pix.mask());



    //宝贝鲤
    pix.load(":/partner/resource/partner/pokedex_head/water/head_bbl.png");
    ui->pushButtonbbl->setFixedSize(pix.size());
    ui->pushButtonbbl->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/water/head_bbl.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/water/head_bbl2.png);}");
    ui->pushButtonbbl->setMask(pix.mask());



    //远古鱼龙
    pix.load(":/partner/resource/partner/pokedex_head/water/head_fishdrgon.png");
    ui->pushButtonfishdrgon->setFixedSize(pix.size());
    ui->pushButtonfishdrgon->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/water/head_fishdrgon.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/water/head_fishdrgon2.png);}");
    ui->pushButtonfishdrgon->setMask(pix.mask());



    //鱼龙王
    pix.load(":/partner/resource/partner/pokedex_head/water/head_king.png");
    ui->pushButtonking->setFixedSize(pix.size());
    ui->pushButtonking->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/water/head_king.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/water/head_king2.png);}");
    ui->pushButtonking->setMask(pix.mask());







//草系
    //布布种子查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/grass/head_bubu.png");
    ui->pushButtonbubu->setFixedSize(pix.size());
    ui->pushButtonbubu->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_bubu.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_bubu2.png);}");
    ui->pushButtonbubu->setMask(pix.mask());


















//普通系
    //咕噜查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/normal/head_guru.png");
    ui->pushButtonguru->setFixedSize(pix.size());
    ui->pushButtonguru->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/normal/head_guru.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/normal/head_guru2.png);}");
    ui->pushButtonguru->setMask(pix.mask());


//    QButtonGroup * box = new QButtonGroup;
//    设置是否互斥
//    box->setExclusive(true);
//    将需要互斥的按钮全部添加到 QButtonGroup 中
//    box->addButton(ui->pushButtonfire);
//    box->addButton(ui->pushButtongrass);
//    box->addButton(ui->pushButtonwater);
//    box->addButton(ui->pushButtonnormal);
//	  box->addButton(ui.pushButton_5);
//	  box->addButton(ui.pushButton_6);
//	  box->addButton(ui.pushButton_7);
//	  box->addButton(ui.pushButton_8);
//	  box->addButton(ui.pushButton_9);
//	  box->addButton(ui.pushButton_10);

//    box->setExclusive(false);
//    将需要互斥的按钮全部添加到 QButtonGroup 中
//    box->addButton(ui->pushButtonfireh);
//    box->addButton(ui->pushButtonfirej);
//    box->addButton(ui->pushButtonfirel);
//    box->addButton(ui->pushButtonfirem);
//    box->addButton(ui->pushButtonfirex);
//    box->addButton(ui->pushButtonfireljls);
//    box->addButton(ui->pushButtonwateryy);
//	  box->addButton(ui.pushButton_8);
//	  box->addButton(ui.pushButton_9);
//	  box->addButton(ui.pushButton_10);

    pdbackPushButton *Close = new pdbackPushButton();

    Close->setParent(this);

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

//按钮隐藏与展示：先隐藏后展示
void pokedex::on_pushButtonfire_clicked()
{
    //隐藏草系精灵按钮
    ui->pushButtonbubu->hide();

    //隐藏普通系精灵按钮
    ui->pushButtonguru->hide();

    //隐藏水系精灵按钮
    ui->pushButtonwateryy->hide();
    ui->pushButtonyourian->hide();
    ui->pushButtonbarus->hide();
    ui->pushButtonbara->hide();
    ui->pushButtonjieni->hide();
    ui->pushButtonbaragui->hide();
    ui->pushButtonyaya->hide();
    ui->pushButtonyayaa->hide();
    ui->pushButtonsyaya->hide();
    ui->pushButtonbbl->hide();
    ui->pushButtonfishdrgon->hide();
    ui->pushButtonking->hide();

    //展示火系精灵按钮
    ui->pushButtonfireh->show();
    ui->pushButtonfirej->show();
    ui->pushButtonfirel->show();
    ui->pushButtonfireljls->show();
    ui->pushButtonfirem->show();
    ui->pushButtonfirex->show();
    ui->pushButtonfirehly->show();
    ui->pushButtonfirelos->show();
    ui->pushButtondierk->show();
    ui->pushButtonfiredierk->show();

    ui->pushButtonfire->setDown(true);//写到最后
}

void pokedex::on_pushButtonwater_clicked()
{
    //隐藏火系精灵按钮
    ui->pushButtonfireh->hide();
    ui->pushButtonfirej->hide();
    ui->pushButtonfirel->hide();
    ui->pushButtonfireljls->hide();
    ui->pushButtonfirem->hide();
    ui->pushButtonfirex->hide();
    ui->pushButtonfirehly->hide();
    ui->pushButtonfirelos->hide();
    ui->pushButtondierk->hide();
    ui->pushButtonfiredierk->hide();

    //隐藏草系精灵按钮
    ui->pushButtonbubu->hide();

    //隐藏普通系精灵按钮
    ui->pushButtonguru->hide();

    //展示水系精灵按钮
    ui->pushButtonwateryy->show();
    ui->pushButtonyourian->show();
    ui->pushButtonbarus->show();
    ui->pushButtonbara->show();
    ui->pushButtonjieni->show();
    ui->pushButtonbaragui->show();
    ui->pushButtonyaya->show();
    ui->pushButtonyayaa->show();
    ui->pushButtonsyaya->show();
    ui->pushButtonbbl->show();
    ui->pushButtonfishdrgon->show();
    ui->pushButtonking->show();


    ui->pushButtonwater->setDown(true);//写到最后
}

void pokedex::on_pushButtongrass_clicked()
{
    //隐藏火系精灵按钮
    ui->pushButtonfireh->hide();
    ui->pushButtonfirej->hide();
    ui->pushButtonfirel->hide();
    ui->pushButtonfireljls->hide();
    ui->pushButtonfirem->hide();
    ui->pushButtonfirex->hide();
    ui->pushButtonfirehly->hide();
    ui->pushButtonfirelos->hide();
    ui->pushButtondierk->hide();
    ui->pushButtonfiredierk->hide();


    //隐藏水系精灵按钮
    ui->pushButtonwateryy->hide();
    ui->pushButtonyourian->hide();
    ui->pushButtonbarus->hide();
    ui->pushButtonbara->hide();
    ui->pushButtonjieni->hide();
    ui->pushButtonbaragui->hide();
    ui->pushButtonyaya->hide();
    ui->pushButtonyayaa->hide();
    ui->pushButtonsyaya->hide();
    ui->pushButtonbbl->hide();
    ui->pushButtonfishdrgon->hide();
    ui->pushButtonking->hide();


    //隐藏普通系精灵按钮
    ui->pushButtonguru->hide();


    //展示草系精灵按钮
    ui->pushButtonbubu->show();


     ui->pushButtongrass->setDown(true);
}

void pokedex::on_pushButtonnormal_clicked()
{
    //隐藏火系精灵按钮
    ui->pushButtonfireh->hide();
    ui->pushButtonfirej->hide();
    ui->pushButtonfirel->hide();
    ui->pushButtonfireljls->hide();
    ui->pushButtonfirem->hide();
    ui->pushButtonfirex->hide();
    ui->pushButtonfirehly->hide();
    ui->pushButtonfirelos->hide();
    ui->pushButtondierk->hide();
    ui->pushButtonfiredierk->hide();

    //隐藏水系精灵按钮
    ui->pushButtonwateryy->hide();
    ui->pushButtonyourian->hide();
    ui->pushButtonbarus->hide();
    ui->pushButtonbara->hide();
    ui->pushButtonjieni->hide();
    ui->pushButtonbaragui->hide();
    ui->pushButtonyaya->hide();
    ui->pushButtonyayaa->hide();
    ui->pushButtonsyaya->hide();
    ui->pushButtonbbl->hide();
    ui->pushButtonfishdrgon->hide();
    ui->pushButtonking->hide();

    //隐藏草系精灵按钮
    ui->pushButtonbubu->hide();


    //展示普通系精灵按钮
    ui->pushButtonguru->show();

    ui->pushButtonnormal->setDown(true);
}

//火系精灵展示触发按钮
void pokedex::on_pushButtonfirem_clicked()
{

       QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/fire/stand_firem.gif");
       ui->label->setAlignment(Qt::AlignRight);
       ui->label->setMovie(movie);
       movie->start();
       ui->label->move(700,550);
        ui->pushButtonfirem->setDown(true);
}

void pokedex::on_pushButtonfireh_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/fire/stand_fireh.gif");
   ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(760,450);
    ui->pushButtonfireh->setDown(true);
}

void pokedex::on_pushButtonfirex_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/fire/stand_firex.gif");
   ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(810,450);
    ui->pushButtonfirex->setDown(true);
}

void pokedex::on_pushButtonfirej_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/fire/stand_fierj.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(700,650);
    ui->pushButtonfirej->setDown(true);
}

void pokedex::on_pushButtonfirel_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/fire/stand_firel.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(690,630);
    ui->pushButtonfirel->setDown(true);
}


void pokedex::on_pushButtonfireljls_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/fire/stand_fireljls.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(990,580);
    ui->pushButtonfireljls->setDown(true);
}



void pokedex::on_pushButtonfirehly_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/fire/stand_huriya.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(720,570);
    ui->pushButtonfirehly->setDown(true);
}

void pokedex::on_pushButtonfirelos_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/fire/stand_los.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(760,360);
    ui->pushButtonfirelos->setDown(true);
}

void pokedex::on_pushButtondierk_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/fire/stand_dierk.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(760,660);
    ui->pushButtondierk->setDown(true);
}

void pokedex::on_pushButtonfiredierk_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/fire/stand_firedierk.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(760,450);
    ui->pushButtonfiredierk->setDown(true);
}

//水系精灵触发展示按钮
void pokedex::on_pushButtonwateryy_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_wateryy.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(650,650);
    ui->pushButtonwateryy->setDown(true);
}

void pokedex::on_pushButtonyourian_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_yourian.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(680,490);
    ui->pushButtonyourian->setDown(true);
}

void pokedex::on_pushButtonbarus_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_barus.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(800,430);
    ui->pushButtonbarus->setDown(true);
}

void pokedex::on_pushButtonbara_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_bara.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(700,660);
    ui->pushButtonbara->setDown(true);
}

void pokedex::on_pushButtonjieni_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_jieni.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(720,650);
    ui->pushButtonjieni->setDown(true);
}

void pokedex::on_pushButtonbaragui_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_baragui.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(720,650);
    ui->pushButtonbaragui->setDown(true);
}

void pokedex::on_pushButtonyaya_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_yaya.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(660,680);
    ui->pushButtonyaya->setDown(true);
}

void pokedex::on_pushButtonyayaa_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_yayaa.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(670,650);
    ui->pushButtonyayaa->setDown(true);
}

void pokedex::on_pushButtonsyaya_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_syaya.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(700,560);
    ui->pushButtonsyaya->setDown(true);
}

void pokedex::on_pushButtonbbl_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_bbl.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(690,650);
    ui->pushButtonbbl->setDown(true);
}

void pokedex::on_pushButtonfishdrgon_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_fishdrgon.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(760,350);
    ui->pushButtonfishdrgon->setDown(true);
}

void pokedex::on_pushButtonking_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_king.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(730,260);
    ui->pushButtonking->setDown(true);
}


//草系精灵触发展示按钮
void pokedex::on_pushButtonbubu_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/grass/stand_bubu.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(680,600);
    ui->pushButtonbubu->setDown(true);
}


//普通系精灵触发展示按钮
void pokedex::on_pushButtonguru_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/normal/stand_guru.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(680,660);
    ui->pushButtonguru->setDown(true);
}










