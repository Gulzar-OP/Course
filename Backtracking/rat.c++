#include <iostream>
#include <vector>
using namespace std;

// #define N 4

bool isSafe(int maze[4][4], int N, int x, int y)
{
    if (x >= 0 && y >= 0 && x < N && y < N && maze[x][y] != 0)
    {
        return true;
    }
    return false;
}

void solveMaze(int maze[4][4], int N, vector<vector<int>> &path, int x, int y)
{
    if (x == N - 1 && y == N - 1)
    {
        cout << "path found " << endl;
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i][0] << " " << path[i][1] << " -> ";
        }
        cout << x << " " << y;
        cout << endl;
        return;
    }
    if (isSafe(maze, N, x, y))
    {
        maze[x][y] = 0;
        vector<int> temp;
        temp.push_back(x);
        temp.push_back(y);
        path.push_back(temp);
        solveMaze(maze, N, path, x, y + 1);
        solveMaze(maze, N, path, x + 1, y);
        solveMaze(maze, N, path, x, y - 1);
        solveMaze(maze, N, path, x - 1, y);
        maze[x][y] = 1;
        path.pop_back();
    }
}

int main()
{
    int N = 4;
    vector<vector<int>> path;
    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 1, 0, 1},
        {1, 1, 1, 1}};

    solveMaze(maze, N, path, 0, 0);
    return 0;
}
