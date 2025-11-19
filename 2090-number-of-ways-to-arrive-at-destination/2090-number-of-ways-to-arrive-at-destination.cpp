class Solution {
public:
    // Modulo for counting ways
    const long long MOD = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        // Build adjacency list: adj[u] = vector of {v, travel_time}
        vector<vector<pair<int, long long>>> adj(n);
        for(auto &road : roads){
            int u = road[0], v = road[1];
            long long t = road[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u , t});
        }

        // dist[i] = shortest distance from node 0 to i
        vector<long long> dist(n, LLONG_MAX);
        // ways[i] = number of shortest paths from node 0 to i
        vector<long long> ways(n, 0);

        // Min-heap (distance, node) to perform Dijkstra
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        // start from node 0
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();

            // If we have already found a better distance, skip
            if(d > dist[node]) continue;

            // Relax edges
            for(auto &[neighbor, wt] : adj[node]){
                long long newDist = d + wt;

                // Found a strictly shorter path to neighbor
                if(newDist < dist[neighbor]){
                    dist[neighbor] = newDist;
                    // Number of ways to reach neighbor equals ways to reach current node
                    ways[neighbor] = ways[node];
                    pq.push({newDist, neighbor});
                }
                // Found an additional shortest path (same distance)
                else if(newDist == dist[neighbor]){
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }
        // Return number of shortest paths to node n-1 modulo MOD
        return ways[n-1] % MOD;
    }
};