class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        queue<pair<int, int>> q;
        
        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[0].size(); x++) {
                if (grid[y][x] == 1) {
                    q.push({x, y});
                    grid[y][x] = 2;
                    break;
                }
                if (!q.empty()) break;
            }
        }

        int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int x2 = x + directions[i][0];
                int y2 = y + directions[i][1];

                if (0 <= x2 && x2 < grid[0].size() && 0 <= y2 && y2 < grid.size()) {
                    if (grid[y2][x2] == 0) ans++;
                    else if (grid[y2][x2] == 1) {
                        q.push({x2, y2});
                        grid[y2][x2] = 2;
                    }
                }
                else ans++;
            }
        }

        return ans;
    }
};