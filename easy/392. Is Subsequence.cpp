class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = 0;
        for (char c : t) {
            if (c == s[n]) n++;
        }
        return n == s.size();
    }
};