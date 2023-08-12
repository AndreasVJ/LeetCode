class MinStack {
public:

    vector<int> m;
    vector<int> s;

    MinStack() {
        m = {};
        s = {};
    }
    
    void push(int val) {
        s.push_back(val);
        if (m.size() == 0) m.push_back(val);
        else m.push_back(min(m.back(), val));
    }
    
    void pop() {
        s.resize(s.size() - 1);
        m.resize(m.size() - 1);
    }
    
    int top() {
        return s.back();
    }
    
    int getMin() {
        return m.back();
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