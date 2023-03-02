class MovingAverage {
public:
    queue<int> q;
    int maxSize;
    double sum = 0;

    MovingAverage(int size) {
        maxSize = size;
    }
    
    double next(int val) {
        if (q.size() == maxSize) {
            sum -= q.front();
            q.pop();
        }
        q.push(val);
        sum += val;
        return sum/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */