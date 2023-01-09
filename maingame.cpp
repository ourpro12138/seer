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

}

maingame::~maingame()
{
    delete ui;
}

