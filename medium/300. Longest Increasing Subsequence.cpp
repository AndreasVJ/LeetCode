class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> length(n);
        int best = 0;
        for (int i = 0; i < n; i++) {
            length[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    length[i] = max(length[i], length[j]+1);
                }
            }
            best = max(best, length[i]);
        }
        return best;
    }
};