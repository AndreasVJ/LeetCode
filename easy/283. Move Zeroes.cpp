class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int a = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (a) {
                nums[i-a] = nums[i];
            }
            if (nums[i] == 0) {
                a++;
            }
            else if (a) {
                nums[i] = 0;
            }
        }
    }
};