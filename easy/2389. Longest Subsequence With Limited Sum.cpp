class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {

        sort(nums.begin(), nums.end());

        vector<int> ans;

        for (int query : queries) {
            
            int count = 0;
            
            for (int num : nums) {
                if (num <= query) {
                    query -= num;
                    count++;
                }
                else {
                    break;
                }
            }

            ans.push_back(count);
        }

        return ans;
    }
};