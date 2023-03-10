QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agong.cpp \
    baobeili.cpp \
    beier.cpp \
    beilami.cpp \
    boge.cpp \
    bubuzhongzi.cpp \
    bullet.cpp \
    cards.cpp \
    cardsblank.cpp \
    cardsmenu.cpp \
    chooselevelscene.cpp \
    choosescene.cpp \
    dida.cpp \
    dugulu.cpp \
    dululu.cpp \
    elf.cpp \
    enemy.cpp \
    gangyasha.cpp \
    guodongya.cpp \
    heertuoke.cpp \
    huliya.cpp \
    jianxishuiling.cpp \
    jier.cpp \
    level.cpp \
    main.cpp \
    maingame.cpp \
    maokai.cpp \
    map.cpp \
    moguguai.cpp \
    nisike.cpp \
    partner.cpp \
    pdbackpushbutton.cpp \
    phoenix.cpp \
    pokedex.cpp \
    sailatu.cpp \
    startpushbutton.cpp \
    startscene.cpp \
    taida.cpp \
    taqiduoke.cpp \
    xianrenqiu.cpp \
    xiaodouya.cpp \
    xiaohuohou.cpp \
    xikela.cpp \
    xingjila.cpp \
    xinke.cpp \
    yiyi.cpp \
    yiyou.cpp \
    zuoluo.cpp

HEADERS += \
    agong.h \
    baobeili.h \
    beier.h \
    beilami.h \
    boge.h \
    bubuzhongzi.h \
    bullet.h \
    cards.h \
    cardsblank.h \
    cardsmenu.h \
    chooselevelscene.h \
    choosescene.h \
    dida.h \
    dugulu.h \
    dululu.h \
    elf.h \
    enemy.h \
    gangyasha.h \
    guodongya.h \
    heertuoke.h \
    huliya.h \
    jianxishuiling.h \
    jier.h \
    level.h \
    lieyanxingxing.h \
    maingame.h \
    maokai.h \
    map.h \
    moguguai.h \
    nisike.h \
    partner.h \
    pdbackpushbutton.h \
    phoenix.h \
    pokedex.h \
    sailatu.h \
    startpushbutton.h \
    startscene.h \
    taida.h \
    taqiduoke.h \
    xianrenqiu.h \
    xiaodouya.h \
    xiaohuohou.h \
    xikela.h \
    xingjila.h \
    xinke.h \
    yiyi.h \
    yiyou.h \
    zuoluo.h

FORMS += \
    cardsblank.ui \
    cardsmenu.ui \
    choosescene.ui \
    level.ui \
    maingame.ui \
    pokedex.ui \
    startscene.ui

CONFIG+=resources_big
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
