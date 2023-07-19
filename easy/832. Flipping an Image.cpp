class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for (int y = 0; y < n; y++) {
            for (int i = 0; i < n/2; i++) {
                if (image[y][i] == image[y][n-1-i]) {
                    image[y][i] = (image[y][i] + 1)%2;
                    image[y][n-1-i] = (image[y][n-1-i] + 1)%2;
                }
            }
            if (n%2) image[y][n/2] = (image[y][n/2] + 1)%2;
        }
        return image;
    }
};