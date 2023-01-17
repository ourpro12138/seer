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
    beilami.cpp \
    bubuzhongzi.cpp \
    bullet.cpp \
    cards.cpp \
    cardsblank.cpp \
    cardsmenu.cpp \
    chooselevelscene.cpp \
    choosescene.cpp \
    elf.cpp \
    enemy.cpp \
    gangyasha.cpp \
    level.cpp \
    main.cpp \
    maingame.cpp \
    map.cpp \
    moguguai.cpp \
    partner.cpp \
    pdbackpushbutton.cpp \
    pokedex.cpp \
    startpushbutton.cpp \
    startscene.cpp \

    taqiduoke.cpp \

    xianrenqiu.cpp \

    xiaohuohou.cpp \
    yiyou.cpp

HEADERS += \
    beilami.h \
    bubuzhongzi.h \
    bullet.h \
    cards.h \
    cardsblank.h \
    cardsmenu.h \
    chooselevelscene.h \
    choosescene.h \
    elf.h \
    enemy.h \
    gangyasha.h \
    level.h \
    maingame.h \
    map.h \
    moguguai.h \
    partner.h \
    pdbackpushbutton.h \
    pokedex.h \
    startpushbutton.h \
    startscene.h \

    taqiduoke.h \

    xianrenqiu.h \

    xiaohuohou.h \
    yiyou.h

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
