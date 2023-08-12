class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int ans = 0;
        int ones = 0;
        int zeros = 0;
        
        for (int a = 0, b = 0; b < nums.size(); b++) {
            if (nums[b]) ones++;
            else zeros++;
            while (zeros > 1) {
                if (nums[a]) ones--;
                else zeros--;
                a++;
            }
            ans = max(ans, ones + zeros);
        }

        return ans;
    }
};