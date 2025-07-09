class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // Get the dimensions of the board
        int m = board.size();
        int n = board[0].size();

        // Define the 4 possible directions for movement (up, down, left, right)
        vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

        // Traverse the first and last columns to mark connected 'O's
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') dfs(i, 0, board, m, n, dirs); // First column
            if (board[i][n-1] == 'O') dfs(i, n-1, board, m, n, dirs); // Last column
        }

        // Traverse the first and last rows to mark connected 'O's
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') dfs(0, j, board, m, n, dirs); // First row
            if (board[m-1][j] == 'O') dfs(m-1, j, board, m, n, dirs); // Last row
        }

        // Update the board
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Convert unmarked 'O's to 'X'
                if (board[i][j] == 'O') board[i][j] = 'X';
                // Convert temporary marked 'T's back to 'O'
                if (board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }
    
private:
    // Depth-First Search (DFS) to mark connected 'O's
    void dfs(int r, int c, vector<vector<char>>& board, int m, int n, vector<pair<int,int>>& dirs) {
        // Boundary check and character comparison
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') return;

        // Mark the cell as visited by changing 'O' to 'T'
        board[r][c] = 'T';

        // Explore all 4 directions
        for (auto [dr, dc] : dirs) {
            dfs(r + dr, c + dc, board, m, n, dirs);
        }
    }
};