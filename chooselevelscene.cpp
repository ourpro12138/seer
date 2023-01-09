#include "chooselevelscene.h"
#include"startpushbutton.h"
#include<QLabel>
#include<QMovie>
#include<QPropertyAnimation>
#include<QtCore>
#include<QtMultimedia>
#include<QMediaPlayer>
ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QWidget(parent)
{
    //设置固定大小
    this->setFixedSize(1366,911);
    //设置标题B
    this->setWindowTitle("赛尔号");
    //设置图片
    this->setWindowIcon(QIcon(":/res/tubiao.png"));

    //返回按钮创建
//    MyPushButton * backBtn=new MyPushButton(":/res/2.png");
//    backBtn->setParent(this);
//    backBtn->move(200,100);

    QLabel * label=new QLabel();
    QMovie * movie=new QMovie(":/res/3.gif");
    label->setMovie(movie);
    movie->start();
    label->setParent(this);
    label->move(1090,630);



    QPropertyAnimation * animation=new QPropertyAnimation(this,"windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();

    QMediaPlayer * player = new QMediaPlayer;

    player->setMedia(QUrl::fromEncoded("qrc:/res/Boss_sound.mp3"));
    player->setVolume(80);
    player->play();

}


void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    //背景图片
    QPainter painter(this);
    QPixmap pix21;
    pix21.load(":/res/21.png");

    painter.drawPixmap(0,0,this->width(),this->height(),pix21);
}
