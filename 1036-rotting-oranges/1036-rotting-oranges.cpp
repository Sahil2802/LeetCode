class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();         // Number of rows
        int n = grid[0].size();      // Number of columns

        queue<pair<int, int>> q;     // Queue for BFS (stores rotten oranges)
        // Directions: down, up, right, left
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        int fresh = 0; // Count of fresh oranges
        // Initialize the queue with all initially rotten oranges and count fresh oranges
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(grid[r][c] == 2){
                    q.push({r, c}); // Add rotten orange to queue
                }
                else if(grid[r][c] == 1){
                    fresh++; // Count fresh oranges
                }
            }
        }

        int minutes = 0; // Time counter
        // BFS to rot adjacent fresh oranges minute by minute
        while(!q.empty()){
            int size = q.size();
            bool rotten = false; // Track if any orange rotted this minute
            // Process all oranges that are rotten at the current minute
            while(size--){
                auto [r, c] = q.front();
                q.pop();

                // Check all four directions
                for(auto [dr, dc] : directions){
                    int nr = r + dr;
                    int nc = c + dc;

                    // If neighbor is a fresh orange, rot it and add to queue
                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        q.push({nr, nc});
                        fresh--; // Decrease count of fresh oranges
                        grid[nr][nc] = 2; // Mark as rotten
                        rotten = true;    // At least one orange rotted this minute
                    }
                }
            }
            // Only increment minutes if any orange rotted in this round
            if(rotten) minutes++;
        }
        
        // If all oranges are rotten, return minutes, else return -1
        if(fresh == 0) return minutes;
        else return -1;
    }
};