// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned int k = 0;
        for (unsigned int b = n/2; b >= 1; b/=2) {
            while (k+b < n && !isBadVersion(k+b)) k += b;
        }
        return k+1;
    }
};