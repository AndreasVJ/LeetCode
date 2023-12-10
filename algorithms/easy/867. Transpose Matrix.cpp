class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> m(matrix[0].size(), vector<int>(matrix.size()));
        for (int y = 0; y < matrix.size(); y++) {
            for (int x = 0; x < matrix[0].size(); x++) {
                m[x][y] = matrix[y][x];
            }
        }
        return m;
    }
};