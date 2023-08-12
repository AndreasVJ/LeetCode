class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {

        int ans = 0;
        vector<vector<int>> dp(nums.size(), vector(1001, 1));

        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int a = nums[j] - nums[i];
                dp[j][a + 500] = dp[i][a + 500] + 1;
                ans = max(ans, dp[j][a + 500]);
            }
        }

        return ans;
    }
};