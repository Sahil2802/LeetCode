class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Base cases — no path if start or end is blocked
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<pair<int, int>> directions = 
        {
         {-1, -1}, {-1, 0}, {-1, 1},
         {0, -1},           {0, 1},
         {1, -1},  {1, 0},  {1, 1}
        };
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int pathLength  = 1;

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto [r, c] = q.front();
                q.pop();

                if(r == n-1 && c == n-1) return pathLength;

                for(auto [dr, dc] : directions){
                    int nr = r + dr;
                    int nc = c + dc;

                    if(nr < n && nr >= 0 && nc < n && nc >= 0 && grid[nr][nc] == 0){
                        q.push({nr, nc});
                        grid[nr][nc] = 1;
                    }
                }
            }
            pathLength++;
        }
        return -1;
    }
};