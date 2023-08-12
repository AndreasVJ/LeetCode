class Solution {
public:
    int firstUniqChar(string s) {
        
        map<char, int> m;
        int a[26];
        
        for (int i = 0; i < s.size(); i++) {
            if (!m[s[i]]) a[s[i]-97] = i;
            m[s[i]]++;
        }
        
        int first = INT_MAX;
        for (auto [k, v] : m) {
            if (v == 1) {
                if (a[k-97] < first) first = a[k-97];
            }
        }
        if (first == INT_MAX) return -1;
        return first;
    }
};