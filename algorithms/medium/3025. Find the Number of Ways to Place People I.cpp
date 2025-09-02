class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        struct Comp {
            bool operator()(const vector<int>& a, const vector<int>& b) const {
                if (a[1] == b[1]) {
                    return a[0] < b[0];
                }
                return a[1] > b[1];
            }
        };

        sort(points.begin(), points.end(), Comp());

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (points[j][0] < points[i][0]) {
                    continue;
                }

                bool isValid = true;
                for (int k = i + 1; k < j; k++) {
                    if (points[i][0] <= points[k][0] && points[k][0] <= points[j][0]) {
                        isValid = false;
                        break;
                    }
                }

                if (isValid) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
