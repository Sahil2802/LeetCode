class Solution {
public:
    // Function to check if the given graph is bipartite
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(); // Number of nodes in the graph
        vector<int> color(n, -1); // Color array to store colors of nodes (-1 means uncolored)

        // Check each component of the graph
        for(int i = 0; i < n; i++){
            // If the node is not colored, perform BFS from that node
            if(color[i] == -1){
                if(bfs(i, graph, color) == false) // If not bipartite, return false
                    return false;
            }
        }
        // If all components are bipartite, return true
        return true;
    }
private:
    // Helper function to perform BFS and check bipartiteness
    bool bfs(int start, vector<vector<int>>& graph, vector<int> &color){
        queue <int> q;
        q.push(start); // Start BFS from the given node
        color[start] = 0; // Assign the first color

        while(!q.empty()){
            int node = q.front();
            q.pop();

            // Traverse all neighbors of the current node
            for(int neighbor : graph[node]){
                if(color[neighbor] == -1){
                    // If neighbor is not colored, assign alternate color and add to queue
                    q.push(neighbor);
                    color[neighbor] = 1 - color[node];
                }
                else if(color[neighbor] == color[node]){
                    // If neighbor has the same color, graph is not bipartite
                    return false;
                }
            }
        }
        // If BFS completes without conflicts, the component is bipartite
        return true;
    }
};