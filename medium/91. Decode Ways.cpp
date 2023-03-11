class Solution {
public:
    int dp(int i, string& s, vector<int>& cache) {

        if (i > s.size()) return 0;
        if (i == s.size()) return 1;
        if (cache[i] != 0) return cache[i];

        if (s[i] == '0') return 0;
        if (s[i] > '2' || (s[i] == '2' && s[i + 1] > '6')) return cache[i] = dp(i + 1, s, cache);
        return cache[i] = dp(i + 1, s, cache) + dp(i + 2, s, cache);
    }

    int numDecodings(string s) {
        vector<int> cache(s.size());
        return dp(0, s, cache);
    }
};