#include "maingame.h"
#include "ui_maingame.h"
#include <QFileDialog>

maingame::maingame(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::maingame)
{


    ui->setupUi(this);
    this->setFixedSize(1366,911);


    this->setWindowIcon(QIcon(":/background/resource/background/tubiao.png"));

    ss = new startscene(this);

    sc = new ChooseLevelScene(this);

    pd = new pokedex(this);

//    cm = new cardsmenu(this);

    choose = new choosescene(this);


    level[0] = new kls;level[1] = new hek; level[2] = new hs;level[3] = new alpha; level[4] = new hm; level[5] = new final;
    for(int i =0;i<Level_num;i++)
    {
        level[i]->setParent(this);
        level[i]->hide();
    }

    sc->hide();
    pd->hide();
//    cm->hide();
    choose->hide();


    connect(ss,&startscene::login,this,&maingame::loginGet);
    connect(sc,&ChooseLevelScene::chooseLevel,this,&maingame::chooseLevel);
    connect(sc,&ChooseLevelScene::pdx,this,&maingame::pdx);
    connect(sc,&ChooseLevelScene::returnstart,this,&maingame::returnstart);

    connect(pd,&pokedex::back,this,&maingame::loginGet);
    connect(choose,&choosescene::back,this,&maingame::loginGet);

    //链接关卡退出与进入信号与槽的函数
    levelback();
    cardsUpdate();

    ss->show();
}

maingame::~maingame()
{
    delete ui;
    delete choose;
    //delete scene;
}
void maingame::loginGet()
{
//    this->cm->hide();
    this->pd->hide();
    this->sc->show();
    this->ss->hide();
    this->choose->hide();
    for(int i=0;i<Level_num;i++)
        this->level[i]->hide();
    savelevel();
    savecards();
    levelUpdate();
    cardsUpdate();
}

void maingame::chooseLevel()
{
//    this->cm->hide();
    this->pd->hide();
    this->sc->hide();
    this->ss->hide();
    this->choose->show();
    for(int i=0;i<Level_num;i++)
    {
        this->level[i]->hide();
    }
    savelevel();
    savecards();
    levelUpdate();
    cardsUpdate();
}
void maingame::returnchooselevel()
{
    for(int i=0;i<Level_num;i++)
    {
        delete level[i];
    }
    this->pd->hide();
    this->sc->hide();
    this->ss->hide();
    this->choose->show();
    level[0] = new kls();
    level[1] = new hek();
    level[2] = new hs();
    level[3] = new alpha();
    level[4] = new hm();
    level[5] = new final();
    for(int i =0;i<Level_num;i++)
    {
        level[i]->setParent(this);
    }
    //每次回到主菜单 重新连接一次信号与槽
    levelback();
}
void maingame::pdx()
{
//    this->cm->hide();
    this->pd->show();
    this->sc->hide();
    this->ss->hide();
    this->choose->hide();
    for(int i=0;i<Level_num;i++)
        this->level[i]->hide();
    savelevel();
    savecards();
    levelUpdate();
    cardsUpdate();
}

void maingame::returnstart()
{
//    this->cm->hide();
    this->pd->hide();
    this->sc->hide();
    this->ss->show();
    this->choose->hide();
    for(int i=0;i<Level_num;i++)
        this->level[i]->hide();
    savelevel();
    savecards();
    levelUpdate();
    cardsUpdate();
}

void maingame::levelback()
{
    for(int i=0;i<Level_num;i++)
    {

        connect(choose->choosebutton[i],&QPushButton::clicked,[=]()
        {
            Partner::parent=level[i];
            level[i]->show();
            sc->hide();
            pd->hide();
            choose->hide();
        });
        connect(level[i],&Level::back,this,&maingame::returnchooselevel);
    }

    //关卡更新，解锁关卡与每个关卡对应的按钮
    //每次回到选关的界面对关卡更新一次
    savelevel();
    savecards();
    levelUpdate();
    cardsUpdate();

}
void maingame::levelUpdate()
{

    QString path = "D:/seer/level.txt";
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        for(int i=1;i<Level_num;i++)
            level[i]->isLocked=1;
        level[0]->isLocked=0;
    }
    QByteArray save;
    int count=0;
    while(!file.atEnd())
    {
        save = file.readLine();
        level[count]->isLocked=save.toInt();
        count++;
    }

    for(int i=0;i<Level_num;i++)
    {
        if(level[i]->isLocked)
        {
            choose->choosebutton[i]->hide();
        }
    }
}

void maingame::savelevel()
{
    QString path = "D:/seer/level.txt";
    QFile file(path);
    file.open(QIODevice::WriteOnly|QIODevice::Text);

   QTextStream out(&file);
   for(int i=0;i<Level_num;i++)
   {
   out<<QString::number(level[i]->isLocked)<<"\n";
   }

    file.close();
}
void maingame::savecards()
{
    QString path = "D:/seer/card.txt";
    QFile file(path);
    file.open(QIODevice::WriteOnly|QIODevice::Text);

   QTextStream out(&file);
   for(int i=0;i<16;i++)
   {
   out<<QString::number(cardsmenu::P_all[i]->isLocked)<<"\n";
   }

    file.close();
}
void maingame::cardsUpdate()
{
    QString path = "D:/seer/card.txt";
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        for(int i=3;i<16;i++)
        {
            cardsmenu::P_all[i]->isLocked=1;
        }
    }
    QByteArray save;
    int count=0;
    while(!file.atEnd())
    {
        save = file.readLine();
        cardsmenu::P_all[count]->isLocked=save.toInt();
        count++;
    }
}
