class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> ans;
        
        unordered_map<char, int> last_index;
        
        for (int i = 0; i < s.size(); i++) last_index[s[i]] = i;
        
        for (int a = -1, i = 0, m = 0; i < s.size(); i++) {
            m = max(m, last_index[s[i]]);
            if (i == m) {
                ans.push_back(i - a);
                a = i;
            }
        }
        
        return ans;
    }
};