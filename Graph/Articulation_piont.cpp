#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, adj, vis);
    }
}

bool isConnected(int V, vector<int> adj[], int skip)
{
    vector<int> vis(V, 0);
    int start = (skip == 0) ? 1 : 0;
    cout << "Checking connectivity by skipping node " << skip << "\n";
    dfs(start, adj, vis);

    for (int i = 0; i < V; i++)
    {
        if (i == skip)
            continue;
        if (!vis[i])
        {
            cout << "Node " << i << " is NOT reachable when skipping " << skip << "\n";
            return false;
        }
    }
    return true;
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    adj[0] = {1, 2};
    adj[1] = {0};
    adj[2] = {0, 3, 4};
    adj[3] = {2, 4};
    adj[4] = {2, 3};

    cout << "Graph adjacency list:\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << " -> ";
        for (auto x : adj[i])
            cout << x << " ";
        cout << "\n";
    }

    for (int i = 0; i < V; i++)
    {
        if (!isConnected(V, adj, i))
            cout << i << " is an articulation point\n";
    }

    cout << "Program finished!\n";
    return 0;
}
