class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_prof = 0;
        int min_price = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            min_price = min(min_price, prices[i]);
            max_prof = max(max_prof, prices[i]-min_price);
        }
        return max_prof;
    }
};