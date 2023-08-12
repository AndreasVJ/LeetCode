class Logger {
public:
    unordered_map<string, int> m;

    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (m.find(message) != m.end()) {
            int t = m[message];
            if (timestamp >= t + 10) {
                m[message] = timestamp;
                return true;
            }
            return false;
        }
        m[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */