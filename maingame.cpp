#include "maingame.h"
#include "ui_maingame.h"

maingame::maingame(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::maingame)
{
    ui->setupUi(this);



}

maingame::~maingame()
{
    delete ui;
}

