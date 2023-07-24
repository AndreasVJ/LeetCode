class Solution {
public:
    int maximum69Number (int num) {
        int n = num;
        int pos = -1;
        for (int i = 0; n; i++) {
            if (n%10 == 6) pos = i;
            n /= 10;
        }
        if (pos != -1) return num + 3 * pow(10, pos);
        return num;
    }
};