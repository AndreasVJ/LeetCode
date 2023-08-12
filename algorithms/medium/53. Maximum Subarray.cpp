class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = nums[0];
        int sum = 0;
        for (int i : nums) {
            sum = max(sum+i, i);
            best = max(best, sum);
        }
        return best;
    }
};