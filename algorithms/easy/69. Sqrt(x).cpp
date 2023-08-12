class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int k = 1;
        for (int b = x/4; b > 0; b /= 2) {
            while (k + b <= x/2 && (k + b) <= x/(k + b)) k += b;
        }
        return k;
    }
};