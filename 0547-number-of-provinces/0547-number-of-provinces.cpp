class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0); // Track visited cities

        int provinces = 0; // Count of connected components (provinces)
        // Iterate through each city
        for(int i = 0; i < n; i++){
            // If the city hasn't been visited, it's a new province
            if(visited[i] == 0){
                dfs(i, n, isConnected, visited); // Visit all cities in this province
                provinces++; // Increment province count
            }
        }
        return provinces;
    }
private:
    // DFS to visit all cities connected to 'node'
    void dfs(int node, int n, vector<vector<int>> &isConnected, vector<int> &visited){
        visited[node] = 1; // Mark current city as visited
        // Check all possible connections
        for(int j = 0; j < n; j++){
            // If there is a connection and the city hasn't been visited
            if(isConnected[node][j] == 1 && visited[j] == 0){
                dfs(j, n, isConnected, visited); // Visit the connected city
            }
        }
    }
};