cmake_minimum_required(VERSION 3.14)

project(TP-Refacto LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TP-Refacto
    main.cpp
    grille.h grille.cpp
    AJoueur.h
    joueurhumain.h joueurhumain.cpp
    joueurordinateur.h joueurordinateur.cpp
    AGrille.h
    jeton.h
    IJeu.h
    jeumorpion.h jeumorpion.cpp
    jeupuissance4.h jeupuissance4.cpp
    TypesJeu.h
    jeufactory.h jeufactory.cpp
    joueurfactory.h joueurfactory.cpp
    inputconsole.h inputconsole.cpp
    grillefactory.h grillefactory.cpp
    IAffichage.h
    affichageconsole.h affichageconsole.cpp
    jeuothello.h jeuothello.cpp
    IChoisirCoup.h
    IGrilleInit.h
    jeudames.h jeudames.cpp
)

# Install the executable
include(GNUInstallDirs)
install(TARGETS TP-Refacto
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(CTest)
add_subdirectory(UnitTests)

