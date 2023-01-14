#include "pokedex.h"
#include "ui_pokedex.h"
#include <QBitmap>
#include <QtGui>
#include <QHBoxLayout>
#include <QLabel>
#include <QMovie>
#include <QButtonGroup>

pokedex::pokedex(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pokedex)
{
    ui->setupUi(this);
    setFixedSize(1366,911);

    //按钮隐藏

    //火系
    ui->pushButtonfireh->hide();
    ui->pushButtonfirej->hide();
    ui->pushButtonfirel->hide();
    ui->pushButtonfireljls->hide();
    ui->pushButtonfirem->hide();
    ui->pushButtonfirex->hide();
    ui->pushButtonfirehly->hide();
    ui->pushButtonfirelos->hide();
    ui->pushButtondierk->hide();
    ui->pushButtonfiredierk->hide();

    //水系
    ui->pushButtonwateryy->hide();
    ui->pushButtonyourian->hide();
    ui->pushButtonbarus->hide();
    ui->pushButtonbara->hide();
    ui->pushButtonjieni->hide();
    ui->pushButtonbaragui->hide();
    ui->pushButtonyaya->hide();
    ui->pushButtonyayaa->hide();
    ui->pushButtonsyaya->hide();
    ui->pushButtonbbl->hide();
    ui->pushButtonfishdrgon->hide();
    ui->pushButtonking->hide();

    //草系
    ui->pushButtonbubu->hide();
    ui->pushButtonbubucao->hide();
    ui->pushButtonbubuhua->hide();
    ui->pushButtonxiaodouya->hide();
    ui->pushButtondingding->hide();
    ui->pushButtonmohua->hide();
    ui->pushButtonxrq->hide();
    ui->pushButtonxrh->hide();
    ui->pushButtonxrz->hide();
    ui->pushButtonyiyi->hide();
    ui->pushButtonyidingsi->hide();
    ui->pushButtonyika->hide();

    //普通系
    ui->pushButtonguru->hide();
    ui->pushButtonguruking->hide();
    ui->pushButtonxinke->hide();
    ui->pushButtonxinnasi->hide();
    ui->pushButtonagong->hide();
    ui->pushButtonbobo->hide();
    ui->pushButtonaoligong->hide();
    ui->pushButtontaida->hide();
    ui->pushButtontailesi->hide();




    QPixmap pix;
    //火属性选择按钮
    pix.load(":/background/resource/background/shuxing_fire.png");
    ui->pushButtonfire->setFixedSize(pix.size());
    ui->pushButtonfire->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/shuxing_fire.png);}"
                                   "QPushButton:pressed{background-image : url(:/background/resource/background/xvanzhong_fire.png);}");
    ui->pushButtonfire->setMask(pix.mask());

    //水属性选择按钮
    pix.load(":/background/resource/background/shuxing_water.png");
    ui->pushButtonwater->setFixedSize(pix.size());
    ui->pushButtonwater->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/shuxing_water.png);}"
                                   "QPushButton:pressed{background-image : url(:/background/resource/background/xvanzhong_water.png);}");
    ui->pushButtonwater->setMask(pix.mask());

    //草属性选择按钮
    pix.load(":/background/resource/background/shuxing_grass.png");
    ui->pushButtongrass->setFixedSize(pix.size());
    ui->pushButtongrass->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/shuxing_grass.png);}"
                                   "QPushButton:pressed{background-image : url(:/background/resource/background/xvanzhong_grass.png);}");
    ui->pushButtongrass->setMask(pix.mask());

    //普通属性选择按钮
    pix.load(":/background/resource/background/shuxing_normal.png");
    ui->pushButtonnormal->setFixedSize(pix.size());
    ui->pushButtonnormal->setStyleSheet("QPushButton{background-image : url(:/background/resource/background/shuxing_normal.png);}"
                                   "QPushButton:pressed{background-image : url(:/background/resource/background/xvanzhong_normal.png);}");
    ui->pushButtonnormal->setMask(pix.mask());

    //小火猴查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/fire/head_firem.png");
    ui->pushButtonfirem->setFixedSize(pix.size());
    ui->pushButtonfirem->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_firem.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_firem2.png);}");
    ui->pushButtonfirem->setMask(pix.mask());

    //烈火猴查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/fire/head_fireh.png");
    ui->pushButtonfireh->setFixedSize(pix.size());
    ui->pushButtonfireh->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_fireh.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_fireh2.png);}");
    ui->pushButtonfireh->setMask(pix.mask());

    //烈焰猩猩查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/fire/head_firex.png");
    ui->pushButtonfirex->setFixedSize(pix.size());
    ui->pushButtonfirex->setStyleSheet("QPushButton{background-image : url(://partner/resource/partner/pokedex_head/fire/head_firex.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_firex2.png);}");
    ui->pushButtonfirex->setMask(pix.mask());

    //吉尔查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/fire/head_firej.png");
    ui->pushButtonfirej->setFixedSize(pix.size());
    ui->pushButtonfirej->setStyleSheet("QPushButton{background-image : url(://partner/resource/partner/pokedex_head/fire/head_firej.png);}"
                                       "QPushButton:pressed{background-image : url(://partner/resource/partner/pokedex_head/fire/head_firej2.png);}");
    ui->pushButtonfirej->setMask(pix.mask());

    //里诺查看按钮
    pix.load("://partner/resource/partner/pokedex_head/fire/head_firel.png");
    ui->pushButtonfirel->setFixedSize(pix.size());
    ui->pushButtonfirel->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_firel.png);}"
                                       "QPushButton:pressed{background-image : url(://partner/resource/partner/pokedex_head/fire/head_firel2.png);}");
    ui->pushButtonfirel->setMask(pix.mask());

    //洛吉拉斯查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/fire/head_fireljls.png");
    ui->pushButtonfireljls->setFixedSize(pix.size());
    ui->pushButtonfireljls->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_fireljls.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_fireljls2.png);}");
    ui->pushButtonfireljls->setMask(pix.mask());

    //胡莉娅查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/fire/head_firehly.png");
    ui->pushButtonfirehly->setFixedSize(pix.size());
    ui->pushButtonfirehly->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_firehly.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_firehly2.png);}");
    ui->pushButtonfirehly->setMask(pix.mask());

    //里奥斯查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/fire/head_firelos.png");
    ui->pushButtonfirelos->setFixedSize(pix.size());
    ui->pushButtonfirelos->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_firelos.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_firelos2.png);}");
    ui->pushButtonfirelos->setMask(pix.mask());

    //迪克查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/fire/head_dierk.png");
    ui->pushButtondierk->setFixedSize(pix.size());
    ui->pushButtondierk->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_dierk.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_dierk2.png);}");
    ui->pushButtondierk->setMask(pix.mask());

    //迪尔克查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/fire/head_firedierk.png");
    ui->pushButtonfiredierk->setFixedSize(pix.size());
    ui->pushButtonfiredierk->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_firedierk.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/fire/head_firedierk2.png);}");
    ui->pushButtonfiredierk->setMask(pix.mask());

