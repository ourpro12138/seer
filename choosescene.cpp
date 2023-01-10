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
    QPushButton *choosebutton1 = new QPushButton(this);
    pix.load(":/background/resource/background/xingqiu1.png");
    choosebutton1->setFixedSize(pix.size());
    choosebutton1->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/xingqiu1.png);}"
                                   "QPushButton:pressed{background-image : url(:/background/resource/background/xingqiu1_clicked.png);}");
   choosebutton1->setMask(pix.mask());
   choosebutton1->move(490,150);

   QPushButton *choosebutton2 = new QPushButton(this);
    pix.load(":/background/resource/background/xingqiu2.png");
    choosebutton2->setFixedSize(pix.size());
    choosebutton2->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/xingqiu2.png);}"
                                    "QPushButton:pressed{background-image : url(:/background/resource/background/xingqiu2_clicked.png);}");
    choosebutton2->setMask(pix.mask());
    choosebutton2->move(140,360);

    QPushButton *choosebutton3 = new QPushButton(this);
    pix.load(":/background/resource/background/xingqiu3.png");
    choosebutton3->setFixedSize(pix.size());
    choosebutton3->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/xingqiu3.png);}"
                                    "QPushButton:pressed{background-image : url(:/background/resource/background/xingqiu3_clicked.png);}");
    choosebutton3->setMask(pix.mask());
    choosebutton3->move(260,750);

    QPushButton *choosebutton4 = new QPushButton(this);
    pix.load(":/background/resource/background/xingqiu4.png");
    choosebutton4 ->setFixedSize(pix.size());
    choosebutton4 ->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/xingqiu4.png);}"
                                    "QPushButton:pressed{background-image : url(:/background/resource/background/xingqiu4_clicked.png);}");
    choosebutton4 ->setMask(pix.mask());
    choosebutton4->move(800,760);

    QPushButton *choosebutton5 = new QPushButton(this);
    pix.load(":/background/resource/background/xingqiu5.png");
    choosebutton5->setFixedSize(pix.size());
    choosebutton5->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/xingqiu5.png);}"
                                    "QPushButton:pressed{background-image : url(:/background/resource/background/xingqiu5_clicked.png);}");
    choosebutton5->setMask(pix.mask());
    choosebutton5->move(970,390);

    QPushButton *choosebutton6 = new QPushButton(this);
    pix.load(":/background/resource/background/xingqiu6.png");
    choosebutton6->setFixedSize(pix.size());
    choosebutton6->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/xingqiu6.png);}"
                                    "QPushButton:pressed{background-image : url(:/background/resource/background/xingqiu6_clicked.png);}");
    choosebutton6->setMask(pix.mask());
    choosebutton6->move(600,490);

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
