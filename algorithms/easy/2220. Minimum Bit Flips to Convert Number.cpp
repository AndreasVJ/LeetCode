class Solution {
public:
    int minBitFlips(int start, int goal) {
        return bitset<30>(start ^ goal).count();
    }
};