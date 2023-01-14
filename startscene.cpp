#include "startscene.h"
#include "ui_startscene.h"
#include<QPainter>
#include<QMovie>
#include<QLabel>
#include<QTimer>
#include"chooselevelscene.h"
#include<startpushbutton.h>
startscene::startscene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startscene)
{
    ui->setupUi(this);


    //设置固定大小
    this->setFixedSize(1366,911);
    //设置标题A
   this->setWindowTitle("赛尔号");




    //gif动态图
    QLabel * label=new QLabel();
    QMovie * movie=new QMovie(":/background/resource/background/10.gif");
    label->setMovie(movie);
    movie->start();
    label->setParent(this);
    label->move(1090,790);



    QLabel * label2=new QLabel();
    QMovie * movie2=new QMovie(":/background/resource/background/2.gif");
    label2->setMovie(movie2);
    movie2->start();
    label2->setParent(this);
    label2->move(250,790);

    //设置登录按钮
    StartPushButton  * startBtn=new StartPushButton(":/background/resource/background/5.png",":/background/resource/background/6.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.8);

    connect(startBtn,&QPushButton::clicked,[=](){
        startBtn->zoom1();
        startBtn->zoom2();
        QTimer::singleShot(250,this,[=](){
                  emit this->login();
        });
    });





}




void startscene::paintEvent(QPaintEvent *)
{
    //背景图片
    QPainter painter(this);
    QPixmap pix2;
    pix2.load(":/background/resource/background/2.png");

    painter.drawPixmap(0,0,this->width(),this->height(),pix2);

    //标题图片
    QPixmap pix1;
    pix1.load(":/background/resource/background/1.png");
    pix1=pix1.scaled(pix1.width(),pix1.height());
    painter.drawPixmap(0,0,pix1);

    QPixmap pix3;
    pix3.load(":/background/resource/background/3.png");
    pix3=pix3.scaled(pix3.width(),pix3.height());
    painter.drawPixmap(700,320,pix3);


    QPixmap pix18;
    pix18.load(":/background/resource/background/18.png");
    pix18=pix18.scaled(pix18.width()*1.5,pix18.height()*2.1);
    painter.drawPixmap(780,790,pix18);

    QPixmap pix17;
    pix17.load(":/background/resource/background/17.png");
    pix17=pix17.scaled(pix17.width(),pix17.height());
    painter.drawPixmap(890,795,pix17);

    QPixmap pix20;
    pix20.load(":/background/resource/background/20.png");
    pix20=pix20.scaled(pix20.width()*1.4,pix20.height()*2);
    painter.drawPixmap(780,850,pix20);

    QPixmap pix19;
    pix19.load(":/background/resource/background/19.png");
    pix19=pix19.scaled(pix19.width(),pix19.height());
    painter.drawPixmap(890,860,pix19);

    QPixmap pix15;
    pix15.load(":/background/resource/background/15.png");
    pix15=pix15.scaled(pix15.width(),pix15.height());
    painter.drawPixmap(1310,5,pix15);

    QPixmap pix10;
    pix10.load(":/background/resource/background/10.png");
    pix10=pix10.scaled(pix10.width(),pix10.height());
    painter.drawPixmap(1270,760,pix10);

    QPixmap pix16;
    pix16.load(":/background/resource/background/16.png");
    pix16=pix16.scaled(pix16.width()*1.2,pix16.height()*1.1);
    painter.drawPixmap(1060,760,pix16);

    QPixmap pix9;
    pix9.load(":/background/resource/background/9.png");
    pix9=pix9.scaled(pix9.width(),pix9.height());
    painter.drawPixmap(1275,700,pix9);

    QPixmap pix23;
    pix23.load(":/background/resource/background/23.png");
    pix23=pix23.scaled(pix23.width(),pix23.height());
    painter.drawPixmap(589,712,pix23);

    QPixmap pix26;
    pix26.load(":/background/resource/background/26.png");
    pix26=pix26.scaled(pix26.width()*1.2,pix26.height()*1.2);
    painter.drawPixmap(485,830,pix26);

    QPixmap pix11;
    pix11.load(":/background/resource/background/11.png");
    pix11=pix11.scaled(pix11.width()*1.1,pix11.height()*1.1);
    painter.drawPixmap(960,865,pix11);

    QPixmap pix13;
    pix13.load(":/background/resource/background/13.png");
    pix13=pix13.scaled(pix13.width()*1.1,pix13.height()*1.1);
    painter.drawPixmap(960,825,pix13);


    QPixmap pix27;
    pix27.load(":/background/resource/background/27.png");
    pix27=pix27.scaled(pix27.width()*1.2,pix27.height()*1.2);
    painter.drawPixmap(380,830,pix27);

    painter.end();

}

startscene::~startscene()
{
    delete ui;
}
