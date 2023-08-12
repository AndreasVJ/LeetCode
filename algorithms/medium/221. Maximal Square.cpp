class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        vector<vector<int>> m(matrix.size() + 1, vector<int>(matrix[0].size() + 1));

        int maxLength = 0;

        for (int y = 1; y < m.size(); y++) {
            for (int x = 1; x < m[0].size(); x++) {
                if (matrix[y-1][x-1] == '1') {
                    m[y][x] = min({m[y-1][x-1], m[y-1][x], m[y][x-1]}) + 1;
                    maxLength = max(maxLength, m[y][x]);
                }
            }
        }

        return maxLength*maxLength;
    }
};