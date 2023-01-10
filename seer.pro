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
    cards.cpp \
    cardsmenu.cpp \
    chooselevelscene.cpp \
    choosescene.cpp \
    elf.cpp \
    enemy.cpp \
    level.cpp \
    main.cpp \
    maingame.cpp \
    map.cpp \
    partner.cpp \
    pdbackpushbutton.cpp \
    pokedex.cpp \
    startpushbutton.cpp \
    startscene.cpp

HEADERS += \
    cards.h \
    cardsmenu.h \
    chooselevelscene.h \
    choosescene.h \
    elf.h \
    enemy.h \
    level.h \
    maingame.h \
    map.h \
    partner.h \
    pdbackpushbutton.h \
    pokedex.h \
    startpushbutton.h \
    startscene.h

FORMS += \
    cardsmenu.ui \
    choosescene.ui \
    level.ui \
    maingame.ui \
    pokedex.ui \
    startscene.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
