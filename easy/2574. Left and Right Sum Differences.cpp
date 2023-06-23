class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        
        vector<int> ans(nums.size(), 0);
        int left = 0;
        int right = 0;

        for (int i = 1; i < nums.size(); i++) {
            left += nums[i - 1];
            right += nums[nums.size() - i];
            ans[i] += left;
            ans[nums.size() - 1 - i] -= right;
        }

        for (int i = 0; i < nums.size(); i++) {
            ans[i] = abs(ans[i]);
        }

        return ans;
    }
};