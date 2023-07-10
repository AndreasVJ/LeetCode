class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        helper(candidates, target, 0, curr, ans);
        return ans;
    }

    void helper(vector<int>& candidates, int target, int idx, vector<int>& curr, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        if (idx == candidates.size() || target - candidates[idx] < 0) return;
        
        curr.push_back(candidates[idx]);
        helper(candidates, target - candidates[idx], idx, curr, ans);
        curr.pop_back();
        
        helper(candidates, target, idx+1, curr, ans);
    }
};