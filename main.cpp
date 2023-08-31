#include <iostream>
#include "SudokuBoard.h"

int main() {
    /* change zeros to spaces, also in printBoard function */
    char sudoku[9][9] = {{'2','7','0','0','0','3','0','0','0'},
                        {'9','0','0','2','1','0','0','0','8'},
                        {'0','0','3','7','0','0','4','0','0'},

                        {'0','6','0','0','0','0','2','0','5'},
                        {'0','0','0','3','0','7','0','0','0'},
                        {'4','0','5','0','0','0','0','7','0'},

                        {'0','0','4','0','0','1','8','0','0'},
                        {'5','0','0','0','2','9','0','0','7'},
                        {'0','0','0','4','0','0','0','2','3'}};
    auto sudokuBoard = new SudokuBoard(sudoku);
    std::cout << SudokuBoard::isValidBoard(sudokuBoard);
}
