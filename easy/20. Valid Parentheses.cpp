class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        for (char i : s) {
            if (i == '(' || i == '{' || i == '[') {
                a.push(i);
            }
            else if (a.empty()) {
                return 0;
            }
            else {
                if (i == ')') {
                    if (a.top() != '(') {
                        return 0;
                    }
                }
                else if (i == '}') {
                    if (a.top() != '{') {
                        return 0;
                    }
                }
                else if (i == ']') {
                    if (a.top() != '[') {
                        return 0;
                    }
                }
                a.pop();
            }
        }
        if (a.empty()) {
            return 1;
        }
        return 0;
    }
};