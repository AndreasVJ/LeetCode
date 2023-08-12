class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int shift = count(arr.begin(), arr.end(), 0);
        for (int i = arr.size()-1; i >= 0; i--) {
            if (arr[i] == 0) shift--;
            if (i + shift < arr.size()) {
                arr[i + shift] = arr[i];
                if (arr[i] == 0 && i + shift + 1 < arr.size()) {
                    arr[i + shift + 1] = 0;
                }
            }
        }
    }
};