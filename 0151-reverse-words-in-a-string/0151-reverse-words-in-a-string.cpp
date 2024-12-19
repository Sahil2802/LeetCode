class Solution {
public:
    string reverseWords(string s) {
        string result; // Initialize an empty string to store the result
        
        // Iterate through each character in the input string
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ')
                continue; // Skip spaces

            string word; // Initialize an empty string to store the current word

            // Collect the current word
            while (i < s.size() && s[i] != ' ')
                word += s[i++]; // Append characters to the word until a space is encountered
            
            if (result.empty()) // If this is the first word
                result = word; // Set the result to the current word
            else // If this is not the first word
                result = word + ' ' + result; // Prepend the current word to the result with a space
        }
        
        return result; // Return the final result string
    }
};
