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

    Cards *P_all[16] = {new bubuzhongzi,new xianrenqiu,new xiaodouya,new yiyi,new yiyou,new beier,new guodongya,new baobeili,new xiaohuohou,
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
//    int count=0;


//    for(int i=0;i<3;i++)
//    {
//        for(int j=0;j<5;j++)
//        {
//            if(!P_all[count]->isLocked)
//            {
//                p_PB[count]->move(33+i*132,161+j*169);
//                qDebug()<<count<<" "<<i<<" "<<j;
//            }
//            count++;
//            qDebug()<<count;
//        }
//    }

    int h=0,l=0;
    for(int i =0;i<16;i++)
    {
        if(!P_all[i]->isLocked)
        {
            qDebug()<<h<<" "<<l<<" "<<P_all[i]->name;
            p_PB[i]->move(33+l*132,161+h*169);
            if(l<4)
            {
                l++;
            }
            else if(l==4)
            {
                l=0;
                h++;
            }
        }
    }


    connect(p_PB[0],&QPushButton::clicked,this,[=](){
        if(count<5)
        {
        qDebug()<<count;
        emit bbzz();
        p_PB[0]->setStyleSheet("background-image:url(:/partner/resource/partner/cardshead/1_clicked.png)");
        p_PB[0]->setEnabled(false);
        }
    });
    connect(p_PB[1],&QPushButton::clicked,this,[=](){
        if(count<5)
        {emit xrq();
        p_PB[1]->setStyleSheet("background-image:url(:/partner/resource/partner/cardshead/16_clicked.png)");
        p_PB[1]->setEnabled(false);}
    });
    connect(p_PB[2],&QPushButton::clicked,this,[=](){
        if(count<5)
        {emit xdy();
        p_PB[2]->setStyleSheet("background-image:url(:/partner/resource/partner/cardshead/27_clicked.png)");
        p_PB[2]->setEnabled(false);}
    });
    connect(p_PB[3],&QPushButton::clicked,this,[=](){
        if(count<5){
        emit yy();
        p_PB[3]->setStyleSheet("background-image:url(:/partner/resource/partner/cardshead/83_clicked.png)");
        p_PB[3]->setEnabled(false);}
    });
    connect(p_PB[4],&QPushButton::clicked,this,[=](){
          if(count<5){
        emit yiy();
        p_PB[4]->setStyleSheet("background-image:url(:/partner/resource/partner/cardshead/4_clicked.png)");
        p_PB[4]->setEnabled(false);};
    });
    connect(p_PB[5],&QPushButton::clicked,this,[=](){
        if(count<5){
        emit be();
        p_PB[5]->setStyleSheet("background-image:url(:/partner/resource/partner/cardshead/30_clicked.png)");
        p_PB[5]->setEnabled(false);};
    });
    connect(p_PB[6],&QPushButton::clicked,this,[=](){
        if(count<5){
        emit gdy();
        p_PB[6]->setStyleSheet("background-image:url(:/partner/resource/partner/cardshead/74_clicked.png)");
        p_PB[6]->setEnabled(false);};
    });
    connect(p_PB[7],&QPushButton::clicked,this,[=](){
        if(count<5){
        emit bbl();
        p_PB[7]->setStyleSheet("background-image:url(:/partner/resource/partner/cardshead/346_clicked.png)");
        p_PB[7]->setEnabled(false);};
    });
    connect(p_PB[8],&QPushButton::clicked,this,[=](){
        if(count<5){
        emit xhh();
        p_PB[8]->setStyleSheet("background-image:url(:/partner/resource/partner/cardshead/7_clicked.png)");
        p_PB[8]->setEnabled(false);};
    });
    connect(p_PB[9],&QPushButton::clicked,this,[=](){
        if(count<5){
        emit je();
        p_PB[9]->setStyleSheet("background-image:url(:/partner/resource/partner/cardshead/35_clicked.png)");
        p_PB[9]->setEnabled(false);};
    });
    connect(p_PB[10],&QPushButton::clicked,this,[=](){
        if(count<5){
        emit hly();
        p_PB[10]->setStyleSheet("background-image:url(:/partner/resource/partner/cardshead/41_clicked.png)");
        p_PB[10]->setEnabled(false);};
    });
    connect(p_PB[11],&QPushButton::clicked,this,[=](){
        if(count<5){
        emit dd();
        p_PB[11]->setStyleSheet("background-image:url(:/partner/resource/partner/cardshead/89_clicked.png)");
        p_PB[11]->setEnabled(false);};
    });
    connect(p_PB[12],&QPushButton::clicked,this,[=](){
        if(count<5){
        emit dgl();
        p_PB[12]->setStyleSheet("background-image:url(:/partner/resource/partner/cardshead/254_clicked.png)");
        p_PB[12]->setEnabled(false);};
    });
    connect(p_PB[13],&QPushButton::clicked,this,[=](){
        if(count<5){
        emit xk();
        p_PB[13]->setStyleSheet("background-image:url(:/partner/resource/partner/cardshead/328_clicked.png)");
        p_PB[13]->setEnabled(false);};
    });
    connect(p_PB[14],&QPushButton::clicked,this,[=](){
        if(count<5){
        emit ag();
        p_PB[14]->setStyleSheet("background-image:url(:/partner/resource/partner/cardshead/456_clicked.png)");
        p_PB[14]->setEnabled(false);};
    });
    connect(p_PB[15],&QPushButton::clicked,this,[=](){
        if(count<5){
        emit td();
        p_PB[15]->setStyleSheet("background-image:url(:/partner/resource/partner/cardshead/690_clicked.png)");
        p_PB[15]->setEnabled(false);};
    });

//    if(!P_all[15]->isLocked)
//    {
//        p_PB[15]->move(33,161+3*169);
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
