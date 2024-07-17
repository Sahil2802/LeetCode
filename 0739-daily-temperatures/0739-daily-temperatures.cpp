class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        stack <int> st;
        int n = temps.size();
        vector <int> ans(n);

        for(int i = n-1; i >= 0; i--){
            // pop till current temp is more than top element of the stack
            while(!st.empty() && temps[i] >= temps[st.top()]){
                st.pop();
            }
            // if stack is empty push 0. i.e. there's no next warmer temperature
            if (st.empty()) ans[i] = 0;
            //calculate the number of days
            else ans[i] = st.top() - i; 
            st.push(i);
        }
        return ans;
    }
};