//水系
    //伊优查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/water/head_wateryy.png");
    ui->pushButtonwateryy->setFixedSize(pix.size());
    ui->pushButtonwateryy->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/water/head_wateryy.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/water/head_wateryy2.png);}");
    ui->pushButtonwateryy->setMask(pix.mask());

    //尤利安
    pix.load(":/partner/resource/partner/pokedex_head/water/head_yourian.png");
    ui->pushButtonyourian->setFixedSize(pix.size());
    ui->pushButtonyourian->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/water/head_yourian.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/water/head_yourian2.png);}");
    ui->pushButtonyourian->setMask(pix.mask());

    //巴鲁斯
    pix.load(":/partner/resource/partner/pokedex_head/water/head_barus.png");
    ui->pushButtonbarus->setFixedSize(pix.size());
    ui->pushButtonbarus->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/water/head_barus.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/water/head_barus2.png);}");
    ui->pushButtonbarus->setMask(pix.mask());


    //小龟龟
    pix.load(":/partner/resource/partner/pokedex_head/water/head_bara.png");
    ui->pushButtonbara->setFixedSize(pix.size());
    ui->pushButtonbara->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/water/head_bara.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/water/head_bara2.png);}");
    ui->pushButtonbara->setMask(pix.mask());


    //小龟
    pix.load(":/partner/resource/partner/pokedex_head/water/head_jieni.png");
    ui->pushButtonjieni->setFixedSize(pix.size());
    ui->pushButtonjieni->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/water/head_jieni.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/water/head_jieni2.png);}");
    ui->pushButtonjieni->setMask(pix.mask());


    //巴拉龟
    pix.load(":/partner/resource/partner/pokedex_head/water/head_baragui.png");
    ui->pushButtonbaragui->setFixedSize(pix.size());
    ui->pushButtonbaragui->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/water/head_baragui.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/water/head_baragui2.png);}");
    ui->pushButtonbaragui->setMask(pix.mask());


    //鸭鸭
    pix.load(":/partner/resource/partner/pokedex_head/water/head_yaya.png");
    ui->pushButtonyaya->setFixedSize(pix.size());
    ui->pushButtonyaya->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/water/head_yaya.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/water/head_yaya2.png);}");
    ui->pushButtonyaya->setMask(pix.mask());


    //鸭鸭鸭
    pix.load(":/partner/resource/partner/pokedex_head/water/head_yayaa.png");
    ui->pushButtonyayaa->setFixedSize(pix.size());
    ui->pushButtonyayaa->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/water/head_yayaa.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/water/head_yayaa2.png);}");
    ui->pushButtonyayaa->setMask(pix.mask());


    //水晶鸭
    pix.load(":/partner/resource/partner/pokedex_head/water/head_syaya.png");
    ui->pushButtonsyaya->setFixedSize(pix.size());
    ui->pushButtonsyaya->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/water/head_syaya.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/water/head_syaya2.png);}");
    ui->pushButtonsyaya->setMask(pix.mask());



    //宝贝鲤
    pix.load(":/partner/resource/partner/pokedex_head/water/head_bbl.png");
    ui->pushButtonbbl->setFixedSize(pix.size());
    ui->pushButtonbbl->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/water/head_bbl.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/water/head_bbl2.png);}");
    ui->pushButtonbbl->setMask(pix.mask());



    //远古鱼龙
    pix.load(":/partner/resource/partner/pokedex_head/water/head_fishdrgon.png");
    ui->pushButtonfishdrgon->setFixedSize(pix.size());
    ui->pushButtonfishdrgon->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/water/head_fishdrgon.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/water/head_fishdrgon2.png);}");
    ui->pushButtonfishdrgon->setMask(pix.mask());



    //鱼龙王
    pix.load(":/partner/resource/partner/pokedex_head/water/head_king.png");
    ui->pushButtonking->setFixedSize(pix.size());
    ui->pushButtonking->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/water/head_king.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/water/head_king2.png);}");
    ui->pushButtonking->setMask(pix.mask());







