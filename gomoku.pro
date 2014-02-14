SOURCES += \
    main.cpp \
    mafenetre.cpp \
    jeu.cpp \
    joueurhumainconsole.cpp \
    joueurhumaingui.cpp \
    pion.cpp \
    joueurIArandom.cpp \
    joueuriaintelligent.cpp \
    grillejeuconsole.cpp \
    widgetgrillejeu.cpp \
    grillejeugraphique.cpp

HEADERS += \
    mafenetre.h \
    jeu.h \
    joueur.h \
    joueurhumainconsole.h \
    joueurhumaingui.h \
    coup.h \
    pion.h \
    joueurIArandom.h \
    joueuriaintelligent.h \
    grillejeu.h \
    grillejeuconsole.h \
    widgetgrillejeu.h \
    grillejeugraphique.h

QT += widgets
QT += gui

CONFIG += c++11
