class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // number of rows in the matrix
        int m = matrix.size();
        // number of columns in the matrix
        int n = matrix[0].size();

        // initialize the left and right boundaries for binary search
        int l = 0;
        int r = m * n - 1;

        while (l <= r) {
            // Calculate the mid index
            int mid = l + (r - l) / 2;

            // Convert the 1D index to 2D indices
            int row = mid / n;
            int col = mid % n;

            // Check if the middle element is the target
            if (matrix[row][col] == target) {
                return true; 
            }
            // If the middle element is greater than the target, search in the left half
            else if (matrix[row][col] > target) {
                r = mid - 1;
            }
            // If the middle element is less than the target, search in the right half
            else {
                l = mid + 1;
            }
        }
        // loop exhausted, target not found
        return false;
    }
};
