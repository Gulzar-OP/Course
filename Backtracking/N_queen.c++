#include<iostream>
#include<vector>
using namespace std;

// Function to print the board
void printBoard(vector<vector<char>> &board){
    int n = board.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------------\n";
}

// Check if it's safe to place a queen at board[row][col]
bool isSafe(vector<vector<char>> &board, int row, int col){
    int n = board.size();

    // Check vertical column
    for(int i = 0; i < row; i++){
        if(board[i][col] == 'Q')
            return false;
    }

    // Check upper-left diagonal
    for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == 'Q')
            return false;
    }

    // Check upper-right diagonal
    for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++){
        if(board[i][j] == 'Q')
            return false;
    }

    return true;
}

// Recursive function to solve N-Queens
void Nqueen(vector<vector<char>> &board, int row){
    int n = board.size();

    if(row == n){
        printBoard(board);
        return;
    }

    for(int j = 0; j < n; j++){
        if(isSafe(board, row, j)){
            board[row][j] = 'Q';
            Nqueen(board, row + 1);
            board[row][j] = '.';  // Backtrack
        }
    }
}

int main(){
    int n = 5;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    Nqueen(board, 0);
    return 0;
}