//草系
    //布布种子查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/grass/head_bubu.png");
    ui->pushButtonbubu->setFixedSize(pix.size());
    ui->pushButtonbubu->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_bubu.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_bubu2.png);}");
    ui->pushButtonbubu->setMask(pix.mask());

    //布布草查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/grass/head_bubucao.png");
    ui->pushButtonbubucao->setFixedSize(pix.size());
    ui->pushButtonbubucao->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_bubucao.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_bubucao2.png);}");
    ui->pushButtonbubucao->setMask(pix.mask());


    //布布花查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/grass/head_bubuhua.png");
    ui->pushButtonbubuhua->setFixedSize(pix.size());
    ui->pushButtonbubuhua->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_bubuhua.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_bubuhua2.png);}");
    ui->pushButtonbubuhua->setMask(pix.mask());


    //小豆芽查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/grass/head_xiaodouya.png");
    ui->pushButtonxiaodouya->setFixedSize(pix.size());
    ui->pushButtonxiaodouya->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_xiaodouya.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_xiaodouya2.png);}");
    ui->pushButtonxiaodouya->setMask(pix.mask());


    //叮叮查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/grass/head_dingding.png");
    ui->pushButtondingding->setFixedSize(pix.size());
    ui->pushButtondingding->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_dingding.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_dingding2.png);}");
    ui->pushButtondingding->setMask(pix.mask());


    //魔花仙子查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/grass/head_mohua.png");
    ui->pushButtonmohua->setFixedSize(pix.size());
    ui->pushButtonmohua->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_mohua.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_mohua2.png);}");
    ui->pushButtonmohua->setMask(pix.mask());


    //仙人球查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/grass/head_xrq.png");
    ui->pushButtonxrq->setFixedSize(pix.size());
    ui->pushButtonxrq->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_xrq.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_xrq2.png);}");
    ui->pushButtonxrq->setMask(pix.mask());



    //仙人花查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/grass/head_xrh.png");
    ui->pushButtonxrh->setFixedSize(pix.size());
    ui->pushButtonxrh->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_xrh.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_xrh2.png);}");
    ui->pushButtonxrh->setMask(pix.mask());




    //仙人掌查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/grass/head_xrz.png");
    ui->pushButtonxrz->setFixedSize(pix.size());
    ui->pushButtonxrz->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_xrz.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_xrz2.png);}");
    ui->pushButtonxrz->setMask(pix.mask());



    //依依查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/grass/head_yiyi.png");
    ui->pushButtonyiyi->setFixedSize(pix.size());
    ui->pushButtonyiyi->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_yiyi.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_yiyi2.png);}");
    ui->pushButtonyiyi->setMask(pix.mask());



    //依丁斯查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/grass/head_yidingsi.png");
    ui->pushButtonyidingsi->setFixedSize(pix.size());
    ui->pushButtonyidingsi->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_yidingsi.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_yidingsi2.png);}");
    ui->pushButtonyidingsi->setMask(pix.mask());



    //依卡莱恩查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/grass/head_yika.png");
    ui->pushButtonyika->setFixedSize(pix.size());
    ui->pushButtonyika->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_yika.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/grass/head_yika2.png);}");
    ui->pushButtonyika->setMask(pix.mask());



