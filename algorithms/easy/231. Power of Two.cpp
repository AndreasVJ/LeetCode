class Solution {
public:
    bool isPowerOfTwo(int n) {
        return bitset<33>(n).count() == 1;
    }
};