#include "cardsblank.h"
#include "ui_cardsblank.h"

cardsblank::cardsblank(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cardsblank)
{
    ui->setupUi(this);

    diamond_view = new QLabel(this);

    diamond_view->move(45,90);
    diamond_view->setStyleSheet("color: rgb(255, 255, 255);font: 75 italic 18pt 'Arial'");
    diamond_view->setText("50");
    this->setFixedSize(783,153);



    cards_num=0;

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
