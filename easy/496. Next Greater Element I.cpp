class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int, int> m;
        for (int i = 0; i < nums2.size(); i++) {
            m[nums2[i]] = i;
        }
        for (int i = 0; i < nums1.size(); i++) {
            for (int n = m[nums1[i]]+1; n < nums2.size(); n++) {
                if (nums2[n] > nums1[i]) {
                    ans.push_back(nums2[n]);
                    break;
                }
            }
            if (ans.size() < i+1) ans.push_back(-1);
        }
        return ans;
    }
};