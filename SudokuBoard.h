#ifndef HELLOWORLD_SUDOKUBOARD_H
#define HELLOWORLD_SUDOKUBOARD_H


class SudokuBoard {
public:
    explicit SudokuBoard(char (*board)[9]);

    static bool isValidBoard(const SudokuBoard *board);
    void printBoard();
private:
    char board[9][9] = {};
    static bool isValidRow(const SudokuBoard *board, int rowNumber);
    static bool isValidColumn(const SudokuBoard *board, int columnNumber);
    static bool isValidBox(const SudokuBoard *board, int boxNumber);
};


#endif //HELLOWORLD_SUDOKUBOARD_H
