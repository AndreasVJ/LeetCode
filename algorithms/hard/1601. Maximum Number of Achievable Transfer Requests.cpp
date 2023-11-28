class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans = 0;
        int s = requests.size();
        vector<int> movements(n, 0);
        for (int i = 0; i < (1 << s); i++) {
            for (int j = 0; j < s; j++) {
                if (i & (1 << j)) {
                    movements[requests[j][0]]--;
                    movements[requests[j][1]]++;
                }
            }
            bool skip = false;
            
            for (int j = 0; j < n; j++) {
                if (movements[j] != 0) {
                    for (int k = j; k < n; k++) {
                        movements[k] = 0;
                    }
                    skip = true;
                }
                if (skip) break;
            }
            if (skip) continue;
            ans = max(ans, __builtin_popcount(i));
        }
        return ans;
    }
};