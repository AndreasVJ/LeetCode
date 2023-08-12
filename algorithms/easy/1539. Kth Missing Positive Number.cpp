class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        if (arr[0] > k) return k;
        
        int i = 0;

        for (int b = arr.size()/2; b > 0; b /= 2) {
            while (i < arr.size() - b && arr[i + b] - i - b <= k) i += b;
        }

        return k + i + 1;
    }
};