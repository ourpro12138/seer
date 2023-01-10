#include "choosescene.h"
#include "ui_choosescene.h"

choosescene::choosescene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::choosescene)
{
    ui->setupUi(this);
    setFixedSize(1366,911);

    this->setStyleSheet("QPushButton{background-color:transparent}");
    for(int i =0;i<Level_num;i++)
        choosebutton[i] = new QPushButton(this);
    QPixmap pix;
    pix.load(":/background/resource/background/xingqiu2.png");
    choosebutton[0]->setFixedSize(pix.size());
    choosebutton[0]->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/xingqiu2.png);}"
                                   "QPushButton:pressed{background-image : url(:/background/resource/background/xingqiu2_clicked.png);}");
    choosebutton[0]->setMask(pix.mask());
    choosebutton[0]->move(490,150);

    pix.load(":/background/resource/background/xingqiu1.png");
    choosebutton[1]->setFixedSize(pix.size());
    choosebutton[1]->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/xingqiu1.png);}"
                                    "QPushButton:pressed{background-image : url(:/background/resource/background/xingqiu1_clicked.png);}");
    choosebutton[1]->setMask(pix.mask());
    choosebutton[1]->move(140,360);

    pix.load(":/background/resource/background/xingqiu3.png");
    choosebutton[2]->setFixedSize(pix.size());
    choosebutton[2]->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/xingqiu3.png);}"
                                    "QPushButton:pressed{background-image : url(:/background/resource/background/xingqiu3_clicked.png);}");
    choosebutton[2]->setMask(pix.mask());
    choosebutton[2]->move(260,750);

    pix.load(":/background/resource/background/xingqiu4.png");
    choosebutton[3] ->setFixedSize(pix.size());
    choosebutton[3] ->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/xingqiu4.png);}"
                                    "QPushButton:pressed{background-image : url(:/background/resource/background/xingqiu4_clicked.png);}");
    choosebutton[3] ->setMask(pix.mask());
    choosebutton[3]->move(800,760);

    pix.load(":/background/resource/background/xingqiu6.png");
    choosebutton[4]->setFixedSize(pix.size());
    choosebutton[4]->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/xingqiu6.png);}"
                                    "QPushButton:pressed{background-image : url(:/background/resource/background/xingqiu6_clicked.png);}");
    choosebutton[4]->setMask(pix.mask());
    choosebutton[4]->move(970,390);

    pix.load(":/background/resource/background/xingqiu5.png");
    choosebutton[5]->setFixedSize(pix.size());
    choosebutton[5]->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/xingqiu5.png);}"
                                    "QPushButton:pressed{background-image : url(:/background/resource/background/xingqiu5_clicked.png);}");
    choosebutton[5]->setMask(pix.mask());
    choosebutton[5]->move(600,490);

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
