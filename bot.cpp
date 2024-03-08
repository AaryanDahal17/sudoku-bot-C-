#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;



void inputSudokuBoard(int board[9][9]) {
    cout << "Enter input of the row in the format -> 0 0 1 9 2 5 0 0 0 " << endl;

    for (int i = 0; i < 9; i++) {
        cout << "Enter row no. " << i + 1 << " : ";

        std::string userInput;
        std::getline(std::cin, userInput);

        std::stringstream ss(userInput);

        int number, index = 0;

        while (ss >> number && index < 9) {
            if (number > 9 || number < 0) {
                cout << "Invalid input" << endl;
                exit(0);
            }
            board[i][index++] = number;
        }

        cout << endl;
    }
}

const int SIZE = 9;

bool isValidPlacement(int sudokuBoard[][SIZE], int row, int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (sudokuBoard[row][i] == num || sudokuBoard[i][col] == num) {
            return false;
        }
    }

    int boxStartRow = row - row % 3;
    int boxStartCol = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudokuBoard[boxStartRow + i][boxStartCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool findEmptyCell(int sudokuBoard[][SIZE], int& row, int& col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (sudokuBoard[i][j] == 0) {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool solveSudokuBoard(int sudokuBoard[][SIZE]) {
    int row, col;
    if (!findEmptyCell(sudokuBoard, row, col)) {
        return true;
    }

    for (int num = 1; num <= SIZE; num++) {
        if (isValidPlacement(sudokuBoard, row, col, num)) {
            sudokuBoard[row][col] = num;

            if (solveSudokuBoard(sudokuBoard)) {
                return true;
            }

            sudokuBoard[row][col] = 0; // Backtrack
        }
    }

    return false;
}

void printSudokuBoard(int sudokuBoard[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << sudokuBoard[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    
    int sudokuBoardState[SIZE][SIZE];
    inputSudokuBoard(sudokuBoardState);

    if (solveSudokuBoard(sudokuBoardState)) {

        cout << "Solved Sudoku Board:" << endl;

        printSudokuBoard(sudokuBoardState);
    } else {

        cout << "No solution exists for this Sudoku Board.";
    }

    return 0;
}
