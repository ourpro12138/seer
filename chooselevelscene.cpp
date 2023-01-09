#include "chooselevelscene.h"
#include "startpushbutton.h"
#include <QLabel>
#include <QMovie>
#include <QtCore>
#include <QPushButton>
#include "QBitmap"
#include<QMediaPlayer>
#include <QMediaPlaylist>

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QWidget(parent)
{
    //设置固定大小
    this->setFixedSize(1366,911);
//    //设置标题B
//    this->setWindowTitle("赛尔号");
//    //设置图片
//    this->setWindowIcon(QIcon(":/res/tubiao.png"));


    this->setStyleSheet("QPushButton{background-color:transparent}");

    QLabel * label=new QLabel();
    QMovie * movie=new QMovie(":/background/resource/background/3.gif");
    label->setMovie(movie);
    movie->start();
    label->setParent(this);
    label->move(850,550);



//    QPropertyAnimation * animation=new QPropertyAnimation(this,"windowOpacity");
//    animation->setDuration(1000);
//    animation->setStartValue(0);
//    animation->setEndValue(1);
//    animation->start();

    QMediaPlayer * music = new QMediaPlayer(this);
    QMediaPlaylist *playlist = new QMediaPlaylist(this);
//    QMediaPlaylist *playlist=new QMediaPlaylist(this);
    playlist->addMedia(QUrl::fromEncoded("qrc:/music/resource/music/loginback.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
//    /*playlist->addMedia(QUrl::fromEncoded("qrc:/music/resource/music/loginback.mp3"));
//    playlist->addMedia(QUrl::fromEncoded("qrc:/music/resource/music/loginback.mp3")*/);
music->setPlaylist(playlist);
  music->play();

    QPushButton *gogogo = new QPushButton();
    gogogo->setParent(this);
    QPixmap Gogogo(":/background/resource/background/goicon.png");
    gogogo->setMask(Gogogo.mask());
    gogogo->setFixedSize(Gogogo.size());
    gogogo->setStyleSheet("QPushButton{background-image: url(:/background/resource/background/goicon.png)}"
                          "QPushButton:hover{background-image: url(:/background/resource/background/goicon_hover.png)}"
                          "QPushButton:pressed{background-image: url(:/background/resource/background/goicon.png)}"
                          );
    gogogo->move(990,302);

    QPushButton *unkown = new QPushButton();
    unkown->setParent(this);
    QPixmap Unkown(":/background/resource/background/unkown.png");
    unkown->setMask(Unkown.mask());
    unkown->setFixedSize(Unkown.size());
    unkown->setStyleSheet("QPushButton{background-image: url(:/background/resource/background/unkown.png)}"
                          "QPushButton:hover{background-image: url(:/background/resource/background/unkown_hover.png)}"
                          "QPushButton:pressed{background-image: url(:/background/resource/background/unkown.png)}"
                          );
    unkown->move(560,124);


    QPushButton *home = new QPushButton();
    home->setParent(this);
    QPixmap Home(":/background/resource/background/home.png");
    home->setMask(Home.mask());
    home->setFixedSize(Home.size());
    home->setStyleSheet("QPushButton{background-image: url(:/background/resource/background/home.png)}"
                          "QPushButton:hover{background-image: url(:/background/resource/background/return_hover.png)}"
                          "QPushButton:pressed{background-image: url(:/background/resource/background/home.png)}"
                          );
    home->move(732,252);

    QPushButton *pdx = new QPushButton();
    pdx->setParent(this);
    QPixmap Pdx(":/background/resource/background/pdx.png");
    pdx->setMask(Pdx.mask());
    pdx->setFixedSize(Pdx.size());
    pdx->setStyleSheet("QPushButton{background-image: url(:/background/resource/background/pdx.png)}"
                          "QPushButton:hover{background-image: url(:/background/resource/background/pdx_hover.png)}"
                          "QPushButton:pressed{background-image: url(:/background/resource/background/pdx.png)}"
                          );
    pdx->move(350,339);


    connect(gogogo,&QPushButton::clicked,this,&ChooseLevelScene::chooseLevel);

    connect(pdx,&QPushButton::clicked,this,&ChooseLevelScene::pdx);

    connect(home,&QPushButton::clicked,this,&ChooseLevelScene::returnstart);

}


void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    //背景图片
    QPainter painter(this);
    QPixmap pix21;
    pix21.load(":/background/resource/background/bigmap.png");

    painter.drawPixmap(0,0,this->width(),this->height(),pix21);

    painter.end();
}
