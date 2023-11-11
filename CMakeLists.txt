cmake_minimum_required(VERSION 3.5)

project(TP-Refacto LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TP-Refacto main.cpp
    jeu.h jeu.cpp
    grille.h grille.cpp
    joueur.h joueur.cpp
    morpion.h morpion.cpp
    puissance4.h puissance4.cpp
    match.h match.cpp
)

include(GNUInstallDirs)
install(TARGETS TP-Refacto
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
