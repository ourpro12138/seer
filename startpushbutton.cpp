#include "startpushbutton.h"
#include<QPropertyAnimation>
#include<QDebug>
StartPushButton::StartPushButton(QString normalImg,QString pressImg)
{
    //保存住 默认显示的路径 和按下后显示的路径
    this->normalImgPath=normalImg;
    this->pressImgPath=pressImg;

    QPixmap pix;
    bool ret=pix.load(this->normalImgPath);//加载默认的图片
    if(!ret)
    {
        QString str=QString("%1 图片加载失败");
        qDebug()<<str;
        return;
    }
    //设定图片大小
    this->setFixedSize(pix.width(),pix.height());
    //设置不规则图片的样式
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图片
    this->setIcon(pix);
    //设置图片的大小
    this->setIconSize(QSize(pix.width(),pix.height()));

}
//向下跳跃
void StartPushButton::zoom1()
{
   QPropertyAnimation * animation=new QPropertyAnimation(this,"geometry");
   //设定时间间隔
   animation->setDuration(200);
   //设置动态对象起始位置
   animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
   //设置动画对象结束位置
   animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
   //设置曲线
   animation->setEasingCurve(QEasingCurve::OutBounce);
   //执行动画
   animation->start();
}
//向上跳跃
void StartPushButton::zoom2()
{
    QPropertyAnimation * animation=new QPropertyAnimation(this,"geomerty");
    //设定时间间隔
    animation->setDuration(200);
    //设置动态对象起始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置动画对象结束位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();
}
//鼠标进入事件
void StartPushButton::enterEvent(QEvent *e)
{
    if(this->pressImgPath!="")
    {

        qDebug()<<this->pressImgPath;
        QPixmap pix1,pix2;
        pix1.load(":/background/resource/background/5.png");
        bool ret=pix2.load(this->pressImgPath);
        if(!ret)
        {
            qDebug()<<"图片加载失败";
        }



    this->setFixedSize(pix1.width(),pix1.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix2);

}
    //交给父类处理
    QPushButton::enterEvent(e);
}
//鼠标离开事件
void StartPushButton::leaveEvent(QEvent *e)
{
    if(this->pressImgPath!="")
    {
        QPixmap pix;
        bool ret=pix.load(this->normalImgPath);
        if(!ret)
        {
            qDebug()<<"图片加载失败";
        }



    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
}
    //交给父类处理
    QPushButton::leaveEvent(e);
}

