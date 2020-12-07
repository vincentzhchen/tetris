cmake_minimum_required(VERSION 3.15)
project(tetris)

set(CMAKE_CXX_FLAGS "-Wall -Wpedantic -Werror -g --std=c++17")

# output binary files to bin directory
set(CMAKE_BINARY_DIR "../bin")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_executable(tetris
    ../src/main.cc
    ../src/tetris/core/board.cc
    ../src/tetris/core/game_state.cc
    ../src/tetris/core/info_panel.cc
    ../src/tetris/core/matrix.cc
    ../src/tetris/core/shape.cc
    ../src/tetris/util/display.cc
    ../src/tetris/util/kb_io.cc
    ../src/tetris/util/user_input.cc)

# need this to find header files
target_include_directories(tetris PRIVATE include)
