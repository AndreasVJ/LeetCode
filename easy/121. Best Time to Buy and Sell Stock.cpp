class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int max = 0;
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > max) {
                max = prices[i];
                if (max-min > profit) profit = max-min;
            }
            if (prices[i] < min) {
                min = prices[i];
                max = min;
            }
        }
        return profit;
    }
};