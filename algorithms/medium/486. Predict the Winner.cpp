class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> cache(nums.size(), vector<int>(nums.size(), INT_MIN));
        return maxDiff(nums, 0, nums.size()-1, cache) >= 0;
    }

    int maxDiff(vector<int>& nums, int a, int b, vector<vector<int>>& cache) {
        if (cache[a][b] != INT_MIN) return cache[a][b];
        if (a == b) return nums[a];
        return max(nums[a] - maxDiff(nums, a+1, b, cache), nums[b] - maxDiff(nums, a, b-1, cache));
    }
};