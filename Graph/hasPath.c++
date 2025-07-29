#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        // Step 1: Create adjacency list
        vector<vector<int>> graph(n);
        for (auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]); // Undirected
        }

        // Step 2: BFS
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            if (node == destination)
                return true;

            for (int neighbor : graph[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return false;
    }
};
int main()
{
    Solution solution;
    int n = 5; // Number of nodes
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {0, 4}};
    int source = 0;
    int destination = 4;

    bool result = solution.validPath(n, edges, source, destination);
    cout << "Is there a valid path from " << source << " to " << destination << "? " << (result ? "Yes" : "No") << endl;

    return 0;
}