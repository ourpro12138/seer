#include "maingame.h"
#include "ui_maingame.h"

maingame::maingame(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::maingame)
{

    ui->setupUi(this);
    this->setFixedSize(1366,911);
    cm = new cardsmenu(this);
    cm->hide();

    this->setWindowIcon(QIcon(":/background/resource/background/tubiao.png"));

    ss = new startscene(this);

    sc = new ChooseLevelScene(this);

    pd = new pokedex(this);

    cm = new cardsmenu(this);

    choose = new choosescene(this);

    sc->hide();
    pd->hide();
    cm->hide();
    choose->hide();

    connect(ss,&startscene::login,this,&maingame::loginGet);
    connect(sc,&ChooseLevelScene::chooseLevel,this,&maingame::chooseLevel);
    connect(sc,&ChooseLevelScene::pdx,this,&maingame::pdx);
    connect(sc,&ChooseLevelScene::returnstart,this,&maingame::returnstart);

    connect(pd,&pokedex::back,this,&maingame::loginGet);
    connect(choose,&choosescene::back,this,&maingame::loginGet);

    ss->show();

}

maingame::~maingame()
{
    delete ui;
    delete choose;
}
void maingame::loginGet()
{
    this->cm->hide();
    this->pd->hide();
    this->sc->show();
    this->ss->hide();
    this->choose->hide();
    qDebug()<<"what";
}

void maingame::chooseLevel()
{
    this->cm->hide();
    this->pd->hide();
    this->sc->hide();
    this->ss->hide();
    this->choose->show();
}

void maingame::pdx()
{
    this->cm->hide();
    this->pd->show();
    this->sc->hide();
    this->ss->hide();
    this->choose->hide();
}

void maingame::returnstart()
{
    this->cm->hide();
    this->pd->hide();
    this->sc->hide();
    this->ss->show();
    this->choose->hide();
}
