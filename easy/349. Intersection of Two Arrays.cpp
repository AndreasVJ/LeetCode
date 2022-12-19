class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> s1;
        for (int num : nums1) s1.insert(num);
        
        unordered_set<int> s2;
        for (int num : nums2) s2.insert(num);
        
        vector<int> ans;
        
        for (int i : s1) {
            if (s2.find(i) != s2.end()) ans.push_back(i);
        }
        
        return ans;
    }
};