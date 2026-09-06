class MyStack {
private:
    queue<int> qt;
public:
    MyStack() {}
    
    void push(int x) {
        int n = qt.size();

        qt.push(x);
        for(int i = 0; i < n; i++) {
            qt.push(qt.front());
            qt.pop();
        }
    }
    
    int pop() {
        int ele = qt.front();
        qt.pop();

        return ele;
    }
    
    int top() {
        return qt.front();
    }
    
    bool empty() {
        return qt.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */