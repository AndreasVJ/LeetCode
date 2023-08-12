class Solution {
public:
    
    int chosen[6]{};
    vector<int> permutation;
    vector<vector<int>> ans;
    
    void search(vector<int>& nums) {
        if (permutation.size() == nums.size()) ans.push_back(permutation);
        else {
            for (int i = 0; i < nums.size(); i++) {
                if (!chosen[i]) {
                    permutation.push_back(nums[i]);
                    chosen[i] = 1;
                    search(nums);
                    permutation.pop_back();
                    chosen[i] = 0;
                }
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        search(nums);
        return ans;
    }
};