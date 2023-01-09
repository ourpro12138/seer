#ifndef STARTPUSHBUTTON_H
#define STARTPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QPropertyAnimation>

class StartPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit StartPushButton(QWidget *parent = nullptr);


    StartPushButton(QString normalImg,QString pressImg="");
    QString normalImgPath;//默认显示图片的路径
    QString pressImgPath;//按下后显示的图片的路径


    //向下跳跃
    void zoom1();
    //向上跳跃
    void zoom2();
    //鼠标按下事件
    void enterEvent(QEvent *e);
    //鼠标松开事件
    void leaveEvent(QEvent *e);



};

#endif // STARTPUSHBUTTON_H
