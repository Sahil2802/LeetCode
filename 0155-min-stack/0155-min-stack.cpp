class MinStack {
public:
    stack<int> s1, s2; // s1: to store all the elements, s2: to store min elements
    MinStack() {}
    
    void push(int val) {
        // If s1 is empty or 
        // the new value is less than or equal to the current minimum i.e s2.top(), 
        // push it onto s2.
        if(s1.empty() || val <= s2.top()){
            s2.push(val);
        }
        // push the curr val in s1
        s1.push(val);
    }
    
    void pop() {
        // if s1 is empty just return
        if(s1.empty()) return;
        // before removing the s1 top check if s1 top is equal to s2 top, pop from s2 as well
        if(s1.top() == s2.top()){
            s2.pop();
        }
        // pop the value from s1
        s1.pop();
    }
    
    int top() {
        // if the stack is empty return -1
        if(s1.empty()) return -1;
        // otherwise just return the top value of s1
        return s1.top();
    }
    
    int getMin() {
        // if the stack is empty return -1
        if(s1.empty()) return -1;
        // otherwise just return the top value of s2, which is the minimum
        return s2.top();
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