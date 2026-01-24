#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int removeStones(vector<vector<int>> &stones)
{
    int n = stones.size();
    int m = stones[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    int x, y;
    for (int i = 0; i < n; i++)
    {
        x = stones[i][0];
        y = stones[i][1];
        // cout<<"Stone " << i + 1 << ": (" << x << ", " << y << ")\n";
        dist[x][y] = 0;
        // cout << dist[x][y];
        q.push({x, y});
        // cout << dist[x][y];
    }

    vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

return x;
}
int main()
{
    vector<vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    cout << removeStones(stones);
    return 0;
}