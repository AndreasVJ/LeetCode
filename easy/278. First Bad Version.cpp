// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int k = 0;
        for (int b = n/2; b > 0; b /= 2) {
            while (k < n - b && !isBadVersion(k+b)) k += b;
        }
        return k+1;
    }
};