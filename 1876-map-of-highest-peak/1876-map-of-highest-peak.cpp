class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        // Get the dimensions of the grid
        int m = isWater.size();
        int n = isWater[0].size();

        // Initialize the height matrix with -1 (unvisited cells)
        vector<vector<int>> height(m, vector<int>(n, -1));
        // Queue to perform BFS
        queue<pair<int, int>> q;

        // Iterate through the grid to find all water cells
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isWater[i][j] == 1){
                    // Water cells have a height of 0
                    q.push({i, j});
                    height[i][j] = 0;
                }
            }
        }

        // Define the 4 possible directions for movement (up, down, left, right)
        pair<int, int> directions[4] = {{1,0},{-1,0},{0,1},{0,-1}};
        
        // Perform BFS to calculate the height of each cell
        while(!q.empty()){
            // Get the current cell from the queue
            auto [r, c] = q.front();
            q.pop();

            // Explore all 4 directions
            for(auto [dr, dc] : directions){
                int nr = dr + r; // New row
                int nc = dc + c; // New column

                // Check if the new cell is within bounds and unvisited
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && height[nr][nc] == -1){
                    // Add the new cell to the queue
                    q.push({nr, nc});
                    // Update the height of the new cell
                    height[nr][nc] = height[r][c] + 1;
                }
            }
        }
        // Return the height matrix
        return height;
    }
};