class Solution {
public:
    int dp(int day, int k, bool holding, vector<int>& prices, vector<vector<vector<int>>>& cache) {

        if (k == 0 || day == prices.size()) return 0;
        if (cache[day][k][holding] != -1) return cache[day][k][holding];

        if (holding) {
            return cache[day][k][holding] = max(dp(day + 1, k, holding, prices, cache), dp(day + 1, k - 1, !holding, prices, cache) + prices[day]);
        }
        return cache[day][k][holding] = max(dp(day + 1, k, holding, prices, cache), dp(day + 1, k, !holding, prices, cache) - prices[day]);
    }


    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> cache(prices.size(), vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return dp(0, k, 0, prices, cache);
    }
};