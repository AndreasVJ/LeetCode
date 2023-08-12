class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans = 0;
        int ruleIdx = 0;
        if (ruleKey == "color") ruleIdx = 1;
        else if (ruleKey == "name") ruleIdx = 2;
        for (vector<string> item : items) {
            if (item[ruleIdx] == ruleValue) ans++;
        }
        return ans;
    }
};