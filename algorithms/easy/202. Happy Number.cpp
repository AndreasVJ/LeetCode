class Solution {
public:
    bool isHappy(int n) {
        map<int, bool> m;
        while (n != 1) {
            m[n] = 1;
            int sum = 0;
            while (n) {
                sum += pow(n%10, 2);
                n /= 10;
            }
            n = sum;
            if (m[n]) return 0;
        }
        return 1;
    }
};