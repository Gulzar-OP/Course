#include <iostream>
#include <list>
#include <vector>
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

    bool isBipartite()
    {
        queue<int> q;
        vector<bool> vis(V, false);
        vector<bool> color(V, -1);

        q.push(0);
        color[0] = 0;
        while (q.size() > 0)
        {
            int curr = q.front();
            q.pop();
            list<int> neighbors = l[curr];
            for (int v : neighbors)
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    color[v] = !color[curr];
                    q.push(v);
                }
                else
                {
                    if (color[v] == color[curr])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 3);

    // g.printAdjacencyList();
    cout << g.isBipartite() << endl;
    return 0;
}