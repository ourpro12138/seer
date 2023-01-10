#include "level.h"
#include "ui_level.h"

Level::Level(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Level)
{
    ui->setupUi(this);
    isLocked =0;
}

Level::~Level()
{
    delete ui;
}

void Level::paintEvent(QPaintEvent *)
{


}
kls::kls()
{

}

hek::hek()
{

}
hs::hs()
{

}
beta::beta()
{

}
hm::hm()
{

}
final::final()
{

}
