class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int n : nums) {
            stack<int> s;
            while (n) {
                s.push(n%10);
                n /= 10;
            }
            while (!s.empty()) {
                ans.push_back(s.top());
                s.pop();
            }
        }
        return ans;
    }
};