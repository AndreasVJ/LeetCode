class Solution {
public:
    bool isPerfectSquare(int num) {
        
        long k = 1;
        
        for (long b = num/2; b > 0; b /= 2) {
            while (k <= num/2 - b && (k + b)*(k + b) <= num) k += b;
        }
        
        return k*k == num;
    }
};