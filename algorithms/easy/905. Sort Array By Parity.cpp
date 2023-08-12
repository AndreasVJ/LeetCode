class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int n = 0;
        int temp;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]%2) {
                n++;
            }
            else {
                temp = nums[i];
                nums[i] = nums[i - n];
                nums[i - n] = temp;
            }
        }
        
        return nums;
    }
};