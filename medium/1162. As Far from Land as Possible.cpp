class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {

        int ans = 0;

        queue<pair<int, int>> q1, q2;

        int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[0].size(); x++) {
                if (grid[y][x] == 1) {
                    for (int i = 0; i < 4; i++) {

                        int x2 = x + directions[i][0];
                        int y2 = y + directions[i][1];

                        if (0 <= x2 && x2 < grid[0].size() && 0 <= y2 && y2 < grid.size() && grid[y2][x2] == 0) {
                            grid[y2][x2] = 2;
                            q1.push({x2, y2});
                        }
                    }
                }
            }
        }

        while (!q1.empty()) {

            ans++;

            while (!q1.empty()) {

                int x = q1.front().first;
                int y = q1.front().second;
                q1.pop();

                int dis = grid[y][x];

                ans = max(ans, dis);

                for (int i = 0; i < 4; i++) {

                    int x2 = x + directions[i][0];
                    int y2 = y + directions[i][1];
                
                    if (0 <= x2 && x2 < grid[0].size() && 0 <= y2 && y2 < grid.size() && grid[y2][x2] == 0) {
                        grid[y2][x2] = dis + 1;
                        q2.push({x2, y2});
                    }
                }
            }

            swap(q1, q2);
        }
        
        return ans - 1;
    }
};