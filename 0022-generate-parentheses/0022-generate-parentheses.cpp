class Solution {
public:
    vector<string> result;
    
    void solve(string& curr, int n, int open, int close) {
        if (curr.length() == 2 * n) {
            result.push_back(curr);
            return;
        }

        // we dont have to add more than n open paranthesis
        if (open < n){
            curr.push_back('(');
            solve(curr, n, open + 1, close);
            curr.pop_back(); // Backtrack to explore other possibilities
        }

        // for valid parantheses, open paranthesis should always be more than closing paranthesis
        if (close < open){
            curr.push_back(')');
            solve(curr, n, open, close + 1);
            curr.pop_back(); // Backtrack to explore other possibilities
        }
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";

        int open = 0; // count of open paranthesis
        int close = 0; // count of close paranthesis
        solve(curr, n, open, close);

        return result;
    }
};