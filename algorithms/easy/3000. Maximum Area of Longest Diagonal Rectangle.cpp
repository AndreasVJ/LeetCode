class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int longestDiagSquared = 0;
        int ans;

        for (int i = 0; i < dimensions.size(); i++) {
            int diagSquared = dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1];
            if (diagSquared > longestDiagSquared) {
                longestDiagSquared = diagSquared;
                ans = dimensions[i][0]*dimensions[i][1];
            }
            else if (diagSquared == longestDiagSquared) {
                int area = dimensions[i][0]*dimensions[i][1];
                if (area > ans) {
                    ans = area;
                }
            }
        }

        return ans;
    }
};
