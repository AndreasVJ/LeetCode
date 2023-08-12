class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](const int& a, const int& b) {
            int ac = __builtin_popcount(a);
            int bc = __builtin_popcount(b);
            return ac == bc ? a < b : ac < bc;
        });
        return arr;
    }
};