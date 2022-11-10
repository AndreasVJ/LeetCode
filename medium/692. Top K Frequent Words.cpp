struct Compare {
    bool operator() (pair<string, int> a, pair<string, int> b) {
        if(a.second == b.second)
            return a.first > b.first;
        else
            return a.second < b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (string word : words) m[word]++;
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;
        for(auto const&[word, count] : m) pq.push({word, count});
        
        vector<string> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};