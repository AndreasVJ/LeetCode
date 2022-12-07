class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        if (nums.size() == 0) return {-1, -1};
        
        int k1 = nums.size() - 1;
        int k2 = 0;

        for (int b = nums.size()/2; b > 0; b /= 2) {
            while (k1 - b >= 0 && nums[k1 - b] >= target) k1 -= b;
            while (k2 < nums.size() - b && nums[k2 + b] <= target) k2 += b;
        }

        if (nums[k1] != target) return {-1, -1};
        return {k1, k2};
    }
};