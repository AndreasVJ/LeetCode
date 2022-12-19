class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        unordered_map<int, int> points;
        int maxNum = 0;

        for (int i = 0; i < nums.size(); i++) {
            points[nums[i]] += nums[i];
            maxNum = max(maxNum, nums[i]);
        }

        vector<int> maxPoints(maxNum + 1);
        maxPoints[1] = points[1];

        for (int i = 2; i <= maxNum; i++) {
            maxPoints[i] = max(maxPoints[i - 1], maxPoints[i - 2] + points[i]);
        }

        return maxPoints.back();
    }
};