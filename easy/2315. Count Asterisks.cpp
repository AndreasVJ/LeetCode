class Solution {
public:
    int countAsterisks(string s) {
        int ans = 0;
        bool isBetween = false;
        for (char c : s) {
            if (c == '|') isBetween = !isBetween;
            else if (!isBetween && c == '*') ans++;
        }
        return ans;
    }
};