class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int k = 0;
        int n = nums.size();
        for (int b = n/2; b > 0; b /= 2) {
            while (k+b < n && nums[k+b] < target) k += b;
        }
        return nums[k] < target ? k+1 : 0;
    }
};