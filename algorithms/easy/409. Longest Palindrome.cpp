class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        int mid = 0;
        map<char, int> m;
        for (char i : s) {
            m[i]++;
        }
        for (auto [k, v] : m) {
            ans += (v/2)*2;
            if (v%2) mid = 1;
        }
        return ans + mid;
    }
};