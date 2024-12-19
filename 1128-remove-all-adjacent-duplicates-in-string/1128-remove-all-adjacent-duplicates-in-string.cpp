class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size(); 
        stack<char> st; // Initialize an empty stack to store characters
        string result = ""; // Initialize an empty string to store the result

        // Iterate over each character in the string
        for (int i = 0; i < n; i++) {
            // Check if the stack is not empty and the current character is equal to the top character of the stack
            if (!st.empty() && s[i] == st.top()) {
                st.pop(); // Remove the top character from the stack
            } else {
                st.push(s[i]); // Push the current character onto the stack
            }
        }

        // Build the result string from the characters in the stack
        while (!st.empty()) {
            result.push_back(st.top()); // Add the top character of the stack to the result string
            st.pop(); // Remove the top character from the stack
        }

        // Reverse the result string to get the correct order
        reverse(result.begin(), result.end());

        return result; 
    }
};