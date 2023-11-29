cmake_minimum_required(VERSION 3.5)

project(TP3-Refacto LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TP3-Refacto main.cpp

    grille.h grille.cpp
    IJoueur.h
    joueurhumain.h
    joueurordinateur.h
    IGrille.h
    jeton.h
    IJeu.h
    jeumorpion.h jeumorpion.cpp
    jeupuissance4.h jeupuissance4.cpp
    TypesJeu.h
    jeufactory.h jeufactory.cpp
    joueurfactory.h joueurfactory.cpp
    InterfaceUtilisateur.h InterfaceUtilisateur.cpp
    grillefactory.h grillefactory.cpp
    IAffichage.h
    affichageconsole.h affichageconsole.cpp
    ISaisie.h
    saisieconsole.h saisieconsole.cpp
    TypesAffichage.h
)

include(GNUInstallDirs)
install(TARGETS TP3-Refacto
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
