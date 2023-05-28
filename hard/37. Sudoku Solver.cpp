class Solution {
public:
    bool solveSudoku(vector<vector<char>>& board) {
        for (int y = 0; y < 9; y++) {
            for (int x = 0; x < 9; x++) {
                if (board[y][x] == '.') {
                    for (char n = '1'; n <= '9'; n++) {
                        if (possible(board, x, y, n)) {
                            board[y][x] = n;
                            if (solveSudoku(board)) return true;
                            board[y][x] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }

    bool possible(vector<vector<char>>& board, int x, int y, char n) {
        for (int i = 0; i < 9; i++) {
            if (board[y][i] == n || board[i][x] == n) return false;
        }

        int x0 = x - x%3;
        int y0 = y - y%3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[y0+i][x0+j] == n) return false;
            }
        }

        return true;
    }
};