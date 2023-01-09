#include "chooselevelscene.h"
#include "startpushbutton.h"
#include <QLabel>
#include <QMovie>
#include <QtCore>
#include <QPushButton>
#include "QBitmap"
ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QWidget(parent)
{
    //设置固定大小
    this->setFixedSize(1366,911);
//    //设置标题B
//    this->setWindowTitle("赛尔号");
//    //设置图片
//    this->setWindowIcon(QIcon(":/res/tubiao.png"));

    //返回按钮创建
//    MyPushButton * backBtn=new MyPushButton(":/res/2.png");
//    backBtn->setParent(this);
//    backBtn->move(200,100);

    QLabel * label=new QLabel();
    QMovie * movie=new QMovie(":/background/resource/background/3.gif");
    label->setMovie(movie);
    movie->start();
    label->setParent(this);
    label->move(1090,630);



//    QPropertyAnimation * animation=new QPropertyAnimation(this,"windowOpacity");
//    animation->setDuration(1000);
//    animation->setStartValue(0);
//    animation->setEndValue(1);
//    animation->start();

//    QMediaPlayer * player = new QMediaPlayer;

//    player->setMedia(QUrl::fromEncoded("qrc:/res/Boss_sound.mp3"));
//    player->setVolume(80);
//    player->play();

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



}


void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    //背景图片
    QPainter painter(this);
    QPixmap pix21;
    pix21.load(":/background/resource/background/bigmap.png");

    painter.drawPixmap(0,0,this->width(),this->height(),pix21);
}
