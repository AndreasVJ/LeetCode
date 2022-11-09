class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int h = matrix.size();
        int l = matrix[0].size();
        int x = 0;
        int y = 0;
        for (int b = h/2; b > 0; b /= 2) {
            while (y+b < h && matrix[y+b][0] <= target) y += b;
        }
        for (int b = l/2; b > 0; b /= 2) {
            while (x+b < l && matrix[y][x+b] <= target) x += b;
        }
        return matrix[y][x] == target;
    }
};