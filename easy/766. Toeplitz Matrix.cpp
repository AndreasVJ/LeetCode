class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int y = 1; y < matrix.size(); y++) {
            for (int x = 1; x < matrix[0].size(); x++) {
                if (matrix[y][x] != matrix[y-1][x-1]) return false;
            }
        }
        return true;
    }
};