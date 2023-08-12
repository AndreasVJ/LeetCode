class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m = {{0, 0}};
        int max = 0;
        for (int i : nums) {
            m[i]++;
        }
        for (auto [k, v] : m) {
            if (v > m[max]) max = k; 
        }
        return max;
    }
};