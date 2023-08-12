class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        queue<int> q;
        for (int i = nums.size()-k; i < nums.size(); i++) {
            q.push(nums[i]);
        }
        for (int i = nums.size()-1; i >= k; i--) {
            nums[i] = nums[i-k];
        }
        for (int i = 0; i < k; i++) {
            nums[i] = q.front();
            q.pop();
        }
    }
};