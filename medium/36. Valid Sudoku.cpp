class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool subgrids[9][9]{};
        bool rows[9][9]{};
        bool columns[9][9]{};
        int val;
        for (int y = 0; y < 9; y++) {
            for (int x = 0; x < 9; x++) {
                val = board[y][x]-49;
                if (val >= 0) {
                    if (subgrids[3*(y/3)+x/3][val]) return 0;
                    if (rows[y][val]) return 0;
                    if (columns[x][val]) return 0;
                    subgrids[3*(y/3)+x/3][val] = 1;
                    rows[y][val] = 1;
                    columns[x][val] = 1;
                }
            }
        }
        return 1;
    }
};