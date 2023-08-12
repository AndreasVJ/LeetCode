class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        
        pair<int, int> p[2] = {{0, nums[0]}, {1, nums[1]}};
        sort(p, p + 2, [](const auto a, const auto b) {return a.second < b.second;});
        
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] > p[0].second) {
                p[0] = {i, nums[i]};
                sort(p, p + 2, [](const auto a, const auto b) {return a.second < b.second;});
            }
        }
        
        return p[1].second >= p[0].second * 2 ? p[1].first : -1;
    }
};