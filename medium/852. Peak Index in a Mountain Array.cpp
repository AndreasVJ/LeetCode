class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int k = 0;
        
        for (int b = arr.size()/2; b > 0; b /= 2) {
            while (k < arr.size() - b && arr[k + b] > arr[k + b - 1]) k += b;
        }
        
        return k;
    }
};