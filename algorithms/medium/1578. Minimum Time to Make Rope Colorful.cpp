class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        if (colors.size() == 1) return 0;
        int ans = 0;
        
        int m = neededTime[0];
        bool sequence = false;
        for (int i = 0; i < colors.size() - 1; i++) {
            if (colors[i] != colors[i+1]) {
                if (sequence) {
                    ans += neededTime[i];
                    ans -= max(m, neededTime[i]);
                }
                m = neededTime[i+1];
                sequence = false;
            }
            else {
                m = max(m, neededTime[i]);
                sequence = true;
                ans += neededTime[i];
            }
        }
        if (sequence) {
            ans += neededTime.back();
            ans -= max(m, neededTime.back());
        }

        return ans;
    }
};