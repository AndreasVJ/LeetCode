class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (r*c != mat.size()*mat[0].size()) return mat;
        vector<vector<int>> ans(r, vector<int>{});
        for (int i = 0; i < mat.size(); i++) {
            for (int n = 0; n < mat[0].size(); n++) {
                ans[((mat[0].size())*i+n)/c].push_back(mat[i][n]);
            }
        }
        return ans;
    }
};