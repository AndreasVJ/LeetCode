class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        int greatest_right = 0;
        int prev_greatest_right = -1;
        
        for (int i = arr.size() - 1; i >= 0; i--) {
            greatest_right = max(greatest_right, arr[i]);
            arr[i] = prev_greatest_right;
            prev_greatest_right = greatest_right;
        }
        
        return arr;
    }
};