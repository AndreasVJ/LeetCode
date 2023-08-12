class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int ans = INT_MAX;
        int a = 0;
        int count = 0;

        for (int b = 0; b < nums.size(); b++) {
            count += nums[b];
            while (count - nums[a] >= target) {
                count -= nums[a];
                a++;
            }
            if (count >= target) ans = min(ans, b - a + 1);
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};