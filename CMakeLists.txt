cmake_minimum_required(VERSION 3.26)
project(ConsoleSudoku)

set(CMAKE_CXX_STANDARD 17)

add_executable(ConsoleSudoku main.cpp
        SudokuBoard.cpp
        SudokuBoard.h)
