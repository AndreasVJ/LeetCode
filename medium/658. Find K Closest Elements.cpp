class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int> ans;
        int start = 0;
        
        for (int b = arr.size()/2; b > 0; b /= 2) {
            while (start < arr.size() - b && arr[start + b] < x) start += b;
        }
        
        if (start < arr.size() - 1 && abs(arr[start + 1] - x) < abs(arr[start] - x)) start++;
        
        int end = start + 1;
        
        while (end - start < k) {
            if (start == 0) end = k;
            else if (end == arr.size()) start = arr.size() - k;
            else if (abs(arr[start - 1] - x) <= abs(arr[end] - x)) start--;
            else end++;
        }
        
        for (int i = start; i < end; i++) ans.push_back(arr[i]);
        
        return ans;
    }
};