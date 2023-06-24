class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        vector<unordered_map<int, int>> cache(rods.size());
        return dp(0, 0, rods, cache);
    }

    int dp(int diff, int i, vector<int>& rods, vector<unordered_map<int, int>>& cache) {
        if (i == rods.size()) {
            if (!diff) return 0;
            else return INT_MIN;
        }
        if (cache[i].find(diff) != cache[i].end()) return cache[i][diff];

        int first = rods[i] + dp(diff + rods[i], i + 1, rods, cache);
        int second = dp(diff - rods[i], i + 1, rods, cache);
        int third = dp(diff, i + 1, rods, cache);

        return cache[i][diff] = max({first, second, third});
    }
};