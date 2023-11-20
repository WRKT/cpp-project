cmake_minimum_required(VERSION 3.5)

project(TP-Refacto LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TP-Refacto main.cpp

    grille.h grille.cpp
    IJoueur.h
    joueurhumain.h joueurhumain.cpp
    joueurordinateur.h joueurordinateur.cpp
    IGrille.h
    jeton.h
    IJeu.h
    jeumorpion.h jeumorpion.cpp
    jeupuissance4.h jeupuissance4.cpp
    TypesJeu.h
    jeufactory.h jeufactory.cpp
    joueurfactory.h joueurfactory.cpp
    InterfaceUtilisateur.h InterfaceUtilisateur.cpp
    configjeu.h configjeu.cpp
)

include(GNUInstallDirs)
install(TARGETS TP-Refacto
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
