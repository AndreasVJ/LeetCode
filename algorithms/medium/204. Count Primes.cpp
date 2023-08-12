class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        int ans = 1;
        vector<bool> notPrime(n, false);
        int lim = sqrt(n);
        for (int i = 3; i < n; i += 2) {
            if (!notPrime[i]) {
                ans++;
                if (i > lim) continue;
                for (int j = i+i; j < n; j += i) {
                    notPrime[j] = true;
                }
            }
        }
        return ans;
    }
};