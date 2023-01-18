#include "enemy.h"
#include "partner.h"
#include "level.h"
#include "map.h"

//QPushButton *Partner::skillButton;
//QPushButton *Partner::evolutionButton;
//QPushButton *Partner::capsuleButton;
QWidget *Partner::parent;



Partner::Partner()
{


    skillButton = new QPushButton(parent);
    evolutionButton = new QPushButton(parent);
    capsuleButton = new QPushButton(parent);
    skillButton->hide();
    evolutionButton->hide();
    capsuleButton->hide();

    QPixmap button;
    button.load(":/background/resource/background/partnerButton.png");
    skillButton->setStyleSheet("background-image:url(:/background/resource/background/partnerButton.png)");
    skillButton->setMask(button.mask());skillButton->setFixedSize(button.size());
    evolutionButton->setStyleSheet("background-image:url(:/background/resource/background/partnerButton.png)");
    evolutionButton->setMask(button.mask());evolutionButton->setFixedSize(button.size());
    capsuleButton->setStyleSheet("background-image:url(:/background/resource/background/partnerButton.png)");
    capsuleButton->setMask(button.mask());capsuleButton->setFixedSize(button.size());


    connect(evolutionButton,&QPushButton::clicked,this,&Partner::evolution);
    connect(capsuleButton,&QPushButton::clicked,this,[=](){
        delete this;
    });

    qDebug()<<"partner构造函数调用";
}
Partner::~Partner()
{
    delete skillButton;
    delete evolutionButton;
    delete capsuleButton;
}
//void partner::skill()
//{}

//void partner::evolution()
//{}
void Partner::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawImage(boundingRect(),atkmovie->currentImage());
}
QRectF Partner::boundingRect() const
{
    return QRectF(0,0,width,height);
}
void Partner::advance(int phase)
{
    if(!phase)
        return;
    update();

}

int Partner::type() const
{
return Type;
}
void Partner::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);




    QLabel *skill_num = new QLabel(skillButton);QLabel *evolution_num = new QLabel(evolutionButton);QLabel *capsule_num = new QLabel(capsuleButton);
    QLabel *icon_ev = new QLabel(evolutionButton);QLabel *icon_cap = new QLabel(capsuleButton);QLabel *icon_sk = new QLabel(skillButton);

//    skill_num->setStyleSheet("background-color:transparent");evolution_num->setStyleSheet("background-color:transparent");
//    capsule_num->setStyleSheet("background-color:transparent");icon_ev->setStyleSheet("background-color:transparent");
//    icon_cap->setStyleSheet("background-color:transparent");icon_sk->setStyleSheet("background-color:transparent");

    skill_num->setStyleSheet("color: rgb(255, 255, 255);font: 87 italic 8pt 'Arial Black'");
    evolution_num->setStyleSheet("color: rgb(255, 255, 255);font: 87 italic 8pt 'Arial Black'");
    capsule_num->setStyleSheet("color: rgb(255, 255, 255);font: 87 italic 8pt 'Arial Black'");

    skill_num->setText(QString::number(this->price_skill));
    evolution_num->setText(QString::number(price_ev));
    capsule_num->setText(QString::number(0));

    skill_num->move(34,60);evolution_num->move(34,60);capsule_num->move(34,60);
    icon_sk->setStyleSheet("color: rgb(255, 255, 255);font:italic 9pt 'Arial'");icon_sk->setText(skillname);
    icon_ev->setPixmap(QPixmap(":/background/resource/background/evolution.png"));
    icon_cap->setPixmap(QPixmap(":/background/resource/background/capsule.png"));

    icon_sk->move(12,30);icon_ev->move(20,23);icon_cap->move(23,18);

    skillButton->move(186+230*j,157-48+160*i);
    evolutionButton->move(219+230*j,237-48+160*i);
    capsuleButton->move(186+230*j,317-48+160*i);
if(skillButton->isHidden()&&evolutionButton->isHidden()&&capsuleButton->isHidden())
{
    skillButton->show();
    evolutionButton->show();
    capsuleButton->show();
}
else
{
        skillButton->hide();
        evolutionButton->hide();
        capsuleButton->hide();
}


}


