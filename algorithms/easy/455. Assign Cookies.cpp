class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int ans = 0;
        while (g.size() && s.size()) {
            if (s.back() >= g.back()) {
                s.pop_back();
                ans++;
            }
            g.pop_back();
        }

        return ans;
    }
};