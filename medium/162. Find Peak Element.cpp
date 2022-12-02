class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int k = 0;
        
        for (int b = nums.size()/2; b > 0; b /= 2) {
            while (k < nums.size() - b && nums[k + b] > nums[k + b - 1]) k += b;
        }
        
        return k;
    }
};