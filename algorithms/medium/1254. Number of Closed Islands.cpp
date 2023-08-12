class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {

        int ans = 0;

        queue<pair<int, int>> q;
        bool closed;
        
        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[0].size(); x++) {
                if (grid[y][x] == 0) {

                    closed = 1;

                    q.push({x, y});
                    grid[y][x] = 2;

                    while (!q.empty()) {

                        int x2 = q.front().first;
                        int y2 = q.front().second;

                        if (y2 == 0 || x2 == 0 || y2 == grid.size() - 1 || x2 == grid[0].size() - 1) {
                            closed = 0;
                        }

                        if (x2 + 1 < grid[0].size() && grid[y2][x2 + 1] == 0) {
                            q.push({x2 + 1, y2});
                            grid[y2][x2 + 1] = 2;
                        }
                        if (y2 + 1 < grid.size() && grid[y2 + 1][x2] == 0) {
                            q.push({x2, y2 + 1});
                            grid[y2 + 1][x2] = 2;
                        }
                        if (x2 - 1 >= 0 && grid[y2][x2 - 1] == 0) {
                            q.push({x2 - 1, y2});
                            grid[y2][x2 - 1] = 2;
                        }
                        if (y2 - 1 >= 0 && grid[y2 - 1][x2] == 0) {
                            q.push({x2, y2 - 1});
                            grid[y2 - 1][x2] = 2;
                        }

                        q.pop();
                    }

                    if (closed) ans++;
                }
            }
        }

        return ans;
    }
};