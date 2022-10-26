class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int max = 0;
        for (int i = 0; i < points.size()-1; i++) {
            unordered_map<float, int> m;
            for (int n = i+1; n < points.size(); n++) {
                float k;
                if (points[i][0] == points[n][0]) k = FLT_MAX;
                else k = (float(points[i][1])-float(points[n][1]))/(float(points[i][0])-float(points[n][0]));
                m[k]++;
                if (m[k] > max) max = m[k];
            }
        }
        return max+1;
    }
};