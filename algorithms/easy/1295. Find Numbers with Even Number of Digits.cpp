class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        int n;
        for (int i : nums) {
            n = 0;
            while (i) {
                i /= 10;
                n++;
            }
            count += (n+1)%2;
        }
        return count;
    }
};