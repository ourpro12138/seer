#include "cardsblank.h"
#include "ui_cardsblank.h"

cardsblank::cardsblank(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cardsblank)
{
    ui->setupUi(this);
    ui->label->move(45,90);
    this->setFixedSize(783,153);

    partner_num=0;
}

cardsblank::~cardsblank()
{
    delete ui;
}
void cardsblank::paintEvent(QPaintEvent *)
{
    QPainter *painter = new QPainter(this);
    QPixmap diamondnum,blank,diamond;
    diamondnum.load(":/background/resource/background/diamondkuang");
    blank.load(":/background/resource/background/blank.png");
    diamond.load(":/background/resource/background/diamond.png");
    painter->drawPixmap(0,0,blank);
    painter->drawPixmap(19,29,diamondnum);
    painter->drawPixmap(35,35,diamond);

    painter->end();
}
