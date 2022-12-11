class Solution {
public:
    bool judgeSquareSum(int c) {

        if (c == 1) return 1;

        long b = 0;
        long a = 0;
        long prod;
        
        for (int n = c/2; n > 0; n /= 2) {
            while (b <= c/2 - n && (b + n)*(b + n) <= c) b += n;
        }

        printf("%d\n", b);

        while (b >= a) {
            prod = a*a + b*b;
            if (prod > c) b--;
            else if (prod < c) a++;
            else return 1;
        }

        return 0;
    }
};