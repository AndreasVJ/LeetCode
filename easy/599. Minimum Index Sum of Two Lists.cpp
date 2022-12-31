class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        vector<string> ans;
        unordered_map<string, int> m;

        for (int i = 0; i < list1.size(); i++) {
            m[list1[i]] = i;
        }

        struct comp {
            bool operator()(std::pair<int, int>& a, std::pair<int, int>& b) {
                return a.second > b.second;
            }
        };

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, comp> pq;

        for (int i = 0; i < list2.size(); i++) {
            if(m.find(list2[i]) != m.end()) {
                pq.push({i, m[list2[i]] + i});
            }
        }

        ans.push_back(list2[pq.top().first]);
        int minIndex = pq.top().second;

        pq.pop();

        while(!pq.empty() && pq.top().second == minIndex) {
            ans.push_back(list2[pq.top().first]);
            pq.pop();
        }

        return ans;
    }
};