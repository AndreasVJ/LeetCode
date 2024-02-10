class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            ans += helper(s, i, i) + helper(s, i, i+1);
        }
        ans += helper(s, s.size() - 1, s.size() - 1);
        return ans;
    }

    int helper(string &s, int a, int b) {
        if (a < 0 || b >= s.size()) return 0;
        if (s[a] == s[b]) {
            return 1 + helper(s, a - 1, b + 1);
        }
        return 0;
    }
};