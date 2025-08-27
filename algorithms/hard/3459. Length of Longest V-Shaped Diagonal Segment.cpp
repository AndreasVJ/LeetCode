class Solution {
public:
    vector<pair<int, int>> directions = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int d1 = 2;
        int d2 = 4;
        int d3 = grid.size();
        int d4 = grid[0].size();

        vector<vector<vector<vector<int>>>> cache(
            d1, vector<vector<vector<int>>>(
                d2, vector<vector<int>>(
                    d3, vector<int>(d4, -1))));

        int ans = 0;

        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[0].size(); x++) {
                if (grid[y][x] == 1) {
                    ans = max(ans, 1);
                    for (int dirIndex = 0; dirIndex < directions.size(); dirIndex++) {
                        pair<int, int> dir = directions[dirIndex];
                        pair<int, int> pos = {x + dir.first, y + dir.second};
                        if (0 <= pos.first && pos.first < grid[0].size() && 0 <= pos.second && pos.second < grid.size()) {
                            if (grid[pos.second][pos.first] == 2) {
                                ans = max(ans, getVLen(grid, cache, pos, dirIndex, true) + 1);
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }

    int getVLen(vector<vector<int>>& grid, vector<vector<vector<vector<int>>>>& cache, pair<int, int> pos, int dirIndex, bool turnLeft) {
        int cacheResult = cache[turnLeft][dirIndex][pos.second][pos.first];
        if (cacheResult != -1) {
            return cacheResult;
        }

        int ans = 1;

        pair<int, int> dir = directions[dirIndex];
        pair<int, int> newPos = {pos.first + dir.first, pos.second + dir.second};
        if (verifyNewPos(grid, pos, newPos)) {
            ans = max(ans, getVLen(grid, cache, newPos, dirIndex, turnLeft) + 1);
        }

        if (turnLeft) {
            int turnDirIndex = (dirIndex + 1) % 4;
            dir = directions[turnDirIndex];
            newPos = {pos.first + dir.first, pos.second + dir.second};
            if (verifyNewPos(grid, pos, newPos)) {
                ans = max(ans, getVLen(grid, cache, newPos, turnDirIndex, false) + 1);
            }
        }

        return cache[turnLeft][dirIndex][pos.second][pos.first] = ans;
    }

    bool verifyNewPos(vector<vector<int>>& grid, pair<int, int> pos, pair<int, int> newPos) {
        if (0 <= newPos.first && newPos.first < grid[0].size() && 0 <= newPos.second && newPos.second < grid.size()) {
            return grid[pos.second][pos.first] + grid[newPos.second][newPos.first] == 2;
        }
        return false;
    }
};
