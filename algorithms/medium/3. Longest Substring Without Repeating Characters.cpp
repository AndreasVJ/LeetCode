class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int a = 0;
        int best = 0;
        for (int b = 0; b < s.size(); b++) {
            m[s[b]]++;
            while (m[s[b]] > 1) {
                m[s[a]]--;
                a++;
            }
            best = max(best, b-a+1);
        }
        return best;
    }
};