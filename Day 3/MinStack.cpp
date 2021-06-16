class MinStack {
    
    stack<int> s;
    stack<int> min;
public:
    void push(int val) {
        if(s.empty()){
            s.push(val);
            min.push(val);
        }
        else{
            if(val <= min.top()){
                min.push(val);
                s.push(val);
            }
            else{
                s.push(val);
            }
        }
    }
    
    void pop() {
        
        if(min.top()==s.top()){
            s.pop();
            min.pop();
        }
        else{
            s.pop();
        }
        
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
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
