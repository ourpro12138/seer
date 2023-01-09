#include "cardsmenu.h"
#include "ui_cardsmenu.h"

cardsmenu::cardsmenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cardsmenu)
{
    ui->setupUi(this);

    this->setFixedSize(1366,911);
    ui->label->move(45,90);
    this->setStyleSheet("background-color:transparent");

}

cardsmenu::~cardsmenu()
{
    delete ui;
}
void cardsmenu::paintEvent(QPaintEvent *)
{
    QPainter *painter = new QPainter(this);

    QPixmap cardsmenu,diamondnum,blank,diamond;
    cardsmenu.load(":/background/resource/background/choicemenu.png");
    diamondnum.load(":/background/resource/background/diamondkuang");
    blank.load(":/background/resource/background/blank.png");
    diamond.load(":/background/resource/background/diamond.png");
    painter->drawPixmap(0,0,cardsmenu);
    painter->drawPixmap(0,0,blank);
    painter->drawPixmap(19,29,diamondnum);
    painter->drawPixmap(35,35,diamond);

}
