class Solution {
public:
    // DFS to traverse all stones in the same connected component
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj) {
        vis[node] = 1; // mark current stone as visited
        
        // Visit all neighboring stones (those sharing row or column)
        for (auto &neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, vis, adj);
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> adj(n); // adjacency list for n stones

        // Build graph: connect stones that share same row or column
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // If stones[i] and stones[j] share row (x) or column (y)
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // Count number of connected components using DFS
        vector<int> vis(n, 0);
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                components++;           // found a new component
                dfs(i, vis, adj);       // mark all stones in this component
            }
        }
        
        // Maximum stones removable = total stones - number of components
        // (from each component,exactly 1 stone will be left after removing max possible stones)
        return n - components;
    }
};