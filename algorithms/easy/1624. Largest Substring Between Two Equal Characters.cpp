class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);

        for (int i = 0; i < s.size(); i++) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            else {
                last[s[i] - 'a'] = i;
            }
        }

        int ans = -1;
        
        for (int i = 0; i < 26; i++) {
            if (last[i] != -1) {
                ans = max(ans, last[i] - first[i] - 1);
            } 
        }

        return ans;
    }
};