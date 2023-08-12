class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (n && nums[i] != val) {
                nums[i-n] = nums[i];
            }
            else if (nums[i] == val) n++;
        }
        nums.resize(nums.size()-n);
        return nums.size();
    }
};