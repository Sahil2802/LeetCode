class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        // Get the dimensions of the grid
        int m = grid.size();
        int n = grid[0].size();

        // Define the 4 possible directions for movement (up, down, left, right)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Traverse the first and last rows to remove boundary-connected land cells
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1) { // First row
                dfs(0, i, grid, m, n, directions);
            }
            if (grid[m-1][i] == 1) { // Last row
                dfs(m-1, i, grid, m, n, directions);
            }
        }

        // Traverse the first and last columns to remove boundary-connected land cells
        for (int j = 0; j < m; j++) {
            if (grid[j][0] == 1) { // First column
                dfs(j, 0, grid, m, n, directions);
            }
            if (grid[j][n-1] == 1) { // Last column
                dfs(j, n-1, grid, m, n, directions);
            }
        }

        // Count the remaining land cells that are not connected to the boundary
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) { // Count land cells
                    ans++;
                }
            }
        }

        return ans; // Return the number of enclaves
    }

private:
    // Depth-First Search (DFS) to remove boundary-connected land cells
    void dfs(int r, int c, vector<vector<int>>& grid, int m, int n, vector<pair<int, int>>& directions) {
        // Boundary check and character comparison
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 1) return;

        // Mark the cell as visited by changing 1 to 0
        grid[r][c] = 0;

        // Explore all 4 directions
        for (auto [dr, dc] : directions) {
            int nr = r + dr; // New row
            int nc = c + dc; // New column
            dfs(nr, nc, grid, m, n, directions);
        }
    }
};