#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;

    void dfsHelper(int node, vector<bool> &visited)
    {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                dfsHelper(neighbor, visited);
            }
        }
    }

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
        if (u >= V || v >= V)
        {
            cout << "Invalid edge: (" << u << ", " << v << ")\n";
            return;
        }
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    void DFS()
    {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                // cout << "DFS Traversal starting from node " << i << ": ";

                dfsHelper(i, visited);
                cout << endl;
            }
        }
        cout << endl;
    }
};

int main()
{
    Graph g(10); // Enough space for nodes up to 9
    g.addEdge(1, 6);
    g.addEdge(6, 4);
    g.addEdge(4, 9);
    g.addEdge(4, 3);
    g.addEdge(3, 8);
    g.addEdge(3, 7);

    Graph G(6); // Enough for 0 to 5
    G.addEdge(2, 5);
    G.addEdge(2, 0);

    g.DFS();
    G.DFS();

    return 0;
}
