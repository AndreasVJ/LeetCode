class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        
        queue<pair<int, int>> q;
        queue<pair<int, int>> q2;

        int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[0].size(); x++) {
                if (grid[y][x] == 1) {

                    q.push({x, y});
                    grid[y][x] = -1;

                    while (!q.empty()) {
                        for (int i = 0; i < 4; i++) {

                            int x2 = q.front().first + directions[i][0];
                            int y2 = q.front().second + directions[i][1];

                            if (0 <= x2 && x2 < grid[0].size() && 0 <= y2 && y2 < grid.size()) {
                                if (grid[y2][x2] == 1) {
                                    q.push({x2, y2});
                                    grid[y2][x2] = -1;
                                }
                                else if (grid[y2][x2] == 0) {
                                    q2.push({x2, y2});
                                    grid[y2][x2] = 2;
                                }
                            }
                        }
                        q.pop();
                    }

                    while (!q2.empty()) {
                        for (int i = 0; i < 4; i++) {

                            int x2 = q2.front().first + directions[i][0];
                            int y2 = q2.front().second + directions[i][1];

                            if (0 <= x2 && x2 < grid[0].size() && 0 <= y2 && y2 < grid.size()) {
                                if (grid[y2][x2] == 0) {
                                    q2.push({x2, y2});
                                    grid[y2][x2] = grid[q2.front().second][q2.front().first] + 1;
                                }
                                else if (grid[y2][x2] == 1) {
                                    return grid[q2.front().second][q2.front().first] - 1;
                                }
                            }
                        }
                        q2.pop();
                    }

                    return -1;
                }
            }
        }

        return -1;
    }
};