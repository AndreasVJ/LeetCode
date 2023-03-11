class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int bestSum = INT_MIN;
        int bestCircSum = INT_MIN;
        vector<int> bestLeftSum(nums.size(), INT_MIN);
        vector<int> bestRightSum(nums.size(), INT_MIN);
        
        int currSum = 0;
        for (int num : nums) {
            currSum = max(currSum + num, num);
            bestSum = max(bestSum, currSum);
        }

        currSum = nums[0];
        bestLeftSum[0] = currSum;
        for (int i = 1; i < nums.size(); i++) {
            currSum += nums[i];
            bestLeftSum[i] = max(bestLeftSum[i - 1], currSum);
        }

        currSum = nums.back();
        bestRightSum.back() = currSum;
        for (int i = nums.size() - 2; i >= 0; i--) {
            currSum += nums[i];
            bestRightSum[i] = max(bestRightSum[i + 1], currSum);
        }

        for (int i = 1; i < nums.size(); i++) {
            bestCircSum = max(bestCircSum, bestLeftSum[i - 1] + bestRightSum[i]);
        }

        return max(bestSum, bestCircSum);
    }
};