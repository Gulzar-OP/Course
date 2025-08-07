#include <iostream>
#include <vector>
#include <queue>
#include <climits> // For INT_MAX
using namespace std;

class Solution {
public:
    class info {
    public:
        int u;
        int cost;
        int stops;
        info(int u, int cost, int stops) {
            this->u = u;
            this->cost = cost;
            this->stops = stops;
        }
    };

    int findCheapestPrice(int V, vector<vector<int>>& flights, int src, int dst, int k) {
        // Adjacency list
        vector<pair<int, int>> adj[V];
        for (auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        // Queue for BFS (u, cost, stops)
        queue<info> q;
        vector<int> dist(V, INT_MAX);
        q.push(info(src, 0, 0));
        dist[src] = 0;

        while (!q.empty()) {
            info curr = q.front();
            q.pop();

            int u = curr.u;
            int cost = curr.cost;
            int stops = curr.stops;

            // If stops > k, skip
            if (stops > k) continue;

            for (auto& [v, wt] : adj[u]) {
                if (cost + wt < dist[v]) {
                    dist[v] = cost + wt;
                    q.push(info(v, dist[v], stops + 1));
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

// === Test the code ===
int main() {
    Solution sol;

    int V = 4;
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {0, 2, 500}
    };
    int src = 0;
    int dst = 2;
    int k = 1;

    int result = sol.findCheapestPrice(V, flights, src, dst, k);
    cout << "Cheapest Price: " << result << endl;

    return 0;
}
