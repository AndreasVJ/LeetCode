class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<pair<char, char>> v;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                v.push_back({s1[i], s2[i]});
                if (v.size() > 2) return 0;
            }
        }
        if (v.size() == 0) return 1;
        if (v.size() == 1) return 0;
        if (v[0].first == v[1].second && v[0].second == v[1].first) return 1;
        return 0;
    }
};