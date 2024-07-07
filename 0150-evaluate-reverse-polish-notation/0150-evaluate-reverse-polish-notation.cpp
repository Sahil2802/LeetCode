class Solution {
public:
    int Operate(int a, int b, string token){
        if(token == "+") return a+b;
        if(token == "-") return a-b;
        if(token == "*") return (long)a*(long)b;
        if(token == "/") return a/b;

        return -1;
    }

    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        // Loop through each token from the input
        for (string &token : tokens){
            // If the token is an operator pop the top 2 elements after storing them in var a and b. 
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int b = st.top(); // Get the second operand from the stack
                st.pop();

                int a = st.top(); // Get the first operand from the stack
                st.pop(); // Push the result back onto the stack

                int result = Operate(a, b, token); // Perform the operation
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