class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int x = 0;
        int y = 0;

        for (int b = matrix.size()/2; b > 0; b /= 2) {
            while (y + b < matrix.size() && matrix[y + b][0] <= target) y += b;
        }

        for (int b = matrix[0].size()/2; b > 0; b /= 2) {
            while (x + b < matrix[0].size() && matrix[y][x + b] <= target) x += b;
        }

        return matrix[y][x] == target;
    }
};