class Solution {
public:
    int dp(int i, bool holding, vector<int>& prices, vector<vector<int>>& cache) {

        if (i >= prices.size()) return 0;
        if (cache[i][holding] != -1) return cache[i][holding];

        int doNothing = dp(i + 1, holding, prices, cache);
        int doSomething;

        if (holding) {
            doSomething = dp(i + 2, false, prices, cache) + prices[i];
        }
        else {
            doSomething = dp(i + 1, true, prices, cache) - prices[i];
        }

        return cache[i][holding] = max(doNothing, doSomething);
    }


    int maxProfit(vector<int>& prices) {
        vector<vector<int>> cache(prices.size(), vector<int>(2, -1));
        return dp(0, false, prices, cache);
    }
};