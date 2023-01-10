#include "choosescene.h"
#include "ui_choosescene.h"

choosescene::choosescene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::choosescene)
{
    ui->setupUi(this);
    setFixedSize(1366,911);

    this->setStyleSheet("QPushButton{background-color:transparent}");

    QPixmap pix;
    pix.load(":/background/resource/background/xingqiu1.png");
    ui->pushbutton->setFixedSize(pix.size());
    ui->pushbutton->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/xingqiu1.png);}"
                                   "QPushButton:pressed{background-image : url(:/background/resource/background/xingqiu1_clicked.png);}");
    ui->pushbutton->setMask(pix.mask());

    pix.load(":/background/resource/background/xingqiu2.png");
    ui->pushButton_2->setFixedSize(pix.size());
    ui->pushButton_2->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/xingqiu2.png);}"
                                    "QPushButton:pressed{background-image : url(:/background/resource/background/xingqiu2_clicked.png);}");
    ui->pushButton_2->setMask(pix.mask());

    pix.load(":/background/resource/background/xingqiu3.png");
    ui->pushButton_3->setFixedSize(pix.size());
    ui->pushButton_3->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/xingqiu3.png);}"
                                    "QPushButton:pressed{background-image : url(:/background/resource/background/xingqiu3_clicked.png);}");
    ui->pushButton_3->setMask(pix.mask());

    pix.load(":/background/resource/background/xingqiu4.png");
    ui->pushButton_4->setFixedSize(pix.size());
    ui->pushButton_4->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/xingqiu4.png);}"
                                    "QPushButton:pressed{background-image : url(:/background/resource/background/xingqiu4_clicked.png);}");
    ui->pushButton_4->setMask(pix.mask());

    pix.load(":/background/resource/background/xingqiu5.png");
    ui->pushButton_5->setFixedSize(pix.size());
    ui->pushButton_5->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/xingqiu5.png);}"
                                    "QPushButton:pressed{background-image : url(:/background/resource/background/xingqiu5_clicked.png);}");
    ui->pushButton_5->setMask(pix.mask());

    pix.load(":/background/resource/background/xingqiu6.png");
    ui->pushButton_6->setFixedSize(pix.size());
    ui->pushButton_6->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/xingqiu6.png);}"
                                    "QPushButton:pressed{background-image : url(:/background/resource/background/xingqiu6_clicked.png);}");
    ui->pushButton_6->setMask(pix.mask());

    pdbackPushButton *back = new pdbackPushButton();
    back->setParent(this);



    connect(back,&pdbackPushButton::backpress,this,&choosescene::back);




}

choosescene::~choosescene()
{
    delete ui;
}
void choosescene::paintEvent(QPaintEvent *)
{

    QPainter *painter = new QPainter(this);
    QPixmap pix;
    pix.load(":/background/resource/background/choosescene.png");
    painter->drawPixmap(0,0,this->width(),this->height(),pix);
    painter->end();

}
