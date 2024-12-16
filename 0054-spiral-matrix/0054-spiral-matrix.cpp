class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Number of rows
        int m = matrix[0].size(); // Number of columns

        vector<int> ans; // Result vector to store the spiral order
        int rowBegin = 0, colBegin = 0; // Initialize the starting indices for rows and columns
        int rowEnd = n - 1, colEnd = m - 1; // Initialize the ending indices for rows and columns

        // Continue the traversal as long as there are rows and columns left to process
        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            // Traverse right across the top row
            for (int i = colBegin; i <= colEnd; i++) {
                ans.push_back(matrix[rowBegin][i]);
            }
            rowBegin++; // Move the starting row index down

            // Traverse down the rightmost column
            for (int i = rowBegin; i <= rowEnd; i++) {
                ans.push_back(matrix[i][colEnd]);
            }
            colEnd--; // Move the ending column index left

            // If rowBegin is now greater than rowEnd, it means there are no more rows left to process, and we should not attempt to traverse left.
            if (rowBegin <= rowEnd) {
                // Traverse left across the bottom row
                for (int i = colEnd; i >= colBegin; i--) {
                    ans.push_back(matrix[rowEnd][i]);
                }
            }
            rowEnd--; // Move the ending row index up

            // If colBegin is now greater than colEnd, it means there are no more columns left to process, and we should not attempt to traverse up.
            if (colBegin <= colEnd) {
                // Traverse up the leftmost column
                for (int i = rowEnd; i >= rowBegin; i--) {
                    ans.push_back(matrix[i][colBegin]);
                }
            }
            colBegin++; // Move the starting column index right
        }
        return ans; 
    }
};
