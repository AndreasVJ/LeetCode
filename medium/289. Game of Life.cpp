class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int h = board.size();
        int w = board[0].size();
        int d[8][2] = {{0, -1}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {-1, 0}, {-1, -1}};
        queue<pair<int, int>> changes;
        int c, nx, ny;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                c = 0;
                for (auto [dx, dy] : d) {
                    nx = x + dx;
                    ny = y +dy;
                    if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
                        c += board[ny][nx];
                    }
                }
                if (board[y][x]) {
                    if (c < 2 || c > 3) changes.push({x, y});
                }
                else if (c == 3) changes.push({x, y});
            }
        }
        int x, y;
        while (!changes.empty()) {
            x = changes.front().first;
            y = changes.front().second;
            board[y][x] = (board[y][x]+1)%2;
            changes.pop();
        }
    }
};