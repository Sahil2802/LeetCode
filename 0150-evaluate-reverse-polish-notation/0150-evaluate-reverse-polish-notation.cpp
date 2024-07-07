class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;

        unordered_map<string, function<int (int, int)>> mp = {
            {"+", [](int a, int b) {return a+b;}},
            {"-", [](int a, int b) {return a-b;}},
            {"*", [](int a, int b) {return (long)a*(long)b;}},
            {"/", [](int a, int b) {return a/b;}},
        }; 

        // Loop through each token from the input
        for (string &token : tokens){
            // If the token is an operator pop the top 2 elements after storing them in var a and b. 
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int b = st.top(); // Get the second operand from the stack
                st.pop();

                int a = st.top(); // Get the first operand from the stack
                st.pop(); // Push the result back onto the stack

                int result = mp[token](a,b); // Perform the operation
                st.push(result);
            }
            else{
                // If the token is a number, convert it to an integer and push onto the stack
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};