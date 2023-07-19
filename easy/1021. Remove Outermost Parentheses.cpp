class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int start;
        int count = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                count++;
                if (count == 1) start = i + 1;
            }
            else {
                count--;
                if (count == 0) ans += s.substr(start, i - start);
            }
        }

        return ans;
    }
};