#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;
class Graph
{
    int V;
    list<pair<int, int>> *l;
    bool isUndir;

public:
    Graph(int V, bool isUndir = true)
    {
        this->V = V;
        l = new list<pair<int, int>>[V];
        this->isUndir = isUndir;
    }
    void addEdge(int x, int y, int wt)
    {
        l[x].push_back(make_pair(y, wt));
        if (isUndir)
            l[y].push_back(make_pair(x, wt)); // For undirected graph
    }
    void primsAlgo(int src)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> mst(V, false);

        pq.push(make_pair(0, src));
        int ans = 0;
        while (pq.size() > 0)
        {
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if (!mst[u])
            {
                mst[u] = true;
                ans += wt;
                list<pair<int, int>> neigh = l[u];
                for (pair<int, int> n : neigh)
                {
                    int v = n.first;
                    int currWt = n.second;
                    if (!mst[v]) // Only push if not already in MST
                        pq.push(make_pair(currWt, v));
                }
            }
        }
        cout << ans << endl;
    }
};

int main()
{

    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 15);
    g.addEdge(0, 3, 30);
    g.addEdge(1, 3, 40);
    g.addEdge(2, 3, 50);

    g.primsAlgo(0);
    return 0;
}