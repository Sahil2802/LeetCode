class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRow = false, firstCol = false; // Flags to indicate if the first row and first column should be zeroed
        int n = matrix.size(); // Number of rows
        int m = matrix[0].size(); // Number of columns

        // First pass: Mark the 0th row and column to be zeroed
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) firstRow = true; // Mark that the first row should be zeroed
                    if (j == 0) firstCol = true; // Mark that the first column should be zeroed
                    matrix[0][j] = 0; // Mark the column in the first row
                    matrix[i][0] = 0; // Mark the row in the first column
                }
            }
        }

        // Second pass: Set the marked rows and columns to zero
        for (int i = 1; i < n; i++) { // Start from the second row
            for (int j = 1; j < m; j++) { // Start from the second column
                // Set the element to zero if its row or column is marked
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0; 
                }
            }
        }

        // Set the first row to zero if needed
        if (firstRow) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Set the first column to zero if needed
        if (firstCol) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};