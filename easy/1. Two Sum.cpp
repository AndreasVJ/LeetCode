class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(-nums[i]) != m.end()) return {m[-nums[i]], i};
            m[nums[i]-target] = i;
        }
        return {};
    }
};