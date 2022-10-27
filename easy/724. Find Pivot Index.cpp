class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int i : nums) sum += i;
        if (sum-nums[0] == 0) return 0;
        for (int i = 1; i < nums.size(); i++) {
            if (sum-2*nums[i-1] == nums[i]) return i;
            nums[i] += nums[i-1];
        }
        return -1;
    }
};