class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat[0].size();
        int n = mat.size();
        
        queue<pair<int, int>> q;
        
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (mat[y][x]) mat[y][x] = INT_MAX;
                else q.push({x, y});
            }
        }
        
        int x, y;
        
        while (!q.empty()) {
            
            x = q.front().first;
            y = q.front().second;
            
            if (x - 1 >= 0 && mat[y][x - 1] > mat[y][x]) {
                mat[y][x - 1] = mat[y][x] + 1;
                q.push({x - 1, y});
            }
            if (y - 1 >= 0 && mat[y - 1][x] > mat[y][x]) {
                mat[y - 1][x] = mat[y][x] + 1;
                q.push({x, y - 1});
            }
            if (x + 1 < m && mat[y][x + 1] > mat[y][x]) {
                mat[y][x + 1] = mat[y][x] + 1;
                q.push({x + 1, y});
            }
            if (y + 1 < n && mat[y + 1][x] > mat[y][x]) {
                mat[y + 1][x] = mat[y][x] + 1;
                q.push({x, y + 1});
            }
            
            q.pop();
        }
        
        return mat;
    }
};