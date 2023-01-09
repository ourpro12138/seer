#include "pokedex.h"
#include "ui_pokedex.h"
#include <QBitmap>
#include <QtGui>

pokedex::pokedex(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pokedex)
{
    ui->setupUi(this);
    setFixedSize(1366,911);
//    QPalette pal =this->palette();
//    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/background/resource/background/backgd.png")));
//    setPalette(pal);


//    void setCursor(const QCursor &);

    QPixmap pix;

    pix.load(":/background/resource/background/backmoto.png");
    pdbackPushButton *Close = new pdbackPushButton();
    Close->setParent(this);
    Close->setFixedSize(pix.size()); Close->setMask(pix.mask()); Close->move(1280,30); Close->setStyleSheet("border-image: url(:/background/resource/background/backmoto.png)");


    Close->setCursor(QCursor(Qt::PointingHandCursor));
    connect(Close,&pdbackPushButton::backpress,this,&pokedex::back);

}

pokedex::~pokedex()
{
    delete ui;
}
void pokedex::back()
{

    this->hide();
}

void pokedex::paintEvent(QPaintEvent *)
{
    QPainter *painter = new QPainter(this);
    QPixmap pix;
    pix.load(":/background/resource/background/backgd.png");
    painter->drawPixmap(0,0,pix);
}
