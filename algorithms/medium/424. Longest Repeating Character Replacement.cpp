class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char, int> m;
        int ans = 0;
        int best = 0;
        
        for (int a = 0, i = 0; i < s.size(); i++) {
            best = max(best, ++m[s[i]]);
            while (i - a - best + 1> k) {
                m[s[a]]--;
                a++;
            }
            ans = max(ans, i - a + 1);
        }
        
        return ans;
    }
};