//普通系
    //咕噜查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/normal/head_guru.png");
    ui->pushButtonguru->setFixedSize(pix.size());
    ui->pushButtonguru->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/normal/head_guru.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/normal/head_guru2.png);}");
    ui->pushButtonguru->setMask(pix.mask());



    //咕噜王查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/normal/head_guruking.png");
    ui->pushButtonguruking->setFixedSize(pix.size());
    ui->pushButtonguruking->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/normal/head_guruking.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/normal/head_guruking2.png);}");
    ui->pushButtonguruking->setMask(pix.mask());




    //阿贡查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/normal/head_agong.png");
    ui->pushButtonagong->setFixedSize(pix.size());
    ui->pushButtonagong->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/normal/head_agong.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/normal/head_agong2.png);}");
    ui->pushButtonagong->setMask(pix.mask());





    //波波贡查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/normal/head_bobo.png");
    ui->pushButtonbobo->setFixedSize(pix.size());
    ui->pushButtonbobo->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/normal/head_bobo.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/normal/head_bobo2.png);}");
    ui->pushButtonbobo->setMask(pix.mask());





    //奥利贡查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/normal/head_aoligong.png");
    ui->pushButtonaoligong->setFixedSize(pix.size());
    ui->pushButtonaoligong->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/normal/head_aoligong.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/normal/head_aoligong2.png);}");
    ui->pushButtonaoligong->setMask(pix.mask());





    //辛可查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/normal/head_xinke.png");
    ui->pushButtonxinke->setFixedSize(pix.size());
    ui->pushButtonxinke->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/normal/head_xinke.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/normal/head_xinke2.png);}");
    ui->pushButtonxinke->setMask(pix.mask());




    //辛纳斯查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/normal/head_xinnasi.png");
    ui->pushButtonxinnasi->setFixedSize(pix.size());
    ui->pushButtonxinnasi->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/normal/head_xinnasi.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/normal/head_xinnasi2.png);}");
    ui->pushButtonxinnasi->setMask(pix.mask());





    //泰达查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/normal/head_taida.png");
    ui->pushButtontaida->setFixedSize(pix.size());
    ui->pushButtontaida->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/normal/head_taida.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/normal/head_taida2.png);}");
    ui->pushButtontaida->setMask(pix.mask());



    //泰勒斯查看按钮
    pix.load(":/partner/resource/partner/pokedex_head/normal/head_tailesi.png");
    ui->pushButtontailesi->setFixedSize(pix.size());
    ui->pushButtontailesi->setStyleSheet("QPushButton{background-image : url(:/partner/resource/partner/pokedex_head/normal/head_tailesi.png);}"
                                       "QPushButton:pressed{background-image : url(:/partner/resource/partner/pokedex_head/normal/head_tailesi2.png);}");
    ui->pushButtontailesi->setMask(pix.mask());











