class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out((1<<nums.size()));
        for (int i = 0; i < (1<<nums.size()); i++) {
            for (int n = 0; n < nums.size(); n++) {
                if (i&(1<<n)) out[i].push_back(nums[n]);
            }
        }
        return out;
    }
};