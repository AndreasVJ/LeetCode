class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        int ans = arr1.size();
        int k;
        
        sort(arr2.begin(), arr2.end());
        
        for (int i : arr1) {
            k = 0;
            for (int b = arr2.size()/2; b > 0; b /= 2) {
                while (k < arr2.size() - b && arr2[k + b] <= i) k += b;
            }
            if (abs(i - arr2[k]) <= d || (k + 1 < arr2.size() && abs(arr2[k + 1] - i) <= d)) ans--;
        }
        
        return ans;
    }
};