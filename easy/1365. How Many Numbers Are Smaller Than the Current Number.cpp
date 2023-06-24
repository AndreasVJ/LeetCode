class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        vector<int> ans(nums.size(), 0);
        vector<vector<int>> s(nums.size(), vector<int>(2));

        for (int i = 0; i < nums.size(); i++) {
            s[i][0] = nums[i];
            s[i][1] = i;
        }

        sort(s.begin(), s.end());

        for (int i = 1; i < s.size(); i++) {
            if (s[i][0] == s[i - 1][0]) ans[s[i][1]] = ans[s[i - 1][1]];
            else ans[s[i][1]] = i;
        }
        
        return ans;
    }
};