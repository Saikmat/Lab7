cmake_minimum_required(VERSION 3.26)
project(Lab7)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab7
        main.cpp
        main.h
        Planet.h
        Planet.cpp)
