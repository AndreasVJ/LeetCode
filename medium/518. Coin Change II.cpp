class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        vector<int> arr(amount + 1);
        arr[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                if (arr[i - coin]) arr[i] += arr[i - coin];
            }
        }

        return arr.back();
    }
};