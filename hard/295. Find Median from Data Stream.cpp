class MedianFinder {
public:
    priority_queue<double> bottom;
    priority_queue<double, vector<double>, greater<double>> top;
    
    void addNum(int num) {
        
        bottom.push(num);
        top.push(bottom.top());
        bottom.pop();

        if (bottom.size() < top.size()) {
            bottom.push(top.top());
            top.pop();
        }

    }
    
    double findMedian() {
        if (bottom.size() > top.size()) return bottom.top();
        return (bottom.top() + top.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */