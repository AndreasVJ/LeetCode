class Solution {
public:
    int specialArray(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        if (nums[0] >= nums.size()) return nums.size();

        int k = nums.size() - 1;

        for (int b = nums.size()/2; b > 0; b /= 2) {
            while (k - b >= 1 && nums[k - b] >= nums.size() - k + b) {
                k -= b;
                if (nums[k - 1] < nums.size() - k) return nums.size() - k;
            }
        }

        return -1;
    }
};