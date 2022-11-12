class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int best = 0;
        int curr;
        int x2, y2;
        queue<pair<int, int>> q;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (grid[y][x]) {
                    grid[y][x] = 0;
                    curr = 0;
                    q.push(make_pair(x, y));
                    while (!q.empty()) {
                        curr++;
                        x2 = q.front().first;
                        y2 = q.front().second;
                        if (x2 > 0 && grid[y2][x2-1]) {
                            grid[y2][x2-1] = 0;
                            q.push(make_pair(x2-1, y2));
                        }
                        if (x2 < m-1 && grid[y2][x2+1]) {
                            grid[y2][x2+1] = 0;
                            q.push(make_pair(x2+1, y2));
                        }
                        if (y2 > 0 && grid[y2-1][x2]) {
                            grid[y2-1][x2] = 0;
                            q.push(make_pair(x2, y2-1));
                        }
                        if (y2 < n-1 && grid[y2+1][x2]) {
                            grid[y2+1][x2] = 0;
                            q.push(make_pair(x2, y2+1));
                        }
                        q.pop();
                    }
                    best = max(best, curr);
                }
            }
        }
        
        return best;
    }
};