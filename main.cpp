#include <iostream>
#include "SudokuBoard.h"

SudokuBoard *getBoard();

void play(SudokuBoard *);

bool isValidSudokuNumber(char number);

int main() {
    auto sudokuBoard = getBoard();
    std::cout << SudokuBoard::isValidBoard(sudokuBoard->board);
    play(sudokuBoard);
    return 1;
}

void play(SudokuBoard *sudoku) {
    char newBoard[9][9] = {};
    char row = 0, column = 0, number = 0;
    std::cout <<( sudoku->isFinished() ? "true" : "false");
    while (!sudoku->isFinished()) {
        sudoku->printBoard();
        std::cout << "in which row want you add number?" << std::endl;
        std::cin >> row;
        std::cout << "in which column want you add number?" << std::endl;
        std::cin >> column;
        std::cout << "which number want you add?" << std::endl;
        std::cin >> number;
        bool check = isValidSudokuNumber(row) && isValidSudokuNumber(column) & isValidSudokuNumber(number);
        row = row - '0' - 1;
        column = column - '0' - 1;
        if (check) {
            SudokuBoard::copyBoard(sudoku->board, newBoard);
            if(SudokuBoard::isEmptyPlace(newBoard, row, column)) {
                newBoard[row][column] = number;
            }
        } else {
            std::cout << "At least one of the numbers is not between 1 and 9";
        }
        if (SudokuBoard::isValidBoard(newBoard)) {
            SudokuBoard::copyBoard(newBoard, sudoku->board);
        } else {
            std::cout << "Illegal move!";
        }
    }
    std::cout << "Congratulations! You've finished the puzzle!";
}

bool isValidSudokuNumber(char number) {
    return number > '0' && number <= '9';
}

SudokuBoard *getBoard() {
    /* change zeros to spaces, also in printBoard function */
    char sudoku[9][9] = {{'2', '7', '0', '0', '0', '3', '0', '0', '0'},
                         {'9', '0', '0', '2', '1', '0', '0', '0', '8'},
                         {'0', '0', '3', '7', '0', '0', '4', '0', '0'},

                         {'0', '6', '0', '0', '0', '0', '2', '0', '5'},
                         {'0', '0', '0', '3', '0', '7', '0', '0', '0'},
                         {'4', '0', '5', '0', '0', '0', '0', '7', '0'},

                         {'0', '0', '4', '0', '0', '1', '8', '0', '0'},
                         {'5', '0', '0', '0', '2', '9', '0', '0', '7'},
                         {'0', '0', '0', '4', '0', '0', '0', '2', '3'}};
    char almostDoneSudoku[9][9] = {
                         {'2', '7', '0', '8', '4', '3', '9', '5', '6'},
                         {'9', '4', '6', '2', '1', '5', '7', '3', '8'},
                         {'8', '5', '3', '7', '9', '6', '4', '1', '2'},

                         {'3', '6', '7', '1', '8', '4', '2', '9', '5'},
                         {'1', '9', '2', '3', '5', '7', '6', '8', '4'},
                         {'4', '8', '5', '9', '6', '2', '3', '7', '1'},

                         {'7', '2', '4', '5', '3', '1', '8', '6', '9'},
                         {'5', '3', '8', '6', '2', '9', '1', '4', '7'},
                         {'6', '1', '9', '4', '7', '8', '5', '2', '3'}};
    return new SudokuBoard(almostDoneSudoku);
}
