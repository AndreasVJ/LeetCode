class Solution {
public:
    int dp(bool same, int i, int n, int k, vector<vector<int>>& cache) {
        
        if (i == n) return 1;
        if (cache[i][same] != 0) return cache[i][same];
        
        if (same) {
            return cache[i][same] = (k-1)*dp(0, i+1, n, k, cache);
        }

        return cache[i][same] = (k-1)*dp(0, i+1, n, k, cache) + dp(1, i+1, n, k, cache);
    }


    int numWays(int n, int k) {
        vector<vector<int>> cache(n, vector<int>(2));
        return k*dp(0, 1, n, k, cache);
    }
};