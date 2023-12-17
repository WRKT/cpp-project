cmake_minimum_required(VERSION 3.14)

project(TP3-Refacto LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Unit-Tests testothello.cpp
    ${CMAKE_SOURCE_DIR}/IJeu.h
    ${CMAKE_SOURCE_DIR}/jeuothello.h ${CMAKE_SOURCE_DIR}/jeuothello.cpp
    ${CMAKE_SOURCE_DIR}/jeumorpion.h ${CMAKE_SOURCE_DIR}/jeumorpion.cpp
    ${CMAKE_SOURCE_DIR}/jeupuissance4.h ${CMAKE_SOURCE_DIR}/jeupuissance4.cpp
    ${CMAKE_SOURCE_DIR}/IGrille.h
    ${CMAKE_SOURCE_DIR}/grille.h ${CMAKE_SOURCE_DIR}/grille.cpp
    ${CMAKE_SOURCE_DIR}/joueurfactory.h ${CMAKE_SOURCE_DIR}/joueurfactory.cpp
    ${CMAKE_SOURCE_DIR}/IAffichage.h
    ${CMAKE_SOURCE_DIR}/affichageconsole.h ${CMAKE_SOURCE_DIR}/affichageconsole.cpp
    ${CMAKE_SOURCE_DIR}/inputconsole.h ${CMAKE_SOURCE_DIR}/inputconsole.cpp
    ${CMAKE_SOURCE_DIR}/joueurhumain.cpp ${CMAKE_SOURCE_DIR}/joueurordinateur.cpp
    testgrille.cpp
    maintest.cpp
    testmorpion.cpp
    testpuissance4.cpp
)
target_include_directories(Unit-Tests PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(
    Unit-Tests
    gtest_main
)

gtest_discover_tests(
    Unit-Tests
)
