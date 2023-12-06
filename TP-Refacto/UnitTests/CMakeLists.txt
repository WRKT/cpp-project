cmake_minimum_required(VERSION 3.14)

project(TP3-Refacto LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TestOthello testothello.cpp
    ../IJeu.h
    ../jeuothello.h ../jeuothello.cpp
    ../IGrille.h
    ../grille.h ../grille.cpp
    ../joueurfactory.h ../joueurfactory.cpp
    ../IAffichage.h
    ../affichageconsole.h ../affichageconsole.cpp
    ../inputconsole.h ../inputconsole.cpp
    ../joueurhumain.cpp ../joueurordinateur.cpp
)

target_link_libraries(
    TestOthello
    gtest_main
)

gtest_discover_tests(
    TestOthello
)
