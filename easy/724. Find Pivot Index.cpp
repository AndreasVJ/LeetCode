class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i-1];
        }
        
        if (nums.back()-nums[0] == 0) return 0;
        
        for (int i = 1; i < nums.size()-1; i++) {
            if (nums.back()-nums[i] == nums[i-1]) return i;
        }
        
        if (nums[nums.size()-2] == 0) return nums.size()-1;
        
        return -1;
    }
};