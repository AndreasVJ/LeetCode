class Solution {
public:
    int fib(int n) {
        int nums[2] = {0, 1};
        for (int i = 1; i < n; i++) {
            nums[(i+1)%2] = nums[0] + nums[1];
        }
        return nums[n%2];
    }
};