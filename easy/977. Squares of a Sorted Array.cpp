class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int a = 0;
        int b = n-1;
        while (a <= b) {
            if (abs(nums[a]) > nums[b]) {
                ans[b-a] = pow(nums[a], 2);
                a++;
            }
            else {
                ans[b-a] = pow(nums[b], 2);
                b--;
            }
        }
        return ans;
    }
};