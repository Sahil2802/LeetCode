class Solution {
public:
    // Main function to perform flood fill
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){       
        int originalColor = image[sr][sc]; // Store the original color of the starting pixel
        // If the starting pixel already has the target color, no need to proceed
        if(originalColor == color) return image;

        // Start DFS to fill all connected pixels with the new color
        dfs(image, sr, sc, color, originalColor);
        return image;
    }

private:
    // Helper DFS function to fill connected pixels
    void dfs(vector<vector<int>> &image, int r, int c, int color, int originalColor){
        int n = image[0].size(); // Number of columns
        int m = image.size();    // Number of rows

        // Check for out-of-bounds or if the pixel is not of the original color
        if(r < 0 || r >= m || c < 0 || c >= n || image[r][c] != originalColor){
            return;
        }

        image[r][c] = color; // Recolor the current pixel
        
        // Recursively fill in all four directions
        dfs(image, r-1, c, color, originalColor); // Up
        dfs(image, r+1, c, color, originalColor); // Down
        dfs(image, r, c+1, color, originalColor); // Right
        dfs(image, r, c-1, color, originalColor); // Left
    }
};