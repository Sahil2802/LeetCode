class Solution {
public:
    // Function to find all eventual safe nodes in a directed graph
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size(); // Number of nodes in the graph
        
        // vis: marks if a node has been visited
        // visPath: marks if a node is in the current DFS path (for cycle detection)
        // isSafe: marks if a node is eventually safe (not part of any cycle)
        vector<bool> vis(n, false), visPath(n, false), isSafe(n, false);
        vector<int> safeNodes; // Stores the result

        // Run DFS for each node if it hasn't been visited
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, vis, visPath, isSafe, graph);
            }
        }

        // Collect all nodes that are marked as safe
        for(int i = 0; i < n; i++){
            if(isSafe[i]){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }

private:
    // Helper DFS function to detect cycles and mark safe nodes
    bool dfs(int node, vector<bool> &vis, vector<bool> &visPath, vector<bool> &isSafe, vector<vector<int>>& graph){
        vis[node] = true;        // Mark node as visited
        visPath[node] = true;    // Mark node as part of current DFS path

        // Traverse all neighbors of the current node
        for(auto neighbor : graph[node]){
            if(!vis[neighbor]){
                // If neighbor is not visited, continue DFS
                // If any neighbor is not safe, return false
                if(!dfs(neighbor, vis, visPath, isSafe, graph)) return false;
            }
            else if(visPath[neighbor]){
                // If neighbor is in current DFS path, a cycle exists
                return false;
            }
        }

        visPath[node] = false;   // Remove node from current DFS path before backtracking
        isSafe[node] = true;     // Mark node as safe
        return true;             // Node is safe
    }
};