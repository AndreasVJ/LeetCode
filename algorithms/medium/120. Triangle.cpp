class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int n = 0; n < triangle[i].size(); n++) {
                triangle[i][n] += min(triangle[i+1][n], triangle[i+1][n+1]);
            }
        }
        return triangle[0][0];
    }
};