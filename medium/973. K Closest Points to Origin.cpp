class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        struct comp {
            bool operator()(pair<int, double>& a, pair<int, double>& b) {
                return a.second < b.second;
            }
        };

        priority_queue<pair<int, double>, vector<pair<int, double>>, comp> pq;

        for (int i = 0; i < points.size(); i++) {
            
            pq.push({i, sqrt(pow(points[i][0], 2) + pow(points[i][1], 2))});

            if (pq.size() > k) pq.pop();
        }

        vector<vector<int>> ans;

        while (!pq.empty()) {
            ans.push_back(points[pq.top().first]);
            pq.pop();
        }

        return ans;
    }
};