class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0; // Variable to store the maximum area of an island
        m = grid.size(); // Number of rows in the grid
        n = grid[0].size(); // Number of columns in the grid

        // Iterate over every cell in the grid
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // If the current cell is part of an island (i.e., value is 1)
                if(grid[i][j] == 1){
                    // Perform DFS to calculate the area of the island and update the maximum area
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }
        return ans; // Return the maximum area found
    }
private:
    int m, n; // Dimensions of the grid

    // DFS function to calculate the area of an island
    int dfs(int i, int j, vector<vector<int>>& grid){
        // Base case: Check if the current cell is out of bounds or water
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) return 0;

        // Mark the current cell as visited by setting it to 0
        grid[i][j] = 0;

        // Calculate the area by visiting all four adjacent cells (up, down, right, left)
        return 1 + dfs(i - 1, j, grid) + // Up
                   dfs(i + 1, j, grid) + // Down
                   dfs(i, j + 1, grid) + // Right
                   dfs(i, j - 1, grid);  // Left
    }
};
