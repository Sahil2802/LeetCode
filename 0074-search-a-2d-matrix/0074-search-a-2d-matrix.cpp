class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Iterate through each row of the matrix
        for (int i = 0; i < matrix.size(); i++){
            // Iterate through each column of the current row
            for (int j = 0; j < matrix[0].size(); j++){
                // Check if the current element matches the target
                if(matrix[i][j] == target){
                    // If found return true
                    return true; 
                }
            }
        }
        // Loop exhausted, element not found
        return false;
    }
};
