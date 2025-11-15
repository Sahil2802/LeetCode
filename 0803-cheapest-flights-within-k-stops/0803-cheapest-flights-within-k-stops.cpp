class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int K) {

        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> cost(n, INT_MAX);
        cost[src] = 0;

        queue<pair<int,int>> q;  // {node, currentCost}
        q.push({src, 0});

        int stops = 0;

        while (!q.empty() && stops <= K) {
            int sz = q.size();

            // Temporary copy to store updates only for this BFS level
            vector<int> temp = cost;

            while (sz--) {
                auto [u, currCost] = q.front();
                q.pop();

                for (auto &[v, price] : adj[u]) {
                    int newCost = currCost + price;

                    // Relax only if strictly cheaper
                    if (newCost < temp[v]) {
                        temp[v] = newCost;
                        q.push({v, newCost});
                    }
                }
            }

            // apply relaxed costs after finishing this level
            cost = temp;
            stops++;
        }

        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};
