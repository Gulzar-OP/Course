#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int u;
    int v;
    int wt;

    Edge(int u, int v, int wt)
    {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

class Graph
{
public:
    vector<Edge> edges;
    int V;
    vector<int> parent;
    vector<int> rank;

    Graph(int V)
    {
        this->V = V;
        parent.resize(V); // Resize is necessary
        rank.resize(V);

        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]); // Path compression
    }

    void unionSet(int x, int y)
    {
        int parA = find(x);
        int parB = find(y);
        if (parA == parB)
            return;

        // Union by rank
        if (rank[parA] < rank[parB])
        {
            parent[parA] = parB;
        }
        else if (rank[parA] > rank[parB])
        {
            parent[parB] = parA;
        }
        else
        {
            parent[parB] = parA;
            rank[parA]++;
        }
    }

    void addEdge(int u, int v, int wt)
    {
        edges.push_back(Edge(u, v, wt));
    }

    void kruskals()
    {
        sort(edges.begin(), edges.end(), [](Edge &a, Edge &b)
             { return a.wt < b.wt; });

        vector<Edge> mst;
        int totalWeight = 0;
        int count = 0; // Count of edges added to MST

        for (Edge &e : edges)
        {
            if (find(e.u) != find(e.v))
            {
                mst.push_back(e);
                totalWeight += e.wt;
                unionSet(e.u, e.v);
                count++;

                if (count == V - 1)
                    break; // Stop after V-1 edges are added
            }
        }

        cout << "Edges in MST:\n";
        for (Edge &e : mst)
        {
            cout << e.u << " - " << e.v << " : " << e.wt << endl;
        }
        cout << "Total weight of MST: " << totalWeight << endl;
    }
};

int main()
{
    Graph g(4); // Specify number of vertices

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 15);
    g.addEdge(0, 3, 30);
    g.addEdge(1, 3, 40);
    g.addEdge(2, 3, 50);

    g.kruskals();

    return 0;
}
