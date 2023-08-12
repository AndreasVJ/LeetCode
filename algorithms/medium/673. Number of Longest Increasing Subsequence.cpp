class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<unordered_map<int, pair<int, int>>> cache(nums.size());
        return dp(nums, 0, INT_MIN, cache).second;
    }

    pair<int, int> dp(vector<int>& nums, int i, int prev, vector<unordered_map<int, pair<int, int>>>& cache) {
        if (i == nums.size()) return {0, 1};
        if (cache[i].find(prev) != cache[i].end()) return cache[i][prev];
        if (nums[i] <= prev) return cache[i][prev] = dp(nums, i+1, prev, cache);
        pair<int, int> include = dp(nums, i+1, nums[i], cache);
        include.first++;
        pair<int, int> exclude = dp(nums, i+1, prev, cache);
        if (include.first == exclude.first) return cache[i][prev] = {include.first, include.second + exclude.second};
        if (include.first > exclude.first) return cache[i][prev] = include;
        return cache[i][prev] = exclude;
    }
};