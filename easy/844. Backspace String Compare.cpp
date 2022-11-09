class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s_s;
        stack<char> s_t;
        for (char c : s) {
            if (c == '#') {
                if (!s_s.empty()) s_s.pop(); 
            }
            else s_s.push(c);
        }
        for (char c : t) {
            if (c == '#') {
                if (!s_t.empty()) s_t.pop();
            }
            else s_t.push(c);
        }
        if (s_s.size() != s_t.size()) return 0;
        while (!s_s.empty()) {
            if (s_s.top() != s_t.top()) return 0;
            s_s.pop();
            s_t.pop();
        }
        return 1;
    }
};