//    QButtonGroup * box = new QButtonGroup;
//    设置是否互斥
//    box->setExclusive(true);
//    将需要互斥的按钮全部添加到 QButtonGroup 中
//    box->addButton(ui->pushButtonfire);
//    box->addButton(ui->pushButtongrass);
//    box->addButton(ui->pushButtonwater);
//    box->addButton(ui->pushButtonnormal);
//	  box->addButton(ui.pushButton_5);
//	  box->addButton(ui.pushButton_6);
//	  box->addButton(ui.pushButton_7);
//	  box->addButton(ui.pushButton_8);
//	  box->addButton(ui.pushButton_9);
//	  box->addButton(ui.pushButton_10);

//    box->setExclusive(false);
//    将需要互斥的按钮全部添加到 QButtonGroup 中
//    box->addButton(ui->pushButtonfireh);
//    box->addButton(ui->pushButtonfirej);
//    box->addButton(ui->pushButtonfirel);
//    box->addButton(ui->pushButtonfirem);
//    box->addButton(ui->pushButtonfirex);
//    box->addButton(ui->pushButtonfireljls);
//    box->addButton(ui->pushButtonwateryy);
//	  box->addButton(ui.pushButton_8);
//	  box->addButton(ui.pushButton_9);
//	  box->addButton(ui.pushButton_10);

    pdbackPushButton *Close = new pdbackPushButton(this->width());

    Close->setParent(this);

    Close->setCursor(QCursor(Qt::PointingHandCursor));

    connect(Close,&pdbackPushButton::backpress,[=](){emit this->back();qDebug()<<"?";});

    this->setStyleSheet("QPushButton{background-color:transparent}");

}

pokedex::~pokedex()
{
    delete ui;
}

void pokedex::paintEvent(QPaintEvent *)
{
    QPainter *painter = new QPainter(this);
    QPixmap pix;
    pix.load(":/background/resource/background/backgd.png");
    painter->drawPixmap(0,0,pix);
    painter->end();
}

//按钮隐藏与展示：先隐藏后展示
void pokedex::on_pushButtonfire_clicked()
{
    //隐藏草系精灵按钮
    ui->pushButtonbubu->hide();
    ui->pushButtonbubucao->hide();
    ui->pushButtonbubuhua->hide();
    ui->pushButtonxiaodouya->hide();
    ui->pushButtondingding->hide();
    ui->pushButtonmohua->hide();
    ui->pushButtonxrq->hide();
    ui->pushButtonxrh->hide();
    ui->pushButtonxrz->hide();
    ui->pushButtonyiyi->hide();
    ui->pushButtonyidingsi->hide();
    ui->pushButtonyika->hide();


    //隐藏普通系精灵按钮
    ui->pushButtonguru->hide();
    ui->pushButtonguruking->hide();
    ui->pushButtonxinke->hide();
    ui->pushButtonxinnasi->hide();
    ui->pushButtonagong->hide();
    ui->pushButtonbobo->hide();
    ui->pushButtonaoligong->hide();
    ui->pushButtontaida->hide();
    ui->pushButtontailesi->hide();



    //隐藏水系精灵按钮
    ui->pushButtonwateryy->hide();
    ui->pushButtonyourian->hide();
    ui->pushButtonbarus->hide();
    ui->pushButtonbara->hide();
    ui->pushButtonjieni->hide();
    ui->pushButtonbaragui->hide();
    ui->pushButtonyaya->hide();
    ui->pushButtonyayaa->hide();
    ui->pushButtonsyaya->hide();
    ui->pushButtonbbl->hide();
    ui->pushButtonfishdrgon->hide();
    ui->pushButtonking->hide();

    //展示火系精灵按钮
    ui->pushButtonfireh->show();
    ui->pushButtonfirej->show();
    ui->pushButtonfirel->show();
    ui->pushButtonfireljls->show();
    ui->pushButtonfirem->show();
    ui->pushButtonfirex->show();
    ui->pushButtonfirehly->show();
    ui->pushButtonfirelos->show();
    ui->pushButtondierk->show();
    ui->pushButtonfiredierk->show();

    ui->pushButtonfire->setDown(true);//写到最后
}

