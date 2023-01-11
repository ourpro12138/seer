#include "cardsmenu.h"
#include "ui_cardsmenu.h"
#include <QDebug>

cardsmenu::cardsmenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cardsmenu)
{
    ui->setupUi(this);
    this->setFixedSize(1366,911);
    this->setStyleSheet("background-color:transparent");

    Cards *P_all[16] = {new bubuzhongzi,new xianrenqou,new xiaodouya,new yiyi,new yiyou,new beier,new guodongya,new baobeili,new xiaohuohou,
                        new jier, new huliya,new dida, new dugulu, new xinke,new agong ,new taida};


    for(int i=0;i<16;i++)
    {
        p_PB[i] = new QPushButton(this);
        p_PB[i]->setFixedSize(P_all[i]->head.size());
        p_PB[i]->hide();
    }
    p_PB[0]->setStyleSheet("background-image:url(:/partner/resource/partner/1/1_head.png)");
    p_PB[1]->setStyleSheet("background-image:url(:/partner/resource/partner/1/16_head.png)");
    p_PB[2]->setStyleSheet("background-image:url(:/partner/resource/partner/1/27_head.png)");
    p_PB[3]->setStyleSheet("background-image:url(:/partner/resource/partner/1/83_head.png)");
    p_PB[4]->setStyleSheet("background-image:url(:/partner/resource/partner/2/4_head.png)");
    p_PB[5]->setStyleSheet("background-image:url(:/partner/resource/partner/2/30_head.png)");
    p_PB[6]->setStyleSheet("background-image:url(:/partner/resource/partner/2/74_head.png)");
    p_PB[7]->setStyleSheet("background-image:url(:/partner/resource/partner/2/346.png)");
    p_PB[8]->setStyleSheet("background-image:url(:/partner/resource/partner/3/7_head.png)");
    p_PB[9]->setStyleSheet("background-image:url(:/partner/resource/partner/3/35_head.png)");
    p_PB[10]->setStyleSheet("background-image:url(:/partner/resource/partner/3/41_head.png)");
    p_PB[11]->setStyleSheet("background-image:url(:/partner/resource/partner/3/89_head.png)");
    p_PB[12]->setStyleSheet("background-image:url(:/partner/resource/partner/4/254_head.png)");
    p_PB[13]->setStyleSheet("background-image:url(:/partner/resource/partner/4/328_head.png)");
    p_PB[14]->setStyleSheet("background-image:url(:/partner/resource/partner/4/456_head.png)");
    p_PB[15]->setStyleSheet("background-image:url(:/partner/resource/partner/4/690_head.png)");
    for(int i=0;i<16;i++)
    {
        if(!P_all[i]->isLocked)
        {
            p_PB[i]->show();
        }
    }
    int count=0;


    for(int i=0;i<3;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(!P_all[count]->isLocked)
            {
                p_PB[count]->move(33+i*132,161+j*169);
                qDebug()<<count<<" "<<i<<" "<<j;
            }
            count++;
            qDebug()<<count;
        }
    }

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
