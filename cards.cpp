#include "cards.h"

Cards::Cards()
{
    this->startMode = 0;//选卡阶段
}
Cards::~Cards()
{

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
    isLocked=1;
     head.load(":/partner/resource/partner/1/16_head.png");
}
xiaodouya::xiaodouya()
{
    name="XiaoDouYa";coolTime=227;No=3;
    zuanshiNeed=25;
    isLocked=1;
    head.load(":/partner/resource/partner/1/27_head.png");
}
yiyi::yiyi()
{
    name="YiYi";coolTime=227;No=4;
    zuanshiNeed=25;
    isLocked=1;
    head.load(":/partner/resource/partner/1/83_head.png");
}

//水系精灵
yiyou::yiyou()
{
    name="YiYou";coolTime=227;No=5;
    zuanshiNeed=25;
    isLocked=0;
    head.load(":/partner/resource/partner/2/4_head.png");
}
beier::beier()
{
    name="BeiEr";coolTime=227;No=6;
    zuanshiNeed=25;
    isLocked=1;
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
    isLocked=1;
     head.load(":/partner/resource/partner/2/346_head.png");
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
    isLocked=1;
    head.load(":/partner/resource/partner/3/35_head.png");
}
huliya::huliya()
{
    name="HuLiYa";coolTime=227;No=11;
    zuanshiNeed=25;
    isLocked=1;
    head.load(":/partner/resource/partner/3/41_head.png");
}

dida::dida()
{
    name="DiDa";coolTime=227;No=12;
    zuanshiNeed=25;
    isLocked=1;
    head.load(":/partner/resource/partner/3/89_head.png");
}

//普通系
dugulu::dugulu()
{
    name="DuGuLu";coolTime=227;No=13;
    zuanshiNeed=25;
    isLocked=1;
    head.load(":/partner/resource/partner/4/254_head.png");
}
xinke::xinke()
{
    name="XinKe";coolTime=227;No=14;
    zuanshiNeed=25;
    isLocked=1;
    head.load(":/partner/resource/partner/4/328_head.png");
}
agong::agong()
{
    name="AGone";coolTime=227;No=15;
    zuanshiNeed=25;
    isLocked=1;
    head.load(":/partner/resource/partner/4/456_head.png");
}
taida::taida()
{
    name="TaiDa";coolTime=227;No=16;
    zuanshiNeed=25;
    isLocked=1;
    head.load(":/partner/resource/partner/4/690_head.png");
}




