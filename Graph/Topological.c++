#include <iostream>
#include <list>
#include <vector>
#include <String>
#include <stack>
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

    void topoHelper(int node, vector<bool> &vis, stack<int> &s)
    {
        vis[node] = true;
        list<int> neighbors = l[node];
        for (int v : neighbors)
        {
            if (!vis[v])
            {
                topoHelper(v, vis, s);
            }
        }
        s.push(node);
    }
    void topoSort()
    {
        vector<bool> vis(V, false);
        stack<int> s;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                topoHelper(i, vis, s);
            }
        }
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
    }
};

int main()
{

    Graph g(6, false);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(5, 0);
    g.addEdge(5, 2);

    g.topoSort();
    return 0;
}