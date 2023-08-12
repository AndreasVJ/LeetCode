class MyCircularQueue {
public:
    vector<int> arr;
    int start = 0;
    int length = 0;

    MyCircularQueue(int k) {
        arr = vector<int>(k);
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        arr[(start + length) % arr.size()] = value;
        length++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        start = (start + 1) % arr.size();
        length--;
        return true;
    }
    
    int Front() {
        if (length == 0) return -1;
        return arr[start];
    }
    
    int Rear() {
        if (length == 0) return -1;
        return arr[(start + length - 1) % arr.size()];
    }
    
    bool isEmpty() {
        return length == 0;
    }
    
    bool isFull() {
        return length == arr.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */