class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        if (grid[0][0] == 1 || grid.back().back() == 1) return -1;
        if (grid.size() == 1) return 1;

        int dir[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        while (!q.empty()) {
            for (int x, y, i = 0; i < 8; i++) {

                x = q.front().first + dir[i][0];
                y = q.front().second + dir[i][1];

                if (0 <= x && x < grid[0].size() && 0 <= y && y < grid.size() && grid[y][x] == 0) {

                    grid[y][x] = grid[q.front().second][q.front().first] + 1;

                    if (x == grid[0].size() - 1 && y == grid.size() - 1) {
                        return grid[y][x];
                    }

                    q.push({x, y});
                }
            }

            q.pop();
        }

        return -1;
    }
};