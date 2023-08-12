class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        for (int n = 1; n <= arr.size(); n += 2) {
            for (int i = 0; i < arr.size()-n+1; i++) {
                for (int j = i; j < i+n; j++) {
                    ans += arr[j];
                }
            }
        }
        return ans;
    }
};