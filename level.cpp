#include "level.h"
#include "ui_level.h"

Level::Level(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Level)
{
    ui->setupUi(this);
    isLocked =0;
    this->setFixedSize(1366,911);
    this->hide();
}

Level::~Level()
{
    delete ui;
}

void Level::paintEvent(QPaintEvent *)
{

   QPainter painter(this);
   QPixmap map;
   map.load(":/map/resource/map/"+levelName+".png");
   painter.drawPixmap(-200,0,map);

}
kls::kls()
{
    levelName = "kls";
}

hek::hek()
{

}
hs::hs()
{

}
alpha::alpha()
{

}
hm::hm()
{

}
final::final()
{

}
