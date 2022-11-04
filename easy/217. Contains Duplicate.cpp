class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int i : nums) {
            if (s.count(i)) return 1;
            s.insert(i);
        }
        return 0;
    }
};