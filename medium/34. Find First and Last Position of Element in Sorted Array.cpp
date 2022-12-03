class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if (nums.size() == 0) return {-1, -1};
        else if (nums.size() == 1) {
            if (nums[0] == target) return {0, 0};
            else return {-1, -1};
        }
        
        int k1 = 0;
        
        for (int b = nums.size()/2; b > 0; b /= 2) {
            while (k1 < nums.size() - b && nums[k1 + b] < target) k1 += b;
        }
        
        if (k1 == 0) {
            if (nums[k1] != target) k1++;
            if (nums[k1] != target) return {-1, -1};
        }
        else if (k1 == nums.size() - 1) {
            if (nums[k1] == target) return {k1, k1};
            else return {-1, -1};
        }
        else if (nums[k1 + 1] != target) return {-1, -1};
        else k1++;
        
        int k2 = k1;
        
        for (int b = (nums.size() - k1)/2; b > 0; b /= 2) {
            while (k2 < nums.size() - b && nums[k2 + b] <= target) k2 += b;
        }
        
        return {k1, k2};
    }
};