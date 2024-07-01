class MinStack {
public:
    stack<long> st;
    long mini; // store the current minimum value
    MinStack() {}
    
    void push(int val) {
        if(st.empty()){
            st.push(val); // If the stack is empty, push the value directly
            mini = val; // set the min value to the curr value
        }
        else if(val <= mini){
            st.push(2ll * val - mini); // Store a modified value to keep track of the previous minimum
            mini = val; // Update the current minimum value
        }
        else{
            st.push(val); // Otherwise, push the value directly
        }
    }
    
    void pop() {
        if(st.empty()) return;
        if(st.top() < mini){
            mini = 2ll * mini - st.top(); // Restore the previous minimum value if a modified value is popped
        }
        st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        if(st.top() < mini){ // If the top value is a modified value, return the current minimum
            return mini;
        }
        return st.top(); // Otherwise, return the top value as it is
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return mini; // Return the current minimum value
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