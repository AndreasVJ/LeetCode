class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string out = "";
        for (int i = 0; i < strs[0].size(); i++) {
            for (int n = 1; n < strs.size(); n++) {
                if (i == strs[n].size() || strs[0][i] != strs[n][i]) {
                    return out;                    
                }
            }
            out += strs[0][i];
        }
        return out;
    }
};