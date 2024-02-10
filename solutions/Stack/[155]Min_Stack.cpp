class MinStack {
public:
    stack<int> elements, mins;
    MinStack() {}
    
    void push(int val) 
    {
        if (elements.empty() || val <= mins.top())
        {
            mins.push(val);
        }
        elements.push(val);
    }
    
    void pop() 
    {
        if (elements.top() == mins.top())
        {
            mins.pop();
        }
        elements.pop();
    }
    
    int top() 
    {
        return (elements.top());
    }
    
    int getMin() 
    {
        return (mins.top());
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
