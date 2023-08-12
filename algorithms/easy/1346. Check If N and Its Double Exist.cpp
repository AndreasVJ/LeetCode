class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());

        for (int k, i = 0; i < arr.size(); i++) {
            k = i;
            if (arr[i] > 0) {
                for (int b = (arr.size() - i)/2; b > 0; b /= 2) {
                    while (k < arr.size() - b && arr[k + b] <= 2*arr[i]) k += b;
                }
            }
            else {
                for (int b = i; b > 0; b /= 2) {
                    while (k - b >= 0 && arr[k - b] >= 2*arr[i]) k -= b;
                }
            }
            if (i != k && arr[k] == 2*arr[i]) return 1;
        }
        
        return 0;
    }
};