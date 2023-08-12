class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {

        queue<vector<int>> q;
        
        for (int y = 0; y < rooms.size(); y++) {
            for (int x = 0; x < rooms[0].size(); x++) {
                if (rooms[y][x] == 0) q.push({x, y});
            }
        }

        vector<vector<int>> directions {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!q.empty()) {

            int x = q.front()[0];
            int y = q.front()[1];
            q.pop();

            for (vector<int> d : directions) {
                
                int x2 = d[0];
                int y2 = d[1];

                if (0 <= x + x2 && x + x2 < rooms[0].size() && 0 <= y + y2 && y + y2 < rooms.size()) {
                    if (rooms[y + y2][x + x2] != -1 && rooms[y + y2][x + x2] > rooms[y][x] + 1) {
                        rooms[y + y2][x + x2] = rooms[y][x] + 1;
                        q.push({x + x2, y + y2});
                    }
                }
            }
        }
    }
};