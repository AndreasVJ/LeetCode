class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        int ans = 0;

        for (int j, i = 0; i < nums1.size(); i++) {
            j = i < nums2.size() ? i : nums2.size() - 1;
            for (int b = nums2.size()/2; b > 0; b /= 2) {
                while (j < nums2.size() - b && nums2[j + b] >= nums1[i]) j += b;
            }
            if (nums1[i] <= nums2[j]) ans = max(ans, j - i);
        }

        return ans;
    }
};