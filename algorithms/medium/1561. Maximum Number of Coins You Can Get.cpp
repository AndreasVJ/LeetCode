class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int ans = 0;
        int n = piles.size()/3;
        for (int i = piles.size()-2; i >= n; i -= 2) {
            ans += piles[i];
        }
        return ans;
    }
};