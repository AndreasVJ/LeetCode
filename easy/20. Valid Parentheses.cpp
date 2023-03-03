class Solution {
public:
    bool isValid(string s) {

        unordered_map<char, char> m;
        m[')'] = '(';
        m['}'] = '{';
        m[']'] = '[';
        
        stack<char> a;

        for (char c : s) {
            if (m.find(c) == m.end()) {
                a.push(c);
            }
            else {
                if (a.empty() || m[c] != a.top()) return false;
                a.pop();
            }
        }

        if (a.empty()) return true;
        return false;
    }
};