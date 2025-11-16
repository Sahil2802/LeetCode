class Solution {
public:
    // Find the cheapest price from src to dst with at most K stops.
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int K) {

        // Build adjacency list: adj[u] = list of {v, price}
        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        // cost[u] = best known cost to reach u using up to the processed number of stops
        vector<int> cost(n, INT_MAX);
        cost[src] = 0; // cost to reach source is zero

        // BFS queue storing {node, cost_so_far}; levels correspond to number of stops used
        queue<pair<int,int>> q;
        q.push({src, 0});

        int stops = 0; // number of edges taken so far (0 at source)

        // Process up to K stops (i.e., K+1 levels including 0 stops)
        while (!q.empty() && stops <= K) {
            int sz = q.size();

            // Temporary copy to apply relaxations for this level only.
            // This prevents updates from the same level influencing other nodes in the same level.
            vector<int> temp = cost;

            // Process all nodes reachable with the current number of stops
            while (sz--) {
                auto [u, currCost] = q.front();
                q.pop();

                // Relax all outgoing edges from u
                for (auto &[v, price] : adj[u]) {
                    int newCost = currCost + price;

                    // If we found a strictly cheaper cost for v for the next level,
                    // update temp and enqueue v to explore its edges in the next level.
                    if (newCost < temp[v]) {
                        temp[v] = newCost;
                        q.push({v, newCost});
                    }
                }
            }

            // Commit level relaxations and move to next stop count
            cost = move(temp);
            stops++;
        }

        // If destination unreachable within K stops, return -1
        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};
