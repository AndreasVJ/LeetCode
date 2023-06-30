class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> rowMax(grid.size(), 0);
        vector<int> columnMax(grid[0].size(), 0);

        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[0].size(); x++) {
                rowMax[y] = max(rowMax[y], grid[y][x]);
            }
        }

        for (int x = 0; x < grid[0].size(); x++) {
            for (int y = 0; y < grid.size(); y++) {
                columnMax[x] = max(columnMax[x], grid[y][x]);
            }
        }

        int ans = 0;

        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[0].size(); x++) {
                int h = min(rowMax[y], columnMax[x]);
                ans += h - grid[y][x];
                grid[y][x] = h;
            }
        }

        return ans;
    }
};