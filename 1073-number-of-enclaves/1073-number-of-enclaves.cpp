class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        // Get the dimensions of the grid
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0; // Variable to store the count of enclaves

        // Queue for BFS traversal
        queue<pair<int, int>> q;

        // Traverse the grid to find all boundary-connected land cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the cell is on the boundary and is land (value 1)
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && (grid[i][j] == 1)) {
                    q.push({i, j}); // Add the cell to the BFS queue
                    grid[i][j] = 0; // Mark the cell as visited by changing 1 to 0
                }
            }
        }

        // Define the 4 possible directions for movement (up, down, left, right)
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Perform BFS to remove all boundary-connected land cells
        while (!q.empty()) {
            auto [r, c] = q.front(); // Get the current cell
            q.pop();

            // Explore all 4 directions
            for (auto [dr, dc] : dirs) {
                int nr = r + dr; // New row
                int nc = c + dc; // New column

                // Check if the new cell is within bounds and is land (value 1)
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    q.push({nr, nc}); // Add the cell to the BFS queue
                    grid[nr][nc] = 0; // Mark the cell as visited by changing 1 to 0
                }
            }
        }

        // Count the remaining land cells that are not connected to the boundary
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) { // If the cell is land
                    ans++; // Increment the count of enclaves
                }
            }
        }

        return ans; // Return the number of enclaves
    }
};