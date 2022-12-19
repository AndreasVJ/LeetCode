class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int rot = nums.size() - 1;
        
        for (int b = nums.size() / 2; b > 0; b /= 2) {
            while (rot - b >= 0 && nums[rot] == nums[rot - b]) rot--;
            while (rot - b >= 0 && nums[rot] > nums[rot - b]) rot -= b;
        }

        return nums[rot];

    }
};