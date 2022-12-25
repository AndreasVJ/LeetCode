class Solution {
public:
    string convertToBase7(int num) {
        
        int ans = 0;

        for (int i = 1; num; i *= 10) {
            ans += (num % 7) * i;
            num /= 7;
        }

        return to_string(ans);
    }
};