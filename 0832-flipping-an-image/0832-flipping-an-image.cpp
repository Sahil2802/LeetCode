class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();

        // Process each row independently
        for (auto& row : image) {
            int i = 0, j = n - 1;   // two pointers from both ends of the row

            while (i <= j) {
                if (i == j) {
                    // Odd-length row: middle element has no pair to swap with,
                    // reversing leaves it in place, so just invert it.
                    row[i] = row[i] ^ 1;
                } else {
                    // Combine "reverse" (swap row[i] and row[j])
                    // with "invert" (flip each bit using ^ 1) in one step.

                    int temp = row[i] ^ 1;   // save inverted original row[i] before it gets overwritten
                    row[i] = row[j] ^ 1;     
                    row[j] = temp;          
                }
                i++;   
                j--;   
            }
        }

        return image;
    }
};