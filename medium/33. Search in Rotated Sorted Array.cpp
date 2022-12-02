class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int rot = nums.size() - 1;
        int k = 0;
        
        for (int b = nums.size()/2; b > 0; b /= 2) {
            while (rot - b >= 0 && nums[rot] > nums[rot - b]) rot -= b;
        }
        
        cout << rot << "\n";
        
        for (int b = nums.size()/2; b > 0; b/= 2) {
            while (k + b < nums.size() && nums[(k + b + rot)%nums.size()] <= target) k += b;
        }
        
        return nums[(k + rot)%nums.size()] == target ? (k + rot)%nums.size() : -1;
    }
};