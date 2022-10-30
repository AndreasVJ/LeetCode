class Solution {
public:
    int mySqrt(int x) {
        double a = 1;
        for (int i = 0; i < 20; i++) {
            a -= (a*a-x)/(2*a);
        }
        return floor(a);
    }
};