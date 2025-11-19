class Solution {
public:
    const long long MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, long long>>> adj(n);
        for(auto &road : roads){
            int u = road[0], v = road[1];
            long long t = road[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u , t});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node]) continue;

            for(auto &[neighbor, wt] : adj[node]){
                long long newDist = d + wt;
                if(newDist < dist[neighbor]){
                    dist[neighbor] = newDist;
                    ways[neighbor] = ways[node];
                    pq.push({newDist, neighbor});
                }
                else if(newDist == dist[neighbor]){
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1] % MOD;
    }
};