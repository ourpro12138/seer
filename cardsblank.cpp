#include "cardsblank.h"
#include "ui_cardsblank.h"
#include <QDebug>
cardsblank::cardsblank(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cardsblank)
{
    ui->setupUi(this);

    for(int i=0;i<5;i++)
    {
        cards[i] = new none;

    }

    diamond_view = new QLabel(this);

    diamond_view->move(45,90);
    diamond_view->setStyleSheet("color: rgb(255, 255, 255);font: 75 italic 18pt 'Arial'");
    diamond_view->setText(QString::number(Cards::diamondTotal));
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
void cardsblank::cardsPaint(int count)
{

    QPixmap pix;

    pix.load(":/partner/resource/partner/cardshead/"+cards[count]->name.toLower()+".png");
    headButton[count]->setStyleSheet("background-image:url(:/partner/resource/partner/cardshead/"+cards[count]->name.toLower()+".png)");
    headButton[count]->setFixedSize(pix.size());
    headButton[count]->move(123+count*120,14);
    headButton[count]->show();

    cards_num++;
}
