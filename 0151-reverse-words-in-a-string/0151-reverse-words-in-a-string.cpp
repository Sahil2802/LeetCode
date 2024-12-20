class Solution {
public:
    string reverseWords(string s) {
        if (s.size() == 0) return s; // Return the string if it is empty

        stack<string> st; // Stack to store words
        string result; // String to store the final result

        // Iterate through each character in the input string
        for (int i = 0; i < s.size(); i++) {
            string word; // Initialize an empty string to store the current word

            if (s[i] == ' ') continue; // Skip spaces

            // Collect the current word
            while (i < s.size() && s[i] != ' ') {
                word += s[i]; // Append characters to the word until a space is encountered
                i++;
            }

            st.push(word); // Push the collected word onto the stack
        }

        // Pop words from the stack and construct the result string
        while (!st.empty()) {
            result += st.top(); // Append the top word from the stack to the result
            st.pop(); // Remove the top word from the stack

            if (!st.empty()) result += " "; // Add a space if there are more words to process
        }

        return result; // Return the final result string
    }
};
