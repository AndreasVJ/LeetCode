class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = 0;
        for (int i = 0; i+n < nums.size(); i++) {
            while (nums[i+n] == 0) {
                n++;
                if (i+n == nums.size()) return;
            }
            nums[i] = nums[i+n];
            if (n) nums[i+n] = 0;
        }
    }
};