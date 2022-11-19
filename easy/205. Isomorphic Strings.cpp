class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        unordered_set<char> seen;
        for (int i = 0; i < t.size(); i++) {
            if (m.find(t[i]) != m.end()) {
                if (m[t[i]] != s[i]) return 0;
            }
            else {
                if (seen.count(s[i])) return 0;
                m[t[i]] = s[i];
                seen.insert(s[i]);
            }
        }
        return 1;
    }
};