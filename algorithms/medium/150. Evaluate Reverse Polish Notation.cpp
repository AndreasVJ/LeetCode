class Solution {
public:
    bool isStringNumber(string str){
        if (str[0] == '-' && str.length() > 1) return isStringNumber(str.substr(1, str.length() - 1));
        for (char c : str) if (c < '0' || '9' < c) return false;
        return true;
    }

    int evalRPN(vector<string>& tokens) {
        
        stack<int> s;

        for (string token : tokens) {
            if (isStringNumber(token)) s.push(stoi(token));
            else {
                int a = s.top();
                s.pop();
                if (token == "+") a += s.top();
                else if (token == "-") a = s.top() - a;
                else if (token == "*") a *= s.top();
                else a = s.top() / a;
                s.pop();
                s.push(a);
            }
        }

        return s.top();
    }
};