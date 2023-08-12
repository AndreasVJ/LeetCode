class Solution {
public:
    double soupServings(int n) {
        if (n > 4500) return 1;
        n = n/25 + (n%25 > 0);
        vector<vector<double>> cache(n+1, vector<double>(n+1, -1));
        return dp(n, n, 1, cache);
    }

    double dp(int a, int b, double p, vector<vector<double>>& cache) {
        if (a <= 0 && b <= 0) return p/2;
        if (a <= 0) return p;
        if (b <= 0) return 0;
        if (cache[a][b] != -1) return cache[a][b];
        return cache[a][b] = dp(a - 4, b, p/4, cache) +
                             dp(a - 3, b - 1, p/4, cache) +
                             dp(a - 2, b - 2, p/4, cache) +
                             dp(a - 1, b - 3, p/4, cache);
    }
};