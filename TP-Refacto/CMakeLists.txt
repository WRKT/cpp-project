cmake_minimum_required(VERSION 3.14)

project(PROJET VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

set(PROJECT_SOURCES
        main.cpp
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
        IJeu.h
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
        fenetreprincipal.cpp
        fenetreprincipal.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(TP-Refacto
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        menuprincipal.h menuprincipal.cpp menuprincipal.ui
    )
else()
    if(ANDROID)
        add_library(TP-Refacto SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(TP-Refacto
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(TP-Refacto PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)


if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.TP-Refacto)
endif()
set_target_properties(TP-Refacto PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS TP-Refacto
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(TP-Refacto)
endif()

# Unit-Tests
include(CTest)
enable_testing()

# Include the UnitTests directory
add_subdirectory(UnitTests)
