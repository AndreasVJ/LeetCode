class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int offset = 0;
        for (char c : s) {
            if (c == 'L') offset++;
            else offset--;
            if (offset == 0) ans++;
        }
        return ans;
    }
};