class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return buildFinalString(s) == buildFinalString(t);        
    }

    stack<char> buildFinalString(string str){
        stack<char> st;
        for(char ch : str){
            if(ch == '#'){
                 if(!st.empty()) st.pop();  // guard: only pop if something exists
            }
            else{
                st.push(ch);
            }
        }
        return st;
    }
};