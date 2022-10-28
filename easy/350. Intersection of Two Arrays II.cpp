class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m1, m2;
        for (int i : nums1) m1[i]++;
        for (int i : nums2) m2[i]++;
        vector<int> ans;
        for (auto [k, v] : m1) {
            for (int i = 0; i < min(v, m2[k]); i++) {
                ans.push_back(k);
            }
        }
        return ans;
    }
};