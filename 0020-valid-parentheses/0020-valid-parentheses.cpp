class Solution {
public:
    bool isValid(string s) {
        stack <char> open;
        for (auto c : s){
            if (c == '(' or c == '{' or c == '['){
                open.push(c);
            }
            else {
                if(open.empty() or 
                (open.top() == '(' and c != ')') or
                (open.top() == '{' and c != '}') or
                (open.top() == '[' and c != ']'))
                return false;
                open.pop();
            }
        }
        return open.empty();

    }
};