void pokedex::on_pushButtonwater_clicked()
{
    //隐藏火系精灵按钮
    ui->pushButtonfireh->hide();
    ui->pushButtonfirej->hide();
    ui->pushButtonfirel->hide();
    ui->pushButtonfireljls->hide();
    ui->pushButtonfirem->hide();
    ui->pushButtonfirex->hide();
    ui->pushButtonfirehly->hide();
    ui->pushButtonfirelos->hide();
    ui->pushButtondierk->hide();
    ui->pushButtonfiredierk->hide();

    //隐藏草系精灵按钮
    ui->pushButtonbubu->hide();
    ui->pushButtonbubucao->hide();
    ui->pushButtonbubuhua->hide();
    ui->pushButtonxiaodouya->hide();
    ui->pushButtondingding->hide();
    ui->pushButtonmohua->hide();
    ui->pushButtonxrq->hide();
    ui->pushButtonxrh->hide();
    ui->pushButtonxrz->hide();
    ui->pushButtonyiyi->hide();
    ui->pushButtonyidingsi->hide();
    ui->pushButtonyika->hide();



    //隐藏普通系精灵按钮
    ui->pushButtonguru->hide();
    ui->pushButtonguruking->hide();
    ui->pushButtonxinke->hide();
    ui->pushButtonxinnasi->hide();
    ui->pushButtonagong->hide();
    ui->pushButtonbobo->hide();
    ui->pushButtonaoligong->hide();
    ui->pushButtontaida->hide();
    ui->pushButtontailesi->hide();

    //展示水系精灵按钮
    ui->pushButtonwateryy->show();
    ui->pushButtonyourian->show();
    ui->pushButtonbarus->show();
    ui->pushButtonbara->show();
    ui->pushButtonjieni->show();
    ui->pushButtonbaragui->show();
    ui->pushButtonyaya->show();
    ui->pushButtonyayaa->show();
    ui->pushButtonsyaya->show();
    ui->pushButtonbbl->show();
    ui->pushButtonfishdrgon->show();
    ui->pushButtonking->show();


    ui->pushButtonwater->setDown(true);//写到最后
}

void pokedex::on_pushButtongrass_clicked()
{
    //隐藏火系精灵按钮
    ui->pushButtonfireh->hide();
    ui->pushButtonfirej->hide();
    ui->pushButtonfirel->hide();
    ui->pushButtonfireljls->hide();
    ui->pushButtonfirem->hide();
    ui->pushButtonfirex->hide();
    ui->pushButtonfirehly->hide();
    ui->pushButtonfirelos->hide();
    ui->pushButtondierk->hide();
    ui->pushButtonfiredierk->hide();


    //隐藏水系精灵按钮
    ui->pushButtonwateryy->hide();
    ui->pushButtonyourian->hide();
    ui->pushButtonbarus->hide();
    ui->pushButtonbara->hide();
    ui->pushButtonjieni->hide();
    ui->pushButtonbaragui->hide();
    ui->pushButtonyaya->hide();
    ui->pushButtonyayaa->hide();
    ui->pushButtonsyaya->hide();
    ui->pushButtonbbl->hide();
    ui->pushButtonfishdrgon->hide();
    ui->pushButtonking->hide();


    //隐藏普通系精灵按钮
    ui->pushButtonguru->hide();
    ui->pushButtonguruking->hide();
    ui->pushButtonxinke->hide();
    ui->pushButtonxinnasi->hide();
    ui->pushButtonagong->hide();
    ui->pushButtonbobo->hide();
    ui->pushButtonaoligong->hide();
    ui->pushButtontaida->hide();
    ui->pushButtontailesi->hide();


    //展示草系精灵按钮
    ui->pushButtonbubu->show();
    ui->pushButtonbubucao->show();
    ui->pushButtonbubuhua->show();
    ui->pushButtonxiaodouya->show();
    ui->pushButtondingding->show();
    ui->pushButtonmohua->show();
    ui->pushButtonxrq->show();
    ui->pushButtonxrh->show();
    ui->pushButtonxrz->show();
    ui->pushButtonyiyi->show();
    ui->pushButtonyidingsi->show();
    ui->pushButtonyika->show();


    ui->pushButtongrass->setDown(true);
}

