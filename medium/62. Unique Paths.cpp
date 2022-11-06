class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n));
        grid[0][0] = 1;
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                if (y) grid[y][x] += grid[y-1][x];
                if (x) grid[y][x] += grid[y][x-1];
            }
        }
        return grid[m-1][n-1];
    }
};