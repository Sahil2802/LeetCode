class Solution {
public:
  /*You can take many possible paths from (0,0) to (n-1,n-1).
    Each path has its own maximum step effort.
    You must find the path whose maximum step effort is the smallest possible among all. */
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        // dist[r][c] = minimum possible "maximum step effort" to reach (r,c)
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

        // 4-directional moves: down, up, right, left
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        // {effort_so_far, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; 
        
        // Start from (0,0) with 0 effort
        pq.push({0, 0, 0});
        dist[0][0] = 0;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int effort = top[0]; // current path's maximum step effort up to this cell
            int r = top[1];
            int c = top[2];

            // If we reached destination, effort is the minimum possible because
            // we always expand the cell with smallest effort first
            if(r == rows-1 && c == cols-1){
                return effort;
            }

            // Explore 4 neighbors
            for(auto [dr, dc] : directions){
                int nr = dr + r;
                int nc = dc + c;

                // Validate bounds
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols){
                    // Effort to move to neighbor is the absolute height diff
                    int currDiff = abs(heights[r][c] - heights[nr][nc]);
                    // New path's effort is the maximum of current path effort and this step
                    int newEffort = max(effort, currDiff);

                    // If this path gives a smaller maximum-step effort to reach (nr,nc),
                    // update and push to heap
                    if(newEffort < dist[nr][nc]){
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, nr, nc});
                    }
                }
            }
        }
        // Should not reach here for valid non-empty grid, but return -1 as fallback
        return -1;
    }
};