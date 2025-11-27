class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Use a large value to represent "infinity" (no direct path).
        // 1e9 is safe here because edge weights and path sums won't exceed this in typical constraints.
        int INF = 1e9;

        // dist[i][j] will hold the shortest known distance from i to j.
        // Initialize all distances to INF.
        vector<vector<int>> dist(n, vector<int>(n, INF));

        // Distance from a node to itself is zero.
        for (int i = 0; i < n; i++) dist[i][i] = 0;

        // Populate direct edge weights into the distance matrix.
        // The graph is undirected so set both dist[u][v] and dist[v][u].
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        // Floyd–Warshall algorithm:
        // Consider each vertex k as an intermediate node and try to improve
        // every pair shortest path dist[i][j] by checking the route i -> k -> j.
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // If either subpath is unreachable, skip relaxing this triple.
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        // Update dist[i][j] if going through k gives a shorter path.
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // After computing all-pairs shortest paths, determine the city with the
        // smallest number of other cities reachable within distanceThreshold.
        // In case of a tie, prefer the city with the greatest index.
        int resultCity = -1;          // answer index to return
        int minReachable = INT_MAX;   // smallest count of reachable cities seen so far

        for (int i = 0; i < n; i++) {
            int reachable = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    reachable++;
                }
            }

            // Update resultCity when we find fewer reachable cities,
            // or when equal but current city index i is larger (tie-break rule).
            if (reachable < minReachable || (reachable == minReachable && i > resultCity)) {
                minReachable = reachable;
                resultCity = i;
            }
        }

        // Return the chosen city index.
        return resultCity;
    }
};