#include "cards.h"

int Cards::diamondTotal =50;

Cards::Cards()
{
    this->startMode = 0;//选卡阶段
}
Cards::~Cards()
{

}

void Cards::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
//    QImage image(":/graphics/Cards/card_" + name.toLower() + ".png");
//    painter->drawImage(boundingRect(), image);
//    if(sunTotal < sunNeed)
//    {
//        painter->setBrush(QColor(128, 128, 0, 200));
//        painter->drawRect(boundingRect());
//    }
//    if(counter < coolTime && !StartMode && isPlanted)
//    {
//        painter->setBrush(QColor(0, 0, 0, 200));
//        painter->drawRect(QRectF(425+60*No, 10, 50, 70*(1-qreal(counter)/coolTime)));
//    }
}
void Cards::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}
void Cards::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}
void Cards::advance(int phase)
{

}

QRectF Cards::boundingRect() const
{
//    return QRectF(111+120*this->chooseNum,15,this->head.width(),this->head.height());
}

//草系精灵
//1-草 2-水 3-火 4-普通
bubuzhongzi::bubuzhongzi()
{
    name="BubuZhongzi";coolTime=227;No=1;
    zuanshiNeed=25;
    isLocked=0;
    head.load(":/partner/resource/partner/1/1_head.png");
}
xianrenqou::xianrenqou()
{
    name="XianRenQou";coolTime=227;No=2;
    zuanshiNeed=25;
    isLocked=0;
     head.load(":/partner/resource/partner/1/16_head.png");
}
xiaodouya::xiaodouya()
{
    name="XiaoDouYa";coolTime=227;No=3;
    zuanshiNeed=25;
    isLocked=0;
    head.load(":/partner/resource/partner/1/27_head.png");
}
yiyi::yiyi()
{
    name="YiYi";coolTime=227;No=4;
    zuanshiNeed=25;
    isLocked=0;
    head.load(":/partner/resource/partner/1/83_head.png");
}

//水系精灵
yiyou::yiyou()
{
    name="YiYou";coolTime=227;No=5;
    zuanshiNeed=25;
    isLocked=1;
    head.load(":/partner/resource/partner/2/4_head.png");
}
beier::beier()
{
    name="BeiEr";coolTime=227;No=6;
    zuanshiNeed=25;
    isLocked=0;
    head.load(":/partner/resource/partner/2/30_head.png");
}
guodongya::guodongya()
{
    name="GuoDongYa";coolTime=227;No=7;
    zuanshiNeed=25;
    isLocked=1;
     head.load(":/partner/resource/partner/2/74_head.png");
}
baobeili::baobeili()
{
    name="BaoBeiLi";coolTime=227;No=8;
    zuanshiNeed=25;
    isLocked=0;
     head.load(":/partner/resource/partner/2/346.png");
}

//火系精灵
xiaohuohou::xiaohuohou()
{
    name="XiaoHuoHou";coolTime=227;No=9;
    zuanshiNeed=25;
    isLocked=0;
    head.load(":/partner/resource/partner/3/7_head.png");
}
jier::jier()
{
    name="JiEr";coolTime=227;No=10;
    zuanshiNeed=25;
    isLocked=0;
    head.load(":/partner/resource/partner/3/35_head.png");
}
huliya::huliya()
{
    name="HuLiYa";coolTime=227;No=11;
    zuanshiNeed=25;
    isLocked=0;
    head.load(":/partner/resource/partner/3/41_head.png");
}

dida::dida()
{
    name="DiDa";coolTime=227;No=12;
    zuanshiNeed=25;
    isLocked=0;
    head.load(":/partner/resource/partner/3/89_head.png");
}

//普通系
dugulu::dugulu()
{
    name="DuGuLu";coolTime=227;No=13;
    zuanshiNeed=25;
    isLocked=0;
    head.load(":/partner/resource/partner/4/254_head.png");
}
xinke::xinke()
{
    name="XinKe";coolTime=227;No=14;
    zuanshiNeed=25;
    isLocked=0;
    head.load(":/partner/resource/partner/4/328_head.png");
}
agong::agong()
{
    name="AGone";coolTime=227;No=15;
    zuanshiNeed=25;
    isLocked=0;
    head.load(":/partner/resource/partner/4/456_head.png");
}
taida::taida()
{
    name="TaiDa";coolTime=227;No=16;
    zuanshiNeed=25;
    isLocked=0;
    head.load(":/partner/resource/partner/4/690_head.png");
}
none::none()
{

}



