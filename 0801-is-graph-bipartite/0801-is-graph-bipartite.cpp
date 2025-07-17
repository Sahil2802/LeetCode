class Solution {
public:
    // Function to check if the given graph is bipartite
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); // Number of nodes in the graph
        vector<int> color(n, -1); // Color array to store colors of nodes (-1 means uncolored)

        // Check each component of the graph
        for(int i = 0; i < n; i++){
            // If the node is not colored, perform DFS from that node
            if(color[i] == -1){
                // If DFS finds a conflict, graph is not bipartite
                if(dfs(i, 0, graph, color) == false)
                    return false;
            }
        }
        // If all components are bipartite, return true
        return true;
    }

private:
    // Helper function to perform DFS and check bipartiteness
    bool dfs(int node, int c, vector<vector<int>>& graph, vector<int> &color){
        color[node] = c; // Assign color c to the current node

        // Traverse all neighbors of the current node
        for(int neighbor : graph[node]){
            if(color[neighbor] == -1){
                // If neighbor is not colored, assign alternate color and continue DFS
                if(dfs(neighbor, 1 - c, graph, color) == false)
                    return false;
            }
            else if(color[neighbor] == color[node]){
                // If neighbor has the same color, graph is not bipartite
                return false;
            }
        }
        // If DFS completes without conflicts, the component is bipartite
        return true;
    }
};