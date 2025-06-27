class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid[0].size(); // Number of columns
        int m = grid.size();    // Number of rows

        int island = 0; // Counter for number of islands
        // Traverse every cell in the grid
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                // If a land cell ('1') is found, start DFS
                if(grid[row][col] == '1'){
                    dfs(row, col, grid, n, m); // Mark all connected land as visited
                    island++; // Increment island count
                }
            }
        }
        return island;
    }
private:
    // DFS to mark all connected land cells as visited
    void dfs(int row, int col, vector<vector<char>> &grid, int n, int m){
        // Check for out-of-bounds or if the cell is not land
        if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col] != '1'){
            return;
        }

        grid[row][col] = '0'; // Mark the current cell as visited (water)

        // Explore all four directions (up, down, left, right)
        dfs(row - 1, col, grid, n, m); // Up
        dfs(row + 1, col, grid, n, m); // Down
        dfs(row, col - 1, grid, n, m); // Left
        dfs(row, col + 1, grid, n, m); // Right
    }
};