class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        bool duplicate = false;
        int removed = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i -1]) {
                if (duplicate) {
                    removed++;
                }
                else {
                    duplicate = true;
                    nums[i - removed] = nums[i];
                }
            }
            else {
                duplicate = false;
                nums[i - removed] = nums[i];
            }
        }

        return nums.size() - removed;
    }
};