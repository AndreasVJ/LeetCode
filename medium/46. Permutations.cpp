class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> permutation;
        for (int i = 0; i < nums.size(); i++) {
            permutation.push_back(nums[i]);
        }
        do {
            ans.push_back(permutation);
        } while (next_permutation(permutation.begin(),permutation.end()));
        return ans;
    }
};