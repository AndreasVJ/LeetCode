class Solution {
public:
    int numberOfWays(string corridor) {
        int chairs = 0;
        int plants = 0;
        long long ans = 1;
        for (char c : corridor) {
            if (c == 'S') {
                chairs++;
                if (chairs == 3) {
                    ans *= plants+1;
                    ans %= static_cast<long long>(1e9 + 7);
                    plants = 0;
                    chairs = 1;
                }
            }
            else if (c == 'P' && chairs == 2) {
                plants++;
            }
        }
        if (chairs != 2) return 0;
        return ans;
    }
};