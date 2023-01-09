#include "choosescene.h"
#include "ui_choosescene.h"

choosescene::choosescene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::choosescene)
{
    ui->setupUi(this);
}

choosescene::~choosescene()
{
    delete ui;
}
