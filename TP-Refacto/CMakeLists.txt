cmake_minimum_required(VERSION 3.14)

project(TP-Refacto VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core Gui)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(PROJECT_SOURCES
    main.cpp
    mainconsole.cpp
    affichageconsole.cpp
    affichageconsole.h
    AGrille.h
    AJoueur.h
    grille.cpp
    grille.h
    grillefactory.cpp
    grillefactory.h
    IAffichage.h
    IChoisirCoup.h
    IGrilleInit.h
    IJeu.h IJeu.cpp
    inputconsole.cpp
    inputconsole.h
    jeton.h
    jeudames.cpp
    jeudames.h
    jeufactory.cpp
    jeufactory.h
    jeumorpion.cpp
    jeumorpion.h
    jeuothello.cpp
    jeuothello.h
    jeupuissance4.cpp
    jeupuissance4.h
    joueurfactory.cpp
    joueurfactory.h
    joueurhumain.cpp
    joueurhumain.h
    joueurordinateur.cpp
    joueurordinateur.h
    TypesJeu.h
    coordonnees.h
    Input.h
)

add_executable(TP-Refacto ${PROJECT_SOURCES}
    affichagegui.h affichagegui.cpp
    mainwindow.h mainwindow.cpp mainwindow.ui
    accueil.h accueil.cpp accueil.ui
    jeugui.h jeugui.cpp jeugui.ui
    inputgui.h inputgui.cpp
    ISauvegarder.h
    Assets.qrc
)

target_link_libraries(TP-Refacto PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Core)


include(GNUInstallDirs)
install(TARGETS TP-Refacto
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# # Unit-Tests
# include(CTest)
# enable_testing()

# # Include the UnitTests directory
# add_subdirectory(UnitTests)
