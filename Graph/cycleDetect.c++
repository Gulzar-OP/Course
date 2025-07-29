#include <iostream>
#include <list>
#include <vector>
using namespace std;

// undirected

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x); // For undirected graph
    }
    void printAdjacencyList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " -> ";
            for (auto j : l[i])
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
    bool cycleHelper(int src, int par, vector<bool> &vis)
    {
        vis[src] = true;
        list<int> neigh = l[src];
        for (int v : neigh)
        {
            if (!vis[v])
            {
                if (cycleHelper(v, src, vis))
                {
                    return true;
                }
            }
            else
            {
                if (v != par)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycleUndir()
    {
        vector<bool> vis(V, false);
        return cycleHelper(0, -1, vis);
    }
};

int main()
{
    // undirected graph
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    // g.printAdjacencyList();
    cout << g.isCycleUndir() << endl;
    return 0;
}