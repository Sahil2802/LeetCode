class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        // Initialize row index to 0 (first row)
        int i = 0;
        // Initialize col index to last column 
        int j = matrix[0].size() - 1;

        // Loop until the indices are within the bounds of the matrix
        while(i < n && j >= 0){
            // If the current element is the target, return true
            if (matrix[i][j] == target) return true;
            // If the current element is greater than the target, move left in the current row
            if (matrix[i][j] > target) j--;
             // If the current element is less than the target, move down to the next row
            else ++i; 
        }
        // Loop exhausted, element does not exist
        return false;        
    }

};