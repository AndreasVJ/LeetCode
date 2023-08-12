class Solution {
public:
    long dp(long m, vector<int>& coins, int amount, vector<int>& cache) {

        if (m == amount) return 0;
        if (m > amount) return INT_MAX >> 1;
        if (cache[m] != -1) return cache[m];

        long best = INT_MAX;

        for (int c : coins) {
            best = min(best, dp(m + c, coins, amount, cache) + 1);
        }

        return cache[m] = best;
    }


    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> cache(amount, -1);

        int ans = dp(0, coins, amount, cache);

        if (ans >= INT_MAX >> 1) return -1;
        return ans;
    }
};