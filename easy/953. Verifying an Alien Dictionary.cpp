class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> m;
        for (int i = 0; i < order.size(); i++) {
            m[order[i]] = i;
        }
        int l;
        for (int i = 1; i < words.size(); i++) {
            l = min(words[i].size(), words[i-1].size());
            for (int n = 0; n < l; n++) {
                if (m[words[i][n]] > m[words[i-1][n]]) break;
                if (m[words[i][n]] < m[words[i-1][n]]) return 0;
                if (n == l-1 && words[i].size() < words[i-1].size()) return 0;
            }
        }
        return 1;
    }
};