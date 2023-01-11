#include "cardsmenu.h"
#include "ui_cardsmenu.h"

cardsmenu::cardsmenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cardsmenu)
{
    ui->setupUi(this);
    this->setFixedSize(1366,911);
    this->setStyleSheet("background-color:transparent");

    QPushButton *p_PB[16];

//    for(int i=0;i<16;i++)
//    {
//        if(P_all[i]->isLocked)
//        {
//            p_PB[i]->hide();
//        }
//        p_PB[i]->setParent(this);
//    }


}

cardsmenu::~cardsmenu()
{
    delete ui;
}
void cardsmenu::paintEvent(QPaintEvent *)
{
    QPainter *painter = new QPainter(this);

    QPixmap cardsmenu;
    cardsmenu.load(":/background/resource/background/choicemenu.png");
    painter->drawPixmap(0,0,cardsmenu);
    painter->end();



}
