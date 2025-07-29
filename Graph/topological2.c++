#include <iostream>
#include <list>
#include <vector>
#include <queue>
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
    // Function to calculate in-degrees of all vertices
    // and store them in the indeg vector
    void calInDeg(vector<int> &indeg)
    {
        for (int u = 0; u < V; u++)
        {
            list<int> neighbors = l[u];
            for (int v : neighbors)
            {
                indeg[v]++;
            }
        }
    }
    void toposort2()
    {
        vector<int> indeg(V, 0);
        calInDeg(indeg);
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";
            list<int> neighbors = l[node];
            for (int v : neighbors)
            {
                indeg[v]--;
                if (indeg[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        cout << endl;
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

    g.toposort2();
    return 0;
}