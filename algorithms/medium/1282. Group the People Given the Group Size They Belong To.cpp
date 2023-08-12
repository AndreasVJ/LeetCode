class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < groupSizes.size(); i++) {
            m[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> groups = {};
        for (auto const &[size, ids] : m) {
            for (int i = 0; i < ids.size(); i++) {
                if (i%size == 0) groups.push_back({});
                groups.back().push_back(ids[i]);
            }
        }

        return groups;
    }
};