class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        
        vector<int> ans;

        for (vector<int> query : queries) {
            int cx = query[0];
            int cy = query[1];
            int cr2 = query[2] * query[2];

            int count = 0;

            for (vector<int> point : points) {
                int x = point[0];
                int y = point[1];
                if (pow(cx - x, 2) + pow(cy - y, 2) <= cr2) count++;
            }

            ans.push_back(count);
        }

        return ans;
    }
};