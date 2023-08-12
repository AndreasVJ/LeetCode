class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int ans = 0;

        queue<pair<int, int>> q;
        bool sub;
        
        for (int y = 0; y < grid2.size(); y++) {
            for (int x = 0; x < grid2[0].size(); x++) {
                if (grid2[y][x] == 1) {

                    sub = 1;

                    q.push({x, y});
                    grid2[y][x] = 2;

                    while (!q.empty()) {

                        int x2 = q.front().first;
                        int y2 = q.front().second;

                        if (grid1[y2][x2] == 0) {
                            sub = 0;
                        }   

                        if (x2 + 1 < grid2[0].size() && grid2[y2][x2 + 1] == 1) {
                            q.push({x2 + 1, y2});
                            grid2[y2][x2 + 1] = 2;
                        }
                        if (y2 + 1 < grid2.size() && grid2[y2 + 1][x2] == 1) {
                            q.push({x2, y2 + 1});
                            grid2[y2 + 1][x2] = 2;
                        }
                        if (x2 - 1 >= 0 && grid2[y2][x2 - 1] == 1) {
                            q.push({x2 - 1, y2});
                            grid2[y2][x2 - 1] = 2;
                        }
                        if (y2 - 1 >= 0 && grid2[y2 - 1][x2] == 1) {
                            q.push({x2, y2 - 1});
                            grid2[y2 - 1][x2] = 2;
                        }

                        q.pop();
                    }

                    if (sub) ans++;
                }
            }
        }

        return ans;
    }
};