void pokedex::on_pushButtonnormal_clicked()
{
    //隐藏火系精灵按钮
    ui->pushButtonfireh->hide();
    ui->pushButtonfirej->hide();
    ui->pushButtonfirel->hide();
    ui->pushButtonfireljls->hide();
    ui->pushButtonfirem->hide();
    ui->pushButtonfirex->hide();
    ui->pushButtonfirehly->hide();
    ui->pushButtonfirelos->hide();
    ui->pushButtondierk->hide();
    ui->pushButtonfiredierk->hide();

    //隐藏水系精灵按钮
    ui->pushButtonwateryy->hide();
    ui->pushButtonyourian->hide();
    ui->pushButtonbarus->hide();
    ui->pushButtonbara->hide();
    ui->pushButtonjieni->hide();
    ui->pushButtonbaragui->hide();
    ui->pushButtonyaya->hide();
    ui->pushButtonyayaa->hide();
    ui->pushButtonsyaya->hide();
    ui->pushButtonbbl->hide();
    ui->pushButtonfishdrgon->hide();
    ui->pushButtonking->hide();

    //隐藏草系精灵按钮
    ui->pushButtonbubu->hide();
    ui->pushButtonbubucao->hide();
    ui->pushButtonbubuhua->hide();
    ui->pushButtonxiaodouya->hide();
    ui->pushButtondingding->hide();
    ui->pushButtonmohua->hide();
    ui->pushButtonxrq->hide();
    ui->pushButtonxrh->hide();
    ui->pushButtonxrz->hide();
    ui->pushButtonyiyi->hide();
    ui->pushButtonyidingsi->hide();
    ui->pushButtonyika->hide();


    //展示普通系精灵按钮
    ui->pushButtonguru->show();
    ui->pushButtonguruking->show();
    ui->pushButtonxinke->show();
    ui->pushButtonxinnasi->show();
    ui->pushButtonagong->show();
    ui->pushButtonbobo->show();
    ui->pushButtonaoligong->show();
    ui->pushButtontaida->show();
    ui->pushButtontailesi->show();


    ui->pushButtonnormal->setDown(true);
}

//火系精灵展示触发按钮
void pokedex::on_pushButtonfirem_clicked()
{

    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/fire/stand_xiaohuohou.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(700,550);
    ui->pushButtonfirem->setDown(true);
}

void pokedex::on_pushButtonfireh_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/fire/stand_fireh.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(760,450);
    ui->pushButtonfireh->setDown(true);
}

void pokedex::on_pushButtonfirex_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/fire/stand_firex.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(810,450);
    ui->pushButtonfirex->setDown(true);
}

void pokedex::on_pushButtonfirej_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/fire/stand_fierj.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(700,650);
    ui->pushButtonfirej->setDown(true);
}

void pokedex::on_pushButtonfirel_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/fire/stand_firel.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(690,630);
    ui->pushButtonfirel->setDown(true);
}


void pokedex::on_pushButtonfireljls_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/fire/stand_fireljls.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(990,580);
    ui->pushButtonfireljls->setDown(true);
}



void pokedex::on_pushButtonfirehly_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/fire/stand_huriya.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(720,570);
    ui->pushButtonfirehly->setDown(true);
}

void pokedex::on_pushButtonfirelos_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/fire/stand_los.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(760,360);
    ui->pushButtonfirelos->setDown(true);
}

void pokedex::on_pushButtondierk_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/fire/stand_dierk.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(760,660);
    ui->pushButtondierk->setDown(true);
}

void pokedex::on_pushButtonfiredierk_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/fire/stand_firedierk.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(760,450);
    ui->pushButtonfiredierk->setDown(true);
}

//水系精灵触发展示按钮
void pokedex::on_pushButtonwateryy_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_yiyou.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(650,650);
    ui->pushButtonwateryy->setDown(true);
}

void pokedex::on_pushButtonyourian_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_yourian.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(680,490);
    ui->pushButtonyourian->setDown(true);
}

void pokedex::on_pushButtonbarus_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_barus.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(800,430);
    ui->pushButtonbarus->setDown(true);
}

void pokedex::on_pushButtonbara_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_bara.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(700,660);
    ui->pushButtonbara->setDown(true);
}

void pokedex::on_pushButtonjieni_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_jieni.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(720,650);
    ui->pushButtonjieni->setDown(true);
}

void pokedex::on_pushButtonbaragui_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_baragui.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(720,650);
    ui->pushButtonbaragui->setDown(true);
}

