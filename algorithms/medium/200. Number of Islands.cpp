class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int h = grid.size();
        int w = grid[0].size();
        queue<pair<int, int>> q;
        int y2, x2;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (grid[y][x] == '1') {
                    q.push({x, y});
                    ans++;
                }
                while (!q.empty()) {
                    x2 = q.front().first;
                    y2 = q.front().second;
                    q.pop();
                    if (grid[y2][x2] == '1') {
                        if (x2+1 < w  && grid[y2][x2+1] == '1') q.push({x2+1, y2});
                        if (y2+1 < h  && grid[y2+1][x2] == '1') q.push({x2, y2+1});
                        if (x2-1 >= 0  && grid[y2][x2-1] == '1') q.push({x2-1, y2});
                        if (y2-1 >= 0  && grid[y2-1][x2] == '1') q.push({x2, y2-1});
                    }
                    grid[y2][x2] = '0';
                }
            }
        }
        return ans;
    }
};