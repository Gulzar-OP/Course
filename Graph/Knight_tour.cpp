#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

struct Node
{
    int x, y, dist;
};

int minKnightMoves(int n, int startX, int startY, int endX, int endY)
{
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<Node> q;

    q.push({startX, startY, 0});
    visited[startX][startY] = true;

    while (!q.empty())
    {
        Node curr = q.front();
        q.pop();

        if (curr.x == endX && curr.y == endY)
            return curr.dist;

        for (int k = 0; k < 8; k++)
        {
            int nx = curr.x + dx[k];
            int ny = curr.y + dy[k];

            if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                q.push({nx, ny, curr.dist + 1});
            }
        }
    }
    return -1; // unreachable
}

int main()
{
    int n=8;
    // cout << "Enter board size: ";
    // cin >> n;

    int moves = minKnightMoves(n, 1, 4, 7, 1);
    if (moves != -1)
        cout << "Minimum moves from (1,4) to (7,1) " << moves << endl;
    else
        cout << "Target not reachable" << endl;

    return 0;
}
