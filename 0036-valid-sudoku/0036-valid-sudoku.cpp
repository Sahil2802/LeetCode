class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set <string> st;

        // rows
        for (int i = 0; i < 9; i++){
            // columns
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.'){
                    continue;
                }
                // Create unique identifiers for row, column, and box
                string row = "number" + string(1, board[i][j]) + "in row" + to_string(i);
                string col = "number" + string(1, board[i][j]) + "in column" + to_string(j);
                string box = "number" + string(1, board[i][j]) + "in box" + to_string(i/3) + "_" + to_string(j/3);

                // Check if any of the identifiers already exist in the set
                if(st.find(row) != st.end() || st.find(col) != st.end() || st.find(box) != st.end()){
                    // if duplicates are found, return false i.e. invalid Sudoku board
                    return false;
                }
                // else insert the identifiers into the set
                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }
        // if no duplicates are found then the sudoku board is valid
        return true;
    }
};