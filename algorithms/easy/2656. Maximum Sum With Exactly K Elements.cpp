class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int m = 0;
        for (int num : nums) m = max(m, num);
        return m * k + ((k-1)*(k))/2;
    }
};