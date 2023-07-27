class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;

        int start = nums.size()-1;
        int end = 0;

        for (int b = nums.size()/2; b > 0; b /= 2) {
            while (start - b >= 0 && nums[start-b] >= target) start -= b; 
        }
        if (nums[start] != target) return ans;

        for (int b = nums.size()/2; b > 0; b /= 2) {
            while (end + b < nums.size() && nums[end + b] <= target) end += b;
        }

        for (int i = start; i <= end; i++) ans.push_back(i);
        return ans;
    }
};