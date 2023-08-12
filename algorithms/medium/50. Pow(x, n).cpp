class Solution {
public:
    double myPow(double x, long n) {
        
        if (n == 0) return 1;

        if (n < 0) {
            x = 1 / x;
            n = -n;
        }

        double half = myPow(x, n / 2);
        
        return n%2 ? half * half * x : half * half;
    }
};