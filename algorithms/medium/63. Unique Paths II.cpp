class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0]) return 0;
        
        vector<vector<int>> paths(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        paths[0][0] = 1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x + 1 < obstacleGrid[0].size() && !obstacleGrid[y][x+1]) {
                if (!paths[y][x + 1]) q.push({x + 1, y});
                paths[y][x + 1] += paths[y][x];
            }
            if (y + 1 < obstacleGrid.size() && !obstacleGrid[y + 1][x]) {
                if (!paths[y + 1][x]) q.push({x, y + 1});
                paths[y + 1][x] += paths[y][x];
            }
        }

        return paths.back().back();
    }
};