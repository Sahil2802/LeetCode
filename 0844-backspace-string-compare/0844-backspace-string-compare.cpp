class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // Compare the final "typed" result of both strings
        return buildFinalString(s) == buildFinalString(t);        
    }

    stack<char> buildFinalString(string str) {
        stack<char> st;
        for (char ch : str) {
            if (ch == '#') {
                // '#' means backspace: remove last typed char, if any
                if (!st.empty()) {
                    st.pop();
                }
                // if stack is empty, backspacing does nothing
            } else {
                // regular character: type it
                st.push(ch);
            }
        }
        return st;
    }
};