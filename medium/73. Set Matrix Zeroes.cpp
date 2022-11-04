class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows;
        set<int> columns;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (matrix[y][x] == 0) {
                    rows.insert(y);
                    columns.insert(x);
                }
            }
        }
        for (int i : rows) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = 0;
            }
        }
        for (int i : columns) {
            for (int j = 0; j < n; j++) {
                matrix[j][i] = 0;
            }
        }
    }
};