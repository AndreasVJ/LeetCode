class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        vector<int> num1left(s.size());
        vector<int> num0right(s.size());
        int ans = INT_MAX;
        
        for (int count = 0, i = 0; i < s.size(); i++) {
            num1left[i] = count;
            if (s[i] == '1') count++;
        }
        
        for (int count = 0, i = s.size() - 1; i >= 0; i--) {
            num0right[i] = count;

            ans = min(ans, num1left[i] + num0right[i]);

            if (s[i] == '0') count++;
        }

        return ans;
    }
};