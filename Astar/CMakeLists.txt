cmake_minimum_required(VERSION 3.7)
project(Astar)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Astar.h Astar.cpp)
add_executable(Astar ${SOURCE_FILES})