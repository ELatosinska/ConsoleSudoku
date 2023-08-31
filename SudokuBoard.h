#ifndef CONSOLESUDOKU_SUDOKUBOARD_H
#define CONSOLESUDOKU_SUDOKUBOARD_H


class SudokuBoard {
public:
    explicit SudokuBoard(char (*board)[9]);
    static bool isValidBoard(char (*board)[9]);
    void printBoard();
    bool isFinished();
    char board[9][9] = {};
    static void copyBoard(char (*oldBoard)[9], char (*newBoard)[9]);

    static bool isEmptyPlace(char board[9][9], char row, char column);

private:
    static bool isValidRow(char (*board)[9], int rowNumber);
    static bool isValidColumn(char (*board)[9], int columnNumber);
    static bool isValidBox(char (*board)[9], int boxNumber);
};


#endif //CONSOLESUDOKU_SUDOKUBOARD_H
