class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        int h = grid.size();
        int w = grid[0].size();
        for (int i = 0; i < w; i++) {
            int x = i, y = 0;
            for (int n = 0; n < h; n++) {
                if (x+grid[y][x] < 0 || x+grid[y][x] >= w) {
                    ans.push_back(-1);
                    break;
                }
                if (grid[y][x] != grid[y][x+grid[y][x]]) {
                    ans.push_back(-1);
                    break;
                }
                x += grid[y][x];
                y++;
                if (y == h) ans.push_back(x);
            }
        }
        return ans;
    }
};