class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_set<int> s;
        for (auto edge : edges) {
            if (s.count(edge[0])) {
                return edge[0];
            }
            if (s.count(edge[1])) {
                return edge[1];
            }
            s.insert(edge[0]);
            s.insert(edge[1]);
        }
        return -1;
    }
};
