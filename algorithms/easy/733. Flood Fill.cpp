class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        int h = image.size();
        int w = image[0].size();
        queue<pair<int, int>> q;
        q.push({sc, sr});
        pair<int, int> coord;
        int val;
        while (!q.empty()) {
            coord = q.front();
            val = image[coord.second][coord.first];
            q.pop();
            if (val == color) continue;
            if (coord.first+1 < w && image[coord.second][coord.first+1] == val) {
                q.push({coord.first+1, coord.second});
            }
            if (coord.second+1 < h && image[coord.second+1][coord.first] == val) {
                q.push({coord.first, coord.second+1});
            }
            if (coord.first-1 >= 0 && image[coord.second][coord.first-1] == val) {
                q.push({coord.first-1, coord.second});
            }
            if (coord.second-1 >= 0 && image[coord.second-1][coord.first] == val) {
                q.push({coord.first, coord.second-1});
            }
            image[coord.second][coord.first] = color;
        }
        return image;
    }
};