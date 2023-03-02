class Solution {
public:
    bool dp(int i, string s, vector<string>& wordDict, vector<int>& cache) {

        if (i == s.length()) return 1;
        if (cache[i] != -1) return cache[i];

        for (string word : wordDict) {
            if (i + word.length() <= s.length()) {
                if (word == s.substr(i, word.length())) {
                    if (dp(i + word.length(), s, wordDict, cache)) return cache[i] = 1;
                }
            }
        }

        return cache[i] = 0;
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> cache(s.size(), -1);
        return dp(0, s, wordDict, cache);
    }
};