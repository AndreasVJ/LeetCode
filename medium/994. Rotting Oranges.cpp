class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        
        bool containsRotten = 0;
        
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (grid[y][x] == 2) {
                    q.push(make_pair(x, y));
                    containsRotten = 1;
                }
            }
        }
        
        int minutes = -1;
        int a, x, y;
        
        while (!q.empty()) {
            minutes++;
            a = q.size();
            for (int i = 0; i < a; i++) {
                x = q.front().first;
                y = q.front().second;
                if (x > 0 && grid[y][x-1] == 1) {
                    q.push(make_pair(x-1, y));
                    grid[y][x-1] = 2;
                }
                if (x < m-1 && grid[y][x+1] == 1) {
                    q.push(make_pair(x+1, y));
                    grid[y][x+1] = 2;
                }
                if (y > 0 && grid[y-1][x] == 1) {
                    q.push(make_pair(x, y-1));
                    grid[y-1][x] = 2;
                }
                if (y < n-1 && grid[y+1][x] == 1) {
                    q.push(make_pair(x, y+1));
                    grid[y+1][x] = 2;
                }
                q.pop();
            }
        }
        
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (grid[y][x] == 1) return -1;
            }
        }
        
        if (containsRotten) return minutes;
        return 0;
    }
};