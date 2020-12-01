cmake_minimum_required(VERSION 3.15)
project(tetris)

set(CMAKE_CXX_FLAGS "-Wall -Wpedantic -Werror -g --std=c++17")

# output binary files to bin directory
set(CMAKE_BINARY_DIR "../bin")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# need this to find header files
include_directories(include)

add_executable(tetris
    ../src/main.cc
    ../src/tetris/core/board.cc
    ../src/tetris/core/shape.cc
    ../include/tetris/core/board.h
    ../include/tetris/core/shape.h)
