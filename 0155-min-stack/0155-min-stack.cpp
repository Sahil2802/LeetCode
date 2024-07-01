class MinStack {
public:
    stack<pair<int, int>> st; //Stack to store pairs of (value, current minimum)
    MinStack() {}
    
    void push(int val) {
        if(st.empty()){
            // if the stack is empty then the curr minimum is the value itself
            int mini = val;
            st.push({val, val});
        }
        else{
            // if the stack is not empty then the curr min is the minimum of new value and curr min
            int mini = min(st.top().second, val);
            st.push({val, mini});
        }
    }
    
    void pop() {
        if(st.empty()) return;
        st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top().first; // return the value of the pair
    }
    
    int getMin() {
        return st.top().second; // return the minimum part of the pair
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */