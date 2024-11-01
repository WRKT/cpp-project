add_executable(Unit-Tests maintest.cpp
    testgrille.cpp
    testjeufactory.cpp
    testmorpion.cpp
    testpuissance4.cpp
    testothello.cpp
    testdames.cpp

    ${CMAKE_SOURCE_DIR}/AGrille.h
    ${CMAKE_SOURCE_DIR}/grille.h ${CMAKE_SOURCE_DIR}/grille.cpp
    ${CMAKE_SOURCE_DIR}/grillefactory.h ${CMAKE_SOURCE_DIR}/grillefactory.cpp

    ${CMAKE_SOURCE_DIR}/TypesJeu.h
    ${CMAKE_SOURCE_DIR}/IJeu.h ${CMAKE_SOURCE_DIR}/IJeu.cpp
    ${CMAKE_SOURCE_DIR}/jeufactory.h ${CMAKE_SOURCE_DIR}/jeufactory.cpp
    ${CMAKE_SOURCE_DIR}/jeumorpion.h ${CMAKE_SOURCE_DIR}/jeumorpion.cpp
    ${CMAKE_SOURCE_DIR}/jeupuissance4.h ${CMAKE_SOURCE_DIR}/jeupuissance4.cpp
    ${CMAKE_SOURCE_DIR}/jeuothello.h ${CMAKE_SOURCE_DIR}/jeuothello.cpp
    ${CMAKE_SOURCE_DIR}/jeudames.h ${CMAKE_SOURCE_DIR}/jeudames.cpp

    ${CMAKE_SOURCE_DIR}/AJoueur.h
    ${CMAKE_SOURCE_DIR}/joueurhumain.cpp ${CMAKE_SOURCE_DIR}/joueurordinateur.cpp
    ${CMAKE_SOURCE_DIR}/joueurfactory.h ${CMAKE_SOURCE_DIR}/joueurfactory.cpp

    ${CMAKE_SOURCE_DIR}/IAffichage.h
    ${CMAKE_SOURCE_DIR}/affichageconsole.h ${CMAKE_SOURCE_DIR}/affichageconsole.cpp
    ${CMAKE_SOURCE_DIR}/inputconsole.h ${CMAKE_SOURCE_DIR}/inputconsole.cpp

)
target_include_directories(Unit-Tests PRIVATE ${CMAKE_SOURCE_DIR} Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(Unit-Tests GTest::gtest_main Qt6::Core Qt6::Widgets)

include(GoogleTest)

gtest_discover_tests(
    Unit-Tests
)
