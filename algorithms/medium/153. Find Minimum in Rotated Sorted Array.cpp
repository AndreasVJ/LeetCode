class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int k = nums.size() - 1;
        
        for (int b = nums.size()/2; b > 0; b /= 2) {
            while (k - b >= 0 && nums[k - b] < nums[k]) k -= b;
        }
        
        return nums[k];
    }
};