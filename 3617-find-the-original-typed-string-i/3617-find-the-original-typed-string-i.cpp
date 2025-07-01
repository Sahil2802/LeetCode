class Solution {
public:
    // Function to count the number of possible strings based on consecutive equal characters
    int possibleStringCount(string word) {
        int n = word.length();
        int count = 0;
        // Iterate through the string starting from the second character
        for(int i = 1; i < n; i++){
            // If the current character is the same as the previous one, increment count
            if(word[i-1] == word[i]) count++;
        }
        // Add 1 to count to include the initial possible string
        return count + 1;
    }
};