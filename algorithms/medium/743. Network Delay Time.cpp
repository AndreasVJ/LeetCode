class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> edges(n);

        for (vector<int> time : times) {
            edges[time[0] - 1].push_back({time[1] - 1, time[2]});
        }
        
        vector<int> distance(n, INT_MAX);
        distance[k - 1] = 0;

        struct comp {
            bool operator()(std::pair<int, int>& a, std::pair<int, int>& b) {
                return a.second > b.second;
            }
        };

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, comp> pq;

        pq.push({k - 1, 0});

        while (!pq.empty()) {
            
            int curr = pq.top().first;
            int currDistance = pq.top().second;
            pq.pop();

            for (pair<int, int> edge : edges[curr]) {
                if (currDistance + edge.second < distance[edge.first]) {
                    distance[edge.first] = currDistance + edge.second;
                    pq.push({edge.first, distance[edge.first]});
                }
            }

        }

        int maxDistance = 0;

        for (int i : distance) {
            if (i == INT_MAX) return -1;
            maxDistance = max(maxDistance, i);
        }

        return maxDistance;
    }
};