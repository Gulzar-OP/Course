#include <iostream>
#include <list>
#include <vector>
using namespace std;

// undirected

class Graph
{
    int V;
    list<int> *l;
    bool isUndir;

public:
    Graph(int V, bool isUndir = true)
    {
        this->V = V;
        l = new list<int>[V];
        this->isUndir = isUndir;
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        if (isUndir)
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
    bool dirCycleHelper(int src, vector<bool> &vis, vector<bool> &recPath)
    {
        vis[src] = true;
        recPath[src] = true;
        list<int> neighbors = l[src];

        for (int v : neighbors)
        {
            if (!vis[v])
            {
                if (dirCycleHelper(v, vis, recPath))
                {
                    return true;
                }
            }
            else
            {
                if (recPath[v])
                {
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }

    bool
    isCycleDir()
    {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dirCycleHelper(i, vis, recPath))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    // directed graph
    Graph g(5, false);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);

    // g.printAdjacencyList();
    // cout << g.isCycleUndir() << endl;
    cout << g.isCycleDir() << endl;
    return 0;
}