void pokedex::on_pushButtonyaya_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_yaya.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(660,680);
    ui->pushButtonyaya->setDown(true);
}

void pokedex::on_pushButtonyayaa_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_yayaa.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(670,650);
    ui->pushButtonyayaa->setDown(true);
}

void pokedex::on_pushButtonsyaya_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_syaya.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(700,560);
    ui->pushButtonsyaya->setDown(true);
}

void pokedex::on_pushButtonbbl_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_bbl.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(690,650);
    ui->pushButtonbbl->setDown(true);
}

void pokedex::on_pushButtonfishdrgon_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_fishdrgon.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(760,350);
    ui->pushButtonfishdrgon->setDown(true);
}

void pokedex::on_pushButtonking_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/water/stand_king.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(730,260);
    ui->pushButtonking->setDown(true);
}


//草系精灵触发展示按钮
void pokedex::on_pushButtonbubu_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/grass/stand_bubuzhongzi.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(680,600);
    ui->pushButtonbubu->setDown(true);
}

void pokedex::on_pushButtonbubucao_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/grass/stand_bubucao.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(710,490);
    ui->pushButtonbubucao->setDown(true);
}


void pokedex::on_pushButtonbubuhua_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/grass/stand_bubuhua.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(730,410);
    ui->pushButtonbubuhua->setDown(true);
}


void pokedex::on_pushButtonxiaodouya_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/grass/stand_xiaodouya.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(660,650);
    ui->pushButtonxiaodouya->setDown(true);
}


void pokedex::on_pushButtondingding_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/grass/stand_dingding.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(660,640);
    ui->pushButtondingding->setDown(true);
}

void pokedex::on_pushButtonmohua_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/grass/stand_mohua.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(680,650);
    ui->pushButtonmohua->setDown(true);
}

void pokedex::on_pushButtonxrq_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/grass/stand_xrq.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(670,650);
    ui->pushButtonxrq->setDown(true);
}

void pokedex::on_pushButtonxrh_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/grass/stand_xrh.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(680,660);
    ui->pushButtonxrh->setDown(true);
}



void pokedex::on_pushButtonxrz_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/grass/stand_xrz.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(700,660);
    ui->pushButtonxrz->setDown(true);
}

void pokedex::on_pushButtonyiyi_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/grass/stand_yiyi.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(670,630);
    ui->pushButtonyiyi->setDown(true);
}

void pokedex::on_pushButtonyidingsi_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/grass/stand_yidingsi.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(670,580);
    ui->pushButtonyidingsi->setDown(true);
}

void pokedex::on_pushButtonyika_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/grass/stand_yika.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(720,500);
    ui->pushButtonyika->setDown(true);
}



//普通系精灵触发展示按钮
void pokedex::on_pushButtonguru_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/normal/stand_guru.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(670,690);
    ui->pushButtonguru->setDown(true);
}


void pokedex::on_pushButtonguruking_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/normal/stand_guruking.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(700,640);
    ui->pushButtonguruking->setDown(true);
}


void pokedex::on_pushButtonxinke_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/normal/stand_xinke.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(700,440);
    ui->pushButtonxinke->setDown(true);
}

void pokedex::on_pushButtonxinnasi_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/normal/stand_xinnasi.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(710,440);
    ui->pushButtonxinnasi->setDown(true);
}

void pokedex::on_pushButtonagong_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/normal/stand_agong.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(690,540);
    ui->pushButtonagong->setDown(true);
}

void pokedex::on_pushButtonbobo_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/normal/stand_bobo.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(720,500);
    ui->pushButtonbobo->setDown(true);
}

void pokedex::on_pushButtonaoligong_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/normal/stand_aoligong.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(730,400);
    ui->pushButtonaoligong->setDown(true);
}

void pokedex::on_pushButtontaida_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/normal/stand_taida.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(710,560);
    ui->pushButtontaida->setDown(true);
}

void pokedex::on_pushButtontailesi_clicked()
{
    QMovie * movie=new QMovie(":/partner/resource/partner/pokedex_head/normal/stand_tailesi.gif");
    ui->label->setAlignment(Qt::AlignRight);
    ui->label->setMovie(movie);
    movie->start();
    ui->label->move(730,460);
    ui->pushButtontailesi->setDown(true);
}







