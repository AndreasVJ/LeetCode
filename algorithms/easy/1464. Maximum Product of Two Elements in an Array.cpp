class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        vector<int> arr = {min(nums[0], nums[1]), max(nums[0], nums[1])};

        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] > arr[0]) {
                if (nums[i] > arr[1]) {
                    arr[0] = arr[1];
                    arr[1] = nums[i];
                }
                else {
                    arr[0] = nums[i];
                }
            }
        }

        return (arr[0] - 1)*(arr[1] - 1);
    }
};