class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> longestPath(m, vector<int>(n, -1));

        int ans = 0;

        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                int l = longestPath[y][x];
                if (l != -1) {
                    if (l > ans) {
                        ans = l;
                    }
                }
                else {
                    ans = max(ans, dfs(x, y, matrix, longestPath));
                }
            }
        }

        return ans;
    }

    int dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& longestPath) {
        int& cacheVal = longestPath[y][x];
        if (cacheVal != -1) {
            return cacheVal;
        }

        int m = matrix.size();
        int n = matrix[0].size();

        int best = 0;

        for (pair<int, int> d : dirs) {
            int x2 = x + d.first;
            int y2 = y + d.second;

            if (!(0 <= x2 && x2 < n && 0 <= y2 && y2 < m)) {
                continue;
            }
            if (matrix[y2][x2] > matrix[y][x]) {
                best = max(best, dfs(x2, y2, matrix, longestPath));
            }
        }

        return cacheVal = best+1;
    }

    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
};
