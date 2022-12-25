class Solution {
public:
    string toHex(int num) {

        if (num == 0) return "0";

        char hexTable[] = "0123456789abcdef";
        string ans;

        uint32_t n = num;

        while (n) {
            ans.insert(0, 1, hexTable[n & 0xF]);
            n >>= 4;
        }

        return ans;
    }
};