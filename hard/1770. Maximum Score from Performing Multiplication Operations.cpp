class Solution {
public:
    int top_down(unordered_map<int, int>& memo, vector<int>& nums, vector<int>& multipliers, int left, int i) {

        int key = nums.size() * left + i;
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        if (i == multipliers.size()) {
            return 0;
        }

        int l = multipliers[i] * nums[left] + top_down(memo, nums, multipliers, left + 1, i + 1);
        int r = multipliers[i] * nums[nums.size() - 1 - i + left] + top_down(memo, nums, multipliers, left, i + 1);

        return memo[key] = max(l, r);
    }
    
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        unordered_map<int, int> memo;

        return top_down(memo, nums, multipliers, 0, 0);
    }
};