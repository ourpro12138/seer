#include "startscene.h"
#include "ui_startscene.h"

startscene::startscene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startscene)
{
    ui->setupUi(this);
}

startscene::~startscene()
{
    delete ui;
}
