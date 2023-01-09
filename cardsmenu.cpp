#include "cardsmenu.h"
#include "ui_cardsmenu.h"

cardsmenu::cardsmenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cardsmenu)
{
    ui->setupUi(this);
}

cardsmenu::~cardsmenu()
{
    delete ui;
}
