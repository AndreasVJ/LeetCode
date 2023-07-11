class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();

        for (int x = 1; x < m; x++) grid[0][x] += grid[0][x-1];
        for (int y = 1; y < n; y++) {
            grid[y][0] += grid[y-1][0];
            for (int x = 1; x < m; x++) grid[y][x] += min(grid[y-1][x], grid[y][x-1]);
        }

        return grid.back().back();
    }
};