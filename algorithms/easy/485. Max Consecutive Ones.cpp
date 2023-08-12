class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = 0;
        int best = 0;
        for (int i : nums) {
            if (i) {
                n++;
                best = max(best, n);
            }
            else n = 0;
        }
        return best;
    }
};