QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Add include directories for header files
INCLUDEPATH += $$PWD/Models/Affichage \
               $$PWD/Models/Factory \
	       $$PWD/Models/Grille \
	       $$PWD/Models/Input \
	       $$PWD/Models/Interfaces \
	       $$PWD/Models/Jeux \
	       $$PWD/Models/Joueur \
	       $$PWD/UI/Widgets \
	       $$PWD/UnitTests \
	       $$PWD/UnitTests/gtest/googletest/include
	       $$PWD/UnitTests/gtest/googletest/src

SOURCES += \
    Models/Affichage/affichageconsole.cpp \
    Models/Factory/grillefactory.cpp \
    Models/Factory/jeufactory.cpp \
    Models/Factory/joueurfactory.cpp \
    Models/Grille/grille.cpp \
    Models/Input/inputconsole.cpp \
    Models/Jeux/jeudames.cpp \
    Models/Jeux/jeumorpion.cpp \
    Models/Jeux/jeuothello.cpp \
    Models/Jeux/jeupuissance4.cpp \
    Models/Joueur/joueurhumain.cpp \
    Models/Joueur/joueurordinateur.cpp \
    UI/Widgets/menuprincipal.cpp \
    UI/Widgets/morpionwidget.cpp \
    main.cpp \
    mainconsole.cpp

HEADERS += \
    Models/Affichage/affichageconsole.h \
    Models/Factory/grillefactory.h \
    Models/Factory/jeufactory.h \
    Models/Factory/joueurfactory.h \
    Models/Grille/AGrille.h \
    Models/Grille/grille.h \
    Models/Grille/jeton.h \
    Models/Input/inputconsole.h \
    Models/Interfaces/IAffichage.h \
    Models/Interfaces/IChoisirCoup.h \
    Models/Interfaces/IGrilleInit.h \
    Models/Interfaces/IJeu.h \
    Models/Jeux/TypesJeu.h \
    Models/Jeux/jeudames.h \
    Models/Jeux/jeumorpion.h \
    Models/Jeux/jeuothello.h \
    Models/Jeux/jeupuissance4.h \
    Models/Joueur/AJoueur.h \
    Models/Joueur/joueurhumain.h \
    Models/Joueur/joueurordinateur.h \
    UI/Widgets/menuprincipal.h \
    UI/Widgets/morpionwidget.h \

FORMS += \
    UI/Forms/menuprincipal.ui \
    UI/Forms/morpionwidget.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

