#include <iostream>
#include <list>
#include <vector>
#include <String>
#include <queue>
using namespace std;
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
    void pathHelper(int src, int dest, vector<bool> &vis, string &path)
    {
        if (src == dest)
        {
            cout << path << dest << endl;
            return;
        }
        vis[src] = true;
        path += to_string(src);
        list<int> neighbors = l[src];

        for (int v : neighbors)
        {
            if (!vis[v])
            {
                pathHelper(v, dest, vis, path);
            }
        }
        path = path.substr(0, path.size() - 1);
        vis[src] = false;
    }
    void printAllPath(int src, int dest)
    {
        vector<bool> vis(V, false);
        string path = "";
        pathHelper(src, dest, vis, path);
    }
};

int main()
{

    Graph g(6, false);
    g.addEdge(0, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(5, 0);
    g.addEdge(5, 2);

    g.printAllPath(5, 1);
    return 0;
}