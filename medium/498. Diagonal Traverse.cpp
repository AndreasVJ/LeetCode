class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        vector<int> ans;
        int x, y;
        
        for (int i = 0; i < mat[0].size() + mat.size() - 1; i++) {
            if (i%2) {
                x = i >= mat[0].size() ? mat[0].size() - 1 : i;
                y = i >= mat[0].size() ? i - mat[0].size() + 1 : 0;

                while (x >= 0 && y < mat.size()) {
                    ans.push_back(mat[y][x]);
                    x--;
                    y++;
                }
            }
            else {
                x = i >= mat.size() ? i - mat.size() + 1 : 0;
                y = i >= mat.size() ? mat.size() - 1 : i;

                while (x < mat[0].size() && y >= 0) {
                    ans.push_back(mat[y][x]);
                    x++;
                    y--;
                }
            }
        }

        return ans;
    }
};