class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // Get the dimensions of the matrix
        int m = mat.size();
        int n = mat[0].size(); 

        // Initialize a distance matrix with -1 (unvisited cells)
        vector<vector<int>> dist(m, vector<int>(n, -1));
        // Queue to perform BFS
        queue<pair<int, int>> q;

        // Iterate through the matrix to find all cells with value 0
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    // Distance to itself is 0
                    dist[i][j] = 0;
                    // Add the cell to the BFS queue
                    q.push({i, j});
                }
            }
        }

        // Define the 4 possible directions for movement (up, down, left, right)
        pair<int, int> directions[4] = {{1,0}, {-1, 0}, {0,1}, {0,-1}};
        
        // Perform BFS to calculate the shortest distance to a 0 for each cell
        while(!q.empty()){
            // Get the current cell from the queue
            auto [r, c] = q.front();
            q.pop();

            // Explore all 4 directions
            for(auto [dr, dc] : directions){
                int nr = dr + r; // New row
                int nc = dc + c; // New column

                // Check if the new cell is within bounds and unvisited
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && dist[nr][nc] == -1){
                    // Update the distance for the new cell
                    dist[nr][nc] = dist[r][c] + 1;
                    // Add the new cell to the queue for further exploration
                    q.push({nr, nc});
                }
            }
        }
        // Return the distance matrix
        return dist;
    }
};