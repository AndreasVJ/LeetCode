class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        int avg;
        int n = nums.size();
        pair<int, long> ans = {0, LONG_MAX};
        vector<long> left_sum(n);
        vector<long> right_sum(n);
        
        left_sum[0] = nums[0];
        
        for (int i = 1; i < n; i++) {
            left_sum[i] = left_sum[i - 1] + nums[i];
            right_sum[n - i - 1] = right_sum[n - i] + nums[n - i];
        }
        
        for (int i = 0; i < n; i++) {
            if (n - i - 1 > 0) avg = abs(left_sum[i] / (i + 1) - right_sum[i] / (n - i - 1));
            else avg = abs(left_sum[i] / (i + 1));
            if (avg < ans.second) ans = {i, avg};
        }
        
        return ans.first;
    }
};