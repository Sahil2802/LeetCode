class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(); // grid is n x n

        // If start or end is blocked, no path exists.
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        // All 8 possible directions (diagonals included).
        vector<pair<int,int>> directions = {
            {-1,-1}, {-1,0}, {-1,1},
            { 0,-1},         { 0,1},
            { 1,-1}, { 1,0}, { 1,1}
        };

        queue<pair<int,int>> q;
        q.push({0, 0});         // start from top-left
        grid[0][0] = 1;         // mark visited by setting to 1
        int pathLength = 1;     // starting cell counts as length 1

        // Standard BFS layered traversal: each layer increments path length.
        while (!q.empty()) {
            int levelSize = q.size(); // Number of cells at current level
            
            for (int i = 0; i < levelSize; ++i) {
                auto [r, c] = q.front();
                q.pop();

                // If we reached bottom-right, return current path length.
                if (r == n - 1 && c == n - 1) return pathLength;

                // Explore all neighbors.
                for (auto [dr, dc] : directions) {
                    int nr = r + dr;
                    int nc = c + dc;

                    // Check bounds and whether the cell is unblocked (0).
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                        q.push({nr, nc});
                        grid[nr][nc] = 1; // mark visited immediately to avoid duplicates
                    }
                }
            }
            ++pathLength; // finished one BFS layer -> increase path length
        }

        // No path found.
        return -1;
    }
};