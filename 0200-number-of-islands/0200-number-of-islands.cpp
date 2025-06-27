class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();         // Number of rows
        int n = grid[0].size();      // Number of columns

        queue<pair<int, int>> q;     // Queue for BFS
        // Directions: down, up, right, left
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int islands = 0;             // Counter for number of islands

        // Traverse every cell in the grid
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                // If a land cell ('1') is found, start BFS
                if(grid[row][col] == '1'){
                    q.push({row, col});      // Add starting cell to queue
                    grid[row][col] = '0';    // Mark as visited
                    islands++;               // Increment island count

                    // BFS to visit all connected land cells
                    while(!q.empty()){
                        auto [r, c] = q.front();
                        q.pop();

                        // Explore all four directions
                        for(auto [dr, dc] : directions){
                            int nr = r + dr;
                            int nc = c + dc;
                            // Check bounds and if the neighbor is land
                            if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1'){
                                q.push({nr, nc});      // Add neighbor to queue
                                grid[nr][nc] = '0';    // Mark neighbor as visited
                            }
                        }
                    }
                }
            }
        }
        return islands; // Return the total number of islands found
    }
};