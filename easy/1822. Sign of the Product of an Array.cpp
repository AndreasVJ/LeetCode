class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool s = 1;
        for (int i : nums) {
            if (i == 0) return 0;
            if (i < 0) s = !s;
        }
        return 2*s-1;
    }
};