#include<iostream>
using namespace std;

#define N 4

bool isSafe(int maze[N][N], int x, int y) {
    return (x < N && y < N && maze[x][y] == 1);
}

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
    // Base case: If (x,y) is the goal
    if (x == N-1 && y == N-1) {
        sol[x][y] = 1;
        return true;
    }

    // Check if maze[x][y] is a valid move
    if (isSafe(maze, x, y)) {
        sol[x][y] = 1;

        // Move Right
        if (solveMazeUtil(maze, x, y + 1, sol))
            return true;

        // Move Down
        if (solveMazeUtil(maze, x + 1, y, sol))
            return true;

        // Backtrack if no direction works
        sol[x][y] = 0;
        return false;
    }

    return false;
}

bool solveMaze(int maze[N][N]) {
    int sol[N][N] = { {0} };

    if (!solveMazeUtil(maze, 0, 0, sol)) {
        cout << "No path found!" << endl;
        return false;
    }

    // Print the solution matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }

    return true;
}

int main() {
    int maze[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    solveMaze(maze);
    return 0;
}
