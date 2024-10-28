cmake_minimum_required(VERSION 3.5)

project(TP2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TP2 main.cpp
    point.h point.cpp
    rectangle.h rectangle.cpp
    cercle.h cercle.cpp
    triangle.h triangle.cpp
    carre.h carre.cpp)

include(GNUInstallDirs)
install(TARGETS TP2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
