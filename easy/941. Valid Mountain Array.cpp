class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        if (arr.size() < 3 || arr[0] > arr[1]) return 0;
        
        int n = 1;
        
        while (n < arr.size() && arr[n] > arr[n - 1]) n++;
        
        if (n == arr.size()) return 0;
        
        for (int i = n; i < arr.size(); i++) {
            if (arr[i] >= arr[i - 1]) return 0;
        }
        
        return 1;
    }
};