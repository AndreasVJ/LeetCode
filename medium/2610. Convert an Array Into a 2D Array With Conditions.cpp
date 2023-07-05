class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int max_count = 0;
        unordered_map<int, int> m;
        for (int n : nums) {
            m[n]++;
            max_count = max(max_count, m[n]);
        }

        vector<vector<int>> ans(max_count);
        for (auto &[k, v] : m) {
            for (int i = 0; i < v; i++) ans[i].push_back(k);
        }
        return ans;
    }
};