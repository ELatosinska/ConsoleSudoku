
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "SudokuBoard.h"

bool SudokuBoard::isValidBoard(const SudokuBoard *board) {
    for (int i = 0; i < 9; ++i) {
        if (!(isValidRow(board, i) && isValidColumn(board, i) && isValidBox(board, i))) return false;
    }
    return true;
}

void SudokuBoard::printBoard() {
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0) {
            for (int k = 0; k < 13; ++k) {
                std::cout << '-';
            }
            std::cout << std::endl;
        }
        for (int j = 0; j < 9; ++j) {
            if (j % 3 == 0) {
                std::cout << '|';
            }
            std::cout << (board[i][j] == '0' ? ' ' : board[i][j]);
        }
        std::cout << std::endl;
    }
}

SudokuBoard::SudokuBoard(char (*sudokuBoard)[9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            this->board[i][j] = sudokuBoard[i][j];
        }
    }
}

bool SudokuBoard::isValidRow(const SudokuBoard *board, int rowNumber) {
    std::vector<char> row;
    for (int i = 0; i < 9; ++i) {
        char number = board->board[i][rowNumber];
        if (number != '0' && number != ' ') row.push_back(number);
    }
    std::unordered_set set(row.begin(), row.end());
    return set.size() == row.size();
}

bool SudokuBoard::isValidColumn(const SudokuBoard *board, int columnNumber) {
    std::vector<char> column;
    for (int i = 0; i < 9; ++i) {
        char number = board->board[columnNumber][i];
        if (number != '0' && number != ' ') column.push_back(number);
    }
    std::unordered_set set(column.begin(), column.end());
    return set.size() == column.size();
}

bool SudokuBoard::isValidBox(const SudokuBoard *board, int boxNumber) {
    int rowStart = boxNumber - boxNumber%3;
    int colStart = (boxNumber%3)*3;
    std::vector<char> box;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            char number = board->board[i+colStart][j+rowStart];
            if (number != '0' && number != ' ') box.push_back(number);
        }
    }
    std::unordered_set set(box.begin(), box.end());
    return set.size() == box.size();
}
