class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        sum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            sum.push_back(nums[i] + sum[i-1]);
        }
    }
    
    int sumRange(int left, int right) {
        if (left) {
            return sum[right] - sum[left-1];
        }
        return sum[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */