#include<iostream>
using namespace std;

const int N = 9;

// Function to print the Sudoku board
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Check if it's safe to place num at board[row][col]
bool isSafe(int board[N][N], int row, int col, int num) {
    // Check row and column
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num || board[x][col] == num)
            return false;
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

// Recursive backtracking function to solve the board
bool solveSudoku(int board[N][N], int row, int col) {
    if (row == N - 1 && col == N) {
        return true; // All cells are filled
    }

    if (col == N) {
        row++;
        col = 0;
    }

    // If already filled, go to next cell
    if (board[row][col] != 0)
        return solveSudoku(board, row, col + 1);

    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;

            if (solveSudoku(board, row, col + 1))
                return true;

            board[row][col] = 0; // backtrack
        }
    }

    return false;
}

int main() {
    int board[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},

        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},

        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(board, 0, 0))
        printBoard(board);
    else
        cout << "No solution exists";

    return 0;
}
