class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int a[2] = {0, 0};
        int b[2] = {INT_MAX, INT_MAX};
        for (int n : nums) {
            if (n > a[1]) {
                a[0] = a[1];
                a[1] = n;
            }
            else if (n > a[0]) {
                a[0] = n;
            }
            if (n < b[1]) {
                b[0] = b[1];
                b[1] = n;
            }
            else if (n < b[0]) {
                b[0] = n;
            }
        }
        return (a[1] * a[0]) - (b[1] * b[0]);
    }
};