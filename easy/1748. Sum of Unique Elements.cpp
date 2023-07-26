class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> count(101);
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) count[nums[i]]++;
        for (int i = 0; i < count.size(); i++) {
            if (count[i] == 1) ans += i;
        }
        return ans;
    }
};