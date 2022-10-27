class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        int m;
        for (vector a : accounts) {
            m = 0;
            for (int i : a) {
                m += i;
            }
            if (m > max) max = m;
        }
        return max;
    }
};