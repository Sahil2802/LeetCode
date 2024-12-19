class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0; // Index to place the compressed characters
        int i = 0; // Pointer to traverse the array

        // Iterate over the array
        while (i < n) {
            char curr = chars[i]; // Current character
            int count = 0; // Count of consecutive duplicates

            // Count the number of consecutive duplicates
            while (i < n && curr == chars[i]) {
                i++;
                count++;
            }

            // Place the current character in the compressed array
            chars[index] = curr;
            index++;

            // If count is greater than 1, add the count to the compressed array
            if (count > 1) {
                string char_count = to_string(count); // Convert count to string
                for (char ch : char_count) {
                    chars[index] = ch;
                    index++;
                }
            }
        }

        return index;
    }
};
