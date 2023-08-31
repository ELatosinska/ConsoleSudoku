
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "SudokuBoard.h"

bool SudokuBoard::isValidBoard(char (*board)[9]) {
    for (int i = 0; i < 9; ++i) {
        if (!isValidRow(board, i)) {
            std::cout << "Invalid row " << i;
            return false;
        }
        if (!isValidColumn(board, i)) {

            std::cout << "Invalid column " << i;
            return false;
        }
        if (!isValidBox(board, i)) {

            std::cout << "Invalid box " << i << std::endl;
            return false;
        }
    }
    return true;
}

void SudokuBoard::printBoard() {
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0) {
            for (int k = 0; k < 19; ++k) {
                std::cout << '-';
            }
            std::cout << std::endl;
        }
        for (int j = 0; j < 9; ++j) {
            if (j % 3 == 0) {
                std::cout << '|';
            } else {
                std::cout << ' ';
            }
            std::cout << (board[i][j] == '0' ? ' ' : board[i][j]);
        }
        std::cout << '|' << std::endl;
    }
    for (int k = 0; k < 19; ++k) {
        std::cout << '-';
    }
    std::cout << std::endl;
}

SudokuBoard::SudokuBoard(char (*sudokuBoard)[9]) {
    copyBoard(sudokuBoard, this->board);
}


bool SudokuBoard::isValidRow(char (*board)[9], int rowNumber) {
    std::vector<char> row;
    for (int i = 0; i < 9; ++i) {
        char number = board[i][rowNumber];
        if (number != '0' && number != ' ') row.push_back(number);
    }
    std::unordered_set set(row.begin(), row.end());
    return set.size() == row.size();
}

bool SudokuBoard::isValidColumn(char (*board)[9], int columnNumber) {
    std::vector<char> column;
    for (int i = 0; i < 9; ++i) {
        char number = board[columnNumber][i];
        if (number != '0' && number != ' ') column.push_back(number);
    }
    std::unordered_set set(column.begin(), column.end());
    return set.size() == column.size();
}

bool SudokuBoard::isValidBox(char (*board)[9], int boxNumber) {
    int rowStart = boxNumber - boxNumber % 3;
    int colStart = (boxNumber % 3) * 3;
    std::vector<char> box;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            char number = board[i + colStart][j + rowStart];
            if (number != '0' && number != ' ') box.push_back(number);
        }
    }
    std::unordered_set set(box.begin(), box.end());
    return set.size() == box.size();
}

bool SudokuBoard::isFinished() {
    for (int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            if(board[i][j] == '0') return false;
            if(board[i][j] == ' ') return false;
        }
        if (**(board + i) == '0') return false;
        if (**(board + i) == ' ') return false;

    }
    return true;
}

void SudokuBoard::copyBoard(char (*oldBoard)[9], char (*newBoard)[9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            newBoard[i][j] = oldBoard[i][j];
        }
    }
}

bool SudokuBoard::isEmptyPlace(char (*board)[9], char row, char column) {
    return board[row][column] == '0' || board[row][column] == ' ';
}
