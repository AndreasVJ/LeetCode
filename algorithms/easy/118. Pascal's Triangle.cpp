class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        
        ans.push_back({1});
        
        for (int i = 1; i < numRows; i++) {
            ans.push_back({1});
            for (int n = 0; n < i-1; n++) {
                ans[i].push_back(ans[i-1][n]+ans[i-1][n+1]);
            }
            ans[i].push_back(1);
        }

        return ans;
    }
};