#include "pokedex.h"
#include "ui_pokedex.h"

pokedex::pokedex(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pokedex)
{
    ui->setupUi(this);
}

pokedex::~pokedex()
{
    delete ui;
}
