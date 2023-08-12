class Solution {
public:
    int dp(int i, int num, vector<int>& nums, int target, vector<vector<int>>& cache) {
        
        if (i == nums.size()) return num == target ? 1 : 0;
        
        int cacheNum = num + 1000;
        if (cache[i][cacheNum] != -1) return cache[i][cacheNum];

        return cache[i][cacheNum] = dp(i + 1, num + nums[i], nums, target, cache) + dp(i + 1, num - nums[i], nums, target, cache);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> cache(nums.size(), vector<int>(2001, -1));
        return dp(0, 0, nums, target, cache);
    }
};