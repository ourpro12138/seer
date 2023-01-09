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

    connect(ss,&startscene::login,this,&maingame::loginGet);

    sc->hide();


    ss->show();
}

maingame::~maingame()
{
    delete ui;
    delete choose;
}
void maingame::loginGet()
{
    ss->hide();
    sc->show();
    qDebug()<<"what";
}

