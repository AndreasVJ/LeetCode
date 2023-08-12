class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int ans = 0;
        int x = grid[0].size() - 1;

        for (int y = 0; y < grid.size(); y++) {
            for (int b = x; b > 0; b /= 2) {
                while (x - b >= 0 && grid[y][x - b] < 0) x -= b;
            }
            if (x == 0 && grid[y][x] < 0) return ans + grid[0].size() * (grid.size() - y);
            if (grid[y][x] < 0) ans += grid[0].size() - x;
        }

        return ans;
    }
};