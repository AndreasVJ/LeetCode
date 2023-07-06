class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans, greater;
        int equal = 0;
        for (int n : nums) {
            if (n < pivot) ans.push_back(n);
            else if (n == pivot) equal++;
            else greater.push_back(n);
        }
        for (int i = 0; i < equal; i++) {
            ans.push_back(pivot);
        }
        ans.insert(ans.end(), greater.begin(), greater.end());
        return ans;
    }
};