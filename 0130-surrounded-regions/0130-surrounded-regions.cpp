class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O'){
                q.push({0, i});
                board[0][i] = 'T';
            } 
            if(board[m-1][i] == 'O'){
                q.push({m-1, i});
                board[m-1][i] = 'T';
            }
        }
        for(int j = 0; j < m; j++){
            if(board[j][0] == 'O'){
                q.push({j, 0});
                board[j][0] = 'T';
            } 
            if(board[j][n - 1] == 'O'){
                q.push({j, n-1});
                board[j][n-1] = 'T';
            }
        }

        vector<pair<int, int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(auto [dr,dc] : directions){
                int nr = r + dr;
                int nc = c + dc;

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'O'){
                    q.push({nr, nc});
                    board[nr][nc] = 'T';
                }
            }
        }

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(board[r][c] == 'O') board[r][c] = 'X';
                if(board[r][c] == 'T') board[r][c] = 'O';
            }
        }
    }
};