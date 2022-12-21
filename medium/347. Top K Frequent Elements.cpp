class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> m;
        for (int num : nums) m[num]++;

        struct comp {
            bool operator()(pair<int, int>& a, pair<int, int>& b) {
                return a.second > b.second;
            }
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

        for (const auto& [key, value] : m) {
            pq.push({key, value});
            if (pq.size() > k) pq.pop();
        }

        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;
    }
};