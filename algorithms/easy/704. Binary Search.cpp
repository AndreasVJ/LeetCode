class Solution {
public:
    int search(vector<int>& nums, int target) {
        int k = 0;
        int n = nums.size();
        for (int b = n/2; b >= 1; b /= 2) {
            while (k+b < n && nums[k+b] <= target) k += b;
        }
        if (nums[k] == target) return k;
        return -1;
    }
};