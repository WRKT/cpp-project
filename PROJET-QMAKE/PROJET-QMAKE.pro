QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Models/Affichage/affichageconsole.cpp \
    Models/Factory/grillefactory.cpp \
    Models/Factory/jeufactory.cpp \
    Models/Factory/joueurfactory.cpp \
    Models/Grille/grille.cpp \
    Models/Jeux/jeudames.cpp \
    Models/Jeux/jeumorpion.cpp \
    Models/Jeux/jeuothello.cpp \
    Models/Jeux/jeupuissance4.cpp \
    Models/Joueurs/joueurhumain.cpp \
    Models/Joueurs/joueurordinateur.cpp \
    Models/Saisie/saisieconsole.cpp \
    UnitTests/maintest.cpp \
    UnitTests/testgrille.cpp \
    UnitTests/testjeufactory.cpp \
    UnitTests/testmorpion.cpp \
    UnitTests/testothello.cpp \
    UnitTests/testpuissance4.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Models/Affichage/affichageconsole.h \
    Models/Factory/grillefactory.h \
    Models/Factory/jeufactory.h \
    Models/Factory/joueurfactory.h \
    Models/Grille/grille.h \
    Models/Grille/jeton.h \
    Models/Interfaces/AGrille.h \
    Models/Interfaces/AJoueur.h \
    Models/Interfaces/IAffichage.h \
    Models/Interfaces/IChoisirCoup.h \
    Models/Interfaces/IGrilleInit.h \
    Models/Interfaces/IJeu.h \
    Models/Jeux/TypesJeu.h \
    Models/Jeux/jeudames.h \
    Models/Jeux/jeumorpion.h \
    Models/Jeux/jeuothello.h \
    Models/Jeux/jeupuissance4.h \
    Models/Joueurs/joueurhumain.h \
    Models/Joueurs/joueurordinateur.h \
    Models/Saisie/saisieconsole.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    UnitTests/CMakeLists.txt
