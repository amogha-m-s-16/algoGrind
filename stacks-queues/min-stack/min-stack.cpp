class MinStack {
private:
    stack<long long> st;
    long long mini = INT_MAX;

public:
    MinStack() {}
    
    void push(int value) {
        if(st.empty()) {
            mini = value;
            st.push(value);
        }

        else {        
            if(value > mini) st.push(value);
            else {
                st.push(value - mini + value);
                mini = value;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;

        long long x = st.top();
        st.pop();

        if(x < mini) mini = 2 * mini - x;
    }
    
    int top() {
        if(st.empty()) return NULL;

        long long x = st.top();

        if(mini < x) return x;
        return mini;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */