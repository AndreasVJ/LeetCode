class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        nums[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i-1] > nums[i] + nums[i-2]) nums[i] = nums[i-1];
            else nums[i] += nums[i-2];
        }
        return max(nums.back(), nums[nums.size()-2]);
    }
};